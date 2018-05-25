# -*- coding: utf-8 -*-
from filterpy.kalman import MerweScaledSigmaPoints as SigmaPoints

mean = 0    # 均值
cov =  1    # 方差

points = SigmaPoints(n=1, alpha=0.1, beta=2.0, kappa=1.0)  
# Wm, Wc = points.weights()
Wm, Wc = points.Wm, points.Wc
sigmas = points.sigma_points(mean, cov)

print Wm, Wc    # 计算均值和方差的权值
print sigmas    # sigma点的坐标