##########################################################################################################################################
#This question was asked by Google.
#Given an integer n and a list of integers l, write a function that randomly generates a number from 0 to n-1 that isn't in l (uniform)
##########################################################################################################################################
import random


def generateRandom(l,n):
	nums = []
	for i in range(1,n+1):
		if i not in l:
			nums.append(i)
	return nums[random.randint(0,len(nums))]
	
l = [2,3,4,7,8,14,18]
n = 25
print(generateRandom(l,n))
print(generateRandom(l,n))
print(generateRandom(l,n))
