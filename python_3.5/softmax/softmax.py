import numpy as np
# softmax(x) = softmax(x+c)
'''
def softmax(x):
    x = x - np.max(x)
    exp_x = np.exp(x)
    softmax_x = exp_x / np.sum(exp_x)
    return softmax_x

x = [1,2,3,4,5]
'''
def softmax(x):
    orig_shape = x.shape
    if len(x.shape) > 1:
        exp_minmax = lambda x: np.exp(x-np.max(x))
        denom = lambda x: 1.0/np.sum(x)
        x = np.apply_along_axis(exp_minmax,1,x)
        denominator = np.apply_along_axis(denom,1,x)
        if len(denominator.shape) == 1:
            denominator = denominator.reshape((denominator.shape[0],1))
        x = x*denominator
    else:
        x_max = np.max(x)
        x = x - x_max
        numerator = np.exp(x)
        denominator = 1.0/np.sum(numerator)
        x = numerator.dor(denominator)

    assert x.shape == orig_shape
    return x
x = np.array([[1,2,3],[4,5,6],[7,8,9]])
print(softmax(x))
