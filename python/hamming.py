 #! /usr/bin/env python

"""
"""


from numpy import *

def hamming(x, y):
    x = str("{0:b}".format(x))
    y = str("{0:b}".format(y))
    l = max(len(x), len(y))
    cnt = 0
    x = x.zfill(l)
    y = y.zfill(l)
    for i in range(l):
        if x[i] != y[i]:
            cnt = cnt + 1
    print cnt

def main():
    x = 10
    y = 3  
    hamming(x, y)


if __name__ == '__main__':
    main()
