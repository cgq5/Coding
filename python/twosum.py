
"""
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
"""


from numpy import *
import math


# brute force solution..
def twosum(arr, target):
    x = range(len(arr))
    indices_orig = argsort(arr)
    indices_ts = []
    arr = arr[indices_orig]
    print arr[:int(ceil(len(arr)/2.0))]
    for idx_x, x in enumerate(arr):
        for idx_y, y in enumerate(arr[::-1]):
            if y == target - x:
                indices_ts.append(indices_orig[idx_x])
                indices_ts.append(indices_orig[len(arr) - idx_y - 1])
                return indices_ts 

def main():
    arr = array([0,4,3,0])
    target = 0 
    idx = twosum(arr, target)
    print idx


if __name__ == '__main__':
    main()
