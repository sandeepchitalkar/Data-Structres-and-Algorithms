# Open addressing

Open addressing is collision-resolution method that is used to control the collision in the hashing table. There is no key stored outside of the hash table. Therefore, the size of the hash table is always greater than or equal to the number of keys. It is also called closed hashing.

The following techniques are used in open addressing:
1. Linear probing
2. Quadratic probing
3. Double hashing

# Linear probing

In this, when the collision occurs, we perform a linear probe for the next slot, and this probing is performed until an empty slot is found. In linear probing, the worst time to search for an element is O(table size). The linear probing gives the best performance of the cache but its problem is clustering. 

If the computed index is hash(x) and the table size is n,
index = hash(x) % n

In the case of a collision,
index = (hash(x) + i) % n

Here, i is the number of times a collision occurs or the number of times a value needs to be rehashed. It means, after calculating the index if a collision occurs then i = 1; if the cell is not available the first time then i = 2, and so on.

# Advantage of this technique is that it can be easily calculated.
# Disadvantages of linear probing
1. The main problem is clustering.
2. It takes too much time to find an empty slot.

# Quadratic probing

A quadratic probing approach is taken to resolve the primary clustering problem that occurs in the linear probing method. This technique performs a quadratic or square-shaped search in the occurrence of a collision. Therefore, a larger gap is created during the search process of finding an element or an empty slot.

Again, if the computed index is hash(x) and the table size is n,
index = hash(x) % n

In the case of a collision,
index = (hash(x) + i^2) % n

Here as well, i indicates the number of attempts taken to find the slot or value. If the calculated index is found to be not available, i = 1 and after the second attempt fails then, i = 2. In this method, the probing is no longer sequential rather the intervals become greater than linear probing.


# Double hashing

This method is considered one of the best approaches for hashing. Clustering can be avoided in this technique by using two hash functions. These hash functions are also used for handling collisions. The first function calculates the primary location for a value and the second function calculates the probing gap to find an alternative location for a value.

If computed index is hash1(x) and size of the interval is hash2(x),

hash1(x) = x % n

hash2(x) = (n-1) - (x % n)
Therefore,

index = (hash1(x) + (i * hash2(x))) % n

Here, x is the value that needs an index, n is the table size which should be a prime number, and i is the number of times a collision occurred. The (n-1) in the hash2(x) function can be any number smaller than the table size. The probing here happens rather randomly, maintaining a consistent manner throughout the hash table.

# Advantages of Open Addressing
1. Open addressing improves cache speed because all the data is stored within the hash table
2. It properly uses its empty indexes and improves memory efficiency
3. As there is no linked list or pointer involved, the performance is faster than chaining or open hashing.
