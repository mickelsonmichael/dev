# STL Containers

STL Containers are the standard library containers provided in C++ ([MSDN](https://docs.microsoft.com/en-us/cpp/standard-library/stl-containers?view=msvc-160)). There are several implementations with several purposes.

| Name | Value or Key/Value | Insertion | Append | Search | IsOrdered |
| ---- | ------------------ | --------- | ------ | ------ | --------- |
| `string`, `vector` | value | O(n) | O(1) | O(n) | no |
| `list` | value | O(1) | O(1) | O(n) | no|
| `forward_list` | value | O(1) | O(1) | O(n) | no |
| `set` | value | O(log n) | _n/a_ | O(log n) | yes |
| `multiset` | value | O(log n) | _n/a_ | O(log n) | yes |
| `map` | key/value | O(log n) | _n/a_ | O(log n) | yes |
| `multimap` | key/value | O(log n) | _n/a_ | O(log n) | yes |
| `deque` | value | O(n) | O(1) | O(n) | no |
| `unordered_set` | value | O(1) | _n/a_ | O(1) | semi |
| `unordered_multiset` | value | O(1) | _n/a_ | O(1) | semi |
| `unordered_map` | key/value | O(1) | _n/a_ | O(1) | semi |
| `unordered_multimap` | key/value | O(1) | _n/a_ | O(1) | semi |

There are several shared methods that each has, including

- Default constructor
- Copy constructor
- `operator=`
- Constructor taking in an iterator range (`ctor(iter, iter)`)
- `empty()` which returns true/false if the container is empty (or not)
- `size()` which returns the current size of the container
- `max_size()` which returns the maximum size of the container
- `clear()` which removes all elements from the container
- `begin()` gets an iterator at the beginning of the container
- `end()` gets an iterator at the end of the container
- `cbegin()` gets a `const_iterator` at the beginning of the container
- `cend()` gets a `const_iterator` at the end of the container

It is worth noting that `begin` and `end` will return `iterator` usually, but if the container is marked `const` like `const vector<int>`, then they will return `const_iterataor`.

There are some additional methods that are on _many_ of the containers, but not _all_ of them:

- `ctor(n)` which will instantiate a container of size `n`
- `rbegin()` which returns a `reverse_iterator` pointing to the _end_ of the container
- `rend()` which returns a `reverse_iterator` pointing to the _start_ of the container
- `crbegin()` same as `rbegin` but returns a `const_reverse_iterator`
- `crend()` same as `rend` but returns a `const_reverse_iterator`
- `front()` returns the first element in the container
- `back()` returns the last element in the container
- `insert()` inserts an element at a point
- `erase()` removes an element at a point
- `find()` returns an iterator pointing to an element matched by the find method
- `count()` returns the count of the elements

The `reverse_iterators` are the same as iterators except they go in the opposite direction, and while `begin` and `rend` may be similar, they are seperate things (as are `end` and `rbegin`). `begin` points to the first element in the sequence, while `rend` points to the memory location just before the first element.

## Array

There is a difference between a C array and the `std::array` in the STL library, but there is no real difference between the two besides the addition of the standard library methods like `size()` and `begin()`/`end()`.

It is worth noting that there is no two-iterator copy constructor.

C# equivalent is `Array`

## `list`

A doubly-linked list (where each node holds a reference to the previous and next element). It requires more storage because it is storing additional pointers to the other elements, but insertion is very fast. Also, there is never a need for reallocation since the data doesn't have to be adjacent.

## `forward_list`

Used to be called a `slist` and is a singly-linked list where each node contains a reference to the next element. Just like the `list` there is a bit of overhead in storing the extra pointers, but iterating forward is fast.

It is worth noting that there is no `size` method for a `forward_list`

## `deque`

`deque` stands for "*d*ouble-*e*nded *que*ue" and is similar to a vector, but it is easy to push and pop from the front or back.

## `set`

A binary tree implementation (usually) with a large storage overhead but reasonably fast traversal. However, it does not allow duplicates, therefore adding the same value to a set twice will only add one copy of the value.

## `multiset`

The same as a `set` but allows for duplicates.

## `unordered_set`

Previously a `hash_set`, it is the same as a `set` but is ordered based on the hash values.

## `unordered_multiset`

Previously a `hash_multiset`, it is the same as `multiset` but is ordered bas on the hash values.

## `map`

Stores a key-value pair in a binary tree implementation (usually) similarly to a `set`. Similar to the `set`, the `map` will not allow for duplicate *keys* to be inserted (duplicate values are OK).

## `multimap`

Same as a `map` implementation (similar to a `multiset`) but will allow for duplicate keys to be inserted.

## `unordered_map`

Similar to `unordered_set`, this is a hash table implementation based on the hash value of the *keys* (not the values). However, duplicate hashes cannot be inserted.

## `unordered_multimap`

Similar to the `unordered_map` and `multimap`, but this implementation uses the hash value of the *keys* (not the values) and allows for duplicate hashes to be inserted.

