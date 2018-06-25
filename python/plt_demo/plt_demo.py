#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
from sklearn import metrics
plt.plot([1,2,3,4])
plt.ylabel('some numbers')
plt.show()
y = np.array([1,1,2,2])
pred = np.array([0.1,0.4,0.35,0.8])
plt.plot(pred, y)
plt.show()
fpr,tpr,thresholds = metrics.roc_curve(y,pred,pos_label=2)
print metrics.auc(fpr,tpr)
print fpr, tpr,thresholds
