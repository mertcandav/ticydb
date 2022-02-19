# TicyDB - enums

```c
// Ticy data-type codes.
enum TicyTypeCode {
  I8_T         = 0,  // Signed 8-bit integer type code.
  I16_T        = 1,  // Signed 16-bit integer type code.
  I32_T        = 2,  // Signed 32-bit integer type code.
  I64_T        = 3,  // Signed 64-bit integer type code.
  U8_T         = 4,  // Unsigned 8-bit integer type code.
  U16_T        = 5,  // Unsigned 16-bit integer type code.
  U32_T        = 6,  // Unsigned 32-bit integer type code.
  U64_T        = 7,  // Unsigned 64-bit integer type code.
  F32_T        = 8,  // 32-bit float type code.
  F64_T        = 9,  // 64-bit float type code.
  CHAR_T       = 10, // Character type code.
  STR_T        = 11, // String type code.
  ANY_T        = 12, // Any type code.
  TICYLIST     = 13, // TicyList instance code.
  TICYLIST_PTR = 14, // TicyList instance pointer code.
  OTHER_T      = 15  // Code of other data-types.
};
```
