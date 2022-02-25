# TicyDB

## Define
```c
// TicyDB connection instance.
typedef struct TicyDB {
  // Content of TicyDB.
  struct TicyStore *_Store;
  // This is a path of your TicyDB store file.
  // Don't touch this if you not sure that.
  str_t _path;
} TicyDB;
```

## Related Functions

```c
// Returns heap-allocated TicyDB instance by specified path.
//
// Special case is;
//  ticydb_new(_Path) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydb_new(_Path) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyDB *ticydb_open(const str_t _Path);
```

```c
// Frees and closes heap-allocated TicyDB instance.
void ticydb_close(struct TicyDB *_Ticydb);
```

```c
// Save TicyDB content to local disk storage.
// Returns true if keeping success, returns false if not.
//
// Special cases are;
//  ticydb_keep(_Ticydb) -> false if _Ticydb is NULL
//  ticydb_keep(_Ticydb) -> false if _Ticydb->_Store is NULL
//  ticydb_keep(_Ticydb) -> false if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydb_keep(_Ticydb) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const bool_t ticydb_keep(const struct TicyDB *_Ticydb);
```
