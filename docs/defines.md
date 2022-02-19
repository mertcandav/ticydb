# TicyDB - Defines

```c
// Version of TicyDB.
#define TICYDB_VERSION
```

```c
// Release channel of TicyDB.
#define TICYDB_CHANNEL
```

```c
// Returns TicyDB data-type name of specified data.
// The return value is str_t and value is directly
// data-type name of specified data.
// Example: ticy_typename(x) -> "u32_t"
//
// Special cases are;
//  ticy_typename(x) -> "u32_t" if x is bool_t
//  ticy_typename(x) -> "u8_t" if x is byte_t
//  ticy_typename(x) -> "i8_t" if x is sbyte_t
//  ticy_typename(x) -> "u32_t" if x is sz_t
#define ticy_typename(x)
```
