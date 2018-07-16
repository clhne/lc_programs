import numpy as np
# softmax(x) = softmax(x+c)
def softmax(x):
    x = x - np.max(x)
    exp_x = np.exp(x)
    softmax_x = exp_x / np.sum(exp_x)
    return softmax_x

x = [1,2,3,4,5]
print(softmax(x))
