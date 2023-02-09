# What is Hashing?

   In computer science, a Hash table or a Hashmap is a type of data structure that maps keys to its value pairs (implement abstract array data types). It basically makes use of a function that computes an index value that in turn holds the elements to be searched, inserted, removed, etc. This makes it easy and fast to access data. In general, hash tables store key-value pairs and the key is generated using a hash function.
  
# What is collision?

  Situation of collision occurs when more than one keys (hash functions) map to the same location of hashes. In this situation, two or more data elements qualify to be mapped to the same location in hash table.
  
# Collision resolution techniques

There are two types of collision resolution techniques.
  1. Separate chaining (open hashing)
  2. Open addressing (closed hashing)
  
# Separate chaining

In this technique, a linked list is created from the slot in which collision has occurred, after which the new key is inserted into the linked list. This linked list of slots looks like a chain, so it is called separate chaining. It is used more when we do not know how many keys to insert or delete.
# Time complexity
  1. Its worst-case complexity for searching is o(n).
  2. Its worst-case complexity for deletion is o(n).

# Advantages of separate chaining
1. It is easy to implement.
2. The hash table never fills full, so we can add more elements to the chain.
3. It is less sensitive to the function of the hashing.

# Disadvantages of separate chaining
1. In this, cache performance of chaining is not good.
2. The memory wastage is too much in this method.
3. It requires more space for element links.
