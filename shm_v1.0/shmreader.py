''' IPC via shared memory
'''
import sysv_ipc
import numpy as np
import time
import cv2

# Create shared memory object
memory = sysv_ipc.SharedMemory(1234)
cv2.namedWindow("Image from torcs", cv2.WINDOW_AUTOSIZE)
while True:
    # time.sleep(1)
    memory_value = memory.read(byte_count=640*480*3 + 1)
    written = np.fromstring(memory_value[0], dtype = np.uint8)

    if (written == 1).all():
        img = np.fromstring(memory_value[1:], dtype = np.uint8)
        img = img.reshape(480, 640, 3)
        res = cv2.resize(img, (100, 100))
        gray = cv2.cvtColor(res, cv2.COLOR_RGB2GRAY)
        cv2.imshow("Image from torcs", gray)
        cv2.waitKey(10)
        memory.write("0", offset = 0) # actually write 48
    else:
        continue

