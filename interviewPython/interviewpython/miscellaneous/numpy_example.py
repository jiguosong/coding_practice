'''
Created on Nov 15, 2016

@author: songjiguo
'''

import matplotlib.pylab as plt
import numpy as np
x = np.linspace(-np.pi, np.pi, 201)
plt.plot(x, np.sin(x))
plt.xlabel('Angle [rad]')
plt.ylabel('sin(x)')
plt.axis('tight')
plt.show()

if __name__ == '__main__':
    pass