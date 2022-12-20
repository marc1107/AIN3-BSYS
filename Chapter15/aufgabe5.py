#! /usr/bin/env python

import random
import matplotlib.pyplot as plt
import numpy as np

addsize = 1024
physize = 16 * 1024
list = [0] * physize

for i in range(20):
    random.seed(i)
    for j in range(addsize):
        limit = j
        viraddress = j * (random.random() + 1)

        if viraddress < limit:
            list[limit] += 1


print("Test")
