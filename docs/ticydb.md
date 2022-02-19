# TicyDB

## Define
```c
// TicyDB connection instance.
typedef struct TicyDB {
  // This is a path of your TicyDB store file.
  // Don't touch this if you not sure that.
  str_t path;
} TicyDB;
```

## Related Functions

```c
// Returns heap-allocated TicyDB instance.
//
// Special case is;
//  ticydb_new(path) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydb_new(path) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyDB *ticydb_new(const str_t path);
```

```c
// Frees heap-allocated TicyDB instance.
void ticydb_free(struct TicyDB *db);
```