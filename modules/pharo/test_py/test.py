#!/usr/bin/env python3.4

import sys
import cv2
import numpy as np
# import matplotlib.pyplot as plt

# cv2_dir = dir(cv2)
    
bgr_img = cv2.imread('lenna.png')
gray_img = cv2.cvtColor(bgr_img, cv2.COLOR_BGR2GRAY)
cv2.imwrite('lenna_gray.jpg',gray_img)

cv2.imshow('we',gray_img)

while True:
    k = cv2.waitKey(0) & 0xFF    # 0xFF? To get the lowest byte.
    if k == 27: break            # Code for the ESC key

cv2.destroyAllWindows()