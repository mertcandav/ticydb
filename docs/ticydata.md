# TicyDB - TicyData

## Define

```c
// Data representation of TicyDB.
typedef struct TicyData {
  // Type code of data.
  // This type code is important because
  // TicyDB process datas by this type code.
  TicyTypeCode _type;
  // Data.
  // If you change here, you must chage the "type" field for success operations.
  any_t        _data;
} TicyData;
```

## Related Functions

```c
// Returns new TicyData instance heap-allocated by data and type code.
//
// Special case is:
//  ticydata_new(_Data, _Ticytc) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydata_new(_Data, _Ticytc) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyData *ticydata_new(const any_t _Data, const TicyTypeCode _Ticytc);
```

```c
// Frees TicyData instance allocated from heap.
// This is not frees data.
void ticydata_free(struct TicyData *_Ticyd);
```

```c
// Returns serialized string (heap-allocated) value of specified TicyData.
//
// Special cases are;
//  ticydata_serialize(_Ticyd) -> "" if data is NULL
//  ticydata_serialize(_Ticyd) -> "" if type code is not supported
//  ticydata_serialize(_Ticyd) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydata_serialize(_Ticyd) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticydata_serialize(const struct TicyData *_Ticyd);
```

```c
// Returns deserialized TicyData by specified serialized string.
//
// Special cases are;
//  ticydata_deserialize(_Str) -> TicyData{_data: NULL, _type: OTHER_T} if _Str is NULL
//  ticydata_deserialize(_Str) -> TicyData{_data: NULL, _type: OTHER_T} if _Str length is 0
//  ticydata_deserialize(_Str) -> TicyData{_data: NULL, _type: OTHER_T} if any parse error
//  ticydata_deserialize(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydata_deserialize(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const TicyData *ticydata_deserialize(const str_t _Str);
```
