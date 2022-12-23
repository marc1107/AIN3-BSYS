#! /usr/bin/env python

import random
import matplotlib.pyplot as plt
import numpy as np

addsize = 1024
physize = 16 * 1024
list = [0] * physize

for i in range(300):
    random.seed(i)
    for j in range(physize):
        limit = j
        viraddress = int(addsize * (random.random()))

        if viraddress < limit:
            list[j] += 1


fig = plt.figure()
x = np.linspace(1, physize, physize)
plt.plot(x, [u / 20 for u in list], color='orange')
plt.ylim(0, 1)
plt.margins(0)
plt.xlabel('Limit')
plt.ylabel('Valid fraction (Average)')
plt.savefig('aufgabe5.png', dpi=227)
plt.show()
