# TicyDB - Functions

```c
// Returns specified any_t as serialized string (heap-allocated) with i8_t type format.
//
// Special cases are;
//  ticy_his(_Hi) -> default if _Hi is NULL
//  ticy_his(_Hi) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_his(_Hi) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_his(const any_t _Hi);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with i16_t, i32_t, bool_t type formats.
//
// Special cases are;
//  ticy_ds(_D) -> default if _D is NULL
//  ticy_ds(_D) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_ds(_D) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_ds(const any_t _D);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with i64_t type format.
//
// Special cases are;
//  ticy_lds(_Lld) -> default if _Lld is NULL
//  ticy_lds(_Lld) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lds(_Lld) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_llds(const any_t _Lld);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with u8_t type format.
//
// Special cases are;
//  ticy_hus(_Hu) -> default if _Hu is NULL
//  ticy_hus(_Hu) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_hus(_Hu) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_hus(const any_t _Hu);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with u16_t, u32_t, sz_t type format.
//
// Special cases are;
//  ticy_us(_U) -> default if _U is NULL
//  ticy_us(_U) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_us(_U) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_us(const any_t _U);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with u64_t type format.
//
// Special cases are;
//  ticy_llus(_Llu) -> default if _Llu is NULL
//  ticy_llus(_Llu) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_llus(_Llu) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_llus(const any_t _Llu);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with f32_t type format.
//
// Special cases are;
//  ticy_fs(_F) -> default if _F is NULL
//  ticy_fs(_F) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_fs(_F) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_fs(const any_t _F);
```

```c
// Returns specified any_t as serialized string (heap-allocated) with f64_t type format.
//
// Special cases are;
//  ticy_lfs(_Lf) -> default if _F is NULL
//  ticy_lfs(_Lf) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lfs(_Lf) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_lfs(const any_t _Lf);
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

```c
// Returns specified any_t as serialized string (heap-allocated) with str_t type format.
//
// Special cases are;
//  ticy_lfs(_Lf) -> default if _S is NULL
//  ticy_lfs(_Lf) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lfs(_Lf) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_ss(const any_t _S);
```

```c
// Returns deserialized i8_t from specified serialized string.
//
// Special case is;
//  ticy_hids(_Str) -> NULL if _Str is NULL
//  ticy_hids(_Str) -> NULL if _Str length is 0
//  ticy_hids(_Str) -> NULL if any parse error
//  ticy_hids(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_hids(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_hids(const str_t _Str);
```

```c
// Returns deserialized i16_t, i32_t, bool_t from specified serialized string.
//
// Special case is;
//  ticy_dds(_Str) -> NULL if _Str is NULL
//  ticy_dds(_Str) -> NULL if _Str length is 0
//  ticy_dds(_Str) -> NULL if any parse error
//  ticy_dds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_dds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_dds(const str_t _Str);
```

```c
// Returns deserialized i64_t (heap-allocated) from specified serialized string.
//
// Special case is;
//  ticy_lldds(_Str) -> NULL if _Str is NULL
//  ticy_lldds(_Str) -> NULL if _Str length is 0
//  ticy_lldds(_Str) -> NULL if any parse error
//  ticy_lldds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lldds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_lldds(const str_t _Str);
```

```c
// Returns deserialized u8_t from specified serialized string.
//
// Special case is;
//  ticy_huds(_Str) -> NULL if _Str is NULL
//  ticy_huds(_Str) -> NULL if _Str length is 0
//  ticy_huds(_Str) -> NULL if any parse error
//  ticy_huds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_huds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_huds(const str_t _Str);
```

```c
// Returns deserialized u16_t, u32_t, sz_t from specified serialized string.
//
// Special case is;
//  ticy_uds(_Str) -> NULL if _Str is NULL
//  ticy_uds(_Str) -> NULL if _Str length is 0
//  ticy_uds(_Str) -> NULL if any parse error
//  ticy_uds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_uds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_uds(const str_t _Str);
```

```c
// Returns deserialized u64_t (heap-allocated) from specified serialized string.
//
// Special case is;
//  ticy_lluds(_Str) -> NULL if _Str is NULL
//  ticy_lluds(_Str) -> NULL if _Str length is 0
//  ticy_lluds(_Str) -> NULL if any parse error
//  ticy_lluds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lluds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_lluds(const str_t _Str);
```

```c
// Returns deserialized f32_t (heap-allocated) from specified serialized string.
//
// Special case is;
//  ticy_fds(_Str) -> NULL if _Str is NULL
//  ticy_fds(_Str) -> NULL if _Str length is 0
//  ticy_fds(_Str) -> NULL if any parse error
//  ticy_fds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_fds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_fds(const str_t _Str);
```

```c
// Returns deserialized f64_t (heap-allocated) from specified serialized string.
//
// Special case is;
//  ticy_lfds(_Str) -> NULL if _Str is NULL
//  ticy_lfds(_Str) -> NULL if _Str length is 0
//  ticy_lfds(_Str) -> NULL if any parse error
//  ticy_lfds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lfds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_lfds(const str_t _Str);
```

```c
// Returns deserialized str_t (heap-allocated) from specified serialized string.
//
// Special case is;
//  ticy_sds(_Str) -> NULL if _Str is NULL
//  ticy_sds(_Str) -> NULL if _Str length is 0
//  ticy_sds(_Str) -> NULL if any parse error
//  ticy_sds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_sds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_sds(const str_t _Str);
```

```c
// Returns deserialized char_t from specified serialized string.
//
// Special case is;
//  ticy_cds(_Str) -> NULL if _Str is NULL
//  ticy_cds(_Str) -> NULL if _Str length is 0
//  ticy_cds(_Str) -> NULL if any parse error
//  ticy_cds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_cds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_cds(const str_t _Str);
```
