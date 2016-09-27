//************** IPC_command.cpp ***************//
// Used for creat shared memory for data and command sharing.
//
// Required files:
//      1. IPC_command.cpp
//      2. torcs_data.pb.h
//      3. torcs_data.pb.cc
//
// $ g++ IPC_command.cpp torcs_data.pb.cc -o IPC_command 
//       `pkg-config --cflags --libs opencv protobuf libzmq`
// 
// Last modified: 2016-09-27: 20:30

#include <iostream>
//#include <termios.h>
#include <unistd.h>
#include <sys/shm.h>
#include <stdlib.h>  
#include <stdio.h>
#include "cv.h"  
#include "highgui.h"
#include <zmq.hpp> 
#include "torcs_data.pb.h"

using namespace std;
using namespace cv;

#define image_width 640
#define image_height 480
#define resize_width 280
#define resize_height 210

struct shared_use_st  
{  
    int written;
    unsigned char data[image_width*image_height*3];
    // double steer_angle;
    int control;
    int pause;
    int zmq_flag;   //  added by lidong
    int save_flag;  //  added by lidong
    double fast;

    double dist_L;
    double dist_R;

    double toMarking_L;
    double toMarking_M;
    double toMarking_R;

    double dist_LL;
    double dist_MM;
    double dist_RR;

    double toMarking_LL;
    double toMarking_ML;
    double toMarking_MR;
    double toMarking_RR;

    double toMiddle;
    double angle;
    double speed;

    double steerCmd;
    double accelCmd;
    double brakeCmd;
};

int main(int argc, char const *argv[])
{
    void *shm = NULL;
    struct shared_use_st *shared;
    int shmid;
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666|IPC_CREAT);
    if(shmid == -1)  
    {  
        fprintf(stderr, "shmget failed\n");  
        exit(EXIT_FAILURE);  
    }
    shm = shmat(shmid, 0, 0);  
    if(shm == (void*)-1)  
    {  
        fprintf(stderr, "shmat failed\n");  
        exit(EXIT_FAILURE);  
    }  
    printf("\n********** Memory sharing started, attached at %X **********\n", shm);

    shared = (struct shared_use_st*)shm; 
    shared->written = 0;
    shared->control = 0;
    shared->pause = 0;
    shared->zmq_flag = 0;  //  added by lidong
    shared->save_flag = 0;
    //shared->steer_angle = 0.0;
    shared->fast = 0.0;

    shared->dist_L = 0.0;
    shared->dist_R = 0.0;

    shared->toMarking_L = 0.0;
    shared->toMarking_M = 0.0;
    shared->toMarking_R = 0.0;

    shared->dist_LL = 0.0;
    shared->dist_MM = 0.0;
    shared->dist_RR = 0.0;

    shared->toMarking_LL = 0.0;
    shared->toMarking_ML = 0.0;
    shared->toMarking_MR = 0.0;
    shared->toMarking_RR = 0.0;

    shared->toMiddle = 0.0;
    shared->angle = 0.0;
    shared->speed = 0.0;

    shared->steerCmd = 0.0;
    shared->accelCmd = 0.0;
    shared->brakeCmd = 0.0;

    // Setup zmq
    static zmq::context_t context(1);
    static zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:5555");
    TorcsData torcs_data;
    unsigned char image[resize_width*resize_height * 3];

    // Setup opencv
    IplImage* screenRGB=cvCreateImage(cvSize(image_width,image_height),IPL_DEPTH_8U,3);
    IplImage* resizeRGB=cvCreateImage(cvSize(resize_width,resize_height),IPL_DEPTH_8U,3);
    cvNamedWindow("Image from TORCS",1);
    int key;
    IplImage* out_red = cvCreateImage(cvSize(resize_width,resize_height), IPL_DEPTH_8U, 1);
    IplImage* out_green = cvCreateImage(cvSize(resize_width,resize_height), IPL_DEPTH_8U, 1);
    IplImage* out_blue = cvCreateImage(cvSize(resize_width,resize_height), IPL_DEPTH_8U, 1);

    while (true) {    

        if (shared->written == 1) {
            for (int h = 0; h < image_height; h++) {
                for (int w = 0; w < image_width; w++) {
                   screenRGB->imageData[(h*image_width+w)*3+2]=shared->data[((image_height-h-1)*image_width+w)*3+0];
                   screenRGB->imageData[(h*image_width+w)*3+1]=shared->data[((image_height-h-1)*image_width+w)*3+1];
                   screenRGB->imageData[(h*image_width+w)*3+0]=shared->data[((image_height-h-1)*image_width+w)*3+2];
                }
            }
            // printf("---screenRGB read complete.\n");
            // Resize image and send it to protobuf
            cvResize(screenRGB, resizeRGB);
            for (int h = 0; h < resize_height; h++) {
                for (int w = 0; w < resize_width; w++){
                    image[(h*resize_width)*3+0] = resizeRGB->imageData[(h*resize_width+w)*3+2];
                    image[(h*resize_width)*3+1] = resizeRGB->imageData[(h*resize_width+w)*3+1];
                    image[(h*resize_width)*3+2] = resizeRGB->imageData[(h*resize_width+w)*3+0];
                }
            }
            // cvShowImage("Image from TORCS", resizeRGB);
            cvSplit(resizeRGB, out_blue, out_green, out_red, NULL);

            // printf("---image read complete.\n");
            torcs_data.clear_width();
            torcs_data.clear_height();
            torcs_data.clear_red();
            torcs_data.clear_green();
            torcs_data.clear_blue();
            torcs_data.clear_save_flag();
            torcs_data.clear_image();
            //torcs_data.add_image((const void*)image, (size_t) resize_width * resize_height * 3);
            //torcs_data.add_red((const void*)&channel[2], (size_t) resize_width * resize_height);
            //torcs_data.add_green((const void*)&channel[1], (size_t) resize_width * resize_height);
            torcs_data.add_red((const void*)out_red->imageData, (size_t) resize_width * resize_height);
            torcs_data.add_green((const void*)out_green->imageData, (size_t) resize_width * resize_height);
            torcs_data.add_blue((const void*)out_blue->imageData, (size_t) resize_width * resize_height);
            // torcs_data.add_image((const void*)resizeRGB, (size_t) resize_width * resize_height * 3);
            torcs_data.add_width(resize_width);
            torcs_data.add_height(resize_height);
            torcs_data.add_save_flag(shared->save_flag);
            cout << "torcs_data shape: [" << torcs_data.width(0) << ", " << torcs_data.height(0) << "]" << endl;

            cvShowImage("Image from TORCS", resizeRGB);

            string serialized_data;
            torcs_data.SerializeToString(&serialized_data);
            // std::cout << "checked OK!  1" << std::endl;

            zmq::message_t request;
            socket.recv(&request);
            std::string replyMessage = std::string(static_cast<char *>(request.data()), request.size());
            std::cout << "Recived from client: " + replyMessage << std::endl;

            zmq::message_t reply(serialized_data.size());
            // std::cout << "checked OK!  2" << std::endl;
            memcpy((void*) reply.data(), serialized_data.data(), serialized_data.size());
            std::cout << "---length of message to client: " << reply.size() << std::endl;
            socket.send(reply);
            // std::cout << "checked OK!  3" << std::endl;

            shared->written=0;
        }

        key = cvWaitKey(100);
        if (key==1048688 || key==112){ // P
            shared->pause = 1 - shared->pause;
            printf("shared->pause = %d\n", shared->pause);
        }else if(key == 115){ // S
            shared->save_flag = 1 - shared->save_flag;
            printf("shared->save_flag = %d\n", shared->save_flag);
        }else if (key==1048603 || key==27){ // ESC
            shared->pause = 0;
            printf("ESC is pressed, exit\n");
            break;
        }

    }

    if(shmdt(shm) == -1)  
    {  
        fprintf(stderr, "shmdt failed\n");  
        exit(EXIT_FAILURE);  
    }  

    if(shmctl(shmid, IPC_RMID, 0) == -1)  
    {  
        fprintf(stderr, "shmctl(IPC_RMID) failed\n");  
        exit(EXIT_FAILURE);  
    }
    printf("\n********** Memory sharing stopped. Good Bye! **********\n");  

    return 0;
}
