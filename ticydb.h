// BSD 3-Clause License
//
// Copyright (c) 2022, Mertcan Davulcu
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef __TICYDB_H
#define __TICYDB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

// Version of TicyDB.
#define TICY_VERSION "0.0.1"
// Release channel of TicyDB.
#define TICY_CHANNEL "preview"

typedef   enum bool_t {F = 0, T = !F}   bool_t    ; // Boolean type.
typedef   __INT8_TYPE__                 i8_t      ; // Signed 8-bit integer type.
typedef   __INT16_TYPE__                i16_t     ; // Signed 16-bit integer type.
typedef   __INT32_TYPE__                i32_t     ; // Signed 32-bit integer type.
typedef   __INT64_TYPE__                i64_t     ; // Signed 64-bit integer type.
typedef   __UINT8_TYPE__                u8_t      ; // Unsigned 8-bit integer type.
typedef   __UINT16_TYPE__               u16_t     ; // Unsigned 16-bit integer type.
typedef   __UINT32_TYPE__               u32_t     ; // Unsigned 32-bit integer type.
typedef   __UINT64_TYPE__               u64_t     ; // Unsigned 64-bit integer type.
typedef   unsigned char                 byte_t    ; // Byte integer type.
typedef   signed char                   sbyte_t   ; // SByte integer type.
typedef   float                         f32_t     ; // 32-bit float type.
typedef   double                        f64_t     ; // 64-bit float type.
typedef   char                          char_t;   ; // Character type.
typedef   char_t                        *str_t    ; // String type.
typedef   void                          *any_t    ; // Any type for any data.
typedef   size_t                        sz_t      ; // Size type.

// Ticy data-type codes.
typedef enum TicyTypeCode {
  SBYTE_T      = 0,  // SByte data type code.
  I8_T         = 0,  // Signed 8-bit integer type code.
  I16_T        = 1,  // Signed 16-bit integer type code.
  I32_T        = 2,  // Signed 32-bit integer type code.
  I64_T        = 3,  // Signed 64-bit integer type code.
  BYTE_T       = 4,  // Byte data type code.
  U8_T         = 4,  // Unsigned 8-bit integer type code.
  U16_T        = 5,  // Unsigned 16-bit integer type code.
  BOOL_T       = 6,  // Boolean type code.
  U32_T        = 6,  // Unsigned 32-bit integer type code.
  U64_T        = 7,  // Unsigned 64-bit integer type code.
  F32_T        = 8,  // 32-bit float type code.
  F64_T        = 9,  // 64-bit float type code.
  CHAR_T       = 10, // Character type code.
  STR_T        = 11, // String type code.
  ANY_T        = 12, // Any type code.
  TICYLIST_PTR = 13, // TicyList instance pointer code.
  SZ_T         = 14, // Size type code.
  OTHER_T      = 15  // Code of other data-types.
} TicyTypeCode;

#ifdef TICY_FAILURE_ALLOC
// Exit code of TicyDB for failures.
volatile i32_t Ticy_Exit_Code_Failure = EXIT_FAILURE;

// Error message of allocation failures.
#define TICY_ERROR_FAIL_ALLOC "allocation is failed"
#endif // #ifdef TICY_FAILURE_ALLOC

// Buffer size of various operations of TicyDB.
volatile sz_t Ticy_Buffer_Size = 128;

// TicyDB format of %hi
#define TICY_FMT_HI "%hi"
// TicyDB format of %d
#define TICY_FMT_D "%d"
// TicyDB format of %lld
#define TICY_FMT_LLD "%lld"
// TicyDB format of %hu
#define TICY_FMT_HU "%hu"
// TicyDB format of %u
#define TICY_FMT_U "%u"
// TicyDB format of %llu
#define TICY_FMT_LLU "%llu"
// TicyDB format of %f
#define TICY_FMT_F "%f"
// TicyDB format of %lf
#define TICY_FMT_LF "%lf"
// TicyDB format of %s
#define TICY_FMT_S "\"%s\""
// TicyDB format of %c
#define TICY_FMT_C "'%c'"

// Returns true if _Str is starts with _Sub, returns false if not.
const bool_t strprefix(const str_t _Str, const str_t _Sub);

// Dynamic list implementation of TicyDB.
typedef struct TicyList {
  // Element buffer.
  // Don't change if you not sure that.
  any_t *_buffer;
  // Allocated element count.
  // Don't change if you not sure that.
  sz_t  _used;
  // Total element count.
  // Don't change if you not sure that.
  sz_t  _size;
} TicyList;

// Returns new TicyList instance heap-allocated by specified size.
//
// Special case is:
//  ticylist_new(_Size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticylist_new(_Size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
//  ticylist_new(_Size) -> accept size as 1 if size < 1
struct TicyList *ticylist_new(sz_t _Size);
// Frees TicyList instance allocated from heap.
void ticylist_free(struct TicyList *_Ticyl);
// Appends item to TicyList.
// Returns true if success, returns false if failed.
//
// Special case is;
//  ticylist_push(_Ticyl, _Item) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const bool_t ticylist_push(struct TicyList *_Ticyl, const any_t _Item);
// Removes n elements starts at specified index.
// If n greater than size, uses size instead of n.
// Returns true if success, returns false is not.
//
// Special cases are:
//  ticylist_remrange(_Ticyl, _Start, _Count) -> F if n < 1
//  ticylist_remrange(_Ticyl, _Start, _Count) -> F if start < 0
//  ticylist_remrange(_Ticyl, _Start, _Count) -> F if start > size
//  ticylist_remrange(_Ticyl, _Start, _Count) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const bool_t ticylist_remrange(struct TicyList* _Ticyl,
                               const sz_t _Start,
                               sz_t _Count);
// Returns new TicyList from source list by specified index and n.
// If n greater than size, uses size instead of n.
//
// Special cases are:
//  ticylist_slice(_Ticyl, _Start, _Count) -> NULL if failed
//  ticylist_slice(_Ticyl, _Start, _Count) -> NULL if list == NULL
//  ticylist_slice(_Ticyl, _Start, _Count) -> NULL if n < 1
//  ticylist_slice(_Ticyl, _Start, _Count) -> NULL if start < 0
//  ticylist_slice(_Ticyl, _Start, _Count) -> NULL if start > size
//  ticylist_slice(_Ticyl, _Start, _Count) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyList *ticylist_slice(const struct TicyList *_List,
                                sz_t _Start,
                                sz_t _Count);

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

// Returns new TicyData instance by data and type code.
struct TicyData ticydata_ins(const any_t _Data, const TicyTypeCode _Ticytc);
// Returns new TicyData instance heap-allocated by data and type code.
//
// Special case is:
//  ticydata_new(_Data, _Ticytc) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydata_new(_Data, _Ticytc) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyData *ticydata_new(const any_t _Data, const TicyTypeCode _Ticytc);
// Frees TicyData instance allocated from heap.
// This is not frees data.
void ticydata_free(struct TicyData *_Ticyd);
// Returns serialized string (heap-allocated) value of specified TicyData.
//
// Special cases are;
//  ticydata_serialize(_Ticyd) -> "" if data is NULL
//  ticydata_serialize(_Ticyd) -> "" if type code is not supported
//  ticydata_serialize(_Ticyd) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydata_serialize(_Ticyd) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticydata_serialize(const struct TicyData *_Ticyd);
// Returns deserialized TicyData by specified serialized string.
//
// Special cases are;
//  ticydata_deserialize(_Str) -> TicyData{_data: NULL, _type: OTHER_T} if _Str is NULL
//  ticydata_deserialize(_Str) -> TicyData{_data: NULL, _type: OTHER_T} if _Str length is 0
//  ticydata_deserialize(_Str) -> TicyData{_data: NULL, _type: OTHER_T} if any parse error
//  ticydata_deserialize(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydata_deserialize(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const TicyData *ticydata_deserialize(const str_t _Str);
// Returns true if equals datas of specified TicyDatas.
const bool_t ticydata_eqs(const struct TicyData _Ticyd1,
                          const struct TicyData _Ticyd2);

// Length of TicyFile's lines.
volatile sz_t TicyFile_Line_Length = 1024;

// File instance of TicyDB.
typedef struct TicyFile {
  // Path of file.
  // Don't change if you not sure that.
  str_t           _path;
  // File content line-by-line.
  // Lines are heap-allocated.
  // Don't change if you not sure that.
  struct TicyList *_lines;
  // Text content of file.
  // This field is heap-allocated.
  // Don't change if you not sure that.
  str_t           _text;
} TicyFile;

// Returns heap-allocated TicyFile instance by specified path.
//
// Special cases are;
//  ticyfile_open(_Path) -> NULL if path == NULL
//  ticyfile_open(_Path) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticyfile_open(_Path) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyFile *ticyfile_open(const str_t _Path);
// Closes and frees heap-allocated TicyFile instance.
void ticyfile_close(struct TicyFile * _Ticyf);

// Key-Value store of TicyDB.
// Don't touch fields if you not sure that.
typedef struct TicyStore {
  // Keys of store, stores any_t type.
  // Don't change if you not sure that.
  struct TicyList *_keys;
  // Values of keys, stores TicyData* type.
  // Don't change if you not sure that.
  struct TicyList *_values;
} TicyStore;

// Returns heap-allocated TicyStore instance.
//
// Special case is;
//  ticystore_new(void) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticystore_new(void) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyStore *ticystore_new(void);
// Frees heap-allocated TicyStore instance.
// It's frees key and value lists but not frees these elements.
void ticystore_free(struct TicyStore *_Ticys);
// Set value o specified key.
// Creates a new key-value node if key is not exist.
// Returns true if created a new key-value node, returns false if not.
//
// Special cases are;
//  ticystore_set(_Ticys, _Key, _Value) -> F if key is can't pushed
//  ticystore_set(_Ticys, _Key, _Value) -> F if value is can't pushed
//  ticystore_set(_Ticys, _Key, _Value) -> F if store is NULL
const bool_t ticystore_set(struct TicyStore *_Ticys,
                           const TicyData *_Key,
                           const TicyData *_Value);
// Returns value o specified key value.
//
// Special case is;
//  ticystore_get(_Ticys, _Key) -> NULL if store is NULL
//  ticystore_get(_Ticys, _Key) -> NULL if key is not exist
const TicyData *ticystore_get(const struct TicyStore *_Ticys,
                              const struct TicyData _Key);
// Reports specified TicyStore is have any key-value node or not.
//
// Special case is;
//  ticystore_any(_Ticys) -> F if store is NULL
const bool_t ticystore_any(const struct TicyStore *_Ticys);
// Returns index of key value if key value is exist, returns -1 if not in specified TicyStore.
//
// Special case is;
//  ticystore_existk(_Ticys, _Key) -> -1 if store is NULL
const sz_t ticystore_findk(const struct TicyStore *_Ticys,
                           const struct TicyData _Key);
// Returns index of key of value if value is exist, returns -1 if not in specified TicyStore.
//
// Special case is;
//  ticystore_existk(_Ticys, _Key) -> -1 if store is NULL
const sz_t ticystore_findv(const struct TicyStore *_Ticys,
                           const struct TicyData _Value);
// Returns serialize TicyStore as string (heap-allocated).
//
// Special cases are;
//  ticystore_serialize(_Ticys) -> NULL if store is NULL
//  ticystore_serialize(_Ticys) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticystore_serialize(_Ticys) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticystore_serialize(const struct TicyStore *_Ticys);
// Returns deserialized TicyStore by specified serialized string.
//
// Special cases are;
//  ticystore_deserialize(_Str) -> Empty TicyStore if _Str is NULL
//  ticystore_deserialize(_Str) -> NULL if any parse error
//  ticystore_deserialize(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticystore_deserialize(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyStore *ticystore_deserialize(const str_t _Str);

// TicyDB connection instance.
typedef struct TicyDB {
  // Content of TicyDB.
  struct TicyStore *_Store;
  // This is a path of your TicyDB store file.
  // Don't touch this if you not sure that.
  str_t _path;
} TicyDB;

// Returns heap-allocated TicyDB instance by specified path.
//
// Special case is;
//  ticydb_new(_Path) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydb_new(_Path) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyDB *ticydb_open(const str_t _Path);
// Frees and closes heap-allocated TicyDB instance.
void ticydb_close(struct TicyDB *_Ticydb);
// Save TicyDB content to local disk storage.
// Returns true if keeping success, returns false if not.
//
// Special cases are;
//  ticydb_keep(_Ticydb) -> false if _Ticydb is NULL
//  ticydb_keep(_Ticydb) -> false if _Ticydb->_Store is NULL
//  ticydb_keep(_Ticydb) -> false if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydb_keep(_Ticydb) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const bool_t ticydb_keep(const struct TicyDB *_Ticydb);

// Returns specified any_t as serialized string (heap-allocated) with i8_t type format.
//
// Special cases are;
//  ticy_his(_Hi) -> default if _Hi is NULL
//  ticy_his(_Hi) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_his(_Hi) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_his(const any_t _Hi);
// Returns specified any_t as serialized string (heap-allocated) with i16_t, i32_t, bool_t type formats.
//
// Special cases are;
//  ticy_ds(_D) -> default if _D is NULL
//  ticy_ds(_D) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_ds(_D) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_ds(const any_t _D);
// Returns specified any_t as serialized string (heap-allocated) with i64_t type format.
//
// Special cases are;
//  ticy_llds(_Lld) -> default if _Lld is NULL
//  ticy_llds(_Lld) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_llds(_Lld) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_llds(const any_t _Lld);
// Returns specified any_t as serialized string (heap-allocated) with u8_t type format.
//
// Special cases are;
//  ticy_hus(_Hu) -> default if _Hu is NULL
//  ticy_hus(_Hu) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_hus(_Hu) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_hus(const any_t _Hu);
// Returns specified any_t as serialized string (heap-allocated) with u16_t, u32_t, sz_t type format.
//
// Special cases are;
//  ticy_us(_U) -> default if _U is NULL
//  ticy_us(_U) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_us(_U) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_us(const any_t _U);
// Returns specified any_t as serialized string (heap-allocated) with u64_t type format.
//
// Special cases are;
//  ticy_llus(_Llu) -> default if _Llu is NULL
//  ticy_llus(_Llu) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_llus(_Llu) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_llus(const any_t _Llu);
// Returns specified any_t as serialized string (heap-allocated) with f32_t type format.
//
// Special cases are;
//  ticy_fs(_F) -> default if _F is NULL
//  ticy_fs(_F) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_fs(_F) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_fs(const any_t _F);
// Returns specified any_t as serialized string (heap-allocated) with f64_t type format.
//
// Special cases are;
//  ticy_lfs(_Lf) -> default if _Lf is NULL
//  ticy_lfs(_Lf) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lfs(_Lf) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_lfs(const any_t _Lf);
// Returns specified any_t as serialized string (heap-allocated) with char_t type format.
//
// Special cases are;
//  ticy_cs(_Char) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_cs(_Char) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_cs(const char_t _Char);
// Returns specified any_t as serialized string (heap-allocated) with str_t type format.
//
// Special cases are;
//  ticy_ss(_Str) -> NULL if _Str is NULL
//  ticy_ss(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_ss(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_ss(const str_t _Str);
// Returns specified TicyList as serialized string (heap-allocated) with TicyData type format.
//
// Special cases are;
//  ticy_tls(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_tls(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_tls(const struct TicyList _Ticyl);
// Returns deserialized i8_t from specified serialized string.
//
// Special case is;
//  ticy_hids(_Str) -> NULL if _Str is NULL
//  ticy_hids(_Str) -> NULL if _Str length is 0
//  ticy_hids(_Str) -> NULL if any parse error
//  ticy_hids(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_hids(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_hids(const str_t _Str);
// Returns deserialized i16_t, i32_t, bool_t from specified serialized string.
//
// Special case is;
//  ticy_dds(_Str) -> NULL if _Str is NULL
//  ticy_dds(_Str) -> NULL if _Str length is 0
//  ticy_dds(_Str) -> NULL if any parse error
//  ticy_dds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_dds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_dds(const str_t _Str);
// Returns deserialized i64_t (heap-allocated) from specified serialized string.
//
// Special case is;
//  ticy_lldds(_Str) -> NULL if _Str is NULL
//  ticy_lldds(_Str) -> NULL if _Str length is 0
//  ticy_lldds(_Str) -> NULL if any parse error
//  ticy_lldds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lldds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_lldds(const str_t _Str);
// Returns deserialized u8_t from specified serialized string.
//
// Special case is;
//  ticy_huds(_Str) -> NULL if _Str is NULL
//  ticy_huds(_Str) -> NULL if _Str length is 0
//  ticy_huds(_Str) -> NULL if any parse error
//  ticy_huds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_huds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_huds(const str_t _Str);
// Returns deserialized u16_t, u32_t, sz_t from specified serialized string.
//
// Special case is;
//  ticy_uds(_Str) -> NULL if _Str is NULL
//  ticy_uds(_Str) -> NULL if _Str length is 0
//  ticy_uds(_Str) -> NULL if any parse error
//  ticy_uds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_uds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_uds(const str_t _Str);
// Returns deserialized u64_t (heap-allocated) from specified serialized string.
//
// Special case is;
//  ticy_lluds(_Str) -> NULL if _Str is NULL
//  ticy_lluds(_Str) -> NULL if _Str length is 0
//  ticy_lluds(_Str) -> NULL if any parse error
//  ticy_lluds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lluds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_lluds(const str_t _Str);
// Returns deserialized f32_t (heap-allocated) from specified serialized string.
//
// Special case is;
//  ticy_fds(_Str) -> NULL if _Str is NULL
//  ticy_fds(_Str) -> NULL if _Str length is 0
//  ticy_fds(_Str) -> NULL if any parse error
//  ticy_fds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_fds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_fds(const str_t _Str);
// Returns deserialized f64_t (heap-allocated) from specified serialized string.
//
// Special case is;
//  ticy_lfds(_Str) -> NULL if _Str is NULL
//  ticy_lfds(_Str) -> NULL if _Str length is 0
//  ticy_lfds(_Str) -> NULL if any parse error
//  ticy_lfds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lfds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_lfds(const str_t _Str);
// Returns deserialized str_t (heap-allocated) from specified serialized string.
//
// Special case is;
//  ticy_sds(_Str) -> NULL if _Str is NULL
//  ticy_sds(_Str) -> NULL if _Str length is 0
//  ticy_sds(_Str) -> NULL if any parse error
//  ticy_sds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_sds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_sds(const str_t _Str);
// Returns deserialized char_t from specified serialized string.
//
// Special case is;
//  ticy_cds(_Str) -> NULL if _Str is NULL
//  ticy_cds(_Str) -> NULL if _Str length is 0
//  ticy_cds(_Str) -> NULL if any parse error
//  ticy_cds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_cds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_cds(const str_t _Str);
// Returns deserialized TicyList (elements are TicyData*) from specified serialized string.
//
// Special cases are;
//  ticy_tlds(_Str) -> NULL if _Str is NULL
//  ticy_tlds(_Str) -> NULL if _Str length is 0
//  ticy_tlds(_Str) -> NULL if any parse error
//  ticy_tlds(_Str) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_tlds(_Str) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const struct TicyData *ticy_tlds(const str_t _Str);

const bool_t strprefix(const str_t _Str, const str_t _Sub) {
  const sz_t _str_length = strlen(_Str);
  const sz_t _sub_length = strlen(_Sub);
  return (const bool_t)(_str_length < _sub_length ? F : memcmp(_Sub, _Str, _sub_length) == 0);
}

struct TicyData ticydata_ins(const any_t _Data, const TicyTypeCode _Ticytc) {
  struct TicyData _ticyd;
  _ticyd._data = _Data;
  _ticyd._type = _Ticytc;
  return _ticyd;
}

struct TicyData *ticydata_new(const any_t _Data, const TicyTypeCode _Ticytc) {
  struct TicyData *_ticyd = (struct TicyData*)(malloc(sizeof(struct TicyData)));
  if (!_ticyd) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  *_ticyd = ticydata_ins(_Data, _Ticytc);
  return _ticyd;
}

void ticydata_free(struct TicyData *_Ticyd) {
  free(_Ticyd);
  _Ticyd = NULL;
}

const str_t ticydata_serialize(const struct TicyData *_Ticyd) {
  if (!_Ticyd) { return NULL; }
  str_t _str = NULL;
  switch (_Ticyd->_type) {
  // case SBYTE_T:
  case I8_T:
    _str = ticy_his(_Ticyd->_data);
    break;
  case I16_T:
  case I32_T:
    _str = ticy_ds(_Ticyd->_data);
    break;
  case I64_T:
    _str = ticy_llds(_Ticyd->_data);
    break;
  // case BYTE_T:
  case U8_T:
    _str = ticy_hus(_Ticyd->_data);
    break;
  // case BOOL_T:
  case U16_T:
  case SZ_T:
  case U32_T:
    _str = ticy_us(_Ticyd->_data);
    break;
  case U64_T:
    _str = ticy_llus(_Ticyd->_data);
    break;
  case F32_T:
    _str = ticy_fs(_Ticyd->_data);
    break;
  case F64_T:
    _str = ticy_lfs(_Ticyd->_data);
    break;
  case STR_T:
    _str = ticy_ss((str_t)(_Ticyd->_data));
    break;
  case CHAR_T:
    _str = ticy_cs((char_t)((intptr_t)(_Ticyd->_data)));
    break;
  case TICYLIST_PTR:
    _str = ticy_tls(*(struct TicyList*)(_Ticyd->_data));
    break;
  default: break;
  }
  if (_str) { return _str; }
  _str = (str_t)(malloc(3*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _str[0] = '"';
  _str[1] = '"';
  _str[2] = '\0';
  return _str;
}

const TicyData *ticydata_deserialize(const str_t _Str) {
  TicyData *_ticyd;
  if (!_Str) { goto err; }
  const sz_t _str_length = strlen(_Str);
  if (_str_length == 0) { goto err; }
       if (strprefix(_Str, "hi"))  { _ticyd = (TicyData*)(ticy_hids(_Str));  }
  else if (strprefix(_Str, "d"))   { _ticyd = (TicyData*)(ticy_dds(_Str));   }
  else if (strprefix(_Str, "lld")) { _ticyd = (TicyData*)(ticy_lldds(_Str)); }
  else if (strprefix(_Str, "hu"))  { _ticyd = (TicyData*)(ticy_huds(_Str));  }
  else if (strprefix(_Str, "u"))   { _ticyd = (TicyData*)(ticy_uds(_Str));   }
  else if (strprefix(_Str, "llu")) { _ticyd = (TicyData*)(ticy_lluds(_Str)); }
  else if (strprefix(_Str, "f"))   { _ticyd = (TicyData*)(ticy_fds(_Str));   }
  else if (strprefix(_Str, "lf"))  { _ticyd = (TicyData*)(ticy_lfds(_Str));  }
  else if (strprefix(_Str, "\""))  { _ticyd = (TicyData*)(ticy_sds(_Str));   }
  else if (strprefix(_Str, "'"))   { _ticyd = (TicyData*)(ticy_cds(_Str));   }
  else if (strprefix(_Str, "["))   { _ticyd = (TicyData*)(ticy_tlds(_Str)); }
  if (_ticyd) { return _ticyd; }
err:
  _ticyd = ticydata_new(NULL, OTHER_T);
#ifndef TICY_FAILURE_ALLOC
  if (!_ticyd) { return NULL; }
#endif // #ifdef TICY_FAILURE_ALLOC
  return _ticyd;
}

const bool_t ticydata_eqs(const struct TicyData _Ticyd1,
                          const struct TicyData _Ticyd2) {
  if (_Ticyd1._type != _Ticyd2._type) { return F; }
  switch (_Ticyd1._type) {
  case STR_T:
    return (bool_t)(strcmp((str_t)(_Ticyd1._data), (str_t)(_Ticyd2._data)) == 0);
  default   :
    return (bool_t)(_Ticyd1._data == _Ticyd2._data);
  }
}

struct TicyList *ticylist_new(sz_t _Size) {
  struct TicyList *_ticyl = (struct TicyList*)(malloc(sizeof(struct TicyList)));
  if (!_ticyl) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _Size = _Size < 1 ? 1 : _Size;
  _ticyl->_buffer = (void**)(malloc(_Size*sizeof(any_t)));
  if (!_ticyl->_buffer) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _ticyl->_used = 0;
  _ticyl->_size = _Size;
  return _ticyl;
}

void ticylist_free(struct TicyList *_Ticyl) {
  if (!_Ticyl) { return; }
  free(_Ticyl->_buffer);
  _Ticyl->_buffer = NULL;
  _Ticyl->_used = 0;
  _Ticyl->_size = 0;
  free(_Ticyl);
  _Ticyl = NULL;
}

const bool_t ticylist_push(struct TicyList* _Ticyl, const any_t _Item) {
  if (_Ticyl->_size <= _Ticyl->_used) {
    _Ticyl->_size *= 2;
    _Ticyl->_buffer = (any_t*)(realloc(_Ticyl->_buffer, _Ticyl->_size*sizeof(any_t)));
    if (!_Ticyl->_buffer) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return F;
#endif // #ifdef TICY_FAILURE_ALLOC
    }
  }
  _Ticyl->_buffer[_Ticyl->_used++] = _Item;
  return T;
}

const bool_t ticylist_remrange(struct TicyList *_Ticyl,
                               const sz_t _Start,
                               sz_t _Count) {
  if (_Start < 0)             { return F; }
  if (_Start > _Ticyl->_used) { return F; }
  if (_Count < 1)             { return F; }
  if (_Count > _Ticyl->_used-_Start) { _Count = _Ticyl->_used; }
  struct TicyList *_new_list = ticylist_new(_Ticyl->_used-_Count);
#ifndef TICY_FAILURE_ALLOC
  if (!_new_list) { return F; }
#endif // #ifndef TICY_FAILURE_ALLOC
  for (sz_t _index = 0; _index < _Start; ++_index)
  { ticylist_push(_new_list, _Ticyl->_buffer[_index]); }
  for (sz_t _index = _Start+_Count; _index < _Ticyl->_used; ++_index)
  { ticylist_push(_new_list, _Ticyl->_buffer[_index]); }
  _Ticyl->_used = _new_list->_used;
  _Ticyl->_size = _new_list->_size;
  free(_Ticyl->_buffer);
  _Ticyl->_buffer = NULL;
  *_Ticyl = *_new_list;
  _new_list->_size = 0;
  _new_list->_used = 0;
  _new_list->_buffer = NULL;
  free(_new_list);
  _new_list = NULL;
  return T;
}

struct TicyList *ticylist_slice(const struct TicyList *_Ticyl,
                                sz_t _Start,
                                sz_t _Count) {
  if (!_Ticyl)    { return NULL; }
  if (_Start < 0) { return NULL; }
  if (_Count < 1) { return NULL; }
  if (_Count > _Ticyl->_used-_Start) { _Count = _Ticyl->_used; }
  struct TicyList* _slice = ticylist_new(_Count);
#ifndef TICY_FAILURE_ALLOC
  if (!_slice) { return NULL; }
#endif // #ifndef TICY_FAILURE_ALLOC
  for (; _Count >= 0; --_Count)
  { ticylist_push(_slice, _Ticyl->_buffer[_Start++]); }
  return _slice;
}

struct TicyFile *ticyfile_open(const str_t _Path) {
  if (!_Path) { return NULL; }
  FILE *_file = fopen(_Path, "r");
  if (!_file) { return NULL; }
  struct TicyFile *_ticyf = (struct TicyFile*)(malloc(sizeof(struct TicyFile)));
  if (!_ticyf) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    fclose(_file);
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _ticyf->_lines = ticylist_new(1);
#ifndef TICY_FAILURE_ALLOC
  if (!_ticyf->_lines) {
    fclose(_file);
    ticyfile_close(_ticyf);
    return NULL;
  }
#endif // #ifdef TICY_FAILURE_ALLOC
  sz_t _text_length = 1;
  _ticyf->_text = (str_t)(malloc((_text_length*Ticy_Buffer_Size)*sizeof(char_t)));
  _ticyf->_text[0] = '\0';
  if (!_ticyf->_text) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    fclose(_file);
    ticyfile_close(_ticyf);
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _ticyf->_path = _Path;
  const sz_t _line_size = TicyFile_Line_Length*sizeof(char_t);
  while (T) {
    str_t _line = (str_t)(malloc(_line_size));
    if (!_line) {
#ifdef TICY_FAILURE_ALLOC
      printf(TICY_ERROR_FAIL_ALLOC "\n");
      exit(Ticy_Exit_Code_Failure);
#else
      fclose(_file);
      ticyfile_close(_ticyf);
      return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
    }
    if (!fgets(_line, _line_size, _file)) {
      free(_line);
      _line = NULL;
      break;
    }
    const sz_t _line_length = strlen(_line);
    if ((_text_length*Ticy_Buffer_Size) < strlen(_ticyf->_text)+_line_length) {
      _ticyf->_text = (str_t)(realloc(_ticyf->_text, (_text_length*=2)*Ticy_Buffer_Size));
      if (!_ticyf->_text) {
#ifdef TICY_FAILURE_ALLOC
        printf(TICY_ERROR_FAIL_ALLOC "\n");
        exit(Ticy_Exit_Code_Failure);
#else
        fclose(_file);
        ticyfile_close(_ticyf);
        free(_line);
        _line = NULL;
        return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
      }
    }
    strcat(_ticyf->_text, _line);
    _line[_line_length-1] = '\0';
    ticylist_push(_ticyf->_lines, _line);
  }
  return _ticyf;
}

void ticyfile_close(struct TicyFile *_Ticyf) {
  if (!_Ticyf) { return; }
  if (_Ticyf->_lines) {
    for (sz_t _index = 0; _index < _Ticyf->_lines->_used; )
    { free((str_t)(_Ticyf->_lines->_buffer[_index++])); }
    ticylist_free(_Ticyf->_lines);
    _Ticyf->_lines = NULL;
  }
  free(_Ticyf->_text);
  _Ticyf->_text = NULL;
  free(_Ticyf);
  _Ticyf = NULL;
}

struct TicyStore *ticystore_new(void) {
  struct TicyStore *_ticys = (struct TicyStore*)(malloc(sizeof(struct TicyStore)));
  if (!_ticys) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _ticys->_keys = ticylist_new(1);
  if (!_ticys->_keys) {
    free(_ticys);
    _ticys = NULL;
    return NULL;
  }
  _ticys->_values = ticylist_new(1);
  if (!_ticys->_values) {
    free(_ticys);
    _ticys = NULL;
    return NULL;
  }
  return _ticys;
}

void ticystore_free(struct TicyStore *_Ticys) {
  if (!_Ticys) { return; }
  if (_Ticys->_keys) {
    ticylist_free(_Ticys->_keys);
    _Ticys->_keys = NULL;
  }
  if (_Ticys->_values) {
    ticylist_free(_Ticys->_values);
    _Ticys->_values = NULL;
  }
  free(_Ticys);
  _Ticys = NULL;
}

const bool_t ticystore_set(struct TicyStore *_Ticys,
                           const TicyData *_Key,
                           const TicyData *_Value) {
  if (!_Ticys) { return F; }
  const sz_t _index = ticystore_findk(_Ticys, *_Key);
  if (_index != -1) {
    _Ticys->_values->_buffer[_index] = (any_t)(_Value);
    return F;
  }
  if (!ticylist_push(_Ticys->_keys, (any_t)(_Key))) { return F; }
  if (!ticylist_push(_Ticys->_values, (any_t)(_Value))) {
    _Ticys->_keys->_buffer[_Ticys->_keys->_used--] = NULL;
    return F;
  }
  return T;
}

const TicyData *ticystore_get(const struct TicyStore *_Ticys,
                              const struct TicyData _Key) {
  const sz_t _index = ticystore_findk(_Ticys, _Key);
  return _index == -1 ? NULL : (TicyData*)(_Ticys->_values->_buffer[_index]);
}

const bool_t ticystore_any(const struct TicyStore *_Ticys)
{ return (const bool_t)(_Ticys && _Ticys->_keys->_used > 0); }

const sz_t ticystore_findk(const struct TicyStore *_Ticys,
                           const TicyData _Key) {
  if (!_Ticys) { return -1; }
  for (sz_t _index = 0; _index < _Ticys->_keys->_used; ++_index) {
    const TicyData *_key = (TicyData*)(_Ticys->_keys->_buffer[_index]);
    if (ticydata_eqs(_Key, *_key)) { return _index; }
  }
  return -1;
}

const sz_t ticystore_findv(const struct TicyStore *_Ticys,
                           const struct TicyData _Value) {
  for (sz_t _index = 0; _index < _Ticys->_values->_used; ++_index) {
    const TicyData *_value = (TicyData*)(_Ticys->_values->_buffer[_index]);
    if (ticydata_eqs(_Value, *_value)) { return _index; }
  }
  return -1;
}

const str_t ticystore_serialize(const struct TicyStore *_Ticys) {
  if (!_Ticys) { return NULL; }
  str_t _str = (str_t)(malloc(sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _str[0] = '\0';
  for (sz_t _index = 0; _index < _Ticys->_keys->_used; ++_index) {
    const TicyData *_key = (TicyData*)(_Ticys->_keys->_buffer[_index]);
    str_t _key_str = ticydata_serialize(_key);
#ifndef TICY_FAILURE_ALLOC
    if (!_key_str) {
      free(_str);
      _str = NULL;
      return NULL;
    }
#endif // #ifdef TICY_FAILURE_ALLOC
    const TicyData *_value = (TicyData*)(_Ticys->_values->_buffer[_index]);
    const str_t _value_str = ticydata_serialize(_value);
#ifndef TICY_FAILURE_ALLOC
    if (!_value_str) {
      free(_key_str);
      _key_str = NULL;
      free(_str);
      _str = NULL;
      return NULL;
    }
#endif // #ifdef TICY_FAILURE_ALLOC
    strcat(_str, _key_str);
    strcat(_str, " ");
    strcat(_str, _value_str);
    strcat(_str, "\n\0");
  }
  return _str;
}

struct TicyStore *ticystore_deserialize(const str_t _Str) {
  struct TicyStore *_ticys = ticystore_new();
#ifndef TICY_FAILURE_ALLOC
  if (!_ticys) { return NULL; }
#endif // #ifndef TICY_FAILURE_ALLOC
  if (!_Str) { return _ticys; }
  str_t _str = strdup(_Str);
  str_t _line_delim = "\n";
  str_t _line = strtok_r(_str, _line_delim, &_str);
  do {
    const str_t _key_str = strtok_r(_line, " ", &_line);
    const str_t _value_str = _line;
    const TicyData *_key = ticydata_deserialize(_key_str);
    const TicyData *_value = ticydata_deserialize(_value_str);
    ticystore_set(_ticys, _key, _value);
  } while((_line = strtok_r(NULL, _line_delim, &_str)));
  free(_str);
  _str = NULL;
  return _ticys;
}

struct TicyDB *ticydb_open(const str_t _Path) {
  struct TicyDB *_ticydb = (struct TicyDB*)(malloc(sizeof(struct TicyDB)));
  if (!_ticydb) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _ticydb->_path = _Path;
  struct TicyFile *_ticyf = ticyfile_open(_Path);
#ifndef TICY_FAILURE_ALLOC
  if (!_ticyf) {
    ticydb_close(_ticydb);
    return NULL;
  }
#endif // #ifndef TICY_FAILURE_ALLOC
  _ticydb->_Store = ticystore_deserialize(_ticyf->_text);
  ticyfile_close(_ticyf);
#ifndef TICY_FAILURE_ALLOC
  if (!_ticydb->_Store) {
    ticydb_close(_ticydb);
    return NULL;
  }
#endif // #ifndef TICY_FAILURE_ALLOC
  return _ticydb;
}

void ticydb_close(struct TicyDB *_Ticydb) {
  if (!_Ticydb) { return; }
  if (_Ticydb->_Store)
  { ticystore_free(_Ticydb->_Store); }
  free(_Ticydb);
  _Ticydb = NULL;
}

const bool_t ticydb_keep(const struct TicyDB *_Ticydb) {
  if (!_Ticydb)         { return F; }
  if (!_Ticydb->_Store) { return F; }
  FILE *_file = fopen(_Ticydb->_path, "w");
  if (!_file) { return F; }
  const str_t serialize_str = ticystore_serialize(_Ticydb->_Store);
  if (!serialize_str) { return F; }
  fprintf(_file, serialize_str);
  return T;
}

const str_t ticy_his(const any_t _Hi) {
  str_t _str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(_str, "hi" TICY_FMT_HI, _Hi);
  return _str;
}

const str_t ticy_ds(const any_t _D) {
  str_t _str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(_str, "d" TICY_FMT_D, _D);
  return _str;
}

const str_t ticy_llds(const any_t _Lld) {
  str_t _str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(_str, "lld" TICY_FMT_LLD, _Lld);
  return _str;
}

const str_t ticy_hus(const any_t _Hu) {
  str_t _str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(_str, "hu" TICY_FMT_HU, _Hu);
  return _str;
}

const str_t ticy_us(const any_t _U) {
  str_t _str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(_str, "u" TICY_FMT_U, _U);
  return _str;
}

const str_t ticy_llus(const any_t _Llu) {
  str_t _str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(_str, "llu" TICY_FMT_LLU, _Llu);
  return _str;
}

const str_t ticy_fs(const any_t _F) {
  str_t _str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(_str, "f" TICY_FMT_F, *(f32_t*)(_F));
  return _str;
}

const str_t ticy_lfs(const any_t _Lf) {
  str_t _str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(_str, "lf" TICY_FMT_LF, *(f64_t*)(_Lf));
  return _str;
}

const str_t ticy_cs(const char_t _Char) {
  str_t _str = (str_t)(malloc(4*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  switch (_Char) {
  case 0:
    sprintf(_str, "'\\%c'", 48);
    break;
  case 7:
    sprintf(_str, "'\\%c'", 97);
    break;
  case 8:
    sprintf(_str, "'\\%c'", 98);
    break;
  case 9:
    sprintf(_str, "'\\%c'", 116);
    break;
  case 10:
    sprintf(_str, "'\\%c'", 110);
    break;
  case 11:
    sprintf(_str, "'\\%c'", 118);
    break;
  case 12:
    sprintf(_str, "'\\%c'", 102);
    break;
  case 13:
    sprintf(_str, "'\\%c'", 114);
    break;
  case 34:
    sprintf(_str, "'\\%c'", 34);
    break;
  case 39:
    sprintf(_str, "'\\%c'", 39);
    break;
  case 92:
    sprintf(_str, "'\\%c'", 92);
    break;
  default:
    sprintf(_str, TICY_FMT_C, _Char);
    break;
  }
  return _str;
}

const str_t ticy_ss(const str_t _Str) {
  if (!_Str) { return NULL; }
  sz_t _str_size = Ticy_Buffer_Size;
  str_t _str = (str_t)(malloc(_str_size*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _str[0] = 34;
  _str[1] = 0;
  const sz_t _Str_length = strlen(_Str);
  for (sz_t _index = 0; _index < _Str_length; ++_index) {
    str_t _cstr = ticy_cs(_Str[_index]);
    const sz_t _cstr_length = strlen(_cstr);
    if (strlen(_str)+_cstr_length-2 >= _str_size) {
      _str = (str_t)(realloc(_str, (_str_size*=2)*sizeof(char_t)));
      if (!_str) {
#ifdef TICY_FAILURE_ALLOC
        printf(TICY_ERROR_FAIL_ALLOC "\n");
        exit(Ticy_Exit_Code_Failure);
#else
        free(_cstr);
        _cstr = NULL;
        return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
      }
    }
    strncat(_str, ++_cstr, _cstr_length-2);
    free(_cstr);
    _cstr = NULL;
  }
  strcat(_str, "\"");
  return _str;
}

const str_t ticy_tls(const struct TicyList _Ticyl) {
  sz_t _str_size = Ticy_Buffer_Size;
  str_t _str = (str_t)(malloc(_str_size*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _str[0] = 91;
  _str[1] = 0;
  for (sz_t _index = 0; _index < _Ticyl._used; ++_index) {
    if (strlen(_str) >= _str_size) {
      _str = (str_t)(realloc(_str, (_str_size*=2)*sizeof(char_t)));
      if (!_str) {
#ifdef TICY_FAILURE_ALLOC
        printf(TICY_ERROR_FAIL_ALLOC "\n");
        exit(Ticy_Exit_Code_Failure);
#else
        return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
      }
    }
    const struct TicyData *_ticyd = (struct TicyData*)(_Ticyl._buffer[_index]);
    strcat(_str, ticydata_serialize(_ticyd));
    if (_index+1 < _Ticyl._used) { strcat(_str, " "); }
  }
  strcat(_str, "]");
  return _str;
}

const struct TicyData *ticy_hids(const str_t _Str) {
  if (!_Str) { return NULL; }
  const sz_t _Str_length = strlen(_Str);
  if (_Str_length == 0) { return NULL; }
  i8_t _hi = 0;
  sscanf(_Str+strlen(TICY_FMT_HI)-1, TICY_FMT_HI, &_hi);
  const struct TicyData *_ticyd = ticydata_new((any_t)((uintptr_t)(_hi)), I8_T);
  return _ticyd;
}

const struct TicyData *ticy_dds(const str_t _Str) {
if (!_Str) { return NULL; }
  const sz_t _Str_length = strlen(_Str);
  if (_Str_length == 0) { return NULL; }
  i32_t _d = 0;
  sscanf(_Str+strlen(TICY_FMT_D)-1, TICY_FMT_D, &_d);
  const struct TicyData *_ticyd = ticydata_new((any_t)(_d), I32_T);
  return _ticyd;
}

const struct TicyData *ticy_lldds(const str_t _Str) {
  if (!_Str) { return NULL; }
  const sz_t _Str_length = strlen(_Str);
  if (_Str_length == 0) { return NULL; }
  i64_t *_lld = (i64_t*)(malloc(sizeof(i64_t)));
  if (!_lld) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  *_lld = 0;
  sscanf(_Str+strlen(TICY_FMT_LLD)-1, TICY_FMT_LLD, &_lld);
  const struct TicyData *_ticyd = ticydata_new((any_t)(&_lld), I64_T);
  return _ticyd;
}

const struct TicyData *ticy_huds(const str_t _Str) {
  if (!_Str) { return NULL; }
  const sz_t _Str_length = strlen(_Str);
  if (_Str_length == 0) { return NULL; }
  u8_t _hu = 0;
  sscanf(_Str+strlen(TICY_FMT_HU)-1, TICY_FMT_HU, &_hu);
  const struct TicyData *_ticyd = ticydata_new((any_t)((uintptr_t)(_hu)), U8_T);
  return _ticyd;
}

const struct TicyData *ticy_uds(const str_t _Str) {
  if (!_Str) { return NULL; }
  const sz_t _Str_length = strlen(_Str);
  if (_Str_length == 0) { return NULL; }
  u32_t _u = 0;
  sscanf(_Str+strlen(TICY_FMT_U)-1, TICY_FMT_U, &_u);
  const struct TicyData *_ticyd = ticydata_new((any_t)(_u), U32_T);
  return _ticyd;
}

const struct TicyData *ticy_lluds(const str_t _Str) {
  if (!_Str) { return NULL; }
  const sz_t _Str_length = strlen(_Str);
  if (_Str_length == 0) { return NULL; }
  u64_t *_llu = (u64_t*)(malloc(sizeof(u64_t)));
  if (!_llu) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  *_llu = 0;
  sscanf(_Str+strlen(TICY_FMT_LLU)-1, TICY_FMT_LLU, &_llu);
  const struct TicyData *_ticyd = ticydata_new((any_t)(&_llu), U64_T);
  return _ticyd;
}

const struct TicyData *ticy_fds(const str_t _Str) {
  if (!_Str) { return NULL; }
  const sz_t _Str_length = strlen(_Str);
  if (_Str_length == 0) { return NULL; }
  f32_t *_f = (f32_t*)(malloc(sizeof(f32_t)));
  if (!_f) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  *_f = 0.;
  sscanf(_Str+strlen(TICY_FMT_F)-1, TICY_FMT_F, _f);
  const struct TicyData *_ticyd = ticydata_new(_f, F32_T);
  return _ticyd;
}

const struct TicyData *ticy_lfds(const str_t _Str) {
  if (!_Str) { return NULL; }
  const sz_t _Str_length = strlen(_Str);
  if (_Str_length == 0) { return NULL; }
  f64_t *_lf = (f64_t*)(malloc(sizeof(f64_t)));
  if (!_lf) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  *_lf = 0.;
  sscanf(_Str+strlen(TICY_FMT_LF)-1, TICY_FMT_LF, _lf);
  const struct TicyData *_ticyd = ticydata_new(_lf, F64_T);
  return _ticyd;
}

const struct TicyData *ticy_sds(const str_t _Str) {
  if (!_Str) { return NULL; }
  const sz_t _Str_length = strlen(_Str);
  str_t _str;
  if (_Str_length == 0)           { goto err; }
  if (_Str[0] != 34)              { goto err; }
  if (_Str[strlen(_Str)-1] != 34) { goto err; }
  sz_t _str_size = 1;
  _str = (str_t)(malloc(_str_size*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _str[0] = 0;
  for (sz_t _Str_index = 1, _str_index = 0;
      _Str_index < _Str_length-1; ++_Str_index) {
    if (strlen(_str) >= _str_size) {
      _str = (str_t)(realloc(_str, (++_str_size)*sizeof(char_t)));
      if (!_str) {
#ifdef TICY_FAILURE_ALLOC
        printf(TICY_ERROR_FAIL_ALLOC "\n");
        exit(Ticy_Exit_Code_Failure);
#else
        return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
      }
      _str[_str_size] = 0;
    }
    const char_t _char = _Str[_Str_index];
    if (_char == 92) {
      if (_Str_index+1 >= _Str_length) {
        free(_str);
        _str = NULL;
        break;
      }
      str_t _char_str = (str_t)(malloc(4*sizeof(char_t)));
      if (!_char_str) {
#ifdef TICY_FAILURE_ALLOC
        printf(TICY_ERROR_FAIL_ALLOC "\n");
        exit(Ticy_Exit_Code_Failure);
#else
        free(_str);
        _str = NULL;
        return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
      }
      _char_str[0] = 0;
      sprintf(_char_str, "'%c%c'", _char, _Str[++_Str_index]);
      struct TicyData *_char_ticyd = (TicyData*)(ticy_cds(_char_str));
      _str[_str_index++] = (char_t)((uintptr_t)(_char_ticyd->_data));
      ticydata_free(_char_ticyd);
      free(_char_str);
      _char_str = NULL;
    } else {
      _str[_str_index++] = _char;
    }
  }
  if (_str) { goto ret; }
err:;
  _str = (str_t)(malloc(sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _str[0] = 0;
ret:;
  const struct TicyData *_ticyd = ticydata_new(_str, STR_T);
  return _ticyd;
}

const struct TicyData *ticy_cds(const str_t _Str) {
  if (!_Str) { return NULL; }
  const sz_t _Str_length = strlen(_Str);
  if (_Str_length == 0) { return NULL; }
  char_t _char = 0;
  if (_Str[1] == 92) {
    if (_Str_length != 4) { return NULL; }
    switch (_Str[2]) {
    case 48 :
      _char = 0;
      break;
    case 97 :
      _char = 7;
      break;
    case 98 :
      _char = 8;
      break;
    case 116:
      _char = 9;
      break;
    case 110:
      _char = 10;
      break;
    case 118:
      _char = 11;
      break;
    case 102:
      _char = 12;
      break;
    case 114:
      _char = 13;
      break;
    case 34 :
      _char = 34;
      break;
    case 39 :
      _char = 39;
      break;
    case 92 :
      _char = 92;
      break;
    default:
      return NULL;
    }
  } else {
    if (_Str_length != 3) { return NULL; }
    _char = _Str[1];
  }
  const struct TicyData *_ticyd = ticydata_new((any_t)((uintptr_t)(_char)), CHAR_T);
  return _ticyd;
}

const struct TicyData *ticy_tlds(const str_t _Str) {
  if (!_Str) { return NULL; }
  sz_t _Str_length = strlen(_Str);
  if (_Str_length == 0)          { return NULL; }
  if (_Str[0] != 91)             { return NULL; }
  if (_Str[_Str_length-1] != 93) { return NULL; }
  struct TicyList *_ticyl = ticylist_new(1);
#ifndef TICY_FAILURE_ALLOC
  if (!_ticyl) { return NULL; }
#endif // #ifndef TICY_FAILURE_ALLOC
  --_Str_length;
  sz_t _last = 1;
  sz_t _braces = 0;
  bool_t _quotes = F;
  bool_t _double_quotes = F;
  for (sz_t _index = 1; _index < _Str_length; ++_index) {
    char_t _char = _Str[_index];
    switch (_char) {
    case 91:
      if (_double_quotes) { break; }
      if (_quotes)        { break; }
      ++_braces;
      break;
    case 93:
      if (_double_quotes) { break; }
      if (_quotes)        { break; }
      --_braces;
      break;
    case 34:
      _double_quotes = !_double_quotes;
      break;
    case 39:
      _quotes = !_quotes;
      break;
    case 32:
      if (_braces > 0)    { break; }
      if (_quotes)        { break; }
      if (_double_quotes) { break; }
      str_t _str = (str_t)(malloc((_Str_length-_last+1)*sizeof(char_t)));
      if (!_str) {
#ifdef TICY_FAILURE_ALLOC
        printf(TICY_ERROR_FAIL_ALLOC "\n");
        exit(Ticy_Exit_Code_Failure);
#else
        free(_ticyl);
        _ticyl = NULL;
        return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
      }
      _str[0] = 0;
      strncpy(_str, _Str+_last, _index-_last);
      _str[_index-_last] = 0;
      _last = _index+1;
      ticylist_push(_ticyl, (struct TicyData*)(ticydata_deserialize(_str)));
      free(_str);
      _str = NULL;
      break;
    case 92:
      if (++_index >= _Str[_index] || (!_quotes && _double_quotes)) {
        free(_ticyl);
        _ticyl = NULL;
        return NULL;
      }
      _char = _Str[_index];
      switch (_char) {
      case 34: break;
      case 39: break;
      }
      break;
    }
  }
  if (_last < _Str_length) {
    str_t _str = (str_t)(malloc((_Str_length-_last+1)*sizeof(char_t)));
    if (!_str) {
#ifdef TICY_FAILURE_ALLOC
      printf(TICY_ERROR_FAIL_ALLOC "\n");
      exit(Ticy_Exit_Code_Failure);
#else
      free(_ticyl);
      _ticyl = NULL;
      return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
    }
    _str[0] = 0;
    strncpy(_str, _Str+_last, _Str_length-_last);
    _str[_Str_length-_last] = 0;
    ticylist_push(_ticyl, (struct TicyData*)(ticydata_deserialize(_str)));
    free(_str);
    _str = NULL;
  }
  const struct TicyData *_ticyd = ticydata_new(_ticyl, TICYLIST_PTR);
#ifndef TICY_FAILURE_ALLOC
  if (!_ticyd) {
    free(_ticyl);
    _ticyl = NULL;
    return NULL;
  }
#endif // #ifndef TICY_FAILURE_ALLOC
  return _ticyd;
}

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef __TICYDB_H
