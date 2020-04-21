/*****************************************************************************************************************************
This problem was asked by Yahoo.
You are given a string of length N and a parameter k. The string can be manipulated by taking one of the first k letters and
moving it to the end.
Write a program to determine the lexicographically smallest string that can be created after an unlimited number of moves.
For example, suppose we are given the string daily and k = 1. The best we can create in this case is ailyd.
*****************************************************************************************************************************/ 
s = "geeksforgeeks"
k = 5
sb = ""
result = s
while len(s) > 0:
	smallest = s[0]
	smallestIndex = 0
	for i, r in enumerate(s):
		if i < k and r < smallest:
			smallest = r
			smallestIndex = i
	s = s[:smallestIndex] + s[smallestIndex+1:]
	sb += smallest
	candidate = s+sb
	print(candidate)
	if candidate < result:
		result = candidate
		
print(result)
