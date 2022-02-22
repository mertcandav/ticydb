# TicyDB - TicyList

## Define
```c
// Dynamic list implementation of TicyDB.
typedef struct TicyList {
  // Element buffer.
  // Don't change if you not sure that.
  any_t *_buffer;
  // Allocated element count.
  // Don't change if you not sure that.
  sz_t  _used;
  // Total element count.
  // Don't change if you not sure that.
  sz_t  _size;
} TicyList;
```

## Related Functions
```c
// Returns new TicyList instance heap-allocated by specified size.
//
// Special case is:
//  ticylist_new(_Size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticylist_new(_Size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
//  ticylist_new(_Size) -> accept size as 1 if size < 1
struct TicyList *ticylist_new(sz_t _Size);
```

```c
// Frees TicyList instance allocated from heap.
void ticylist_free(struct TicyList *_Ticyl);
```

```c
// Appends item to TicyList.
// Returns true if success, returns false if failed.
//
// Special case is;
//  ticylist_push(_Ticyl, _Item) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const bool_t ticylist_push(struct TicyList *_Ticyl, const any_t _Item);
```

```c
// Removes n elements starts at specified index.
// If n greater than size, uses size instead of n.
// Returns true if success, returns false is not.
//
// Special cases are:
//  ticylist_remrange(_Ticyl, _Start, _Count) -> F if n < 1
//  ticylist_remrange(_Ticyl, _Start, _Count) -> F if start < 0
//  ticylist_remrange(_Ticyl, _Start, _Count) -> F if start > size
//  ticylist_remrange(_Ticyl, _Start, _Count) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const bool_t ticylist_remrange(struct TicyList* _Ticyl,
                               const sz_t _Start,
                               sz_t _Count);
```

```c
// Returns new TicyList from source list by specified index and n.
// If n greater than size, uses size instead of n.
//
// Special cases are:
//  ticylist_slice(_Ticyl, _Start, _Count) -> NULL if failed
//  ticylist_slice(_Ticyl, _Start, _Count) -> NULL if list == NULL
//  ticylist_slice(_Ticyl, _Start, _Count) -> NULL if n < 1
//  ticylist_slice(_Ticyl, _Start, _Count) -> NULL if start < 0
//  ticylist_slice(_Ticyl, _Start, _Count) -> NULL if start > size
//  ticylist_slice(_Ticyl, _Start, _Count) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyList *ticylist_slice(const struct TicyList *_List,
                                sz_t _Start,
                                sz_t _Count);
```
