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

```c
// Returns string (heap-allocated) value of specified TicyData.
//
// Special cases are;
//  ticydata_s(data) -> NULL if data is NULL
//  ticydata_s(data) -> NULL if type code is not supported
//  ticydata_s(data) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydata_s(data) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticydata_s(const struct TicyData *data);
```
