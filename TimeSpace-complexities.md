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
