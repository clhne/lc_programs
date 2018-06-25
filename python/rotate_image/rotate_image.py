#!/usr/bin/python2.7
import numpy as np
def rotate(matrix):
    matrix[:] = [[row[i] for row in reversed(matrix)] for i in range(len(matrix))]

matrix = np.arange(10)
print matrix