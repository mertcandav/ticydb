# TicyDB - TicyList

Dynamic list implementation of TicyDB.

## Fields
+ ``any_t *buffer`` <br>
  Element buffer.
+ ``sz_t used`` <br>
  Allocated element count.
+ ``sz_t size`` <br>
  Total element count.

## Related Functions
```c
// Create new TicyList instance allocated from heap by specified size.
//
// Special case is:
//  ticylist_new(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticylist_new(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
//  ticylist_new(size) -> accept size as 1 if size < 1
struct TicyList *ticylist_new(sz_t size);
```

# 

```c
// Free TicyList instance allocated from heap.
void ticylist_free(struct TicyList *list);
```

# 

```c
// Appends item to TicyList.
// Returns true if success, returns false if failed.
//
// Special case is;
//  ticylist_push(list, item) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
bool_t ticylist_push(struct TicyList *list, any_t item);
```

# 

```c
// Removes n elements starts at specified index.
// If n greater than size, uses size instead of n.
// Returns true if success, returns false is not.
//
// Special cases are:
//  ticylist_remrange(list, start, n) -> F if n < 1
//  ticylist_remrange(list, start, n) -> F if start < 0
//  ticylist_remrange(list, start, n) -> F if start > size
//  ticylist_remrange(list, start, n) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
bool_t ticylist_remrange(struct TicyList* list, const sz_t start, sz_t n);
```

# 

```c
// Returns new TicyList from source list by specified index and n.
// If n greater than size, uses size instead of n.
//
// Special cases are:
//  ticylist_slice(list, start, n) -> NULL if failed
//  ticylist_slice(list, start, n) -> NULL if list == NULL
//  ticylist_slice(list, start, n) -> NULL if n < 1
//  ticylist_slice(list, start, n) -> NULL if start < 0
//  ticylist_slice(list, start, n) -> NULL if start > size
//  ticylist_slice(list, start, n) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyList *ticylist_slice(struct TicyList *list, sz_t start, sz_t n);
```
