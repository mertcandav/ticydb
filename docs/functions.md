# TicyDB - Functions

```c
// Returns specified any_t as string (heap-allocated) with i8_t type format.
//
// Special cases are;
//  ticy_i8s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_i8s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_his(const any_t hi);
```

```c
// Returns specified any_t as string (heap-allocated) with i16_t, i32_t, bool_t type formats.
//
// Special cases are;
//  ticy_ds(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_ds(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_ds(const any_t d);
```

```c
// Returns specified any_t as string (heap-allocated) with i64_t type format.
//
// Special cases are;
//  ticy_i64s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_i64s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_llds(const any_t lld);
```

```c
// Returns specified any_t as string (heap-allocated) with u8_t type format.
//
// Special cases are;
//  ticy_u8s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_u8s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_hus(const any_t hu);
```

```c
// Returns specified any_t as string (heap-allocated) with u16_t, u32_t type format.
//
// Special cases are;
//  ticy_u16s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_u16s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_us(const any_t u);
```

```c
// Returns specified any_t as string (heap-allocated) with u64_t type format.
//
// Special cases are;
//  ticy_u64s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_u64s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_llus(const any_t llu);
```

```c
// Returns specified any_t as string (heap-allocated) with f32_t type format.
//
// Special cases are;
//  ticy_f32s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_f32s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_fs(const any_t f);
```

```c
// Returns specified any_t as string (heap-allocated) with f64_t type format.
//
// Special cases are;
//  ticy_f64s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_f64s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_lfs(const any_t lf);
```

```c
// Returns specified any_t as string (heap-allocated) with char_t type format.
//
// Special cases are;
//  ticy_cs(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_cs(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_cs(const any_t c);
```

```c
// Returns specified any_t as string (heap-allocated) with sz_t type format.
//
// Special cases are;
//  ticy_szs(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_szs(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_zus(const any_t zu);
```
