## Time & Space complexities

### Binary search:

Requires sorted array, O(logn) time algo

---

### Trie data structure :

Consider we have list of n words with average word length Lavg.

- **Prefix trie** :
  trie build time = O(n\*Lavg), space required depends on actual words > O(all unique characters) <br/>
  Operations on trie -

  - Insert - O(k)
  - Delete - O(k)
  - Search - O(k)

- **Suffix trie** :
  Let's say we have a string of length D for which we want to create a suffix trie. <br/>
  trie build time = O(D^2)

  Operations on trie -

  - Insert - O(k)
  - Delete - O(k)
  - Search - O(k)

Deque and list offer similar operation capabilities like-
push_back, push_front, pop_back, pop_front, front, back etc

however-
A deque is very much like a vector, it is a sequence that supports random access to elements, constant time insertion and removal of elements at the end of the sequence, and linear time insertion and removal of elements in the middle.
The main way in which deque differs from vector is that deque also supports constant time insertion and removal of elements at the beginning of the sequence. Additionally, deque does not have any member functions analogous to vector's capacity() and reserve(), and does not provide any of the guarantees on iterator validity that are associated with those member functions.

list doesn't allow random access of elements
list insert, emplace operations are faster compared to deque
A list is a doubly linked list. That is, it is a Sequence that supports both forward and backward traversal, and (amortized) constant time insertion and removal of elements at the beginning or the end, or in the middle. Lists have the important property that insertion and splicing do not invalidate iterators to list elements, and that even removal invalidates only the iterators that point to the elements that are removed. The ordering of iterators may be changed (that is, list::iterator might have a different predecessor or successor after a list operation than it did before), but the iterators themselves will not be invalidated or made to point to different elements unless that invalidation or mutation is explicit.
