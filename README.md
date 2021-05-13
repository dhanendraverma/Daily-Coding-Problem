# Daily-Coding-Problem

Solutions in cpp/python to problems from the daily mailer of the [DailyCodingProblem](https://www.dailycodingproblem.com)

- - - -
#### Problem 1
Given a list of numbers, return whether any two sums to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass?

[Solution](Day1.cpp)
- - - -

#### Problem 2
<br>This problem was asked by Uber.
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the
numbers in the original array except the one at i.
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2,
1], the expected output would be [2, 3, 6].
Follow-up: what if you can't use division?

[Solution](Day2.cpp)
- - - -

#### Problem 3
This problem was asked by Google.
Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s),
which deserializes the string back into the tree.

[Solution](Day3.cpp)
- - - -

#### Problem 4
This problem was asked by Stripe.
<br>Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find
the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
You can modify the input array in-place.

[Solution](Day4.cpp)
- - - -

#### Problem 5
This problem was asked by Jane Street.
cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. 
For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.
Given this implementation of cons:
```python
def cons(a, b):
    return lambda f : f(a, b)
```
Implement car and cdr.

[Solution](Day5.cpp)
- - - -

#### Problem 6
This problem was asked by Google.
An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds
a field named both, which is an XOR of the next node and the previous node.
<br>Implement an XOR linked list; it has an
add(element) which adds the element to the end, and a get(index) which returns the node at index.
If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and
dereference_pointer functions that converts between nodes and memory addresses.

[Solution](Day6.cpp)
- - - -

#### Problem 7
This problem was asked by Facebook.
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
You can assume that the messages are decodable. For example, '001' is not allowed.

[Solution](Day7.cpp)
- - - -

#### Problem 8
This problem was asked by Google.
<br>A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
<br>Given the root to a binary tree, count the number of unival subtrees.
For example, the following tree has 5 unival subtrees:
```
   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
```

[Solution](Day8.cpy)
- - - -

#### Problem 9
This problem was asked by Airbnb.
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or
negative.
For example, [2, 4, 6, 8] should return 12, since we pick 4 and 8. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

[Solution](Day9.cpp)
- - - -

#### Problem 10
This problem was asked by Apple.
Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.

[Solution](Day10.cpp)
- - - -

#### Problem 11
This problem was asked by Twitter.
Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings
in the set that have s as a prefix.
For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].
Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.

[Solution](Day11.cpp)
- - - -

#### Problem 12
This problem was asked by Amazon.
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that
returns the number of unique ways you can climb the staircase. The order of the steps matters.
For example, if N is 4, then there are 5 unique ways:
```
1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
```
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.

[Solution](Day12.cpp)
- - - -

#### Problem 13
This problem was asked by Amazon.
Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

[Solution](Day13.cpp)
- - - -

#### Problem 14
This problem was asked by Google.
The area of a circle is defined as r^2. Estimate \pi to 3 decimal places using a Monte Carlo method.
Hint: The basic equation of a circle is x^2 + y^2 = r^2.

[Solution](Day14.cpp)
- - - -

#### Problem 15
This problem was asked by Facebook.
Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.

[Solution](Day15.cpp)
- - - -

#### Problem 16
This problem was asked by Twitter.
You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish
this, with the following API:
record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.

[Solution](Day16.cpp)
- - - -

#### Problem 17
This problem was asked by Google.
Suppose we represent our file system by a string in the following manner:
The string `"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"` represents:
```
dir
    subdir1
    subdir2
        file.ext
```
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
The string `"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"` represents:
```
dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
```
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second
level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.
We are interested in finding the longest (number of characters) absolute path to a file within our file system. 
For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is
32 (notincluding the double quotes).
<br>Given a string representing the file system in the above format, return the length of the longest absolute path to a file
in the abstracted file system. If there is no file in the system, return 0.

[Solution](Day17.cpp)
- - - -

#### Problem 18
This problem was asked by Google.
Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray
of length k.
<br>For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:
```
10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
```
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You
can simply print them out as you compute them.

[Solution](Day18.cpp)
- - - -

#### Problem 19
This problem was asked by Facebook.
A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while
ensuring that no two neighboring houses are of the same color.
Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, return the
minimum cost which achieves this goal.

[Solution](Day19.cpp)
- - - -

#### Problem 20
This problem was asked by Google.
Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.
For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.
In this example, assume nodes with the same value are the exact same node objects.
Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.

[Solution](Day20.cpp)
- - - -

#### Problem 21
This problem was asked by Snapchat.
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms
required.
For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.

[Solution](Day21.cpp)
- - - -

#### Problem 22
This problem was asked by Microsoft.
Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there
is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.
For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return
['the', 'quick', 'brown', 'fox'].
Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed',
'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].

[Solution](Day22.cpp)
- - - -

#### Problem 23
This problem was asked by Google.
You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each
False boolean represents a tile you can walk on.
Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end
coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot
move through walls. You cannot wrap around the edges of the board.
For example, given the following board:
```
[[f, f, f, f],
 [t, t, f, t],
 [f, f, f, f],
 [f, f, f, f]]
```
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.

[Solution](Day23.cpp)
- - - -

#### Problem 24
This problem was asked by Google.
Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors
are not locked.
Design a binary tree node class with the following methods:
is_locked, which returns whether the node is locked
lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and
return true.
unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and
return true.
You may augment the node to add parent pointers or any other property you would like. You may assume the class is used in a
single-threaded program, so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the
height of the tree.

[Solution](Day24.cpp)
- - - -

#### Problem 25
This problem was asked by Facebook.
Implement regular expression matching with the following special characters:
* . (period) which matches any single character
* \* (asterisk) which matches zero or more of the preceding element
That is, implement a function that takes in a string and a valid regular expression and returns whether or not the string
matches the regular expression.
For example, given the regular expression "ra." and the string "ray", your function should return true. The same regular
expression on the string "raymond" should return false.
Given the regular expression `".*at"` and the string "chat", your function should return true. The same regular expression on the string "chats" should return false.

[Solution](Day25.cpp)
- - - -

#### Problem 26
This problem was asked by Google.
Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than
the length of the list.
The list is very long, so making more than one pass is prohibitively expensive.
Do this in constant space and in one pass.

[Solution](Day26.cpp)
- - - -

#### Problem 27
This problem was asked by Facebook.
Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).
For example, given the string "([])[]({})", you should return true.
Given the string "([)]" or "((()", you should return false.

[Solution](Day27.cpp)
- - - -

#### Problem 28
This problem was asked by Palantir.
Write an algorithm to justify text. Given a sequence of words and an integer line length k, return a list of strings which
represents each line, fully justified.
More specifically, you should have as many words as possible in each line. There should be at least one space between each
word. Pad extra spaces when necessary so that each line has exactly length k. Spaces should be distributed as equally as
possible, with the extra spaces, if any, distributed starting from the left.
If you can only fit one word on a line, then you should pad the right-hand side with spaces.
Each word is guaranteed not to be longer than k.
For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k = 16, you
should return the following:
["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly

[Solution](Day28.cpp)
- - - -

#### Problem 29
This problem was asked by Amazon.
Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive
characters as a single count and character.
For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".
Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of
alphabetic characters. You can assume the string to be decoded is valid.

[Solution](Day29.cpp)
- - - -

#### Problem 30
You are given an array of non-negative integers that represents a two-dimensional elevation map where each element is unit
width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.
Compute how many units of water remain trapped on the map in O(N) time and O(1) space.
For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.
Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index (we
cannot hold 5 since it would run off to the left), so we can trap 8 units of water.

[Solution](Day30.cpp)
- - - -

#### Problem 31
This problem was asked by Google.
The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions
required to change one string to the other. For example, the edit distance between "kitten" and "sitting" is three:
substitute the "k" for "s", substitute the "e" for "i", and append a "g".
Given two strings, compute the edit distance between them.

[Solution](Day31.cpp)
- - - -

#### Problem 32
This problem was asked by Jane Street.
Suppose you are given a table of currency exchange rates, represented as a 2D array. Determine whether there is a possible
arbitrage: that is, whether there is some sequence of trades you can make, starting with some amount A of any currency, so
that you can end up with some amount greater than A of that currency.
There are no transaction costs and you can trade fractional quantities.

[Solution](Day32.cpp)
- - - -

#### Problem 33
This problem was asked by Microsoft.
Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so
far on each new element.
Recall that the median of an even-numbered list is the average of the two middle numbers.
For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:
```
2
1.5
2
3.5
2
2
2
```

[Solution](Day33.cpp)
- - - -

#### Problem 34
This problem was asked by Quora.
Given a string, find the palindrome that can be made by inserting the fewest number of characters as possible anywhere in the
word. If there is more than one palindrome of minimum length that can be made, return the lexicographically earliest one (the
first one alphabetically).
For example, given the string "race", you should return "ecarace", since we can add three letters to it (which is the
smallest amount to make a palindrome). There are seven other palindromes that can be made from "race" by adding three
letters, but "ecarace" comes first alphabetically.
As another example, given the string "google", you should return "elgoogle".

[Solution](Day34.cpp)
- - - -

#### Problem 35
This problem was asked by Google.
Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first,
the Gs come second, and the Bs come last. You can only swap elements of the array.Do this in linear time and in-place.
For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].

[Solution](Day35.cpp)
- - - -

#### Problem 36
This problem was asked by Dropbox.
Given the root to a binary search tree, find the second largest node in the tree.

[Solution](Day36.cpp)
- - - -

#### Problem 37
This problem was asked by Google.
The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.
For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.
You may also use a list or array to represent a set.

[Solution](Day37.cpp)
- - - -

#### Problem 38
This problem was asked by Microsoft.
You have an N by N board. Write a function that, given N, returns the number of possible arrangements of the board where N
queens can be placed on the board without threatening each other, i.e. no two queens share the same row, column, or diagonal.

[Solution](Day38.cpp)
- - - -

#### Problem 39
This problem was asked by Dropbox.
Conway's Game of Life takes place on an infinite two-dimensional board of square cells. Each cell is either dead or alive, and at each tick, the following rules apply:
* Any live cell with less than two live neighbours dies.
* Any live cell with two or three live neighbours remains living.
* Any live cell with more than three live neighbours dies.
* Any dead cell with exactly three live neighbours becomes a live cell.
* A cell neighbours another cell if it is horizontally, vertically, or diagonally adjacent.
Implement Conway's Game of Life. It should be able to be initialized with a starting list of live cell coordinates and the
number of steps it should run for. Once initialized, it should print out the board state at each step. Since it's an infinite
board, print out only the relevant coordinates, i.e. from the top-leftmost live cell to bottom-rightmost live cell.
You can represent a live cell with an asterisk `*` and a dead cell with a dot `.`.

[Solution](Day39.cpp)
- - - -

#### Problem 40
This problem was asked by Google.
Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and
return the non-duplicated integer.
For example, given `[6, 1, 3, 3, 3, 6, 6]`, return `1`. Given `[13, 19, 13, 13]`, return `19`.
Do this in $O(N)$ time and $O(1)$ space.

[Solution](Day40.cpp)
- - - -

#### Problem 41
This problem was asked by Facebook.
Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, and a starting airport,
compute the person's itinerary. If no such itinerary exists, return null. If there are multiple possible itineraries, return
the lexicographically smallest one. All flights must be used in the itinerary.
For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and starting airport
'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].
Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.
Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', you should return the
list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary. However, the first one is
lexicographically smaller.

[Solution](Day41.py)
- - - -

#### Problem 42
This problem was asked by Google.
Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k. If such a
subset cannot be made, then return null.
Integers can appear more than once in the list. You may assume all numbers in the list are positive.
For example, given `S = [12, 1, 61, 5, 9, 2]` and `k = 24`, return [12, 9, 2, 1] since it sums up to 24.

[Solution](Day42.cpp)
- - - -

#### Problem 43
This problem was asked by Amazon.
Implement a stack that has the following methods:
* `push(val)`, which pushes an element onto the stack
* `pop()`, which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should
throw an error or return null.
* `max()`, which returns the maximum value in the stack currently. If there are no elements in the stack, then it should
throw an error or return null.
Each method should run in constant time.

[Solution](Day43.cpp)
- - - -

#### Problem 44
This problem was asked by Google.
We can determine how "out of order" an array A is by counting the number of inversions it has. Two elements A[i] and A[j]
form an inversion if A[i] > A[j] but i < j. That is, a smaller element appears after a larger element.
Given an array, count the number of inversions it has. Do this faster than O(N^2) time.You may assume each element in the array is distinct.
For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3).
The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.

[Solution](Day44.cpp)
- - - -

#### Problem 45
This problem was asked by Two Sigma.
Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability, implement a function
rand7() that returns an integer from 1 to 7 (inclusive).

[Solution](Day45.cpp)
- - - -

#### Problem 46
This problem was asked by Amazon.
Given a string, find the longest palindromic contiguous substring. If there are more than one with the maximum length, return
any one.
For example, the longest palindromic substring of "aabcdcb" is "bcdcb". The longest palindromic substring of "bananas" is "anana".

[Solution](Day46.cpp)
- - - -

#### Problem 47
This problem was asked by Facebook.
Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates
the maximum profit you could have made from buying and selling that stock once. You must buy before you can sell it.
For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 
dollars.

[Solution](Day47.cpp)
- - - -

#### Problem 48
This problem was asked by Google.
Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.
For example, given the following preorder traversal:
```
[a, b, d, e, c, f, g]
```
And the following inorder traversal:
```
[d, b, e, a, f, c, g]
```
You should return the following tree:
```
    a
   / \
  b   c
 / \ / \
d  e f  g
```

[Solution](Day48.cpp)
- - - -

#### Problem 49
This problem was asked by Amazon.
Given an array of numbers, find the maximum sum of any contiguous subarray of the array.
For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14,
-5, and 86.
Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.
Do this in O(N) time.

[Solution](Day49.cpp)
- - - -

#### Problem 50
This problem was asked by Microsoft.
Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+',
'−', '∗', or '/'.
Given the root to such a tree, write a function to evaluate it.
For example, given the following tree:
```
    *
   / \
  +    +
 / \  / \
3  2  4  5
```
You should return 45, as it is (3 + 2) * (4 + 5).

[Solution](Day50.cpp)
- - - -

#### Problem 51
This problem was asked by Facebook.
Given a function that generates perfectly random numbers between 1 and k (inclusive), where k is an input, write a function
that shuffles a deck of cards represented as an array using only swaps.
It should run in O(N) time.
Hint: Make sure each one of the 52! permutations of the deck is equally likely.

[Solution](Day51.py)
- - - -

#### Problem 52
This problem was asked by Google.
Implement an LRU (Least Recently Used) cache. It should be able to be initialized with a cache size n, and contain the
following methods:
set(key, value): sets key to value. If there are already n items in the cache and we are adding a new item, then it should
also remove the least recently used item.
get(key): gets the value at key. If no such key exists, return null.
Each operation should run in O(1) time.

[Solution](Day52.py)
- - - -

#### Problem 53
This problem was asked by Apple.
Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) data structure with the following
methods: enqueue, which inserts an element into the queue, and dequeue, which removes it.

[Solution](Day53.cpp)
- - - -

#### Problem 54
This problem was asked by Dropbox.
Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with digits. The objective is to fill the grid with the
constraint that every row, column, and box (3 by 3 subgrid) must contain all of the digits from 1 to 9.
Implement an efficient sudoku solver.

[Solution](Day54.cpp)
- - - -

#### Problem 55
This problem was asked by Microsoft.
Implement a URL shortener with the following methods:
* shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
* restore(short), which expands the shortened string into the original url. If no such shortened string exists, return null.
Hint: What if we enter the same URL twice?

[Solution](Day55.cpp)
- - - -

#### Problem 56
This problem was asked by Google.
Given an undirected graph represented as an adjacency matrix and an integer k, write a function to determine whether each
vertex in the graph can be colored such that no two adjacent vertices share the same color using at most k colors.

[Solution](Day56.cpp)
- - - -

#### Problem 57
This problem was asked by Amazon.
Given a string s and an integer k, break up the string into multiple texts such that each text has a length of k or less. You
must break it up so that words don't break across lines. If there's no way to break the text up, then return null.
You can assume that there are no spaces at the ends of the string and that there is exactly one space between each word.
For example, given the string "the quick brown fox jumps over the lazy dog" and k = 10, you should return: ["the quick",
"brown fox", "jumps over", "the lazy", "dog"]. No string in the list has a length of more than 10.

[Solution](Day57.cpp)
- - - -

#### Problem 58
This problem was asked by Amazon.
An sorted array of integers was rotated an unknown number of times. Given such an array, find the index of the element in the
array in faster than linear time. If the element doesn't exist in
the array, return null.
For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).
You can assume all the integers in the array are unique.

[Solution](Day58.cpp)
- - - -

#### Problem 59
This problem was asked by Google.
Implement a file syncing algorithm for two computers over a low-bandwidth network. What if we know the files in the two
computers are mostly the same?

[Solution](Day59.cpp)
- - - -

#### Problem 60
This problem was asked by Facebook.
Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same. 
For example, given the multiset {15, 5, 20, 10, 35, 15, 10}, it would return true, since we can split it up into {15, 5, 10,
15, 10} and {20, 35}, which both add up to 55. Given the multiset {15, 5, 20, 10, 35}, it would return false, since we can't
split it up into two subsets that add up to the same sum.

[Solution](Day60.cpp)
- - - -

#### Problem 61
This problem was asked by Google.
Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y are integers and returns x^y.
Do this faster than the naive method of repeated multiplication.
For example, pow(2, 10) should return 1024.

[Solution](Day61.cpp)
- - - -

#### Problem 62
This problem was asked by Facebook.
There is an N by M matrix of zeroes. Given N and M, write a function to count the number of ways of starting at the top-left
corner and getting to the bottom-right corner. You can only move right or down.
For example, given a 2 by 2 matrix, you should return 2, since there are two ways to get to the bottom-right:
* Right, then down
* Down, then right
Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.

[Solution](Day62.cpp)
- - - -

#### Problem 63
This problem was asked by Microsoft.
Given a 2D matrix of characters and a target word, write a function that returns whether the word can be found in the matrix
by going left-to-right, or up-to-down.
For example, given the following matrix:
```
[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]
```
and the target word 'FOAM', you should return true, since it's the leftmost column. Similarly, given the target word 'MASS',
you should return true, since it's the last row.

[Solution](Day63.cpp)
- - - -

#### Problem 64
This problem was asked by Google.
A knight's tour is a sequence of moves by a knight on a chessboard such that all squares are visited once.
Given N, write a function to return the number of knight's tours on an N by N chessboard.

[Solution](Day64.cpp)
- - - -

#### Problem 65
This problem was asked by Amazon.
Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.
For example, given the following matrix:
```
[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]
```
You should print out the following:
```
1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12
```

[Solution](Day65.cpp)
- - - -

#### Problem 66
This problem was asked by Square.
Assume you have access to a function toss_biased() which returns 0 or 1 with a probability that's not 50-50 (but also not 0
100 or 100-0). You do not know the bias of the coin.
Write a function to simulate an unbiased coin toss.

[Solution](Day66.cpp)
- - - -

#### Problem 67
This problem was asked by Google.
Implement an LFU (Least Frequently Used) cache. It should be able to be initialized with a cache size n, and contain the
following methods:
* `set(key, value)`: sets key to value. If there are already n items in the cache and we are adding a new item, then it
should also remove the least frequently used item. If there is a tie, then the least recently used key should be removed.
* `get(key)`: gets the value at key. If no such key exists, return null. 
Each operation should run in O(1) time.

[Solution](Day67.cpp)
- - - -

#### Problem 68
This problem was asked by Google.
On our special chessboard, two bishops attack each other if they share the same diagonal. This includes bishops that have
another bishop located between them, i.e. bishops can attack through pieces.
You are given N bishops, represented as (row, column) tuples on a M by M chessboard. Write a function to count the number of
pairs of bishops that attack each other. The ordering of the pair doesn't matter: (1, 2) is considered the same as (2, 1).
For example, given M = 5 and the list of bishops:
```
(0, 0)
(1, 2)
(2, 2)
(4, 0)
```
The board would look like this:
```
[b 0 0 0 0]
[0 0 b 0 0]
[0 0 b 0 0]
[0 0 0 0 0]
[b 0 0 0 0]
```
You should return 2, since bishops 1 and 3 attack each other, as well as bishops 3 and 4.

[Solution](Day68.cpp)
- - - -

#### Problem 69
This problem was asked by Facebook.
Given a list of integers, return the largest product that can be made by multiplying any three integers.
For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.
You can assume the list has at least three integers.

[Solution](Day69.cpp)
- - - -

#### Problem 70
A number is considered perfect if its digits sum up to exactly 10.
Given a positive integer n, return the n-th perfect number.
For example, given 1, you should return 19. Given 2, you should return 28.

[Solution](Day70.cpp)
- - - -

#### Problem 71
This problem was asked by Two Sigma.
Using a function rand7() that returns an integer from 1 to 7 (inclusive) with uniform probability, implement a function
rand5() that returns an integer from 1 to 5 (inclusive).
(repeated question - Problem 45)

[Solution](Day71.cpp)
- - - -

#### Problem 72
This problem was asked by Google.
In a directed graph, each node is assigned an uppercase letter. We define a path's value as the number of most frequently
occurring letter along that path. For example, if a path in the graph goes through "ABACA", the value of the path is 3, since
there are 3 occurrences of 'A' on the path.
Given a graph with n nodes and m directed edges, return the largest value path of the graph. If the largest value is 
nfinite, then return null.
The graph is represented with a string and an edge list. The i-th character represents the uppercase letter of the i-th node.
Each tuple in the edge list (i, j) means there is a directed edge from the i-th node to the j-th node. Self-edges are
possible, as well as multi-edges.For example, the following input graph:
```
ABACA
[(0, 1),
 (0, 2),
 (2, 3),
 (3, 4)]
```
Would have maximum value 3 using the path of vertices `[0, 2, 3, 4], (A, A, C, A)`.
The following input graph:
```
A
[(0, 0)]
```
Should return null, since we have an infinite loop.

[Solution](Day72.cpp)
- - - -

#### Problem 73
This problem was asked by Google.
Given the head of a singly linked list, reverse it in-place.

[Solution](Day73.cpp)
- - - -

#### Problem 74
This problem was asked by Apple.
Suppose you have a multiplication table that is N by N. That is, a 2D array where the value at the i-th row and j-th column
is (i + 1) * (j + 1) (if 0-indexed) or i * j (if 1-indexed).
Given integers N and X, write a function that returns the number of times X appears as a value in an N by N multiplication
table.
For example, given N = 6 and X = 12, you should return 4, since the multiplication table looks like this:

| 1   | 2   | 3   | 4   | 5   | 6   |
|-----|-----|-----|-----|-----|-----|
| 2   | 4   | 6   | 8   | 10  | 12  |
| 3   | 6   | 9   | 12  | 15  | 18  |
| 4   | 8   | 12  | 16  | 20  | 24  |
| 5   | 10  | 15  | 20  | 25  | 30  |
| 6   | 12  | 18  | 24  | 30  | 36  |

And there are 4 12's in the table.

[Solution](Day74.cp)
- - - -

#### Problem 75
This problem was asked by Microsoft.
Given an array of numbers, find the length of the longest increasing subsequence in the array. The subsequence does not
necessarily have to be contiguous.
For example, given the array `[0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]`, the longest increasing subsequence has
length 6: it is `0, 2, 6, 9, 11, 15`.

[Solution](Day75.cpp)
- - - -

#### Problem 76
This problem was asked by Google.

You are given an N by M 2D matrix of lowercase letters. Determine the minimum number of columns that can be removed to ensure
that each row is ordered from top to bottom lexicographically. That is, the letter at each column is lexicographically later
as you go down each row. It does not matter whether each row itself is ordered lexicographically.

For example, given the following table:
```
cba
daf
ghi
```
This is not ordered because of the a in the center. We can remove the second column to make it ordered:
```
ca
df
gi
```
So your function should return 1, since we only needed to remove 1 column.
As another example, given the following table:
```
abcdef
```
Your function should return 0, since the rows are already ordered (there's only one row).

As another example, given the following table:
```
zyx
wvu
tsr
```
Your function should return 3, since we would need to remove all the columns to order it.

[Solution](Day76.cpp)
- - - -

#### Problem 77
This problem was asked by Snapchat.
Given a list of possibly overlapping intervals, return a new list of intervals where all overlapping intervals have been
merged.
The input list is not necessarily ordered in any way.
For example, given `[(1, 3), (5, 8), (4, 10), (20, 25)]`, you should return `[(1, 3), (4, 10), (20, 25)]`.

[Solution](Day77.cpp)
- - - -

#### Problem 78
This problem was asked recently by Google.
Given k sorted singly linked lists, write a function to merge all the lists into one sorted singly linked list.

[Solution](Day78.cpp)
- - - -

#### Problem 79
This problem was asked by Facebook.
Given an array of integers, write a function to determine whether the array could become non-decreasing by modifying at most
1 element.
<br>For example, given the array `[10, 5, 7]`, you should return true, since we can modify the 10 into a 1 to make the array non
decreasing.
Given the array `[10, 5, 1]`, you should return false, since we can't modify any one element to get a non-decreasing array.

[Solution](Day79.cpp)
- - - -

#### Problem 80
This problem was asked by Google.
Given the root of a binary tree, return a deepest node. For example, in the following tree, return d.
```
    a
   / \
  b   c
 /
d
```

[Solution](Day80.cpp)
- - - -

#### Problem 81
This problem was asked by Yelp.
Given a mapping of digits to letters (as in a phone number), and a digit string, return all possible letters the number could
represent. You can assume each valid number in the mapping is a single digit.
For example if `{'2': ['a', 'b', 'c'], '3': ['d', 'e', 'f'], }` then `"23"` should return `['ad', 'ae', 'af', 'bd', 'be',
'bf', 'cd', 'ce', 'cf']`.

[Solution](Day81.cpp)
- - - -

#### Problem 82
This problem was asked Microsoft.
Using a read7() method that returns 7 characters from a file, implement readN(n) which reads n characters.
For example, given a file with the content "Hello world", three read7() returns "Hello w", "orld" and then "".

[Solution](Day82.cpp)
- - - -

#### Problem 83
This problem was asked by Google.
Invert a binary tree.
For example, given the following tree:
```
    a
   / \
  b   c
 / \  /
d   e f
```
should become:
```
  a
 / \
 c  b
 \  / \
  f e  d
```

[Solution](Day83.cpp)
- - - -

#### Problem 84
This problem was asked by Amazon.
Given a matrix of 1s and 0s, return the number of "islands" in the matrix. A 1 represents land and 0 represents water, so an
island is a group of 1s that are neighboring and their perimeter is surrounded by water.
For example, this matrix has 4 islands.
```
1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
```

[Solution](Day84.cpp)
- - - -

#### Problem 85
This problem was asked by Facebook.
Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0, using only mathematical or bit operations. You
can assume b can only be 1 or 0.

[Solution](]Day85.cpp)
- - - -

#### Problem 86
This problem was asked by Google.
Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed to make the string
valid (i.e. each open parenthesis is eventually closed).
For example, given the string "()())()", you should return 1. Given the string ")(", you should return 2, since we must
remove all of them.

[Solution](Day86.cpp)
- - - -

#### Problem 87
This problem was asked by Uber.
A rule looks like this:
`A NE B`
This means this means point A is located northeast of point B.
`A SW C`
means that point A is southwest of C.
Given a list of rules, check if the sum of the rules validate. For example:
```
A N B
B NE C
C N A
```
does not validate, since A cannot be both north and south of C.
```
A NW B
A N B
```
is considered valid.

[Solution](Day87.cpp)
- - - -

#### Problem 88
This question was asked by ContextLogic.
Implement division of two positive integers without using the division, multiplication, or modulus operators.Return the quotient as an integer, ignoring the remainder.

[Solution](Day88.cpp)
- - - -

#### Problem 89
This problem was asked by LinkedIn.
Determine whether a tree is a valid binary search tree.
A binary search tree is a tree with two children, left and right, and satisfies the constraint that the key in the left child
must be less than or equal to the root and the key in the right child must be greater than or equal to the root.

[Solution](Day89.cpp)
- - - -

#### Problem 90
This question was asked by Google.
Given an integer n and a list of integers l, write a function that randomly generates a number from 0 to n-1 that isn't in
(uniform).

[Solution](Day90.py)
- - - -

#### Problem 91
This problem was asked by Dropbox.
What does the below code snippet print out? How can we fix the anonymous functions to behave as we'd expect?
```python
functions = []
for i in range(10):
    functions.append(lambda : i)

for f in functions:
    print(f())
```

[Solution](Day91.py)
- - - -

#### Problem 92
This problem was asked by Airbnb.
We're given a hashmap with a key courseId and value a list of courseIds, which represents that the prerequsite of courseId is
courseIds. Return a sorted ordering of courses such that we can finish all courses.
Return null if there is no such ordering.
For example, given `{'CSC300': ['CSC100', 'CSC200'], 'CSC200': ['CSC100'], 'CSC100': []}`, should return `['CSC100',
'CSC200', 'CSCS300']`.

[Solution](Day92.cpp)
- - - -

#### Problem 93
This problem was asked by Apple.
Given a tree, find the largest tree/subtree that is a BST.
Given a tree, return the size of the largest tree/subtree that is a BST.

[Solution](Day93.cpp)
- - - -

#### Problem 94
This problem was asked by Google.
Given a binary tree of integers, find the maximum path sum between two nodes. The path must go through at least one node, and
does not need to go through the root.

[Solution](Day94.cpp)
- - - -

#### Problem 95
This problem was asked by Palantir.
Given a number represented by a list of digits, find the next greater permutation of a number, in terms of lexicographic
ordering. If there is not greater permutation possible, return the permutation with the lowest value/ordering.
For example, the list `[1,2,3]` should return `[1,3,2]`. The list `[1,3,2]` should return `[2,1,3]`. The list `[3,2,1]`
should return `[1,2,3]`.
Can you perform the operation without allocating extra memory (disregarding the input memory)?

[Solution](Day95.cpp)
- - - -

#### Problem 96
This problem was asked by Microsoft.
Given a number in the form of a list of digits, return all possible permutations.
For example, given `[1,2,3]`, return `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]`.

[Solution](Day96.cpp)
- - - -

#### Problem 97
This problem was asked by Stripe.
Write a map implementation with a get function that lets you retrieve the value of a key at a particular time.
It should contain the following methods:
```
    set(key, value, time): # sets key to value for t = time.
    get(key, time): # gets the key at t = time.
```

The map should work like this. If we set a key at a particular time, it will maintain that value forever or until it gets set
at a later time. In other words, when we get a key at a time, it should return the value that was set for that key set at the
most recent time.
Consider the following examples:
```
d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 2) # set key 1 to value 2 at time 2
d.get(1, 1) # get key 1 at time 1 should be 1
d.get(1, 3) # get key 1 at time 3 should be 2

d.set(1, 1, 5) # set key 1 to value 1 at time 5
d.get(1, 0) # get key 1 at time 0 should be null
d.get(1, 10) # get key 1 at time 10 should be 1

d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 0) # set key 1 to value 2 at time 0
d.get(1, 0) # get key 1 at time 0 should be 2
```

[Solution](Day97.cpp)
- - - -

#### Problem 98
This problem was asked by Coursera.
Given a 2D board of characters and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or
vertically neighboring. The same letter cell may not be used more than once.
For example, given the following board:
```
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
```
`exists(board, "ABCCED")` returns true, `exists(board, "SEE")` returns true, `exists(board, "ABCB")` returns false.

[Solution](Day98.cpp)
- - - -

#### Problem 99
This problem was asked by Microsoft.
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.

[Solution](Day99.cpp)
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
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in
which you can achieve it. You start from the first point.
Example:
Input: [(0, 0), (1, 1), (1, 2)]
Output: 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).

[Solution](Day100.cpp)
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

[Solution](Day101.cpp)
- - - -

### Day 102 ###
This problem was asked by Lyft.
Given a list of integers and a number K, return which contiguous elements of the list sum to K.
For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should return [2, 3, 4], since 2 + 3 + 4 = 9.

[Solution](Day102.cpp)
- - - -

### Day 103 ###
This problem was asked by Square.
Given a string and a set of characters, return the shortest substring containing all the characters in the set.
<br>For example, given the string "figehaeci" and the set of characters {a, e, i}, you should return "aeci".
If there is no substring containing all the characters in the set, return null.

[Solution](Day103.cpp)
- - - -

### Day 104 ###
This problem was asked by Google.
Determine whether a doubly linked list is a palindrome. What if it’s singly linked?
For example, 1 -> 4 -> 3 -> 4 -> 1 returns True while 1 -> 4 returns False.

[Solution](Day104.cpp)
- - - -

### Day 106 ###
This problem was asked by Pinterest.
Given an integer list where each number represents the number of hops you can make, determine whether you can reach to the
last index starting at index 0.
<br>For example, [2, 0, 1, 0] returns True while [1, 1, 0, 1] returns False.

[Solution](Day106.cpp)
- - - -

### Day 107 ###
This problem was asked by Microsoft.
Print the nodes in a binary tree level-wise. For example, the following should print 1, 2, 3, 4, 5.
```
  1
 / \
2   3
   / \
  4   5
```

[Solution](Day107.cpp)
- - - -

#### Problem 108
This problem was asked by Google.
Given two strings A and B, return whether or not A can be shifted some number of times to get B.
<br>For example, if A is `abcde` and B is `cdeab`, return true. If A is `abc` and B is `acb`, return false.

[Solution](Day108.cpp)
- - - -

#### Problem 109
This problem was asked by Cisco.
Given an unsigned 8-bit integer, swap its even and odd bits. The 1st and 2nd bit should be swapped, the 3rd and 4th bit should be swapped, and so on.
<br>For example, `10101010` should be `01010101`. `11100010` should be `11010001`.
Bonus: Can you do this in one line?

[Solution](Day109.cpp)
- - - -

#### Problem 110
This problem was asked by Facebook.
Given a binary tree, return all paths from the root to leaves.
<br>For example, given the tree
```
   1
  / \
 2   3
    / \
   4   5
```
it should return `[[1, 2], [1, 3, 4], [1, 3, 5]]`.

[Solution](Day110.cpp)
- - - -

#### Problem 111
This problem was asked by Google.
Given a word W and a string S, find all starting indices in S which are anagrams of W.
<br>For example, given that W is "ab", and S is "abxaba", return 0, 3, and 4.

[Solution](Day111.cpp)
- - - -

#### Problem 112
This problem was asked by Twitter.
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. Assume that each node in the tree also has a pointer to its parent.
According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself)."

[Solution](Day112.cpp)
- - - -

#### Problem 113
This problem was asked by Google.Given a string of words delimited by spaces, reverse the words in string. 
<br>For example, given "hello world here", return "here world hello"
Follow-up: given a mutable string representation, can you perform this operation in-place?

[Solution](Day113.cpp)
- - - -

#### Problem 114
This problem was asked by Facebook.Given a string and a set of delimiters, reverse the words in the string while maintaining the relative order of the delimiters. 
<br>For example, given "hello/world:here", return "here/world:hello"
Follow-up: Does your solution work for the following cases: "hello/world:here/", "hello//world:here"

[Solution](Day114.cpp)
- - - -

#### Problem 115
This problem was asked by Google.
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

[Solution](Day115.cpp)
- - - -

#### Problem 116
This problem was asked by Jane Street.
Generate a finite, but an arbitrarily large binary tree quickly in `O(1)`.
That is, `generate()` should return a tree whose size is unbounded but finite.

[Solution](Day116.cpp)
- - - -

#### Problem 117
This problem was asked by Facebook.
Given a binary tree, return the level of the tree with minimum sum.

[Solution](Day117.cpp)
- - - -

#### Problem 118
This problem was asked by Google.
Given a sorted list of integers, square the elements and give the output in sorted order.
<br>For example, given `[-9, -2, 0, 2, 3]`, return `[0, 4, 4, 9, 81]`.

[Solution](Day118.cpp)
- - - -

#### Problem 119
This problem was asked by Google.
Given a set of closed intervals, find the smallest set of numbers that covers all the intervals. If there are multiple smallest sets, return any of them.
<br>For example, given the intervals `[0, 3], [2, 6], [3, 4], [6, 9]`, one set of numbers that covers all these intervals is `{3, 6}`.

[Solution](Day119.cpp)
- - - -

#### Problem 120
This problem was asked by Microsoft.
Implement the singleton pattern with a twist. First, instead of storing one instance, store two instances. And in every even call of getInstance(), return the first instance and in every odd call of getInstance(), return the second instance.

[Solution](Day120.cpp)
- - - -

#### Problem 121
This problem was asked by Google.
Given a string which we can delete at most k, return whether you can make a palindrome.
<br>For example, given 'waterrfetawx' and a k of 2, you could delete f and x to get 'waterretaw'.

[Solution](Day121.cpp)
- - - -

#### Problem 122
This question was asked by Zillow.
You are given a 2-d matrix where each cell represents number of coins in that cell. Assuming we start at `matrix[0][0]`, and can only move right or down, find the maximum number of coins you can collect by the bottom right corner.
<br>For example, in this matrix
```
0 3 1 1
2 0 0 4
1 5 3 1
```
The most we can collect is `0 + 2 + 1 + 5 + 3 + 1 = 12` coins.

[Solution](Day122.cpp)
- - - -

#### Problem 123
This problem was asked by LinkedIn.
Given a string, return whether it represents a number. Here are the different kinds of numbers:
* "10", a positive integer
* "-10", a negative integer
* "10.1", a positive real number
* "-10.1", a negative real number
* "1e5", a number in scientific notation

And here are examples of non-numbers:
* "a"
* "x 1"
* "a -2"
* "-"

[Solution](Day123.cpp)
- - - -

#### Problem 124
This problem was asked by Microsoft.
<br>You have 100 fair coins and you flip them all at the same time. Any that come up tails you set aside. The ones that come up heads you flip again. How many rounds do you expect to play before only one coin remains?
<br>Write a function that, given $n$, returns the number of rounds you'd expect to play until one coin remains.

[Solution](Day124.cpp)
- - - -

#### Problem 125
This problem was asked by Google.
<br>Given the root of a binary search tree, and a target K, return two nodes in the tree whose sum equals K.
<br>For example, given the following tree and K of 20
```
    10
   /   \
 5      15
       /  \
     11    15
```

Return the nodes 5 and 15.

[Solution](Day125.cpp)
- - - -

#### Problem 126
This problem was asked by Facebook.
<br>Write a function that rotates a list by k elements. 
<br>For example, `[1, 2, 3, 4, 5, 6]` rotated by two becomes `[3, 4, 5, 6, 1, 2]`. Try solving this without creating a copy of the list. How many swap or move operations do you need?

[Solution](Day126.cpp)
- - - -

#### Problem 127
This problem was asked by Microsoft.
<br>Let's represent an integer in a linked list format by having each node represent a digit in the number. The nodes make up the number in reversed order.
<br>For example, the following linked list:
`1 -> 2 -> 3 -> 4 -> 5`
is the number `54321`.
Given two linked lists in this format, return their sum in the same linked list format.
For example, given
`9 -> 9`
`5 -> 2`
return `124 (99 + 25)` as:
`4 -> 2 -> 1`

[Solution](Day127.cpp)
- - - -

#### Problem 128
The Tower of Hanoi is a puzzle game with three rods and n disks, each a different size.
All the disks start off on the first rod in a stack. They are ordered by size, with the largest disk on the bottom and the smallest one at the top.
<br>The goal of this puzzle is to move all the disks from the first rod to the last rod while following these rules:
* You can only move one disk at a time.
* A move consists of taking the uppermost disk from one of the stacks and placing it on top of another stack.
* You cannot place a larger disk on top of a smaller disk.
<br>Write a function that prints out all the steps necessary to complete the Tower of Hanoi. You should assume that the rods are numbered, with the first rod being 1, the second (auxiliary) rod being 2, and the last (goal) rod being 3.
<br>For example, with n = 3, we can do this in 7 moves:
* Move 1 to 3
* Move 1 to 2
* Move 3 to 2
* Move 1 to 3
* Move 2 to 1
* Move 2 to 3
* Move 1 to 3

[Solution](Day128.cpp)
- - - -

#### Problem 129
Given a real number n, find the square root of n. 
<br>For example, given n = 9, return 3.

[Solution](Day129.cpp)
- - - -

#### Problem 130
This problem was asked by Facebook.
<br>Given an array of numbers representing the stock prices of a company in chronological order and an integer k, return the maximum profit you can make from k buys and sells. You must buy the stock before you can sell it, and you must sell the stock before you can buy it again.
<br>For example, given `k = 2` and the array `[5, 2, 4, 0, 1]`, you should return `3`.

[Solution](Day130.cpp)
- - - -

#### Problem 131
This question was asked by Snapchat.
<br>Given the head to a singly linked list, where each node also has a 'random' pointer that points to anywhere in the linked list, deep clone the list.

[Solution](Day131.cpp)
- - - -

#### Problem 132
This question was asked by Riot Games.
<br>Design and implement a HitCounter class that keeps track of requests (or hits). It should support the following operations:
* `record(timestamp)`: records a hit that happened at timestamp
* `total()`: returns the total number of hits recorded
* `range(lower, upper)`: returns the number of hits that occurred between timestamps lower and upper (inclusive)
Follow-up: What if our system has limited memory?

[Solution](Day132.cpp)
- - - -

#### Problem 133
This problem was asked by Amazon.
<br>Given a node in a binary tree, return the next bigger element, also known as the inorder successor.
(NOTE: I'm assuming this is a binary search tree, because otherwise, the problem makes no sense at all)
For example, the inorder successor of 22 is 30.
```
   10
  /  \
 5    30
     /  \
   22    35
```
You can assume each node has a parent pointer.

[Solution](Day133.cpp)
- - - -

#### Problem 134
This problem was asked by Facebook.
<br>You have a large array with most of the elements as zero. Use a more space-efficient data structure, SparseArray, that implements the same interface:
* `init(arr, size)`: initialize with the original large array and size.
* `set(i, val)`: updates index at i with val.
* `get(i)`: gets the value at index i.

[Solution](Day134.cpp)
- - - -

#### Problem 135
This question was asked by Apple.
<br>Given a binary tree, find a minimum path sum from root to a leaf.
<br>For example, the minimum path in this tree is `[10, 5, 1, -1]`, which has sum 15.
```
  10
 /  \
5    5
 \     \
   2    1
       /
     -1
```

[Solution](Day135.cppy)
- - - -

#### Problem 136
This question was asked by Google.
<br>Given an N by M matrix consisting only of 1's and 0's, find the largest rectangle containing only 1's and return its area.
<br>For example, given the following matrix:
```
[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]
```
Return 4.

[Solution](Day136.cpp)
- - - -

#### Problem 137
This problem was asked by Amazon.
<br>Implement a bit array. A bit array is a space efficient array that holds a value of 1 or 0 at each index.
* init(size): initialize the array with size
* set(i, val): updates index at i with val where val is either 1 or 0.
* get(i): gets the value at index i.

[Solution](Day137.cpp)
- - - -

#### Problem 138
This problem was asked by Google.
<br>Find the minimum number of coins required to make n cents. You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.
<br>For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.

[Solution](Day138.cpp)
- - - -

#### Problem 139
This problem was asked by Google.
<br>Given an iterator with methods next() and hasNext(), create a wrapper iterator, PeekableInterface, which also implements peek(). peek shows the next element that would be returned on next(). Here is the interface:
```
class PeekableInterface(object):
    def __init__(self, iterator):
        pass

    def peek(self):
        pass

    def next(self):
        pass

    def hasNext(self):
        pass
```

[Solution](Day139.cpp)
- - - -

#### Problem 140
This problem was asked by Facebook.
<br>Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, find the two elements that appear only once.
<br>For example, given the array `[2, 4, 6, 8, 10, 2, 6, 10]`, return 4 and 8. The order does not matter.
<br>Follow-up: Can you do this in linear time and constant space?

[Solution](Day140.cpp)
- - - - 

#### Problem 141
This problem was asked by Microsoft.
<br>Implement 3 stacks using a single list:
```
class Stack:
    def __init__(self):
        self.list = []

    def pop(self, stack_number):
        pass

    def push(self, item, stack_number):
        pass
```

[Solution](Day141.cpp)
- - - -

#### Problem 142
This problem was asked by Google.
<br>You're given a string consisting solely of `(`, `)`, and `*`. 
`*` can represent either a `(`, `)`, or an empty string. Determine whether the parentheses are balanced.
<br>For example, `(()*` and `(*)` are balanced. `)*(` is not balanced.

[Solution](Day142.cpp)
- - - -

#### Problem 143
This problem was asked by Amazon.
<br>Given a pivot `x`, and a list `lst`, partition the list into three parts.
* The first part contains all elements in `lst` that are less than `x`
* The second part contains all elements in `lst` that are equal to `x`
* The third part contains all elements in `lst` that are larger than `x`
Ordering within a part can be arbitrary.
<br>For example, given `x = 10` and `lst = [9, 12, 3, 5, 14, 10, 10]`, one partition may be `[9, 3, 5, 10, 10, 12, 14]`

[Solution](Day143.cpp)
- - - -

#### Problem 144
This problem was asked by Google.
<br>Given an array of numbers and an index `i`, return the index of the nearest larger number of the number at index `i`, where distance is measured in array indices.
<br>For example, given `[4, 1, 3, 5, 6]` and index `0`, you should return `3`.
If two distances to larger numbers are equal, then return any one of them. If the array at `i` doesn't have a nearest larger integer, then return `null`.
<br>Follow-up: If you can preprocess the array, can you do this in constant time?

[Solution](Day144.cpp)
- - - -

#### Problem 145
This problem was asked by Google.
<br>Given the head of a singly linked list, swap every two nodes and return its head.
<br>For example, given `1 -> 2 -> 3 -> 4`, return `2 -> 1 -> 4 -> 3`.

[Solution](Day145.cpp)
- - - -

#### Problem 146
This question was asked by BufferBox.
<br>Given a binary tree where all nodes are either 0 or 1, prune the tree so that subtrees containing all 0s are removed.
<br>For example, given the following tree:
```
   0
  / \
 1   0
    / \
   1   0
  / \
 0   0
```
should be pruned to:
```
   0
  / \
 1   0
    /
   1
```
We do not remove the tree at the root or its left child because it still has a 1 as a descendant.

[Solution](Day146.cpp)
- - - -

#### Problem 147
Given a list, sort it using this method: `reverse(lst, i, j)`, which sorts `lst` from `i` to `j`.

[Solution](Day147.cpp)
- - - -

#### Problem 148
This problem was asked by Apple.
<br>Gray code is a binary code where each successive value differ in only one bit, as well as when wrapping around. Gray code is common in hardware so that we don't see temporary spurious values during transitions. Given a number of bits `n`, generate a possible gray code for it.
<br>For example, for `n = 2`, one gray code would be `[00, 01, 11, 10]`.

[Solution](Day148.cpp)
- - - -

#### Problem 149
This problem was asked by Goldman Sachs.
<br>Given a list of numbers `L`, implement a method `sum(i, j)` which returns the sum from the sublist `L[i:j]` (including i, excluding j).
<br>For example, given `L = [1, 2, 3, 4, 5]`, `sum(1, 3)` should return `sum([2, 3])`, which is `5`. You can assume that you can do some pre-processing. `sum()` should be optimized over the pre-processing step.

[Solution](Day149.cpp)
- - - -

#### Problem 150
This problem was asked by LinkedIn.
<br>Given a list of points, a central point, and an integer k, find the nearest k points from the central point.
<br>For example, given the list of points `[(0, 0), (5, 4), (3, 1)]`, the central point `(1, 2)`, and `k = 2`, return `[(0, 0), (3, 1)]`.

[Solution](Day150.cpp)
- - - -

#### Problem 151
<br>Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C, replace the color of the given pixel and all adjacent same colored pixels with C.
<br>For example, given the following matrix, and location pixel of `(2, 2)`, and `'G'` for green:
```
B B W
W W W
W W W
B B B
```
Becomes
```
B B G
G G G
G G G
B B B
```

[Solution](Day151.cpp)
- - - -

#### Problem 152
This problem was asked by Triplebyte.
<br>You are given `n` numbers as well as `n` probabilities that sum up to `1`. Write a function to generate one of the numbers with its corresponding probability.
<br>For example, given the numbers `[1, 2, 3, 4]` and probabilities `[0.1, 0.5, 0.2, 0.2]`, your function should return `1` `10%` of the time, `2` `50%` of the time, and `3` and `4` `20%` of the time.
You can generate random numbers between 0 and 1 uniformly.

[Solution](Day152.cppy)
- - - -

#### Problem 153
Find an efficient algorithm to find the smallest distance (measured in number of words) between any two given words in a string.
<br>For example, given words "hello", and "world" and a text content of "dog cat hello cat dog dog hello cat world", return 1 because there's only one word "cat" in between the two words.

[Solution](Day153.cpp)
- - - -

#### Problem 154
This problem was asked by Amazon.
<br>Implement a stack API using only a heap. A stack implements the following methods:
* `push(item)`, which adds an element to the stack
* `pop()`, which removes and returns the most recently added element (or throws an error if there is nothing on the stack)
Recall that a heap has the following operations:
* `push(item)`, which adds a new key to the heap
* `pop()`, which removes and returns the max value of the heap

[Solution](Day154.cpp)
- - - -

#### Problem 155
Given a list of elements, find the majority element, which appears more than half the times `(> floor(len(lst) / 2.0))`.
<br>You can assume that such an element exists.
<br>For example, given `[1, 2, 1, 1, 3, 4, 0]`, return `1`.

[Solution](Day156.cpp)
- - - -

#### Problem 156
This problem was asked by Facebook.
<br>Given a positive integer `n`, find the smallest number of squared integers which sum to `n`.
<br>For example, given n = `13`, return `2` since `13 = 3^2 + 2^2 = 9 + 4`. Given `n = 27`, return `3` since `27 = 3^2 + 3^2 + 3^2 = 9 + 9 + 9`.

[Solution](Day156.cpp)
- - - -

#### Problem 157
This problem was asked by Amazon.
<br>Given a string, determine whether any permutation of it is a palindrome.
<br>For example, `carrace` should return `true`, since it can be rearranged to form `racecar`, which is a palindrome. `daily` should return `false`, since there's no rearrangement that can form a palindrome.

[Solution](Day157.cpp)
- - - -

#### Problem 158
This problem was asked by Slack.
<br>You are given an `N * M` matrix of `0`s and `1`s. Starting from the top left corner, how many ways are there to reach the bottom right corner? You can only move right and down. `0` represents an empty space while `1` represents a wall you cannot walk through.
<br>For example, given the following matrix:
```
[[0, 0, 1],
 [0, 0, 1],
 [1, 0, 0]]
```
Return `2`, as there are only two ways to get to the bottom right:
* `Right, down, down, right`
* `Down, right, down, right`

The top left corner and bottom right corner will always be `0`.

[Solution](Day158.cpp)
- - - -

#### Problem 159
This problem was asked by Google.
<br>Given a string, return the first recurring character in it, or `null` if there is no recurring chracter.
<br>For example, given the string `"acbbac"`, return `"b"`. Given the string `"abcdef"`, return `null`.

[Solution](Day159.cpp)
- - - -

#### Problem 160
This problem was asked by Uber.
<br>Given a tree where each edge has a weight, compute the length of the longest path in the tree.
<br>For example, given the following tree:
```
   a
  /|\
 b c d
    / \
   e   f
  / \
 g   h
```
and the weights: `a-b: 3`, `a-c: 5`, `a-d: 8`, `d-e: 2`, `d-f: 4`, `e-g: 1`, `e-h: 1`, the longest path would be `c -> a -> d -> f`, with a length of `17`.
The path does not have to pass through the root, and each node can have any amount of children.

[Solution](Day160.cpp)
- - - -

#### Problem 161
This problem was asked by Facebook.
<br>Given a 32-bit integer, return the number with its bits reversed.
<br>For example, given the binary number `1111 0000 1111 0000 1111 0000 1111 0000`, return `0000 1111 0000 1111 0000 1111 0000 1111`.

[Solution](Day161.cpp)
- - - -

#### Problem 162
This problem was asked by Square.
<br>Given a list of words, return the shortest unique prefix of each word. For example, given the list:
* dog
* cat
* apple
* apricot
* fish
Return the list:
* d
* c
* app
* apr
* f

[Solution](Day162.cpp)
- - - -

#### Problem 163
This problem was asked by Jane Street.
<br>Given an arithmetic expression in Reverse Polish Notation, write a program to evaluate it. The expression is given as a list of numbers and operands. For example: `[5, 3, '+']` should return `5 + 3 = 8`.
<br>For example, `[15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-']` should return `5`, since it is equivalent to `((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5`.
<br> You can assume the given expression is always valid.

[Solution](Day163.cpp)
- - - -

#### Problem 164
This problem was asked by Google.
<br>You are given an array of length n + 1 whose elements belong to the set `{1, 2, ..., n}`. By the pigeonhole principle, there must be a duplicate. Find it in linear time and space.

[Solution](Day164.cpp)
- - - -

#### Problem 165
This problem was asked by Google.
<br>Given an array of integers, return a new array where each element in the new array is the number of smaller elements to the right of that element in the original input array.
<br>For example, given the array `[3, 4, 9, 6, 1]`, return `[1, 1, 2, 1, 0]`, since:
* There is 1 smaller element to the right of `3`
* There is 1 smaller element to the right of `4`
* There are 2 smaller elements to the right of `9`
* There is 1 smaller element to the right of `6`
* There are no smaller elements to the right of `1`

[Solution](Day165.cpp)
- - - -

#### Problem 166
This problem was asked by Uber.
<br> Implement a 2D iterator class. It will be initialized with an array of arrays, and should implement the following methods:
* `next()`: returns the next element in the array of arrays. If there are no more elements, raise an exception.
* `has_next()`: returns whether or not the iterator still has elements left.
<br>For example, given the input `[[1, 2], [3], [], [4, 5, 6]]`, calling `next()` repeatedly should output `1, 2, 3, 4, 5, 6`. Do not use flatten or otherwise clone the arrays. Some of the arrays can be empty.

[Solution](Day166.cpp)
- - - -

#### Problem 167
This problem was asked by Airbnb.
<br> Given a list of words, find all pairs of unique indices such that the concatenation of the two words is a palindrome.
<br> For example, given the list `["code", "edoc", "da", "d"]`, return `[(0, 1), (1, 0), (2, 3)]`.

[Solution](Day167.cppy)
- - - -

#### Problem 168
This problem was asked by Facebook.
<br>Given an N by N matrix, rotate it by 90 degrees clockwise.
<br>For example, given the following matrix:
```
[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]
```
you should return:
```
[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]
```
Follow-up: What if you couldn't use any extra space?

[Solution](Day168.cpp)
- - - -

#### Problem 169
This problem was asked by Google.
<br>Given a linked list, sort it in `O(n log n)` time and constant space.
<br>For example, the linked list `4 -> 1 -> -3 -> 99` should become `-3 -> 1 -> 4 -> 99`.

[Solution](Day169.cpp)
- - - -

#### Problem 170
This problem was asked by Facebook.
<br>Given a start word, an end word, and a dictionary of valid words, find the shortest transformation sequence from start to end such that only one letter is changed at each step of the sequence, and each transformed word exists in the dictionary. If there is no possible transformation, return null. Each word in the dictionary have the same length as start and end and is lowercase.
<br>For example, given `start = "dog"`, `end = "cat"`, and `dictionary = {"dot", "dop", "dat", "cat"}`, return `["dog", "dot", "dat", "cat"]`. Given `start = "dog"`, `end = "cat"`, and `dictionary = {"dot", "tod", "dat", "dar"}`, return null as there is no possible transformation from dog to cat.

[Solution](Day170.cpp)
- - - -

#### Problem 171
This problem was asked by Amazon.
<br>You are given a list of data entries that represent entries and exits of groups of people into a building. An entry looks like this:
<br> `{"timestamp": 1526579928, "count": 3, "type": "enter"}`
<br>This means 3 people entered the building. An exit looks like this:
<br> `{"timestamp": 1526580382, "count": 2, "type": "exit"}`
<br>This means that 2 people exited the building. timestamp is in Unix time.
<br>Find the busiest period in the building, that is, the time with the most people in the building. Return it as a pair of `(start, end)` timestamps. You can assume the building always starts off and ends up empty, i.e. with 0 people inside.

[Solution](Day171.cpp)
- - - -

#### Problem 172
This problem was asked by Dropbox.
<br>Given a string `s` and a list of words `words`, where each word is the same length, find all starting indices of substrings in `s` that is a concatenation of every word in `words` exactly once.
<br>For example, given `s = "dogcatcatcodecatdog"` and `words = ["cat", "dog"]`, return `[0, 13]`, since `"dogcat"` starts at index `0` and `"catdog"` starts at index `13`.
<br>Given `s = "barfoobazbitbyte"` and `words = ["dog", "cat"]`, return `[]` since there are no substrings composed of `"dog"` and `"cat"` in `s`.The order of the indices does not matter.

[Solution](Day172.cpp)
- - - -

#### Problem 173
This problem was asked by Stripe.
<br>Write a function to flatten a nested dictionary. Namespace the keys with a period.
<br>For example, given the following dictionary:
```
{
    "key": 3,
    "foo": {
        "a": 5,
        "bar": {
            "baz": 8
        }
    }
}
```
it should become:
```
{
    "key": 3,
    "foo.a": 5,
    "foo.bar.baz": 8
}
```
You can assume keys do not contain dots in them, i.e. no clobbering will occur.

[Solution](Day173.cpp)
- - - -

#### Problem 174
This problem was asked by Microsoft.
<br>Describe and give an example of each of the following types of polymorphism:
* Ad-hoc polymorphism
* Parametric polymorphism
* Subtype polymorphism

[Solution](Day174.cpp)
- - - -

#### Problem 175
This problem was asked by Google.
<br>You are given a starting state start, a list of transition probabilities for a Markov chain, and a number of steps num_steps. Run the Markov chain starting from start for num_steps and compute the number of times we visited each state.
<br>For example, given the starting state `a`, number of steps `5000`, and the following transition probabilities:
```
[
  ('a', 'a', 0.9),
  ('a', 'b', 0.075),
  ('a', 'c', 0.025),
  ('b', 'a', 0.15),
  ('b', 'b', 0.8),
  ('b', 'c', 0.05),
  ('c', 'a', 0.25),
  ('c', 'b', 0.25),
  ('c', 'c', 0.5)
]
```
One instance of running this Markov chain might produce `{'a': 3012, 'b': 1656, 'c': 332 }`.

[Solution](Day175.cpp)
- - - -

#### Problem 176
This problem was asked by Bloomberg.
<br>Determine whether there exists a one-to-one character mapping from one string `s1` to another `s2`.
<br>For example, given `s1 = abc` and `s2 = bcd`, return `true` since we can map `a` to `b`, `b` to `c`, and `c` to `d`.
Given `s1 = foo` and `s2 = bar`, return `false` since the `o` cannot map to two characters.

[Solution](Day176.cpp)
- - - -

#### Problem 177
This problem was asked by Airbnb.
<br>Given a linked list and a positive integer `k`, rotate the list to the right by `k` places.
<br>For example, given the linked list `7 -> 7 -> 3 -> 5` and `k = 2`, it should become `3 -> 5 -> 7 -> 7`.
Given the linked list `1 -> 2 -> 3 -> 4 -> 5` and `k = 3`, it should become `3 -> 4 -> 5 -> 1 -> 2`.

[Solution](Day177.cpp)
- - - -

#### Problem 178
This problem was asked by Two Sigma.
<br>Alice wants to join her school's Probability Student Club. Membership dues are computed via one of two simple probabilistic games.
<br>The first game: roll a die repeatedly. Stop rolling once you get a five followed by a six. Your number of rolls is the amount you pay, in dollars.
The second game: same, except that the stopping condition is a five followed by a five.
Which of the two games should Alice elect to play? Does it even matter? Write a program to simulate the two games and calculate their expected value.

[Solution](Day178.cpp)
- - - -

#### Problem 179
This problem was asked by Google.
<br> Given the sequence of keys visited by a postorder traversal of a binary search tree, reconstruct the tree.
<br> For example, given the sequence `2, 4, 3, 8, 7, 5`, you should construct the following tree:
```
    5
   / \
  3   7
 / \   \
2   4   8
```

[Solution](Day179.cpp)
- - - -

#### Problem 180
This problem was asked by Google.
<br>Given a stack of `N` elements, interleave the first half of the stack with the second half reversed using only one other queue. This should be done in-place. Recall that you can only push or pop from a stack, and enqueue or dequeue from a queue.
<br>For example, if the stack is `[1, 2, 3, 4, 5]`, it should become `[1, 5, 2, 4, 3]`. If the stack is `[1, 2, 3, 4]`, it should become `[1, 4, 2, 3]`.
<br>Hint: Try working backwards from the end state.

[Solution](Day180.cpp)
- - - -

#### Problem 181
This problem was asked by Google.
<br>Given a string, split it into as few strings as possible such that each string is a palindrome.
<br>For example, given the input string `"racecarannakayak"`, return `["racecar", "anna", "kayak"]`. Given the input string `"abc"`, return `["a", "b", "c"]`.

[Solution](Day181.cpp)
- - - -

#### Problem 182
This problem was asked by Facebook.
<br>A graph is minimally-connected if it is connected and there is no edge that can be removed while still leaving the graph connected. For example, any binary tree is minimally-connected.
<br>Given an undirected graph, check if the graph is minimally-connected. You can choose to represent the graph as either an adjacency matrix or adjacency list.

[Solution](Day182.cpp)
- - - -

#### Problem 183
This problem was asked by Twitch.
<br>Describe what happens when you type a URL into your browser and press Enter.

[Solution](Day183.cpp)
- - - -

#### Problem 184
This problem was asked by Amazon.
<br>Given n numbers, find the greatest common denominator between them.
<br>For example, given the numbers `[42, 56, 14]`, return `14`.

[Solution](Day184.cpp)
- - - -

#### Problem 185
This problem was asked by Google.
<br>Given two rectangles on a 2D graph, return the area of their intersection. If the rectangles don't intersect, return `0`.
<br>For example, given the following rectangles:
```
{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
}
```
and
```
{
    "top_left": (0, 5),
    "dimensions" (4, 3) # width, height
}
```
return `6`.

[Solution](Day185.cpp)
- - - -

#### Problem 186
This problem was asked by Microsoft.
<br>Given an array of positive integers, divide the array into two subsets such that the difference between the sum of the subsets is as small as possible.
<br>For example, given `[5, 10, 15, 20, 25]`, return the sets `{10, 25}` and `{5, 15, 20}`, which has a difference of `5`, which is the smallest possible difference.

[Solution](Day186.cpp)
- - - -

#### Problem 187
This problem was asked by Google.
<br>You are given given a list of rectangles represented by min and max x- and y-coordinates. Compute whether or not a pair of rectangles overlap each other. If one rectangle completely covers another, it is considered overlapping.
<br>For example, given the following rectangles:
```
{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
},
{
    "top_left": (-1, 3),
    "dimensions": (2, 1)
},
{
    "top_left": (0, 5),
    "dimensions": (4, 3)
}
```
return `true` as the first and third rectangle overlap each other.

[Solution](/Day187.cpp)
- - - -

#### Problem 188
This problem was asked by Google.
<br>What will this code print out?

```
def make_functions():
    flist = []

    for i in [1, 2, 3]:
        def print_i():
            print(i)
        flist.append(print_i)

    return flist

functions = make_functions()
for f in functions:
    f()
```
How can we make it print out what we apparently want?

[Solution](Day188.py)
- - - -

#### Problem 189
This problem was asked by Google.
<br>Given an array of elements, return the length of the longest subarray where all its elements are distinct.
<br>For example, given the array `[5, 1, 3, 5, 2, 3, 4, 1]`, return `5` as the longest subarray of distinct elements is `[5, 2, 3, 4, 1]`.

[Solution](Day189.cpp)
- - - -

#### Problem 190
This problem was asked by Facebook.
<br>Given a circular array, compute its maximum subarray sum in `O(n)` time.
For example, given `[8, -1, 3, 4]`, return `15` as we choose the numbers `3`, `4`, and `8` where the `8` is obtained from wrapping around.
<br>Given `[-4, 5, 1, 0]`, return `6` as we choose the numbers `5` and `1`.

[Solution](Day190.cpp)
- - - -

#### Problem 191
This problem was asked by Stripe.
<br>Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping. Intervals can "touch", such as `[0, 1]` and `[1, 2]`, but they won't be considered overlapping.
<br>For example, given the intervals `(7, 9), (2, 4), (5, 8)`, return `1` as the last interval can be removed and the first two won't overlap.
<br>The intervals are not necessarily sorted in any order.

[Solution](Day191.cpp)
- - - -

#### Problem 192
This problem was asked by Google.
<br>You are given an array of nonnegative integers. Let's say you start at the beginning of the array and are trying to advance to the end. You can advance at most, the number of steps that you're currently on. Determine whether you can get to the end of the array.
<br>For example, given the array `[1, 3, 1, 2, 0, 1]`, we can go from indices `0 -> 1 -> 3 -> 5`, so return `true`.
<br>Given the array `[1, 2, 1, 0, 0]`, we can't reach the end, so return `false`.

[Solution](Day192.cpp)
- - - -

#### Problem 193
This problem was asked by Affirm.
<br>Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates the maximum profit you could have made from buying and selling that stock. You're also given a number fee that represents a transaction fee for each buy and sell transaction.
<br>You must buy before you can sell the stock, but you can make as many transactions as you like.
<br>For example, given `[1, 3, 2, 8, 4, 10]` and `fee = 2`, you should return `9`, since you could buy the stock at `$1`, and sell at `$8`, and then buy it at `$4` and sell it at `$10`. Since we did two transactions, there is a `$4` fee, so we have `7 + 6 = 13` profit minus `$4` of fees.

[Solution](Day193.cpp)
- - - -

#### Problem 194
This problem was asked by Facebook.
Suppose you are given two lists of n points, one list `p1, p2, ..., pn` on the line `y = 0` and the other list `q1, q2, ..., qn` on the line `y = 1`. Imagine a set of `n` line segments connecting each point `pi` to `qi`. Write an algorithm to determine how many pairs of the line segments intersect.

[Solution](Day194.cpp)
- - - -

#### Problem 195
This problem was asked by Google.
<br>Let `M` be an `N` by `N` matrix in which every row and every column is sorted. No two elements of `M` are equal.
<br>Given `i1`, `j1`, `i2`, and `j2`, compute the number of elements of `M` smaller than `M[i1, j1]` and larger than `M[i2, j2]`.

[Solution](Day195.cpp)
- - - -

#### Problem 196
This problem was asked by Apple.
<br>Given the root of a binary tree, find the most frequent subtree sum. The subtree sum of a node is the sum of all values under a node, including the node itself.
<br>For example, given the following tree:
```
  5
 / \
2  -5
```
Return `2` as it occurs twice: once as the left leaf, and once as the sum of `2 + 5 - 5.`

[Solution](Day196.cpp)
- - - -

#### Problem 197
This problem was asked by Amazon.
Given an array and a number `k` that's smaller than the length of the array, rotate the array to the right `k` elements in-place.

[Solution](Day197.cpp)
- - - -

#### Problem 198
This problem was asked by Google.
<br>Given a set of distinct positive integers, find the largest subset such that every pair of elements in the subset `(i, j)` satisfies either `i % j = 0` or `j % i = 0`.
<br>For example, given the set `[3, 5, 10, 20, 21]`, you should return `[5, 10, 20]`. Given `[1, 3, 6, 24]`, return `[1, 3, 6, 24]`.

[Solution](Day198.cpp)
- - - 

#### Problem 199
This problem was asked by Facebook.
<br>Given a string of parentheses, find the balanced string that can be produced from it using the minimum number of insertions and deletions. If there are multiple solutions, return any of them.
<br>For example, given `"(()"`, you could return `"(())"`. Given `"))()("`, you could return `"()()()()"`.

[Solution](Day199.cpp)
- - - -

#### Problem 200
This problem was asked by Microsoft.
<br>Let `X` be a set of `n` intervals on the real line. We say that a set of points `P` "stabs" `X` if every interval in `X` contains at least one point in `P`. Compute the smallest set of points that stabs `X`.
<br>For example, given the intervals `[(1, 4), (4, 5), (7, 9), (9, 12)]`, you should return `[4, 9]`.

[Solution](Day200.cpp)
- - - -

#### Problem 201
This problem was asked by Google.
<br>You are given an array of arrays of integers, where each array corresponds to a row in a triangle of numbers. For example, `[[1], [2, 3], [1, 5, 1]]` represents the triangle:
```
  1
 2 3
1 5 1
```
We define a path in the triangle to start at the top and go down one row at a time to an adjacent value, eventually ending with an entry on the bottom row. For example, `1 -> 3 -> 5`. The weight of the path is the sum of the entries.
<br>Write a program that returns the weight of the maximum weight path.

[Solution](Day201.cpp)
- - - -

#### Problem 202
This problem was asked by Palantir.
<br>Write a program that checks whether an integer is a palindrome. For example, `121` is a palindrome, as well as `888`. `678` is not a palindrome. Do not convert the integer into a string.

[Solution](Day202.cpp)
- - - -

#### Problem 203
This problem was asked by Uber.
<br>Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. Find the minimum element in `O(log N)` time. You may assume the array does not contain duplicates.
<br>For example, given `[5, 7, 10, 3, 4]`, return `3`.

[Solution](Day203.cpp)
- - - -

#### Problem 204
This problem was asked by Amazon.
<br>Given a complete binary tree, count the number of nodes in faster than `O(n)` time. Recall that a complete binary tree has every level filled except the last, and the nodes in the last level are filled starting from the left.

[Solution](Day204.cpp)
- - - -

#### Problem 205
This problem was asked by IBM.
Given an integer, find the next permutation of it in absolute order. For example, given `48975`, the next permutation would be `49578`.

[Solution](Day205.cppy)
- - - -

#### Problem 206
This problem was asked by Twitter.
<br>A permutation can be specified by an array `P`, where `P[i]` represents the location of the element at `i` in the permutation. For example, `[2, 1, 0]` represents the permutation where elements at the index `0` and `2` are swapped.
<br>Given an array and a permutation, apply the permutation to the array. For example, given the array `["a", "b", "c"]` and the permutation `[2, 1, 0]`, return `["c", "b", "a"]`.

[Solution](Day206.cpp)
- - - -

#### Problem 207
This problem was asked by Dropbox.
<br>Given an undirected graph `G`, check whether it is bipartite. Recall that a graph is bipartite if its vertices can be divided into two independent sets, `U` and `V`, such that no edge connects vertices of the same set.

[Solution](Day207.cpp)
- - - -

#### Problem 208
This problem was asked by LinkedIn.
<br>Given a linked list of numbers and a pivot `k`, partition the linked list so that all nodes less than `k` come before nodes greater than or equal to `k`.
<br>For example, given the linked list `5 -> 1 -> 8 -> 0 -> 3` and `k = 3`, the solution could be `1 -> 0 -> 5 -> 8 -> 3`.

[Solution](Day208.cpp)
- - - -

#### Problem 209
This problem was asked by YouTube.
<br>Write a program that computes the length of the longest common subsequence of three given strings. For example, given "epidemiologist", "refrigeration", and "supercalifragilisticexpialodocious", it should return `5`, since the longest common subsequence is "eieio".

[Solution](Day209.cpp)
- - - -

#### Problem 210
This problem was asked by Apple.
<br>A Collatz sequence in mathematics can be defined as follows. Starting with any positive integer:
* If `n` is even, the next number in the sequence is `n / 2`
* If `n` is odd, the next number in the sequence is `3n + 1`
It is conjectured that every such sequence eventually reaches the number `1`. Test this conjecture.
<br>Bonus: What input `n <= 1000000` gives the longest sequence?

[Solution](Day210.cpp)
- - - -

#### Problem 211
This problem was asked by Microsoft.
<br>Given a string and a pattern, find the starting indices of all occurrences of the pattern in the string. For example, given the string "abracadabra" and the pattern "abr", you should return `[0, 7]`.

[Solution](Day211.cpp)
- - - -

#### Problem 212
This problem was asked by Dropbox.
<br>Spreadsheets often use this alphabetical encoding for its columns: "A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....
<br>Given a column number, return its alphabetical column id. For example, given `1`, return "A". Given `27`, return "AA".

[Solution](/Day212.cpp)
- - - -

#### Problem 213
This problem was asked by Snapchat.
<br>Given a string of digits, generate all possible valid IP address combinations.
<br>IP addresses must follow the format `A.B.C.D`, where `A`, `B`, `C`, and `D` are numbers between `0` and `255`. Zero-prefixed numbers, such as `01` and `065`, are not allowed, except for `0` itself.
<br>For example, given "2542540123", you should return `['254.25.40.123', '254.254.0.123']`.

[Solution](Day213.cpp)
- - - -

#### Problem 214
This problem was asked by Stripe.
<br>Given an integer `n`, return the length of the longest consecutive run of `1`s in its binary representation.
<br>For example, given `156`, you should return `3`.

[Solution](/Day214.cpp)
- - - -

#### Problem 215
This problem was asked by Yelp.
<br>The horizontal distance of a binary tree node describes how far left or right the node will be when the tree is printed out.
<br>More rigorously, we can define it as follows:
* The horizontal distance of the root is `0`.
* The horizontal distance of a left child is `hd(parent) - 1`.
* The horizontal distance of a right child is `hd(parent) + 1`.

For example, for the following tree, `hd(1) = -2`, and `hd(6) = 0`.
```
             5
          /     \
        3         7
      /  \      /   \
    1     4    6     9
   /                /
  0                8
```
The bottom view of a tree, then, consists of the lowest node at each horizontal distance. If there are two nodes at the same depth and horizontal distance, either is acceptable.
For this tree, for example, the bottom view could be `[0, 1, 3, 6, 8, 9]`.
<br>Given the root to a binary tree, return its bottom view.

[Solution](Day215.cpp)
- - - -

#### Problem 216
This problem was asked by Facebook.
<br>Given a number in Roman numeral format, convert it to decimal.
<br>The values of Roman numerals are as follows:
```
{
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
}
```
In addition, note that the Roman numeral system uses subtractive notation for numbers such as `IV` and `XL`.
<br>For the input `XIV`, for instance, you should return `14`.

[Solution](Day216.cpp)
- - - -

#### Problem 217
This problem was asked by Oracle.
<br>We say a number is sparse if there are no adjacent ones in its binary representation. For example, `21` (`10101`) is sparse, but `22` (`10110`) is not. For a given input `N`, find the smallest sparse number greater than or equal to `N`.
<br>Do this in faster than `O(N log N)` time.

[Solution](Day217.cpp)
- - - -

#### Problem 218
This problem was asked by Yahoo.
<br>Write an algorithm that computes the reversal of a directed graph. For example, if a graph consists of `A -> B -> C`, it should become `A <- B <- C`.

[Solution](Day218.cpp)
- - - -

#### Problem 219
This problem was asked by Salesforce.
<br>Connect 4 is a game where opponents take turns dropping red or black discs into a `7 x 6` vertically suspended grid. The game ends either when one player creates a line of four consecutive discs of their color (horizontally, vertically, or diagonally), or when there are no more spots left in the grid.
<br>Design and implement Connect 4.

[Solution](Day219.cpp)
- - - - 

#### Problem 220
This problem was asked by Square.
<br>In front of you is a row of N coins, with values `v_1, v_2, ..., v_n`.
<br>You are asked to play the following game. You and an opponent take turns choosing either the first or last coin from the row, removing it from the row, and receiving the value of the coin.
<br>Write a program that returns the maximum amount of money you can win with certainty, if you move first, assuming your opponent plays optimally.

[Solution](Day220.cpp)
- - - -

#### Problem 221
This problem was asked by Zillow.
<br>Let's define a "sevenish" number to be one which is either a power of `7`, or the sum of unique powers of `7`. The first few sevenish numbers are `1, 7, 8, 49`, and so on. Create an algorithm to find the `n`th sevenish number.

[Solution](Day221.cpp)
- - - -

#### Problem 222
This problem was asked by Quora.
<br>Given an absolute pathname that may have `.` or `..` as part of it, return the shortest standardized path.
<br>For example, given `/usr/bin/../bin/./scripts/../`, return `/usr/bin/`.

[Solution](Day222.cpp)
- - - -

#### Problem 223
This problem was asked by Palantir.
<br>Typically, an implementation of in-order traversal of a binary tree has `O(h)` space complexity, where `h` is the height of the tree. Write a program to compute the in-order traversal of a binary tree using `O(1)` space.

[Solution](Day223.cpp)
- - - -

#### Problem 224
This problem was asked by Amazon.
<br>Given a sorted array, find the smallest positive integer that is not the sum of a subset of the array.
<br>For example, for the input `[1, 2, 3, 10]`, you should return `7`. Do this in `O(N)` time.

[Solution](Day224.cpp)
- - - -

#### Problem 225
This problem was asked by Bloomberg.
<br>There are `N` prisoners standing in a circle, waiting to be executed. The executions are carried out starting with the `k`th person, and removing every successive `k`th person going clockwise until there is no one left. Given `N` and `k`, write an algorithm to determine where a prisoner should stand in order to be the last survivor.
<br>For example, if `N = 5` and `k = 2`, the order of executions would be `[2, 4, 1, 5, 3]`, so you should return `3`.

Bonus: Find an `O(log N)` solution if `k = 2`.

[Solution](Day225.cpp)
- - - -

#### Problem 226
This problem was asked by Airbnb.
<br>You come across a dictionary of sorted words in a language you've never seen before. Write a program that returns the correct order of letters in this language.
<br>For example, given `['xww', 'wxyz', 'wxyw', 'ywx', 'ywz']`, you should return `['x', 'z', 'w', 'y']`.

[Solution](Day226.cpp)
- - - -

#### Problem 227
This problem was asked by Facebook.
<br>Boggle is a game played on a `4 x 4` grid of letters. The goal is to find as many words as possible that can be formed by a sequence of adjacent letters in the grid, using each cell at most once. Given a game board and a dictionary of valid words, implement a Boggle solver.

[Solution](Day227.cpp)
- - - -

#### Problem 228
This problem was asked by Twitter.
<br>Given a list of numbers, create an algorithm that arranges them in order to form the largest possible integer. For example, given `[10, 7, 76, 415]`, you should return `77641510`.

[Solution](Day228.cpp)
- - - -

#### Problem 229
This problem was asked by Flipkart.
<br>Snakes and Ladders is a game played on a `10 x 10` board, the goal of which is get from square `1` to square `100`. On each turn players will roll a six-sided die and move forward a number of spaces equal to the result. If they land on a square that represents a snake or ladder, they will be transported ahead or behind, respectively, to a new square.
<br>Find the smallest number of turns it takes to play snakes and ladders.
<br>For convenience, here are the squares representing snakes and ladders, and their outcomes:
```
snakes = {16: 6, 48: 26, 49: 11, 56: 53, 62: 19, 64: 60, 87: 24, 93: 73, 95: 75, 98: 78}
ladders = {1: 38, 4: 14, 9: 31, 21: 42, 28: 84, 36: 44, 51: 67, 71: 91, 80: 100}
```

[Solution](Day229.cppy)
- - - -

#### Problem 230
This problem was asked by Goldman Sachs.
<br>You are given `N` identical eggs and access to a building with `k` floors. Your task is to find the lowest floor that will cause an egg to break, if dropped from that floor. Once an egg breaks, it cannot be dropped again. If an egg breaks when dropped from the `x`th floor, you can assume it will also break when dropped from any floor greater than `x`.
<br>Write an algorithm that finds the minimum number of trial drops it will take, in the worst case, to identify this floor.
<br>For example, if `N = 1` and `k = 5`, we will need to try dropping the egg at every floor, beginning with the first, until we reach the fifth floor, so our solution will be `5`.

[Solution](Day230.cpp)
- - - -

#### Problem 231
This problem was asked by IBM.
<br>Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same. If this is not possible, return None.
<br>For example, given "aaabbc", you could return "ababac". Given "aaab", return None.

[Solution](Day231.cpp)
- - - -

#### Problem 232
This problem was asked by Google.
<br>Implement a PrefixMapSum class with the following methods:
`insert(key: str, value: int)`: Set a given key's value in the map. If the key already exists, overwrite the value.
`sum(prefix: str)`: Return the sum of all values of keys that begin with a given prefix.
<br>For example, you should be able to run the following code:
```
mapsum.insert("columnar", 3)
assert mapsum.sum("col") == 3
```
```
mapsum.insert("column", 2)
assert mapsum.sum("col") == 5
```
[Solution](Day232.cpp)
- - - -

#### Problem 233
This problem was asked by Apple.
<br>Implement the function `fib(n)`, which returns the nth number in the Fibonacci sequence, using only `O(1)` space.

[Solution](Day233.cpp)
- - - -

#### Problem 234
This problem was asked by Microsoft.
<br>Recall that the minimum spanning tree is the subset of edges of a tree that connect all its vertices with the smallest possible total edge weight. Given an undirected graph with weighted edges, compute the maximum weight spanning tree.

[Solution](Day234.cpp)
- - - -

#### Problem 235
This problem was asked by Facebook.
<br>Given an array of numbers of length `N`, find both the minimum and maximum using less than `2 * (N - 2)` comparisons.

[Solution](Day235.cpp)
- - - -

#### Problem 236
This problem was asked by Nvidia.
<br>You are given a list of N points `(x1, y1), (x2, y2), ..., (xN, yN)` representing a polygon. You can assume these points are given in order; that is, you can construct the polygon by connecting point 1 to point 2, point 2 to point 3, and so on, finally looping around to connect point N to point 1.
<br>Determine if a new point p lies inside this polygon. (If p is on the boundary of the polygon, you should return False).

[Solution](Day236.cpp)
- - - -

#### Problem 237
This problem was asked by Amazon.
<br>A tree is symmetric if its data and shape remain unchanged when it is reflected about the root node. The following tree is an example:
```
        4
      / | \
    3   5   3
  /           \
9              9
```
Given a k-ary tree, determine whether it is symmetric.

[Solution](/Day237.cpp)
- - - -

#### Problem 238
This problem was asked by MIT.
<br>Blackjack is a two player card game whose rules are as follows:
* The player and then the dealer are each given two cards.
* The player can then "hit", or ask for arbitrarily many additional cards, so long as their total does not exceed 21.
* The dealer must then hit if their total is 16 or lower, otherwise pass.
* Finally, the two compare totals, and the one with the greatest sum not exceeding 21 is the winner.
<br>For this problem, cards values are counted as follows: each card between 2 and 10 counts as their face value, face cards count as 10, and aces count as 1.
<br>Given perfect knowledge of the sequence of cards in the deck, implement a blackjack solver that maximizes the player's score (that is, wins minus losses).

[Solution](Day238.cpp)
- - - -

#### Problem 239
This problem was asked by Uber.
<br>One way to unlock an Android phone is through a pattern of swipes across a 1-9 keypad.
<br>For a pattern to be valid, it must satisfy the following:
* All of its keys must be distinct.
* It must not connect two keys by jumping over a third key, unless that key has already been used.
<br>For example, `4 - 2 - 1 - 7` is a valid pattern, whereas `2 - 1 - 7` is not. Find the total number of valid unlock patterns of length N, where `1 <= N <= 9`.

[Solution](Day239.cpp)
- - - -

#### Problem 240
This problem was asked by Spotify.
<br>There are `N` couples sitting in a row of length `2 * N`. They are currently ordered randomly, but would like to rearrange themselves so that each couple's partners can sit side by side. What is the minimum number of swaps necessary for this to happen?

[Solution](Day240.cpp)
- - - -

#### Problem 241
This problem was asked by Palantir.
<br>In academia, the h-index is a metric used to calculate the impact of a researcher's papers. It is calculated as follows:
<br>A researcher has index `h` if at least `h` of her `N` papers have `h` citations each. If there are multiple `h` satisfying this formula, the maximum is chosen.
<br>For example, suppose `N = 5`, and the respective citations of each paper are `[4, 3, 0, 1, 5]`. Then the h-index would be `3`, since the researcher has `3` papers with at least `3` citations.
<br>Given a list of paper citations of a researcher, calculate their h-index.

[Solution](Day241.cpp)
- - - -

#### Problem 242
This problem was asked by Twitter.
<br>You are given an array of length 24, where each element represents the number of new subscribers during the corresponding hour. Implement a data structure that efficiently supports the following:
* `update(hour: int, value: int)`: Increment the element at index hour by value.
* `query(start: int, end: int)`: Retrieve the number of subscribers that have signed up between start and end (inclusive).
You can assume that all values get cleared at the end of the day, and that you will not be asked for start and end values that wrap around midnight.

[Solution](Day242.cpp)
- - - -

#### Problem 243
This problem was asked by Etsy.
<br>Given an array of numbers `N` and an integer `k`, your task is to split `N` into `k` partitions such that the maximum sum of any partition is minimized. Return this sum.
<br>For example, given `N = [5, 1, 2, 7, 3, 4]` and `k = 3`, you should return `8`, since the optimal partition is `[5, 1, 2], [7], [3, 4]`.

[Solution](Day243.cpp)
- - - -

#### Problem 244
This problem was asked by Square.
<br>The Sieve of Eratosthenes is an algorithm used to generate all prime numbers smaller than N. The method is to take increasingly larger prime numbers, and mark their multiples as composite.
<br>For example, to find all primes less than 100, we would first mark `[4, 6, 8, ...]` (multiples of two), then `[6, 9, 12, ...]` (multiples of three), and so on. Once we have done this for all primes less than `N`, the unmarked numbers that remain will be prime.Implement this algorithm.
<br>Bonus: Create a generator that produces primes indefinitely (that is, without taking `N` as an input).

[Solution](Day244.cpp)
- - - -

#### Problem 245
This problem was asked by Yelp.
<br>You are given an array of integers, where each element represents the maximum number of steps that can be jumped going forward from that element. Write a function to return the minimum number of jumps you must take in order to get from the start to the end of the array.
<br>For example, given `[6, 2, 4, 0, 5, 1, 1, 4, 2, 9]`, you should return `2`, as the optimal solution involves jumping from `6` to `5`, and then from `5` to `9`.

[Solution](Day245.cpp)
- - - -

#### Problem 246
This problem was asked by Dropbox.
<br>Given a list of words, determine whether the words can be chained to form a circle. A word `X` can be placed in front of another word `Y` in a circle if the last character of `X` is same as the first character of `Y`.
<br>For example, the words `['chair', 'height', 'racket', 'touch', 'tunic']` can form the following circle: `chair -> racket -> touch -> height -> tunic -> chair`.

[Solution](Day246.cpp)
- - - -

#### Problem 247
This problem was asked by PayPal.
<br>Given a binary tree, determine whether or not it is height-balanced. A height-balanced binary tree can be defined as one in which the heights of the two subtrees of any node never differ by more than one.

[Solution](Day247.cpp)
- - - -

#### Problem 248
This problem was asked by Nvidia.
<br>Find the maximum of two numbers without using any if-else statements, branching, or direct comparisons.

[Solution](Day248.cpp)
- - - -

### Problem 249
This problem was asked by Salesforce.
<br>Given an array of integers, find the maximum XOR of any two elements.

[Solution](Day249.cpp)
- - - -

### Problem 250
This problem was asked by Google.
<br>A cryptarithmetic puzzle is a mathematical game where the digits of some numbers are represented by letters. Each letter represents a unique digit.
<br>For example, a puzzle of the form:
```
  SEND
+ MORE
--------
 MONEY
```
may have the solution:
`{'S': 9, 'E': 5, 'N': 6, 'D': 7, 'M': 1, 'O': 0, 'R': 8, 'Y': 2}`
<br>Given a three-word puzzle like the one above, create an algorithm that finds a solution.

[Solution](Day250.cpp)
- - - 

### Problem 251
This problem was asked by Amazon.
<br>Given an array of a million integers between zero and a billion, out of order, how can you efficiently sort it? Assume that you cannot store an array of a billion elements in memory.

[Solution](Day251.md)
- - - -

### Problem 252
This problem was asked by Palantir.
<br>The ancient Egyptians used to express fractions as a sum of several terms where each numerator is one. For example, `4 / 13` can be represented as `1 / (4 + 1 / (18 + (1 / 468)))`.
<br>Create an algorithm to turn an ordinary fraction `a / b`, where `a < b`, into an Egyptian fraction.

[Solution](Day252.cpp)
- - - -

### Problem 253
This problem was asked by PayPal.
<br>Given a string and a number of lines `k`, print the string in zigzag form. In zigzag, characters are printed out diagonally from top left to bottom right until reaching the kth line, then back up to top right, and so on.
<br>For example, given the sentence `"thisisazigzag"` and `k = 4`, you should print:
```
t     a     g
 h   s z   a
  i i   i z
   s     g
```

[Solution](Day253.cpp)
- - - -

### Problem 254
This problem was asked by Yahoo.
<br>Recall that a full binary tree is one in which each node is either a leaf node, or has two children. Given a binary tree, convert it to a full one by removing nodes with only one child.
<br>For example, given the following tree:
```
         a
      /     \
    b         c
  /            \
d                 e
  \             /   \
    f          g     h
```
You should convert it to:
```
     a
  /     \
f         e
        /   \
       g     h
```
[Solution](Day254.cpp)
- - - -

### Problem 255
This problem was asked by Microsoft.
<br>The transitive closure of a graph is a measure of which vertices are reachable from other vertices. It can be represented as a matrix `M`, where `M[i][j] == 1` if there is a path between vertices `i` and `j`, and otherwise `0`.
<br>For example, suppose we are given the following graph in adjacency list form:
```
graph = [
    [0, 1, 3],
    [1, 2],
    [2],
    [3]
]
```
The transitive closure of this graph would be:
```
[1, 1, 1, 1]
[0, 1, 1, 0]
[0, 0, 1, 0]
[0, 0, 0, 1]
```
Given a graph, find its transitive closure.

[Solution](Day255.cpp)
- - - -

### Problem 256
This problem was asked by Fitbit.
<br>Given a linked list, rearrange the node values such that they appear in alternating `low -> high -> low -> high` ... form. For example, given `1 -> 2 -> 3 -> 4 -> 5`, you should return `1 -> 3 -> 2 -> 5 -> 4`.

[Solution](Day256.cpp)
- - - -

### Problem 257
This problem was asked by WhatsApp.
<br>Given an array of integers out of order, determine the bounds of the smallest window that must be sorted in order for the entire array to be sorted. For example, given `[3, 7, 5, 6, 9]`, you should return `(1, 3)`.

[Solution](Day257.cpp)
- - - -

### Problem 258
This problem was asked by Morgan Stanley.
<br>In Ancient Greece, it was common to write text with the first line going left to right, the second line going right to left, and continuing to go back and forth. This style was called "boustrophedon".
<br>Given a binary tree, write an algorithm to print the nodes in boustrophedon order.
<br>For example, given the following tree:
```
       1
    /     \
  2         3
 / \       / \
4   5     6   7
```
You should return `[1, 3, 2, 4, 5, 6, 7]`.

[Solution](Day258.cpp)
- - - -

### Problem 259
This problem was asked by Two Sigma.
<br>Ghost is a two-person word game where players alternate appending letters to a word. The first person who spells out a word, or creates a prefix for which there is no possible continuation, loses. Here is a sample game:
```
Player 1: g
Player 2: h
Player 1: o
Player 2: s
Player 1: t [loses]
```
<br>Given a dictionary of words, determine the letters the first player should start with, such that with optimal play they cannot lose.
<br>For example, if the dictionary is `["cat", "calf", "dog", "bear"]`, the only winning start letter would be b.

[Solution](Day259.cpp)
- - - -

### Problem 260
This problem was asked by Pinterest.
<br>The sequence `[0, 1, ..., N]` has been jumbled, and the only clue you have for its order is an array representing whether each number is larger or smaller than the last. Given this information, reconstruct an array that is consistent with it. For example, given `[None, +, +, -, +]`, you could return `[1, 2, 3, 0, 4]`.

[Solution](Day260.cpp)
- - - -

### Problem 261
This problem was asked by Amazon.
<br>Huffman coding is a method of encoding characters based on their frequency. Each letter is assigned a variable-length binary string, such as `0101` or `111110`, where shorter lengths correspond to more common letters. To accomplish this, a binary tree is built such that the path from the root to any leaf uniquely maps to a character. When traversing the path, descending to a left child corresponds to a `0` in the prefix, while descending right corresponds to `1`.
<br>Here is an example tree (note that only the leaf nodes have letters):
```
        *
      /   \
    *       *
   / \     / \
  *   a   t   *
 /             \
c               s
```
With this encoding, cats would be represented as `0000110111`.
<br>Given a dictionary of character frequencies, build a Huffman tree, and use it to determine a mapping between characters and their encoded binary strings.

[Solution](Day261.cpp)
- - - -

### Problem 262
This problem was asked by Mozilla.
<br>A bridge in a connected (undirected) graph is an edge that, if removed, causes the graph to become disconnected. Find all the bridges in a graph.

[Solution](Day262.cpp)
- - - -

### Problem 263
This problem was asked by Nest.
<br>Create a basic sentence checker that takes in a stream of characters and determines whether they form valid sentences. If a sentence is valid, the program should print it out.
We can consider a sentence valid if it conforms to the following rules:
* The sentence must start with a capital letter, followed by a lowercase letter or a space.
* All other characters must be lowercase letters, separators `(,,;,:)` or terminal marks `(.,?,!,‽)`.
* There must be a single space between each word.
* The sentence must end with a terminal mark immediately following a word.

[Solution](Day263.cpp)
- - - -

### Problem 264
This problem was asked by LinkedIn.
<br>Given a set of characters `C` and an integer `k`, a De Bruijn sequence is a cyclic sequence in which every possible `k`-length string of characters in `C` occurs exactly once.
<br>For example, suppose `C = {0, 1}` and `k = 3`. Then our sequence should contain the substrings `{'000', '001', '010', '011', '100', '101', '110', '111'}`, and one possible solution would be `00010111`.
<br>Create an algorithm that finds a De Bruijn sequence.

[Solution](Day264.cpp)
- - - -

### Problem 265
This problem was asked by Atlassian.
<br>MegaCorp wants to give bonuses to its employees based on how many lines of codes they have written. They would like to give the smallest positive amount to each worker consistent with the constraint that if a developer has written more lines of code than their neighbor, they should receive more money.
<br>Given an array representing a line of seats of employees at MegaCorp, determine how much each one should get paid.
<br>For example, given `[10, 40, 200, 1000, 60, 30]`, you should return `[1, 2, 3, 4, 2, 1]`.

[Solution](Day265.cpp)
- - - -

### Problem 266
This problem was asked by Pivotal.
<br>A step word is formed by taking a given word, adding a letter, and anagramming the result. For example, starting with the word "APPLE", you can add an "A" and anagram to get "APPEAL".
<br>Given a dictionary of words and an input word, create a function that returns all valid step words.

[Solution](Day266.cpp)
- - - -

### Problem 267
This problem was asked by Oracle.
<br>You are presented with an 8 by 8 matrix representing the positions of pieces on a chess board. The only pieces on the board are the black king and various white pieces. Given this matrix, determine whether the king is in check.
<br>For details on how each piece moves, see [here](https://en.wikipedia.org/wiki/Chess_piece#Moves_of_the_pieces).
<br>For example, given the following matrix:
```
...K....
........
.B......
......P.
.......R
..N.....
........
.....Q..
```
You should return `True`, since the bishop is attacking the king diagonally.
[Solution](Day267.cpp)
- - - -

### Problem 268
This problem was asked by Indeed.
<br>Given a 32-bit positive integer `N`, determine whether it is a power of four in faster than `O(log N)` time.

[Solution](Day268.cpp)
- - - -

### Problem 269
This problem was asked by Microsoft.
<br>You are given an string representing the initial conditions of some dominoes. Each element can take one of three values:
* `L`, meaning the domino has just been pushed to the left,
* `R`, meaning the domino has just been pushed to the right, or
* `.`, meaning the domino is standing still.
<br>Determine the orientation of each tile when the dominoes stop falling. Note that if a domino receives a force from the left and right side simultaneously, it will remain upright.
<br>For example, given the string `.L.R....L`, you should return `LL.RRRLLL`.
<br>Given the string `..R...L.L`, you should return `..RR.LLLL`.

[Solution](Day269.cpp)
- - - -

### Problem 270
This problem was asked by Twitter.
<br>A network consists of nodes labeled `0` to `N`. You are given a list of edges `(a, b, t)`, describing the time `t` it takes for a message to be sent from node `a` to node `b`. Whenever a node receives a message, it immediately passes the message on to a neighboring node, if possible.
<br>Assuming all nodes are connected, determine how long it will take for every node to receive a message that begins at node `0`.
For example, given `N = 5`, and the following edges:
```
edges = [
    (0, 1, 5),
    (0, 2, 3),
    (0, 5, 4),
    (1, 3, 8),
    (2, 3, 1),
    (3, 5, 10),
    (3, 4, 5)
]
```
You should return `9`, because propagating the message from `0 -> 2 -> 3 -> 4` will take that much time.

[Solution](Day270.cpp)
- - - -

### Problem 271
This problem was asked by Netflix.
<br>Given a sorted list of integers of length `N`, determine if an element `x` is in the list without performing any multiplication, division, or bit-shift operations.
<br>Do this in `O(log N)` time.

[Solution](Day271.cpp)
- - - -

### Problem 272
This problem was asked by Spotify.
<br>Write a function, `throw_dice(N, faces, total)`, that determines how many ways it is possible to throw `N` dice with some number of faces each to get a specific total.
<br>For example, `throw_dice(3, 6, 7)` should equal `15`.

[Solution](Day272.cpp)
- - - -

### Problem 273
This problem was asked by Apple.
<br>A fixed point in an array is an element whose value is equal to its index. Given a sorted array of distinct elements, return a fixed point, if one exists. Otherwise, return `False`.
<br>For example, given `[-6, 0, 2, 40]`, you should return `2`. Given `[1, 5, 7, 8]`, you should return `False`.

[Solution](Day273.cpp)
- - - -

### Problem 274
This problem was asked by Facebook.
<br>Given a string consisting of parentheses, single digits, and positive and negative signs, convert the string into a mathematical expression to obtain the answer.
<br>Don't use eval or a similar built-in parser.
<br>For example, given `'-1 + (2 + 3)'`, you should return `4`.

[Solution](Day274.cpp)
- - - -

### Problem 275
This problem was asked by Epic.
<br>The "look and say" sequence is defined as follows: beginning with the term `1`, each subsequent term visually describes
the digits appearing in the previous term. The first few terms are as follows:
```
1
11
21
1211
111221
```
As an example, the fourth term is `1211`, since the third term consists of one `2` and one `1`.
<br>Given an integer `N`, print the `Nth` term of this sequence.
[Solution](Day275.cpp)
- - - -

### Problem 276
This problem was asked by Dropbox.
<br>Implement an efficient string matching algorithm.
<br>That is, given a string of length `N` and a pattern of length `k`, write a program that searches for the pattern in the
string with less than `O(N * k)` worst-case time complexity.
<br>If the pattern is found, return the start index of its location. If not, return `False`.

[Solution](Day276.cpp)
- - - -

### Problem 277
This problem was asked by Google.
<br>UTF-8 is a character encoding that maps each symbol to one, two, three, or four bytes.
<br>For example, the Euro sign, `€`, corresponds to the three bytes `11100010 10000010 10101100`. The rules for mapping characters are as follows:
* For a single-byte character, the first bit must be zero.
* For an `n`-byte character, the first byte starts with `n` ones and a zero. The other `n - 1` bytes all start with `10`.
Visually, this can be represented as follows.

```
 Bytes   |           Byte format
-----------------------------------------------
   1     | 0xxxxxxx
   2     | 110xxxxx 10xxxxxx
   3     | 1110xxxx 10xxxxxx 10xxxxxx
   4     | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
```

Write a program that takes in an array of integers representing byte values, and returns whether it is a valid UTF-8 encoding.

[Solution](Day277.cpp)
- - - -

### Problem 278
This problem was asked by Amazon.
<br>Given an integer `N`, construct all possible binary search trees with `N` nodes.

[Solution](Day278.cpp)
- - - -

### Problem 279
This problem was asked by Twitter.
<br>A classroom consists of N students, whose friendships can be represented in an adjacency list. For example, the following descibes a situation where `0` is friends with `1` and `2`, `3` is friends with `6`, and so on.
```
{
    0: [1, 2],
    1: [0, 5],
    2: [0],
    3: [6],
    4: [],
    5: [1],
    6: [3]
}
```
Each student can be placed in a friend group, which can be defined as the transitive closure of that student's friendship
relations. In other words, this is the smallest set such that no student in the group has any friends outside this group. For
the example above, the friend groups would be `{0, 1, 2, 5}, {3, 6}, {4}`.
<br>Given a friendship list such as the one above, determine the number of friend groups in the class.

[Solution](Day279.cpp)
- - - -

### Problem 280
This problem was asked by Pandora.
<br>Given an undirected graph, determine if it contains a cycle.

[Solution](Day280.cpp)
- - - -

### Problem 281
This problem was asked by LinkedIn.
<br>A wall consists of several rows of bricks of various integer lengths and uniform height. Your goal is to find a vertical line
going from the top to the bottom of the wall that cuts through the fewest number of bricks. If the line goes through the edge
between two bricks, this does not count as a cut.
<br>For example, suppose the input is as follows, where values in each row represent the lengths of bricks in that row:
```
[[3, 5, 1, 1],
 [2, 3, 3, 2],
 [5, 5],
 [4, 4, 2],
 [1, 3, 3, 3],
 [1, 1, 6, 1, 1]]
```
The best we can we do here is to draw a line after the eighth brick, which will only require cutting through the bricks in the third and fifth row.
<br>Given an input consisting of brick lengths for each row such as the one above, return the fewest number of bricks that must be cut to create a vertical line.

[Solution](Day281.cpp))
 - - - -

### Problem 282
This problem was asked by Netflix.
<br>Given an array of integers, determine whether it contains a Pythagorean triplet. Recall that a Pythogorean triplet `(a, b, c)` is defined by the equation `a^2 + b^2 = c^2`.

[Solution](Day282.cpp))
 - - - -

### Problem 283
This problem was asked by Google.
<br>A regular number in mathematics is defined as one which evenly divides some power of `60`. Equivalently, we can say that
a regular number is one whose only prime divisors are `2`, `3`, and `5`.
<br>These numbers have had many applications, from helping ancient Babylonians keep time to tuning instruments according to the diatonic scale.
<br>Given an integer `N`, write a program that returns, in order, the first `N` regular numbers.

[Solution](Day283.cpp)
- - - -

### Problem 284
This problem was asked by Yext.
<br>Two nodes in a binary tree can be called cousins if they are on the same level of the tree but have different parents. <br>For example, in the following diagram `4` and `6` are cousins.
```
    1
   / \
  2   3
 / \   \
4   5   6
```
Given a binary tree and a particular node, find all cousins of that node.

[Solution](Day284.cpp)
- - - -

### Problem 285
This problem was asked by Mailchimp.
<br>You are given an array representing the heights of neighboring buildings on a city street, from east to west. The city
assessor would like you to write an algorithm that returns how many of these buildings have a view of the setting sun, in
order to properly value the street.
<br>For example, given the array `[3, 7, 8, 3, 6, 1]`, you should return `3`, since the top floors of the buildings with heights `8`, `6`, and `1` all have an unobstructed view to the west.
<br>Can you do this using just one forward pass through the array?

[Solution](Day285.cpp)
- - - -

### Problem 286
This problem was asked by VMware.
<br>The skyline of a city is composed of several buildings of various widths and heights, possibly overlapping one another
when viewed from a distance. We can represent the buildings using an array of `(left, right, height)` tuples, which tell us
where on an imaginary `x`-axis a building begins and ends, and how tall it is. The skyline itself can be described by a list
of `(x, height)` tuples, giving the locations at which the height visible to a distant observer changes, and each new height.
<br>Given an array of buildings as described above, create a function that returns the skyline.
<br>For example, suppose the input consists of the buildings `[(0, 15, 3), (4, 11, 5), (19, 23, 4)]`. In aggregate, these
buildings would create a skyline that looks like the one below.
```
     ______  
    |      |        ___
 ___|      |___    |   | 
|   |   B  |   |   | C |
| A |      | A |   |   |
|   |      |   |   |   |
------------------------
```
As a result, your function should return `[(0, 3), (4, 5), (11, 3), (15, 0), (19, 4), (23, 0)]`.

[Solution](Day286.cpp)
- - - -

### Problem 287
This problem was asked by Quora.
<br>You are given a list of (website, user) pairs that represent users visiting websites. Come up with a program that identifies the top `k` pairs of websites with the greatest similarity.
<br>For example, suppose `k = 1`, and the list of tuples is:
```
[('a', 1), ('a', 3), ('a', 5),
 ('b', 2), ('b', 6),
 ('c', 1), ('c', 2), ('c', 3), ('c', 4), ('c', 5),
 ('d', 4), ('d', 5), ('d', 6), ('d', 7),
 ('e', 1), ('e', 3), ('e', 5), ('e', 6)]
```
<br>Then a reasonable similarity metric would most likely conclude that `a` and `e` are the most similar, so your program should return `[('a', 'e')]`.

[Solution](Day287.cpp)

---

### Problem 288
This problem was asked by Salesforce.
<br>The number `6174` is known as Kaprekar's contant, after the mathematician who discovered an associated property: for all
four-digit numbers with at least two distinct digits, repeatedly applying a simple procedure eventually results in this
value. The procedure is as follows:
<br>For a given input `x`, create two new numbers that consist of the digits in `x` in ascending and descending order.
Subtract the smaller number from the larger number.
For example, this algorithm terminates in three steps when starting from `1234`:
```
4321 - 1234 = 3087
8730 - 0378 = 8352
8532 - 2358 = 6174
```
<br>Write a function that returns how many steps this will take for a given input `N`.

[Solution](Day288.cpp)
- - - -

### Problem 289
This problem was asked by Google.
The game of Nim is played as follows. Starting with three heaps, each containing a variable number of items, two players take
turns removing one or more items from a single pile. The player who eventually is forced to take the last stone loses. For
example, if the initial heap sizes are 3, 4, and 5, a game could be played as shown below:

| A   | B   | C   |
| --- | --- | --- |
| 3   | 4   | 5   |
| 3   | 1   | 5   |
| 3   | 1   | 3   |
| 0   | 1   | 3   |
| 0   | 1   | 0   |
| 0   | 0   | 0   |

<br>In other words, to start, the first player takes three items from pile `B`. The second player responds by removing two
stones from pile `C`. The game continues in this way until player one takes last stone and loses.
Given a list of non-zero starting values `[a, b, c]`, and assuming optimal play, determine whether the first player has a forced win.

[Solution](Day289.cpp)
- - - -

### Problem 290
This problem was asked by Facebook.
<br>On a mysterious island there are creatures known as Quxes which come in three colors: red, green, and blue. One power of the Qux is that if two of them are standing next to each other, they can transform into a single creature of the third color.
<br>Given N Quxes standing in a line, determine the smallest number of them remaining after any possible sequence of such transformations.
<br>For example, given the input `['R', 'G', 'B', 'G', 'B']`, it is possible to end up with a single Qux through the following steps:
```
        Arrangement       |   Change
----------------------------------------
['R', 'G', 'B', 'G', 'B'] | (R, G) -> B
['B', 'B', 'G', 'B']      | (B, G) -> R
['B', 'R', 'B']           | (R, B) -> G
['B', 'G']                | (B, G) -> R
['R']                     |
```

[Solution](Day290.cpp)
- - - -

### Problem 291
This problem was asked by Glassdoor.
<br>An imminent hurricane threatens the coastal town of Codeville. If at most two people can fit in a rescue boat, and the maximum weight limit for a given boat is `k`, determine how many boats will be needed to save everyone.
<br>For example, given a population with weights `[100, 200, 150, 80]` and a boat limit of `200`, the smallest number of boats required will be three.

[Solution](Day291.cpp)
- - - -

### Problem 292
This problem was asked by Twitter.
A teacher must divide a class of students into two teams to play dodgeball. Unfortunately, not all the kids get along, and
several refuse to be put on the same team as that of their enemies.
<br>Given an adjacency list of students and their enemies, write an algorithm that finds a satisfactory pair of teams, or returns `False` if none exists.
For example, given the following enemy graph you should return the teams `{0, 1, 4, 5}` and `{2, 3}`.
```
students = {
    0: [3],
    1: [2],
    2: [1, 4],
    3: [0, 4, 5],
    4: [2, 3],
    5: [3]
}
```
On the other hand, given the input below, you should return `False`.
```
students = {
    0: [3],
    1: [2],
    2: [1, 3, 4],
    3: [0, 2, 4, 5],
    4: [2, 3],
    5: [3]
}
```

[Solution](Day292.cpp)
- - - -

### Problem 293
This problem was asked by Uber.
<br>You have N stones in a row, and would like to create from them a pyramid. This pyramid should be constructed such that
the height of each stone increases by one until reaching the tallest stone, after which the heights decrease by one. In
addition, the start and end stones of the pyramid should each be one stone high.
<br>You can change the height of any stone by paying a cost of `1` unit to lower its height by `1`, as many times as necessary. Given this information, determine the lowest cost method to produce this pyramid.
<br>For example, given the stones `[1, 1, 3, 3, 2, 1]`, the optimal solution is to pay 2 to create `[0, 1, 2, 3, 2, 1]`.

[Solution](Day293.cpp)
- - - -

### Problem 294
This problem was asked by Square.
<br>A competitive runner would like to create a route that starts and ends at his house, with the condition that the route
goes entirely uphill at first, and then entirely downhill.
<br>Given a dictionary of places of the form `{location: elevation}`, and a dictionary mapping paths between some of these
locations to their corresponding distances, find the length of the shortest route satisfying the condition above. Assume the
runner's home is location `0`.
<br>For example, suppose you are given the following input:
```
elevations = {0: 5, 1: 25, 2: 15, 3: 20, 4: 10}
paths = {
    (0, 1): 10,
    (0, 2): 8,
    (0, 3): 15,
    (1, 3): 12,
    (2, 4): 10,
    (3, 4): 5,
    (3, 0): 17,
    (4, 0): 10
}
```
<br>In this case, the shortest valid path would be `0 -> 2 -> 4 -> 0`, with a distance of `28`.

[Solution](Day294.cpp)
- - - -

### Problem 295
This problem was asked by Stitch Fix.
<br>Pascal's triangle is a triangular array of integers constructed with the following formula:
* The first row consists of the number 1.
* For each subsequent row, each element is the sum of the numbers directly above it, on either side.
<br>For example, here are the first few rows:
```
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
```
Given an input `k`, return the `k`th row of Pascal's triangle.
<br>Bonus: Can you do this using only `O(k)` space?

[Solution](Day295.cpp)
- - - -

### Problem 296
This problem was asked by Etsy.
<br>Given a sorted array, convert it into a height-balanced binary search tree.

[Solution](Day296.cpp)
- - - -

### Problem 297
This problem was asked by Amazon.
<br>At a popular bar, each customer has a set of favorite drinks, and will happily accept any drink among this set. For
example, in the following situation, customer 0 will be satisfied with drinks `0`, `1`, `3`, or `6`.
```
preferences = {
    0: [0, 1, 3, 6],
    1: [1, 4, 7],
    2: [2, 4, 7, 5],
    3: [3, 2, 5],
    4: [5, 8]
}
```
A lazy bartender working at this bar is trying to reduce his effort by limiting the drink recipes he must memorize. Given a
dictionary input such as the one above, return the fewest number of drinks he must learn in order to satisfy all customers.
<br>For the input above, the answer would be `2`, as drinks `1` and `5` will satisfy everyone.

[Solution](Day297.cpp)
- - - -

### Problem 298
This problem was asked by Google.
A girl is walking along an apple orchard with a bag in each hand. She likes to pick apples from each tree as she goes along,
but is meticulous about not putting different kinds of apples in the same bag.
<br>Given an input describing the types of apples she will pass on her path, in order, determine the length of the longest portion of her path that consists of just two types of apple trees.
<br>For example, given the input `[2, 1, 2, 3, 3, 1, 3, 5]`, the longest portion will involve types `1` and `3`, with a length of four.

[Solution](Day298.cpp)
- - - -

### Problem 299
This problem was asked by Samsung.
<br>A group of houses is connected to the main water plant by means of a set of pipes. A house can either be connected by a set of pipes extending directly to the plant, or indirectly by a pipe to a nearby house which is otherwise connected.
<br>For example, here is a possible configuration, where A, B, and C are houses, and arrows represent pipes:
`A <--> B <--> C <--> plant`
<br>Each pipe has an associated cost, which the utility company would like to minimize. Given an undirected graph of pipe connections, return the lowest cost configuration of pipes such that each house has access to water.
<br>In the following setup, for example, we can remove all but the pipes from plant to A, plant to B, and B to C, for a total cost of 16.
```python
pipes = {
    'plant': {'A': 1, 'B': 5, 'C': 20},
    'A': {'C': 15},
    'B': {'C': 10},
    'C': {}
}
```

[Solution](Day299.cpp)
- - - -

### Problem 300
This problem was asked by Uber.
On election day, a voting machine writes data in the form `(voter_id, candidate_id)` to a text file. Write a program that
reads this file as a stream and returns the top 3 candidates at any given time. If you find a voter voting more than once,
report this as fraud.

[Solution](Day300.cpp)
- - - -

### Problem 301
This problem was asked by Triplebyte.
<br>Implement a data structure which carries out the following operations without resizing the underlying array:
- `add(value)`: Add a value to the set of values.
- `check(value)`: Check whether a value is in the set.
<br>The check method may return occasional false positives (in other words, incorrectly identifying an element as part of the set), but should always correctly identify a true element.

[Solution](Day301.cpp)
- - - -

### Problem 302
This problem was asked by Uber.
<br>You are given a 2-d matrix where each cell consists of either `/`, `\`, or an empty space. Write an algorithm that determines into how many regions the slashes divide the space.
<br>For example, suppose the input for a three-by-six grid is the following:
```
\    /
 \  /
  \/
```
Considering the edges of the matrix as boundaries, this divides the grid into three triangles, so you should return `3`.

[Solution](Day302.cpp)
- - - -

### Problem 303
This problem was asked by Microsoft.
<br>Given a clock time in `hh:mm` format, determine, to the nearest degree, the angle between the hour and the minute hands.
<br>Bonus: When, during the course of a day, will the angle be zero?

[Solution](Day303.cpp)
- - - -

### Problem 304
This problem was asked by Two Sigma.
<br>A knight is placed on a given square on an `8 x 8` chessboard. It is then moved randomly several times, where each move
is as tandard knight move. If the knight jumps off the board at any point, however, it is not allowed to jump back on.
<br>After `k` moves, what is the probability that the knight remains on the board?

[Solution](Day304.cpp)
- - - -

### Problem 305
This problem was asked by Amazon.
<br>Given a linked list, remove all consecutive nodes that sum to zero. Print out the remaining nodes.
<br>For example, suppose you are given the input `3 -> 4 -> -7 -> 5 -> -6 -> 6`. In this case, you should first remove `3 -> 4 -> -7`, then `-6 -> 6`, leaving only `5`.

[Solution](Day305.cpp)
- - - -

### Problem 306
This problem was asked by Palantir.
<br>You are given a list of N numbers, in which each number is located at most k places away from its sorted position. For
example, if `k = 1`, a given element at index `4` might end up at indices `3`, `4`, or `5`.
<br>Come up with an algorithm that sorts this list in `O(N log k)` time.

[Solution](Day306.cpp)
- - - -

### Problem 307
This problem was asked by Oracle.
<br>Given a binary search tree, find the floor and ceiling of a given integer. The floor is the highest element in the tree
less than or equal to an integer, while the ceiling is the lowest element in the tree greater than or equal to an integer.
<br>If either value does not exist, return None.

[Solution](Day307.cpp)
- - - -

### Problem 308
This problem was asked by Quantcast.
<br>You are presented with an array representing a Boolean expression. The elements are of two kinds:
* `T` and `F`, representing the values `True` and `False`.
* `&`, `|`, and `^`, representing the bitwise operators for `AND`, `OR`, and `XOR`.
Determine the number of ways to group the array elements using parentheses so that the entire expression evaluates to `True`.
<br>For example, suppose the input is `['F', '|', 'T', '&', 'T']`. In this case, there are two acceptable groupings: `(F | T)
& T` and `F | (T & T)`.

[Solution](Day308.cpp)
- - - -

### Problem 309
This problem was asked by Walmart Labs.
<br>There are `M` people sitting in a row of `N` seats, where `M < N`. Your task is to redistribute people such that there
are no gaps between any of them, while keeping overall movement to a minimum.
<br>For example, suppose you are faced with an input of `[0, 1, 1, 0, 1, 0, 0, 0, 1]`, where `0` represents an empty seat and
`1` represents a person. In this case, one solution would be to place the person on the right in the fourth seat. We can
consider the cost of a solution to be the sum of the absolute distance each person must move, so that the cost here would be `5`.
<br>Given an input such as the one above, return the lowest possible cost of moving people to remove all gaps.

[Solution](Day309.cpp)
- - - -

### Problem 310
This problem was asked by Pivotal.
<br>Write an algorithm that finds the total number of set bits in all integers between `1` and `N`.

[Solution](Day310.cpp)
- - - -

### Problem 311
This problem was asked by Sumo Logic.
<br>Given an unsorted array, in which all elements are distinct, find a "peak" element in `O(log N)` time.
<br>An element is considered a peak if it is greater than both its left and right neighbors. It is guaranteed that the first and last elements are lower than all others.

[Solution](Day311.cpp)
- - - -

### Problem 312
This problem was asked by Wayfair.
<br>You are given a `2 x N` board, and instructed to completely cover the board with the following shapes:
* Dominoes, or `2 x 1` rectangles.
* Trominoes, or L-shapes.
For example, if `N = 4`, here is one possible configuration, where A is a domino, and B and C are trominoes.
```
A B B C
A B C C
```
Given an integer N, determine in how many ways this task is possible.

[Solution](Day312.cpp)
- - - -

### Problem 313
This problem was asked by Citrix.
<br>You are given a circular lock with three wheels, each of which display the numbers `0` through `9` in order. Each of
these wheels rotate clockwise and counterclockwise.
<br>In addition, the lock has a certain number of "dead ends", meaning that if you turn the wheels to one of these combinations, the lock becomes stuck in that state and cannot be opened.
<br>Let us consider a "move" to be a rotation of a single wheel by one digit, in either direction. Given a lock initially set to `000`, a target combination, and a list of dead ends, write a function that returns the minimum number of moves required to reach the target state, or `None` if this is impossible.

[Solution](Day313.cpp)
- - - -

### Problem 314
This problem was asked by Spotify.
<br>You are the technical director of WSPT radio, serving listeners nationwide. For simplicity's sake we can consider each listener to live along a horizontal line stretching from `0` (west) to `1000` (east).
<br>Given a list of `N` listeners, and a list of `M` radio towers, each placed at various locations along this line, determine what the minimum broadcast range would have to be in order for each listener's home to be covered.
<br>For example, suppose `listeners = [1, 5, 11, 20]`, and `towers = [4, 8, 15]`. In this case the minimum range would be `5`, since that would be required for the tower at position `15` to reach the listener at position `20`.

[Solution](Day314.cpp)
- - - -

### Problem 315
This problem was asked by Google.
<br>In linear algebra, a Toeplitz matrix is one in which the elements on any given diagonal from top left to bottom right are identical.
Here is an example:
```
1 2 3 4 8
5 1 2 3 4
4 5 1 2 3
7 4 5 1 2
```
Write a program to determine whether a given input is a Toeplitz matrix.

[Solution](Day315.cpp)
- - - -

### Problem 316
This problem was asked by Snapchat.
<br>You are given an array of length `N`, where each element `i` represents the number of ways we can produce `i` units of change. For example, `[1, 0, 1, 1, 2]` would indicate that there is only one way to make `0`, `2`, or `3` units, and two ways of making `4` units.
<br>Given such an array, determine the denominations that must be in use. In the case above, for example, there must be coins with value `2`, `3`, and `4`.

[Solution](Day316.cpp)
- - - -

### Problem 317
This problem was asked by Yahoo.
<br>Write a function that returns the bitwise `AND` of all integers between `M` and `N`, inclusive.

[Solution](Day317.cpp)
- - - -

### Problem 318
This problem was asked by Apple.
<br>You are going on a road trip, and would like to create a suitable music playlist. The trip will require `N` songs, though
you only have `M` songs downloaded, where `M < N`. A valid playlist should select each song at least once, and guarantee a
buffer of `B` songs between repeats.
<br>Given `N`, `M`, and `B`, determine the number of valid playlists.

[Solution](Day318.cpp)
- - - -

### Problem 319
This problem was asked by Airbnb.
<br>An 8-puzzle is a game played on a `3 x 3` board of tiles, with the ninth tile missing. The remaining tiles are labeled
`1` through `8` but shuffled randomly. Tiles may slide horizontally or vertically into an empty space, but may not be removed
from the board.
<br>Design a class to represent the board, and find a series of steps to bring the board to the state 
`[[1, 2, 3], [4, 5, 6],[7, 8, None]]`.

[Solution](Day319.cpp)
- - - -

### Problem 320
This problem was asked by Amazon.
<br>Given a string, find the length of the smallest window that contains every distinct character. Characters may appear more
than once in the window.
<br>For example, given "jiujitsu", you should return 5, corresponding to the final five letters.

[Solution](Day320.cpp)
- - - -

### Problem 321
This problem was asked by PagerDuty.
<br>Given a positive integer `N`, find the smallest number of steps it will take to reach `1`.
<br>There are two kinds of permitted steps:
* You may decrement `N` to `N - 1`.
* If `a * b = N`, you may decrement `N` to the larger of `a` and `b`.
For example, given `100`, you can reach `1` in five steps with the following route: `100 -> 10 -> 9 -> 3 -> 2 -> 1`.

[Solution](Day321.cpp)
- - - -

### Problem 322
This problem was asked by Flipkart.
<br>Starting from `0` on a number line, you would like to make a series of jumps that lead to the integer `N`.
<br>On the `i`th jump, you may move exactly `i` places to the left or right.
<br>Find a path with the fewest number of jumps required to get from `0` to `N`.

[Solution](Day322.cpp)
- - - -

### Problem 323
This problem was asked by Dropbox.
<br>Create an algorithm to efficiently compute the approximate median of a list of numbers.
<br>More precisely, given an unordered list of `N` numbers, find an element whose rank is between `N / 4` and `3 * N / 4`,
with a high level of certainty, in less than `O(N)` time.

[Solution](Day323.cpp)
- - - -

### Problem 324
This problem was asked by Amazon.
<br>Consider the following scenario: there are `N` mice and `N` holes placed at integer points along a line. Given this, find
a method that maps mice to holes such that the largest number of steps any mouse takes is minimized.
<br>Each move consists of moving one mouse one unit to the left or right, and only one mouse can fit inside each hole.
<br>For example, suppose the mice are positioned at `[1, 4, 9, 15]`, and the holes are located at `[10, -5, 0, 16]`. In this
case, the best pairing would require us to send the mouse at `1` to the hole at `-5`, so our function should return `6`.

[Solution](Day324.cpp)
- - - -

### Problem 325
This problem was asked by Jane Street.
<br>The United States uses the imperial system of weights and measures, which means that there are many different, seemingly
arbitrary units to measure distance. There are 12 inches in a foot, 3 feet in a yard, 22 yards in a chain, and so on.
<br>Create a data structure that can efficiently convert a certain quantity of one unit to the correct amount of any other unit. You should also allow for additional units to be added to the system.

[Solution](Day325.cpp)
- - - -

### Problem 326
This problem was asked by Netflix.
<br>A Cartesian tree with sequence `S` is a binary tree defined by the following two properties:
<br>It is heap-ordered, so that each parent value is strictly less than that of its children.
An in-order traversal of the tree produces nodes with values that correspond exactly to `S`.
For example, given the sequence `[3, 2, 6, 1, 9]`, the resulting Cartesian tree would be:
```
      1
    /   \   
  2       9
 / \
3   6
```
Given a sequence S, construct the corresponding Cartesian tree.

[Solution](Day326.cpp)
- - - -

### Problem 327
This problem was asked by Salesforce.
<br>Write a program to merge two binary trees. Each node in the new tree should hold a value equal to the sum of the values
of the corresponding nodes of the input trees.
<br>If only one input tree has a node in a given position, the corresponding node in the new tree should match that input node.

[Solution](Day327.cpp)
- - - -

### Problem 328
This problem was asked by Facebook.
<br>In chess, the Elo rating system is used to calculate player strengths based on game results.
<br>A simplified description of the Elo system is as follows. Every player begins at the same score. For each subsequent
game, the loser transfers some points to the winner, where the amount of points transferred depends on how unlikely the win
is. For example, a 1200-ranked player should gain much more points for beating a 2000-ranked player than for beating a 1300
ranked player.
Implement this system.

[Solution](Day328.cpp)
- - - -

### Problem 329
This problem was asked by Amazon.
<br>The stable marriage problem is defined as follows:
<br>Suppose you have `N` men and `N` women, and each person has ranked their prospective opposite-sex partners in order of
preference.
<br>For example, if `N = 3`, the input could be something like this:
```
guy_preferences = {
    'andrew': ['caroline', 'abigail', 'betty'],
    'bill': ['caroline', 'betty', 'abigail'],
    'chester': ['betty', 'caroline', 'abigail'],
}
gal_preferences = {
    'abigail': ['andrew', 'bill', 'chester'],
    'betty': ['bill', 'andrew', 'chester'],
    'caroline': ['bill', 'chester', 'andrew']
}
```
<br>Write an algorithm that pairs the men and women together in such a way that no two people of opposite sex would both
rather be with each other than with their current partners.

[Solution](Day329.cpp)
- - - -

### Problem 330
This problem was asked by Dropbox.
<br>A Boolean formula can be said to be satisfiable if there is a way to assign truth values to each variable such that the
entire formula evaluates to true.
<br>For example, suppose we have the following formula, where the symbol `¬` is used to denote negation:
```
(¬c OR b) AND (b OR c) AND (¬b OR c) AND (¬c OR ¬a)
```
<br>One way to satisfy this formula would be to let `a = False`, `b = True`, and `c = True`.
<br>This type of formula, with AND statements joining tuples containing exactly one OR, is known as 2-CNF.
<>brGiven a 2-CNF formula, find a way to assign truth values to satisfy it, or return `False` if this is impossible.

[Solution](Day330.cpp)
- - - -

### Problem 331
This problem was asked by LinkedIn.
<br>You are given a string consisting of the letters `x` and `y`, such as `xyxxxyxyy`. In addition, you have an operation
called flip, which changes a single `x` to `y` or vice versa.
<br>Determine how many times you would need to apply this operation to ensure that all `x`'s come before all `y`'s. In the
preceding example, it suffices to flip the second and sixth characters, so you should return `2`.

[Solution](Day331.cpp)
- - - -

### Problem 332
This problem was asked by Jane Street.
<br>Given integers `M` and `N`, write a program that counts how many positive integer pairs `(a, b)` satisfy the following
conditions:
```
a + b = M
a XOR b = N
```

[Solution](Day332.cpp)
- - - -

### Problem 333
This problem was asked by Pinterest.
<br>At a party, there is a single person who everyone knows, but who does not know anyone in return (the "celebrity"). To
help figure out who this is, you have access to an `O(1)` method called `knows(a, b)`, which returns `True` if person `a`
knows person `b`, else `False`.
<br>Given a list of `N` people and the above operation, find a way to identify the celebrity in `O(N)` time.

[Solution](Day333.cpp)
- - - -

### Problem 334
This problem was asked by Twitter.
<br>The `24` game is played as follows. You are given a list of four integers, each between `1` and `9`, in a fixed order. By
placing the operators `+`, `-`, `*`, and `/` between the numbers, and grouping them with parentheses, determine whether it is
possible to reach the value `24`.
For example, given the input `[5, 2, 7, 8]`, you should return True, since `(5 * 2 - 7) * 8 = 24`.
<br>Write a function that plays the `24` game.

[Solution](Day334.cpp)
- - - -

### Problem 335
This problem was asked by Google.
<br>PageRank is an algorithm used by Google to rank the importance of different websites. While there have been changes over
the years, the central idea is to assign each site a score based on the importance of other pages that link to that page.
<br>More mathematically, suppose there are `N` sites, and each site `i` has a certain count `Ci` of outgoing links. Then the
score for a particular site `Sj` is defined as :
```
score(Sj) = (1 - d) / N + d * (score(Sx) / Cx+ score(Sy) / Cy+ ... + score(Sz) / Cz))
```
<br>Here, `Sx, Sy, ..., Sz` denote the scores of all the other sites that have outgoing links to `Sj`, and `d` is a damping factor, usually set to around `0.85`, used to model the probability that a user will stop searching.
<br>Given a directed graph of links between various websites, write a program that calculates each site's page rank.

[Solution](sDay335.cpp)
- - - -

### Problem 336
This problem was asked by Microsoft.
<br>Write a program to determine how many distinct ways there are to create a max heap from a list of `N` given integers.
<br>For example, if `N = 3`, and our integers are `[1, 2, 3]`, there are two ways, shown below.
```
  3      3
 / \    / \
1   2  2   1
```

[Solution](Day336)
- - - -

### Problem 337
This problem was asked by Apple.
<br>Given a linked list, uniformly shuffle the nodes. What if we want to prioritize space over time?

[Solution](Day337.cpp)
- - - -

### Problem 338
This problem was asked by Facebook.
<br>Given an integer `n`, find the next biggest integer with the same number of `1`-bits on. For example, given the number
`6` (`0110` in binary), return `9` (`1001`).

[Solution](Day338.cpp)
- - - -

### Problem 339
This problem was asked by Microsoft.
<br>Given an array of numbers and a number `k`, determine if there are three entries in the array which add up to the
specified number `k`. For example, given `[20, 303, 3, 4, 25]` and `k = 49`, return true as `20 + 4 + 25 = 49`.

[Solution](Day339.cpp)
- - - -

### Problem 340
This problem was asked by Google.
<br>Given a set of points `(x, y)` on a 2D cartesian plane, find the two closest points. For example, given the points
`[(1,1), (-1, -1), (3, 4), (6, 1), (-1, -6), (-4, -3)]`, return `[(-1, -1), (1, 1)]`.

[Solution](Day340.cpp)
- - - -

### Problem 341

This problem was asked by Google.

You are given an N by N matrix of random letters and a dictionary of words. Find the maximum number of words that can be packed on the board from the given dictionary.

A word is considered to be able to be packed on the board if:
- It can be found in the dictionary
- It can be constructed from untaken letters by other words found so far on the board
- The letters are adjacent to each other (vertically and horizontally, not diagonally).
- Each tile can be visited only once by any word.

For example, given the following dictionary:
```
{ 'eat', 'rain', 'in', 'rat' }
```

and matrix:
```
[['e', 'a', 'n'],
 ['t', 't', 'i'],
 ['a', 'r', 'a']]
```

Your function should return 3, since we can make the words 'eat', 'in', and 'rat' without them touching each other. We could have alternatively made 'eat' and 'rain', but that would be incorrect since that's only 2 words.

[Solution](Day341.cpp)

---

### Problem 342
This problem was asked by Stripe.
<br>`reduce` (also known as `fold`) is a function that takes in an array, a combining function, and an initial value and
builds up a result by calling the combining function on each element of the array, left to right. For example, we can write
`sum()` in terms of reduce:

```python
def add(a, b):
    return a + b
```

```python
def sum(lst):
    return reduce(lst, add, 0)
```

This should call add on the initial value with the first element of the array, and then the result of that with the second
element of the array, and so on until we reach the end, when we return the sum of the array.
<br>Implement your own version of reduce.

[Solution](Day342.cpp)
- - - -

### Problem 343
This problem was asked by Google.
<br>Given a binary search tree and a range `[a, b]` (inclusive), return the sum of the elements of the binary search tree
within the range.
<br>For example, given the following tree:
```
    5
   / \
  3   8
 / \ / \
2  4 6  10
```
<br>and the range `[4, 9]`, return `23 (5 + 4 + 6 + 8)`.

[Solution](Day343.cpp)

---

### Problem 344
This problem was asked by Adobe.
<br>You are given a tree with an even number of nodes. Consider each connection between a parent and child node to be an
"edge". You would like to remove some of these edges, such that the disconnected subtrees that remain each have an even
number of nodes.
<br>For example, suppose your input was the following tree:
```
   1
  / \ 
 2   3
    / \ 
   4   5
 / | \
6  7  8
```
<br>In this case, removing the edge `(3, 4)` satisfies our requirement.
<br>Write a function that returns the maximum number of edges you can remove while still satisfying this requirement.

[Solution](Day344.cpp)
- - - -

### Problem 345
This problem was asked by Google.
<br>You are given a set of synonyms, such as `(big, large)` and `(eat, consume)`. Using this set, determine if two sentences
with the same number of words are equivalent.
<br>For example, the following two sentences are equivalent:
* "He wants to eat food."
* "He wants to consume food."
<br>Note that the synonyms `(a, b)` and `(a, c)` do not necessarily imply `(b, c)`: consider the case of `(coach, bus)` and `(coach, teacher)`.
<br>Follow-up: what if we can assume that `(a, b)` and `(a, c)` do in fact imply `(b, c)`?

[Solution](Day345.cpp)
- - - -

### Problem 346
This problem was asked by Airbnb.
<br>You are given a huge list of airline ticket prices between different cities around the world on a given day. These are
all direct flights. Each element in the list has the format `(source_city, destination, price)`.
<br>Consider a user who is willing to take up to `k` connections from their origin city `A` to their destination `B`. Find
the cheapest fare possible for this journey and print the itinerary for that journey.
<br>For example, our traveler wants to go from JFK to LAX with up to 3 connections, and our input flights are as follows:
```
[
    ('JFK', 'ATL', 150),
    ('ATL', 'SFO', 400),
    ('ORD', 'LAX', 200),
    ('LAX', 'DFW', 80),
    ('JFK', 'HKG', 800),
    ('ATL', 'ORD', 90),
    ('JFK', 'LAX', 500),
]
```
<br>Due to some improbably low flight prices, the cheapest itinerary would be JFK -> ATL -> ORD -> LAX, costing $440.

[Solution](Day346.cpp)
- - - -

### Problem 347
This problem was asked by Yahoo.
<br>You are given a string of length `N` and a parameter `k`. The string can be manipulated by taking one of the first `k`
letters and moving it to the end.
<br>Write a program to determine the lexicographically smallest string that can be created after an unlimited number of
moves.
<br>For example, suppose we are given the string `daily` and `k = 1`. The best we can create in this case is `ailyd`.

[Solution](Day347.py)
- - - - 

### Problem 348
This problem was asked by Zillow.
<br>A ternary search tree is a trie-like data structure where each node may have up to three children. Here is an example
which represents the words `code`, `cob`, `be`, `ax`, `war`, and `we`.
```
       c
    /  |  \
   b   o   w
 / |   |   |
a  e   d   a
|    / |   | \ 
x   b  e   r  e
```
The tree is structured according to the following rules:
* left child nodes link to words lexicographically earlier than the parent prefix
* right child nodes link to words lexicographically later than the parent prefix
* middle child nodes continue the current word
<br>For instance, since code is the first word inserted in the tree, and `cob` lexicographically precedes `cod`, `cob` is
represented as a left child extending from `cod`.
<br>Implement insertion and search functions for a ternary search tree.

[Solution](Day348.cpp)
- - - -

### Problem 349

This problem was asked by Grammarly.

Soundex is an algorithm used to categorize phonetically, such that two names that sound alike but are spelled differently have the same representation.

Soundex maps every name to a string consisting of one letter and three numbers, like `M460`.

One version of the algorithm is as follows:
- Remove consecutive consonants with the same sound (for example, change `ck -> c`).
- Keep the first letter. The remaining steps only apply to the rest of the string.
- Remove all vowels, including `y`, `w`, and `h`.
- Replace all consonants with the following digits:
    ```
    b, f, p, v -> 1
    c, g, j, k, q, s, x, z -> 2
    d, t -> 3
    l -> 4
    m, n -> 5
    r -> 6
    ```

If you don't have three numbers yet, append zeros until you do. Keep the first three numbers.
Using this scheme, `Jackson` and `Jaxen` both map to `J250`.

Implement Soundex.

[Solution](Day349.cpp)

---

### Problem 350

This problem was asked by Uber.

Write a program that determines the smallest number of perfect squares that sum up to `N`.

Here are a few examples:
- Given `N = 4`, return `1` `(4)`
- Given `N = 17`, return `2` `(16 + 1)`
- Given `N = 18`, return `2` `(9 + 9)`

[Solution](Day350.cpp)

---

### Problem 351

This problem was asked by Quora.

Word sense disambiguation is the problem of determining which sense a word takes on in a particular setting, if that word has multiple meanings. For example, in the sentence "I went to get money from the bank", bank probably means the place where people deposit money, not the land beside a river or lake.

Suppose you are given a list of meanings for several words, formatted like so:
```
{
    "word_1": ["meaning one", "meaning two", ...],
    ...
    "word_n": ["meaning one", "meaning two", ...]
}
```

Given a sentence, most of whose words are contained in the meaning list above, create an algorithm that determines the likely sense of each possibly ambiguous word.

[Solution](solutions/problem_351.md)

---

### Problem 352
This problem was asked by Palantir.

A typical American-style crossword puzzle grid is an `N x N` matrix with black and white squares, which obeys the following rules:
* Every white square must be part of an "across" word and a "down" word.
* No word can be fewer than three letters long.
* Every white square must be reachable from every other white square.
* The grid is rotationally symmetric (for example, the colors of the top left and bottom right squares must match).

Write a program to determine whether a given matrix qualifies as a crossword grid.

[Solution](Day352.cpp)
- - - -

### Problem 353
This problem was asked by Square.
<br>You are given a histogram consisting of rectangles of different heights. These heights are represented in an input list,
such that `[1, 3, 2, 5]` corresponds to the following diagram:
```
      x
      x  
  x   x
  x x x
x x x x
```
<br>Determine the area of the largest rectangle that can be formed only from the bars of the histogram. For the diagram above, for example, this would be six, representing the `2 x 3` area at the bottom right.

[Solution](Day353.cpp)
- - - -

### Problem 354
This problem was asked by Google.
<br>Design a system to crawl and copy all of Wikipedia using a distributed network of machines.
<br>More specifically, suppose your server has access to a set of client machines. Your client machines can execute code you have written to access Wikipedia pages, download and parse their data, and write the results to a database.

Some questions you may want to consider as part of your solution are:
* How will you reach as many pages as possible?
* How can you keep track of pages that have already been visited?
* How will you deal with your client machines being blacklisted?
* How can you update your database when Wikipedia pages are added or updated?

[Solution](solutions/problem_354.md)

---

### Problem 355
This problem was asked by Airbnb.
<br>You are given an array `X` of floating-point numbers `x1, x2, ... xn`. These can be rounded up or down to create a
corresponding array `Y` of integers `y1, y2, ... yn`.
<br>Write an algorithm that finds an appropriate `Y` array with the following properties:
* The rounded sums of both arrays should be equal.
* The absolute pairwise difference between elements is minimized. In other words, `|x1- y1| + |x2- y2| + ... + |xn- yn|`
should be as small as possible.
<br>For example, suppose your input is `[1.3, 2.3, 4.4]`. In this case you cannot do better than `[1, 2, 5]`, which has an
absolute difference of `|1.3 - 1| + |2.3 - 2| + |4.4 - 5| = 1`.

[Solution](Day355.cpp)
- - - -

### Problem 356

This problem was asked by Netflix.

Implement a queue using a set of fixed-length arrays.

The queue should support `enqueue`, `dequeue`, and `get_size` operations.

[Solution](Day356.cpp)

---

### Problem 357
This problem was asked by LinkedIn.
<br>You are given a binary tree in a peculiar string representation. Each node is written in the form `(lr)`, where `l`
corresponds to the left child and `r` corresponds to the right child.
<br>If either `l` or `r` is null, it will be represented as a zero. Otherwise, it will be represented by a new `(lr)` pair.
<br>Here are a few examples:
* A root node with no children: `(00)`
* A root node with two children: `((00)(00))`
* An unbalanced tree with three consecutive left children: `((((00)0)0)0)`
Given this representation, determine the depth of the tree.

[Solution](Day357.cpp)
- - - -

### Problem 358

This problem was asked by Dropbox.

Create a data structure that performs all the following operations in `O(1)` time:
- `plus`: Add a key with value 1. If the key already exists, increment its value by one.
- `minus`: Decrement the value of a key. If the key's value is currently 1, remove it.
- `get_max`: Return a key with the highest value.
- `get_min`: Return a key with the lowest value.

[Solution](Day358.cpp)

---

### Problem 359
This problem was asked by Slack.
<br>You are given a string formed by concatenating several words corresponding to the integers zero through nine and then anagramming.
<br>For example, the input could be 'niesevehrtfeev', which is an anagram of 'threefiveseven'. Note that there can be multiple instances of each integer.
<br>Given this string, return the original integers in sorted order. In the example above, this would be `357`.

[Solution](Day359.cpp)
- - - -

### Problem 360
This problem was asked by Spotify.
<br>You have access to ranked lists of songs for various users. Each song is represented as an integer, and more preferred songs appear earlier in each list. For example, the list `[4, 1, 7]` indicates that a user likes song `4` the best, followed by songs `1` and `7`.
<br>Given a set of these ranked lists, interleave them to create a playlist that satisfies everyone's priorities.
For example, suppose your input is `{[1, 7, 3], [2, 1, 6, 7, 9], [3, 9, 5]}`. In this case a satisfactory playlist could be `[2, 1, 6, 7, 3, 9, 5]`.

[Solution](Day360.cpp)
- - - -

### Problem 361

This problem was asked by Facebook.

Mastermind is a two-player game in which the first player attempts to guess the secret code of the second. In this version, the code may be any six-digit number with all distinct digits.

Each turn the first player guesses some number, and the second player responds by saying how many digits in this number correctly matched their location in the secret code. For example, if the secret code were `123456`, then a guess of `175286` would score two, since `1` and `6` were correctly placed.

Write an algorithm which, given a sequence of guesses and their scores, determines whether there exists some secret code that could have produced them.

For example, for the following scores you should return `True`, since they correspond to the secret code `123456`:
`{175286: 2, 293416: 3, 654321: 0}`

However, it is impossible for any key to result in the following scores, so in this case you should return `False`:
`{123456: 4, 345678: 4, 567890: 4}`

[Solution](Day361.cpp)

---

### Problem 362
This problem was asked by Twitter.
<br>A strobogrammatic number is a positive number that appears the same after being rotated `180` degrees. For example, `16891` is strobogrammatic.
<br>Create a program that finds all strobogrammatic numbers with N digits.

[Solution](Day362.cpp)
- - - -

### Problem 363

Write a function, add_subtract, which alternately adds and subtracts curried arguments. Here are some sample operations:

```
add_subtract(7) -> 7
add_subtract(1)(2)(3) -> 1 + 2 - 3 -> 0
add_subtract(-5)(10)(3)(9) -> -5 + 10 - 3 + 9 -> 11
```

[Solution](Day363)

---

### Problem 364
This problem was asked by Facebook.
<br>Describe an algorithm to compute the longest increasing subsequence of an array of numbers in `O(n log n)` time.

[Solution](Day364.cpp)
- - - - 

### Problem 365
This problem was asked by Google.
<br>A quack is a data structure combining properties of both stacks and queues. It can be viewed as a list of elements written left to right such that three operations are possible:
* `push(x)`: add a new item `x` to the left end of the list
* `pop()`: remove and return the item on the left end of the list
* `pull()`: remove the item on the right end of the list.
<br>Implement a quack using three stacks and `O(1)` additional memory, so that the amortized time for any push, pop, or pull operation is `O(1)`.

[Solution](Day365.cpp)
- - - -

### Problem 366
This problem was asked by Flexport.

Given a string s, rearrange the characters so that any two adjacent characters are not the same. If this is not possible, return null.

For example, if s = yyz then return yzy. If s = yyy then return null.
[Solution](Day366.cpp)
- - - -

### Problem 367
This problem was asked by Two Sigma.

Given two sorted iterators, merge it into one iterator.

For example, given these two iterators:
`
foo = iter([5, 10, 15])
bar = iter([3, 8, 9])
`
You should be able to do:
`
for num in merge_iterators(foo, bar):
    print(num)
# 3
# 5
# 8
# 9
# 10
# 15
`
Bonus: Make it work without pulling in the contents of the iterators in memory.
[Solution](Day367.py)
- - - -

### Problem 368
This problem was asked by Google.
Implement a key value store, where keys and values are integers, with the following methods:

`update(key, vl)`: updates the value at key to val, or sets it if doesn't exist
`get(key)`: returns the value with key, or None if no such value exists
`max_key(val)`: returns the largest key with value val, or None if no key with that value exists
For example, if we ran the following calls:
`kv.update(1, 1)
kv.update(2, 1)`
And then called `kv.max_key(1)`, it should return 2, since it's the largest key with value 1.

[Solution](Day368.cpp)
- - - -

### Problem 370
Good morning! Here's your coding interview problem for today.

This problem was asked by Postmates.

The “active time” of a courier is the time between the pickup and dropoff of a delivery. Given a set of data formatted like the following:
`
(delivery id, timestamp, pickup/dropoff)
`
Calculate the total active time in seconds. A courier can pick up multiple orders before dropping them off. The timestamp is in unix epoch seconds.

For example, if the input is the following:

`
(1, 1573280047, 'pickup')
(1, 1570320725, 'dropoff')
(2, 1570321092, 'pickup')
(3, 1570321212, 'pickup')
(3, 1570322352, 'dropoff')
(2, 1570323012, 'dropoff')
`
The total active time would be 1260 seconds.

[Solution](Day370.cpp)
- - - -

### Problem 372
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Write a function that takes a natural number as input and returns the number of digits the input has.

Constraint: don't use any loops.

[Solution](Day372.cpp)
- - - -

### Problem 373
This problem was asked by Facebook.

Given a list of integers L, find the maximum length of a sequence of consecutive numbers that can be formed using elements from L.

For example, given `L = [5, 2, 99, 3, 4, 1, 100]`, return 5 as we can build a sequence `[1, 2, 3, 4, 5]` which has length 5.
[Solution](Day373.cpp)
- - - -

### Problem 374
This problem was asked by Amazon.

Given a sorted array arr of distinct integers, return the lowest index i for which arr[i] == i. Return null if there is no such index.

For example, given the array [-5, -3, 2, 3], return 2 since arr[2] == 2. Even though arr[3] == 3, we return 2 since it's the lowest index.
[Solution](Day374.cpp)
- - - -


### Problem 375
This problem was asked by Google.

The h-index is a metric used to measure the impact and productivity of a scientist or researcher.

A scientist has index h if h of their N papers have at least h citations each, and the other N - h papers have no more than h citations each. If there are multiple possible values for h, the maximum value is used.

Given an array of natural numbers, with each value representing the number of citations of a researcher's paper, return the h-index of that researcher.

For example, if the array was:

`[4, 0, 0, 2, 3]`
This means the researcher has 5 papers with 4, 1, 0, 2, and 3 citations respectively. The h-index for this researcher is 2, since they have 2 papers with at least 2 citations and the remaining 3 papers have no more than 2 citations.
[Solution](Day375.cpp)
- - - -

### Problem 376
This problem was asked by Google.

You are writing an AI for a 2D map game. You are somewhere in a 2D grid, and there are coins strewn about over the map.

Given the position of all the coins and your current position, find the closest coin to you in terms of Manhattan distance. 
That is, you can move around up, down, left, and right, but not diagonally. If there are multiple possible closest coins, return any of them.

For example, given the following map, where you are x, coins are o, and empty spaces are . (top left is 0, 0):
```
---------------------
| . | . | x | . | o |
---------------------
| o | . | . | . | . |
---------------------
| o | . | . | . | o |
---------------------
| . | . | o | . | . |
---------------------
```
return `(0, 4)`, since that coin is closest. This map would be represented in our question as:
`
Our position: (0, 2)
Coins: [(0, 4), (1, 0), (2, 0), (3, 2)]
`
[Solution](Day376.cpp)
- - - -

#### Problem 392
This problem was asked by Google.

You are given a 2D matrix of 1s and 0s where 1 represents land and 0 represents water.

Grid cells are connected horizontally orvertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or
more connected land cells).

An island is a group is cells connected horizontally or vertically, but not diagonally. There is guaranteed to be exactly one island in this grid, and the
island doesn't have water inside that isn't connected to the water around the island. Each cell has a side length of 1.

Determine the perimeter of this island.

For example, given the following matrix:
```
[[0, 1, 1, 0],
[1, 1, 1, 0],
[0, 1, 1, 0],
[0, 0, 1, 0]]
```
Return `14`.

[Solution](Day392.cpp)
- - - -

## Problem 423
This problem was asked by Microsoft.
<br>The transitive closure of a graph is a measure of which vertices are reachable from other vertices. It can be represented as a matrix `M`, where `M[i][j] == 1` if there is a path between vertices `i` and `j`, and otherwise `0`.
<br>For example, suppose we are given the following graph in adjacency list form:
```
graph = [
    [0, 1, 3],
    [1, 2],
    [2],
    [3]
]
```
The transitive closure of this graph would be:
```
[1, 1, 1, 1]
[0, 1, 1, 0]
[0, 0, 1, 0]
[0, 0, 0, 1]
```
Given a graph, find its transitive closure.

[Solution](Day423.cpp)
- - - -

### Problem 425
This problem was asked by Oracle.
<br>You are presented with an 8 by 8 matrix representing the positions of pieces on a chess board. The only pieces on the board are the black king and various white pieces. Given this matrix, determine whether the king is in check.
<br>For details on how each piece moves, see [here](https://en.wikipedia.org/wiki/Chess_piece#Moves_of_the_pieces).
<br>For example, given the following matrix:
```
...K....
........
.B......
......P.
.......R
..N.....
........
.....Q..
```
You should return `True`, since the bishop is attacking the king diagonally.
[Solution](Day425.cpp)
- - - -

#### Problem 435
This problem was asked by Google.
Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.
For example, given the following preorder traversal:
```
[a, b, d, e, c, f, g]
```
And the following inorder traversal:
```
[d, b, e, a, f, c, g]
```
You should return the following tree:
```
    a
   / \
  b   c
 / \ / \
d  e f  g
```

[Solution](Day435.cpp)
- - - -

### Problem 438
This problem was asked by Amazon.

Implement a stack API using only a heap. A stack implements the following methods:
* push(item), which adds an element to the stack
* pop(), which removes and returns the most recently added element (or throws an error if there is nothing on the stack)

Recall that a heap has the following operations:
* push(item), which adds a new key to the heap
* pop(), which removes and returns the max value of the heap

[Solution](Day438.cpp)
- - - -

#### Problem 461
This problem was asked by Facebook.
There is an N by M matrix of zeroes. Given N and M, write a function to count the number of ways of starting at the top-left
corner and getting to the bottom-right corner. You can only move right or down.
For example, given a 2 by 2 matrix, you should return 2, since there are two ways to get to the bottom-right:
* Right, then down
* Down, then right
Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.

[Solution](Day461.cpp)
- - - -

### Problem 465
This problem was asked by Google.

Given the head of a singly linked list, reverse it in-place.

[Solution](Day465.cpp)
- - - -

### Problem 466
This problem was asked by Amazon.

A tree is symmetric if its data and shape remain unchanged when it is reflected about the root node. The following tree is an example:
```
        4
      / | \
    3   5   3
  /           \
9              9
```
Given a k-ary tree, determine whether it is symmetric.
[Solution](Day466.cpp)
- - - -

### Problem 468
This problem was asked by Facebook.

Given an N by N matrix, rotate it by 90 degrees clockwise.

For example, given the following matrix:
```
[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]
```
you should return:
```
[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]
```
Follow-up: What if you couldn't use any extra space?
[Solution](Day468.cpp)
- - - -

### Problem 481
This problem was asked by Jane Street.

Given an arithmetic expression in Reverse Polish Notation, write a program to evaluate it.

The expression is given as a list of numbers and operands. For example: `[5, 3, '+']` should return `5 + 3 = 8`.

For example, `[15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-']` should return 5, since it is equivalent to 
((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5.

You can assume the given expression is always valid.

[Solution](Day481.cpp)
- - - -


### Problem 486
This problem was asked by Pinterest.

At a party, there is a single person who everyone knows, but who does not know anyone in return (the "celebrity"). To help figure out who this is, you have
access to an `O(1)` method called `knows(a, b)`, which returns `True` if person `a` knows person `b`, else `False`.

Given a list of `N` people and the above operation, find a way to identify the celebrity in `O(N)` time.
[Solution](Day486.cpp)
- - - -

### Problem 499
This problem was asked by Palantir.

A typical American-style crossword puzzle grid is an `N x N` matrix with black and white squares, which obeys the following rules:
* Every white square must be part of an "across" word and a "down" word.
* No word can be fewer than three letters long.
* Every white square must be reachable from every other white square.
* The grid is rotationally symmetric (for example, the colors of the top left and bottom right squares must match).

Write a program to determine whether a given matrix qualifies as a crossword grid.

[Solution](Day499.cpp)
- - - -

#### Problem 500
This problem was asked by Google.
You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each
False boolean represents a tile you can walk on.
Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end
coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot
move through walls. You cannot wrap around the edges of the board.
For example, given the following board:
```
[[f, f, f, f],
 [t, t, f, t],
 [f, f, f, f],
 [f, f, f, f]]
```
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.

[Solution](Day500.cpp)
- - - -

### Problem 524
This problem was asked by Amazon.

Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, given the array `[34, -50, 42, 14, -5, 86]`, the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.
Given the array `[-5, -1, -8, -9]`, the maximum sum would be 0, since we would not take any elements.

Do this in O(N) time.

[Solution](Day524.cpp)
- - - -

#### Problem 525
This problem was asked by Amazon.
Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.
For example, given the following matrix:
```
[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]
```
You should print out the following:
```
1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12
```

[Solution](Day525.cpp)
- - - -

### Problem 543
This problem was asked by Google.

Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.
[Solution](Day543.cpp)
- - - -

#### Problem 553
This problem was asked by Google.

You are given an N by M 2D matrix of lowercase letters. Determine the minimum number of columns that can be removed to ensure
that each row is ordered from top to bottom lexicographically. That is, the letter at each column is lexicographically later
as you go down each row. It does not matter whether each row itself is ordered lexicographically.

For example, given the following table:
```
cba
daf
ghi
```
This is not ordered because of the a in the center. We can remove the second column to make it ordered:
```
ca
df
gi
```
So your function should return 1, since we only needed to remove 1 column.
As another example, given the following table:
```
abcdef
```
Your function should return 0, since the rows are already ordered (there's only one row).

As another example, given the following table:
```
zyx
wvu
tsr
```
Your function should return 3, since we would need to remove all the columns to order it.

[Solution](Day553.cpp)
- - - -

#### Problem 585
This question was asked by Google.
<br>Given an N by M matrix consisting only of 1's and 0's, find the largest rectangle containing only 1's and return its area.
<br>For example, given the following matrix:
```
[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]
```
Return 4.

[Solution](Day585.cpp)
- - - -

#### Problem 592
This problem was asked by Amazon.
Given a matrix of 1s and 0s, return the number of "islands" in the matrix. A 1 represents land and 0 represents water, so an
island is a group of 1s that are neighboring and their perimeter is surrounded by water.
For example, this matrix has 4 islands.
```
1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
```

[Solution](Day592.cpp)
- - - -

### Problem 597
This problem was asked by Netflix.

Given an array of integers, determine whether it contains a Pythagorean triplet. Recall that a Pythogorean triplet (a, b, c) is defined by the equation:
`a2+ b2= c2`.
[Solution](Day597.cpp)
- - - -

### Problem 634
This problem was asked by Square.

You are given a histogram consisting of rectangles of different heights. These heights are represented in an input list,
such that `[1, 3, 2, 5]` corresponds to the following diagram:
```
      x
      x  
  x   x
  x x x
x x x x
```
determine the area of the largest rectangle that can be formed only from the bars of the histogram. For the diagram above, for example, this would be six,
representing the `2 x 3` area at the bottom right.

[Solution](Day634.cpp)
- - - -

### Problem 637
This problem was asked by Snapchat.

Given a list of possibly overlapping intervals, return a new list of intervals where all overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)], you should return [(1, 3), (4, 10), (20, 25)].
[Solution](Day637.cpp)
- - - -

#### Problem 645
This problem was asked by Microsoft.
Given a 2D matrix of characters and a target word, write a function that returns whether the word can be found in the matrix
by going left-to-right, or up-to-down.
For example, given the following matrix:
```
[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]
```
and the target word 'FOAM', you should return true, since it's the leftmost column. Similarly, given the target word 'MASS',
you should return true, since it's the last row.

[Solution](Day645.cpp)
- - - -

### Problem 648
This question was asked by Snapchat.

Given the head to a singly linked list, where each node also has a “random” pointer that points to anywhere in the linked list, deep clone the list.
[Solution](Day648.cpp)
- - - -

#### Problem 650
This problem was asked by Google.
<br>Let `M` be an `N` by `N` matrix in which every row and every column is sorted. No two elements of `M` are equal.
<br>Given `i1`, `j1`, `i2`, and `j2`, compute the number of elements of `M` smaller than `M[i1, j1]` and larger than `M[i2, j2]`.

[Solution](Day650.cpp)
- - - -

#### Problem 717
This problem was asked by Facebook.
A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while
ensuring that no two neighboring houses are of the same color.
Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, return the
minimum cost which achieves this goal.

[Solution](Day717.cpp)
- - - -

### Problem 732
This problem was asked by Glassdoor.

An imminent hurricane threatens the coastal town of Codeville. If at most two people can fit in a rescue boat, and the maximum weight limit for a given boat is k, determine how many boats will be needed to save everyone.

For example, given a population with weights `[100, 200, 150, 80]` and a boat limit of `200`, the smallest number of boats required will be three. 

[Solution](Day732.cpp)
- - - -
