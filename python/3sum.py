 #! /usr/bin/env python

"""
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

O(n^2) solution
"""


from numpy import *

def threesum(nums):
    indices = array(range(len(nums)))
    sums = []
    if len(nums) == 0:
        return nums
    for target in nums:
        lookup = {}
        target = - target
        for i in indices[indices != nums.index(-target)]: 
            if nums[i] in lookup:
                sums.append(tuple(sorted([nums[i], target - nums[i], -target])))
            else:
                lookup[target - nums[i]] = i
    return list(set(sums))

def main():
    nums = [-1, 0, 1, 2, -1, -4] 
    nums = [-2, 0, 6, -3, -1, -4] 
    #nums = [] 
    idx = threesum(nums)
    print idx


if __name__ == '__main__':
    main()
