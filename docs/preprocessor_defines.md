# TicyDB - Preprocessor Defines

```c
// Version of TicyDB.
#define TICYDB_VERSION
```

```c
// Release channel of TicyDB.
#define TICYDB_CHANNEL
```

```c
// Returns TicyDB data-type code of specified data.
// The return value is TicyTypeCode.
// Example: ticy_typename(x) -> U32_T
//
// Special cases are;
//  ticy_typename(x) -> U32_T if x is bool_t
//  ticy_typename(x) -> U8_T if x is byte_t
//  ticy_typename(x) -> I8_T if x is sbyte_t
//  ticy_typename(x) -> U32_T if x is sz_t
#define ticy_typename(x)
```
