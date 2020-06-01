/******************************************************************************************************************************
This problem was asked by Two Sigma.

Given two sorted iterators, merge it into one iterator.

For example, given these two iterators:

foo = iter([5, 10, 15])
bar = iter([3, 8, 9])
You should be able to do:

for num in merge_iterators(foo, bar):
    print(num)

# 3
# 5
# 8
# 9
# 10
# 15
Bonus: Make it work without pulling in the contents of the iterators in memory.
******************************************************************************************************************************/

class ExtendedIter:
    """An extended iterator that wraps around an existing iterators.
    It provides extra methods:

        has_next(): checks if we can still yield items.

        peek(): returns the next element of our iterator, but doesn't
                pass by it."""
    def __init__(self, i):
        self._myiter = iter(i)
        self._next_element = None
        self._has_next = 0
        self._prime()


    def has_next(self):
        """Returns true if we can call next() without raising a
        StopException."""
        return self._has_next


    def peek(self):
        """Nonexhaustively returns the next element in our iterator."""
        assert self.has_next()
        return self._next_element


    def next(self):
        """Returns the next element in our iterator."""
        if not self._has_next:
            raise StopIteration
        result = self._next_element
        self._prime()
        return result


    def _prime(self):
        """Private function to initialize the states of
        self._next_element and self._has_next.  We poke our
        self._myiter to see if it's still alive and kicking."""
        try:
            self._next_element = next(self._myiter)
            self._has_next = 1
        except StopIteration:
            self.next_element = None
            self._has_next = 0


class merge_iterators:
    def __init__(self,i1,i2):
        self.max = max
        self.left = ExtendedIter(i1)
        self.right = ExtendedIter(i2)

    def __iter__(self):
        self.a = 0
        self.b = 1
        return self

    def __next__(self):
        if not self.left.has_next():
            return self.right.next()
        if not self.right.has_next():
            return self.left.next()
        if self.left.peek() <self.right.peek():
            return self.left.next()
        else:
            return self.right.next()

foo = iter([5, 10, 15])
bar = iter([3, 8, 9])

for num in merge_iterators(foo, bar):
    print(num)
