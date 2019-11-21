/****************************************************************************************************************************************
This problem was asked by Facebook.
Given a function that generates perfectly random numbers between 1 and k (inclusive), where k is an input, write a function that shuffles
a deck of cards represented as an array using only swaps.
It should run in O(N) time.
Hint: Make sure each one of the 52! permutations of the deck is equally likely.
*****************************************************************************************************************************************/
import random
cards = [i for i in range(1,53)]
print(cards)

for i in range(51,1,-1):
	x = random.randint(1,i-1)
	cards[i],cards[x] = cards[x],cards[i]

print(cards)
