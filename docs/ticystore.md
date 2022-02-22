# TicyDB - TicyStore

## Define

```c
// Key-Value store of TicyDB.
// Don't touch fields if you not sure that.
typedef struct TicyStore {
  // Keys of store, stores any_t type.
  struct TicyList *keys;
  // Values of keys, stores TicyData* type.
  struct TicyList *values;
} TicyStore;
```

## Related Functions

```c
// Returns heap-allocated TicyStore instance.
//
// Special case is;
//  ticystore_new(void) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticystore_new(void) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyStore *ticystore_new(void);
```

```c
// Frees heap-allocated TicyStore instance.
// It's frees key and value lists but not frees these elements.
void ticystore_free(struct TicyStore *store);
```

```c
// Set value o specified key.
// Creates a new key-value node if key is not exist.
// Returns true if created a new key-value node, returns false if not.
//
// Special cases are;
//  ticystore_set(store, key, value) -> F if key is can't pushed
//  ticystore_set(store, key, value) -> F if value is can't pushed
//  ticystore_set(store, key, value) -> F if store is NULL
const bool_t ticystore_set(struct TicyStore *store, const TicyData *key, const TicyData *value);
```

```c
// Returns value o specified key value.
//
// Special case is;
//  ticystore_get(store, key) -> NULL if store is NULL
//  ticystore_get(store, key) -> NULL if key is not exist
const TicyData *ticystore_get(const struct TicyStore *store, const any_t *key);
```

```c
// Reports specified TicyStore is have any key-value node or not.
//
// Special case is;
//  ticystore_any(store) -> F if store is NULL
const bool_t ticystore_any(const struct TicyStore *store);
```

```c
// Returns index of key value if key value is exist, returns -1 if not in specified TicyStore.
//
// Special case is;
//  ticystore_existk(store, key) -> -1 if store is NULL
const sz_t ticystore_findk(const struct TicyStore *store, const any_t *key);
```

```c
// Returns index of key if value is exist, returns -1 if not in specified TicyStore.
//
// Special case is;
//  ticystore_existk(store, key) -> -1 if store is NULL
const sz_t ticystore_findv(const struct TicyStore *store, const TicyData *value);
```

```c
// Returns serialize TicyStore as string (heap-allocated).
//
// Special cases are;
//  ticystore_serialize(store) -> NULL if store is NULL
//  ticystore_serialize(store) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticystore_serialize(store) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticystore_serialize(const struct TicyStore *store);
```
