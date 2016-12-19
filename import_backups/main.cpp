/***************************************************************************

    file                 : main.cpp
    created              : Sat Mar 18 23:54:30 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: main.cpp,v 1.14.2.3 2012/06/01 01:59:42 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <stdlib.h>

#include <GL/glut.h>

#include <tgfclient.h>
#include <client.h>

#include "linuxspec.h"
#include <raceinit.h>

/////////////////// added by lidong (start)
#include <sys/shm.h> 
#define image_width 640
#define image_height 480
#include <iostream> // added by lidong 
#include <unistd.h> // added by lidong
/////////////////// added by lidong (end)

extern bool bKeepModules;

static void
init_args(int argc, char **argv, const char **raceconfig)
{
	int i;
	char *buf;

	i = 1;

	while(i < argc) {
		if(strncmp(argv[i], "-l", 2) == 0) {
			i++;

			if(i < argc) {
				buf = (char *)malloc(strlen(argv[i]) + 2);
				sprintf(buf, "%s/", argv[i]);
				SetLocalDir(buf);
				free(buf);
				i++;
			}
		} else if(strncmp(argv[i], "-L", 2) == 0) {
			i++;

			if(i < argc) {
				buf = (char *)malloc(strlen(argv[i]) + 2);
				sprintf(buf, "%s/", argv[i]);
				SetLibDir(buf);
				free(buf);
				i++;
			}
		} else if(strncmp(argv[i], "-D", 2) == 0) {
			i++;

			if(i < argc) {
				buf = (char *)malloc(strlen(argv[i]) + 2);
				sprintf(buf, "%s/", argv[i]);
				SetDataDir(buf);
				free(buf);
				i++;
			}
		} else if(strncmp(argv[i], "-s", 2) == 0) {
			i++;
			SetSingleTextureMode();
		} else if(strncmp(argv[i], "-k", 2) == 0) {
			i++;
			// Keep modules in memory (for valgrind)
			printf("Unloading modules disabled, just intended for valgrind runs.\n");
			bKeepModules = true;
#ifndef FREEGLUT
		} else if(strncmp(argv[i], "-m", 2) == 0) {
			i++;
			GfuiMouseSetHWPresent(); /* allow the hardware cursor */
#endif
		} else if(strncmp(argv[i], "-r", 2) == 0) {
			i++;
			*raceconfig = "";

			if(i < argc) {
				*raceconfig = argv[i];
				i++;
			}

			if((strlen(*raceconfig) == 0) || (strstr(*raceconfig, ".xml") == 0)) {
				printf("Please specify a race configuration xml when using -r\n");
				exit(1);
			}
		} else {
			i++;		/* ignore bad args */
		}
	}

#ifdef FREEGLUT
	GfuiMouseSetHWPresent(); /* allow the hardware cursor (freeglut pb ?) */
#endif
}

/*
 * Function
 *	main
 *
 * Description
 *	LINUX entry point of TORCS
 *
 * Parameters
 *
 *
 * Return
 *
 *
 * Remarks
 *
 */

///////////////// added by lidong (start)
struct shared_use_st
{
	uint8_t written;
	uint8_t restart;
    uint8_t steer_cmd_idx_high;
    uint8_t steer_cmd_idx_low;
	float speed;
	float to_track_middle;
    float dist_raced;
	uint8_t data[image_width*image_height*3];
};

uint8_t* pwritten = NULL;
uint8_t* prestart_ghost = NULL;
uint8_t* psteer_cmd_idx_high_ghost = NULL;
uint8_t* psteer_cmd_idx_low_ghost = NULL;
float* pspeed_ghost = NULL;
float* pto_track_middle_ghost = NULL;
float* pdist_raced_ghost = NULL;
uint8_t* pdata = NULL;
void* shm = NULL;
///////////////// added by lidong (end) 

int
main(int argc, char *argv[])
{
	///////////////// added by lidong (start)
	struct shared_use_st *shared = NULL;
	int shmid;
	shmid = shmget((key_t)2345, sizeof(struct shared_use_st), 0666|IPC_CREAT);
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
    printf("\n **************** Memory sharing starting *************\n");
    shared = (struct shared_use_st*) shm;

    shared->written = 0;
    shared->restart = 0;
    shared->speed = 0.0;
    shared->to_track_middle = 0.0;
    pwritten = &shared->written;
    prestart_ghost = &shared->restart;
    psteer_cmd_idx_high_ghost = &shared->steer_cmd_idx_high;
    psteer_cmd_idx_low_ghost = &shared->steer_cmd_idx_low;
    pspeed_ghost = &shared->speed;
    pto_track_middle_ghost = &shared->to_track_middle;
    pdist_raced_ghost = &shared->dist_raced;
    pdata = shared->data;
	///////////////// added by lidong (end) 

	const char *raceconfig = "";

	init_args(argc, argv, &raceconfig);
	LinuxSpecInit();			/* init specific linux functions */

	if(strlen(raceconfig) == 0) {
		GfScrInit(argc, argv);	/* init screen */
		TorcsEntry();			/* launch TORCS */
		glutMainLoop();			/* event loop of glut */
	} else {
		// Run race from console, no Window, no OpenGL/OpenAL etc.
		// Thought for blind scripted AI training
		ReRunRaceOnConsole(raceconfig);
	}

	return 0;					/* just for the compiler, never reached */
}

