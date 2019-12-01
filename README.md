# Daily-Coding-Problem

- - - -
### Day 100 ###
This problem was asked by Google.
You are in an infinite 2D grid where you can move in any of the 8 directions:
```
(x,y) to
    (x+1, y),
    (x - 1, y),
    (x, y+1),
    (x, y-1),
    (x-1, y-1),
    (x+1,y+1),
    (x-1,y+1),
    (x+1,y-1)
 ```
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.
Example:
Input: [(0, 0), (1, 1), (1, 2)]
Output: 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).

[Solution](https://github.com/dhanendraverma/Daily-Coding-Problem/blob/master/Day100.cpp)
- - - -
### Day 101 ###
This problem was asked by Alibaba.
Given an even number (greater than 2), return two prime numbers whose sum will be equal to the given number.
A solution will always exist. See Goldbach’s conjecture.
Example:
Input: 4
Output: 2 + 2 = 4
If there are more than one solution possible, return the lexicographically smaller solution.
If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, then
[a, b] < [c, d]
If a < c OR a==c AND b < d.

[Solution](https://github.com/dhanendraverma/Daily-Coding-Problem/blob/master/Day101.cpp)
- - - -
### Day 102 ###
This problem was asked by Lyft.
Given a list of integers and a number K, return which contiguous elements of the list sum to K.
For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should return [2, 3, 4], since 2 + 3 + 4 = 9.

[Solution](https://github.com/dhanendraverma/Daily-Coding-Problem/blob/master/Day102.cpp)
- - - -
### Day 103 ###
This problem was asked by Square.
Given a string and a set of characters, return the shortest substring containing all the characters in the set.
For example, given the string "figehaeci" and the set of characters {a, e, i}, you should return "aeci".
If there is no substring containing all the characters in the set, return null.

[Solution](https://github.com/dhanendraverma/Daily-Coding-Problem/blob/master/Day103.cpp)
- - - -
### Day 104 ###
This problem was asked by Google.
Determine whether a doubly linked list is a palindrome. What if it’s singly linked?
For example, 1 -> 4 -> 3 -> 4 -> 1 returns True while 1 -> 4 returns False.

[Solution](https://github.com/dhanendraverma/Daily-Coding-Problem/blob/master/Day104.cpp)
- - - -
### Day 106 ###
This problem was asked by Pinterest.
Given an integer list where each number represents the number of hops you can make, determine whether you can reach to the last index starting at index 0.
For example, [2, 0, 1, 0] returns True while [1, 1, 0, 1] returns False.

[Solution](https://github.com/dhanendraverma/Daily-Coding-Problem/blob/master/Day106.cpp)
