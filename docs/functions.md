# TicyDB - Functions

```c
// Returns string (heap-allocated) value of i8_t.
//
// Special cases are;
//  ticy_i8s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_i8s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_i8s(const i8_t hi);
```

```c
// Returns string (heap-allocated) value of i16_t.
//
// Special cases are;
//  ticy_i16s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_i16s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_i16s(const i16_t d);
```

```c
// Returns string (heap-allocated) value of i32_t.
//
// Special cases are;
//  ticy_i32s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_i32s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_i32s(const i32_t d);
```

```c
// Returns string (heap-allocated) value of i64_t.
//
// Special cases are;
//  ticy_i64s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_i64s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_i64s(const i64_t lld);
```

```c
// Returns string (heap-allocated) value of u8_t.
//
// Special cases are;
//  ticy_u8s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_u8s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_u8s(const u8_t hu);
```

```c
// Returns string (heap-allocated) value of u16_t.
//
// Special cases are;
//  ticy_u16s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_u16s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_u16s(const u16_t u);
```

```c
// Returns string (heap-allocated) value of u32_t.
//
// Special cases are;
//  ticy_u32s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_u32s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_u32s(const u32_t u);
```

```c
// Returns string (heap-allocated) value of u64_t.
//
// Special cases are;
//  ticy_u64s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_u64s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_u64s(const u64_t llu);
```

```c
// Returns string (heap-allocated) value of f32_t.
//
// Special cases are;
//  ticy_f32s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_f32s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_f32s(const f32_t f);
```

```c
// Returns string (heap-allocated) value of f64_t.
//
// Special cases are;
//  ticy_f64s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_f64s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_f64s(const f64_t lf);
```

```c
// Returns string (heap-allocated) value of char_t.
//
// Special cases are;
//  ticy_cs(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_cs(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_cs(const char_t c);
```

```c
// Returns string (heap-allocated) value of bool_t.
//
// Special cases are;
//  ticy_bs(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_bs(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_bs(const bool_t d);
```

```c
// Returns string (heap-allocated) value of sz_t.
//
// Special cases are;
//  ticy_szs(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_szs(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_szs(const sz_t zu);
```
