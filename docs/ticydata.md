# TicyDB - TicyData

## Define

```c
// Data representation of TicyDB.
typedef struct TicyData {
  // Type code of data.
  // This type code is important because
  // TicyDB process datas by this type code.
  TicyTypeCode type;
  // Data.
  any_t        data;
} TicyData;
```

## Related Functions

```c
// Returns new TicyData instance heap-allocated by data and type code.
//
// Special case is:
//  ticydata_new(void) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydata_new(void) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyData *ticydata_new(const any_t data, const TicyTypeCode type);
```

```c
// Frees TicyData instance allocated from heap.
// This is not frees data.
void ticydata_free(struct TicyData *data);
```
