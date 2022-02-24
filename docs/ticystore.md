# TicyDB - TicyStore

## Define

```c
// Key-Value store of TicyDB.
// Don't touch fields if you not sure that.
typedef struct TicyStore {
  // Keys of store, stores any_t type.
  // Don't change if you not sure that.
  struct TicyList *_keys;
  // Values of keys, stores TicyData* type.
  // Don't change if you not sure that.
  struct TicyList *_values;
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
void ticystore_free(struct TicyStore *_Ticys);
```

```c
// Set value o specified key.
// Creates a new key-value node if key is not exist.
// Returns true if created a new key-value node, returns false if not.
//
// Special cases are;
//  ticystore_set(_Ticys, _Key, _Value) -> F if key is can't pushed
//  ticystore_set(_Ticys, _Key, _Value) -> F if value is can't pushed
//  ticystore_set(_Ticys, _Key, _Value) -> F if store is NULL
const bool_t ticystore_set(struct TicyStore *_Ticys,
                           const TicyData *_Key,
                           const TicyData *_Value);
```

```c
// Returns value o specified key value.
//
// Special case is;
//  ticystore_get(_Ticys, _Key) -> NULL if store is NULL
//  ticystore_get(_Ticys, _Key) -> NULL if key is not exist
const TicyData *ticystore_get(const struct TicyStore *_Ticys, const any_t *_Key);
```

```c
// Reports specified TicyStore is have any key-value node or not.
//
// Special case is;
//  ticystore_any(_Ticys) -> F if store is NULL
const bool_t ticystore_any(const struct TicyStore *_Ticys);
```

```c
// Returns index of key value if key value is exist, returns -1 if not in specified TicyStore.
//
// Special case is;
//  ticystore_existk(_Ticys, _Key) -> -1 if store is NULL
const sz_t ticystore_findk(const struct TicyStore *_Ticys, const any_t *_Key);
```

```c
// Returns index of key of value if value is exist, returns -1 if not in specified TicyStore.
//
// Special case is;
//  ticystore_existk(_Ticys, _Key) -> -1 if store is NULL
const sz_t ticystore_findv(const struct TicyStore *_Ticys,
                           const any_t _Value);
```

```c
// Returns serialize TicyStore as string (heap-allocated).
//
// Special cases are;
//  ticystore_serialize(_Ticys) -> NULL if store is NULL
//  ticystore_serialize(_Ticys) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticystore_serialize(_Ticys) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticystore_serialize(const struct TicyStore *_Ticys);
```

```c
// Returns deserialized TicyStore by specified serialized string.
//
// Special cases are;
//  ticystore_deserialize(_Str) -> Empty TicyStore if _Str is NULL
//  ticystore_deserialize(_Str) -> NULL if any parse error
//  ticystore_deserialize(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticystore_deserialize(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyStore *ticystore_deserialize(const str_t _Str);
```
