import os
import numpy as np
from PIL import Image

f = np.load("MNIST_DATA/npz/mnist.npz")
x_train = f['x_train']
y_train = f['y_train']
x_test = f['x_test']
y_test = f['y_test']
##new_im = os.makedirs(r'F:\Projects\Git\lc_programs_cpp\python_3.5\cv\MNIST_png\train')
##new_im = os.makedirs(r'F:\Projects\Git\lc_programs_cpp\python_3.5\cv\MNIST_png\test')
new_im = os.makedirs(r'MNIST_png\train')
new_im = os.makedirs(r'MNIST_png\test')
for i in range(x_train.shape[0]):
    new_im = Image.fromarray(x_train[i,:,:])
    new_im.save('MNIST_png/train/No_%d label_%d.png' %(i,y_train[i]))

for j in range(x_test.shape[0]):
    new_im = Image.fromarray(x_test[j,:,:])
    new_im.save('MNIST_png/test/No_%d label_%d.png' %(j,y_test[j]))
print("Completed")
