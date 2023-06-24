#!/usr/bin/python
# -*- coding: utf-8 -*-
import cv2
import numpy as np

cap = cv2.VideoCapture(0) 
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi', fourcc, 20.0, (800,480))

while True:
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    out.write(frame)
    cv2.imshow('gray', gray)
    cv2.imshow('frame', frame)

    if cv2.waitKey(10) is 27:
        break
cap.release()
out.release()
cv2.destroyAllWindows()
