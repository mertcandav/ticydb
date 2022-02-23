# TicyDB - Functions

```c
// Returns specified any_t as serialized string (heap-allocated) with i8_t type format.
//
// Special cases are;
//  ticy_his(_Hi) -> NULL if _Hi is NULL
//  ticy_his(_Hi) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_his(_Hi) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_his(const any_t _Hi);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with i16_t, i32_t, bool_t type formats.
//
// Special cases are;
//  ticy_ds(_D) -> NULL if _D is NULL
//  ticy_ds(_D) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_ds(_D) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_ds(const any_t _D);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with i64_t type format.
//
// Special cases are;
//  ticy_lds(_Lld) -> NULL if _Lld is NULL
//  ticy_lds(_Lld) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lds(_Lld) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_llds(const any_t _Lld);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with u8_t type format.
//
// Special cases are;
//  ticy_hus(_Hu) -> NULL if _Hu is NULL
//  ticy_hus(_Hu) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_hus(_Hu) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_hus(const any_t _Hu);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with u16_t, u32_t, sz_t type format.
//
// Special cases are;
//  ticy_us(_U) -> NULL if _U is NULL
//  ticy_us(_U) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_us(_U) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_us(const any_t _U);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with u64_t type format.
//
// Special cases are;
//  ticy_llus(_Llu) -> NULL if _Llu is NULL
//  ticy_llus(_Llu) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_llus(_Llu) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_llus(const any_t _Llu);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with f32_t type format.
//
// Special cases are;
//  ticy_fs(_F) -> NULL if _F is NULL
//  ticy_fs(_F) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_fs(_F) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_fs(const any_t _F);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with f64_t type format.
//
// Special cases are;
//  ticy_lfs(_Lf) -> NULL if _F is NULL
//  ticy_lfs(_Lf) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lfs(_Lf) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_lfs(const any_t _Lf);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with str_t type format.
//
// Special cases are;
//  ticy_lfs(_Lf) -> NULL if _S is NULL
//  ticy_lfs(_Lf) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lfs(_Lf) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_ss(const any_t _S);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with char_t type format.
//
// Special cases are;
//  ticy_lfs(_Lf) -> NULL if _C is NULL
//  ticy_lfs(_Lf) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lfs(_Lf) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_cs(const any_t _C);
```
