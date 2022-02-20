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
#define TICYDB_VERSION "0.0.1"
// Release channel of TicyDB.
#define TICYDB_CHANNEL "preview"

#ifdef TICY_FAILURE_ALLOC
// Exit code of TicyDB for failures.
volatile int ticy_exit_code_failure = 1;

// Error message of allocation failures.
#define TICY_ERROR_FAIL_ALLOC "allocation is failed"
#endif // #ifdef TICY_FAILURE_ALLOC

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
  BYTE_T       = 3,  // Byte data type code.
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
  TICYLIST     = 13, // TicyList instance code.
  TICYLIST_PTR = 14, // TicyList instance pointer code.
  SZ_T         = 15, // Size type code.
  OTHER_T      = 16  // Code of other data-types.
} TicyTypeCode;

// Buffer size of various operations of TicyDB.
sz_t Ticy_Buffer_Size = 128;

// Returns string (heap-allocated) value of i8_t.
//
// Special cases are;
//  ticy_i8s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_i8s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_i8s(const i8_t hi);
// Returns string (heap-allocated) value of i16_t.
//
// Special cases are;
//  ticy_i16s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_i16s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_i16s(const i16_t d);
// Returns string (heap-allocated) value of i32_t.
//
// Special cases are;
//  ticy_i32s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_i32s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_i32s(const i32_t d);
// Returns string (heap-allocated) value of i64_t.
//
// Special cases are;
//  ticy_i64s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_i64s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_i64s(const i64_t lld);
// Returns string (heap-allocated) value of u8_t.
//
// Special cases are;
//  ticy_u8s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_u8s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_u8s(const u8_t hu);
// Returns string (heap-allocated) value of u16_t.
//
// Special cases are;
//  ticy_u16s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_u16s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_u16s(const u16_t u);
// Returns string (heap-allocated) value of u32_t.
//
// Special cases are;
//  ticy_u32s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_u32s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_u32s(const u32_t u);
// Returns string (heap-allocated) value of u64_t.
//
// Special cases are;
//  ticy_u64s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_u64s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_u64s(const u64_t llu);
// Returns string (heap-allocated) value of f32_t.
//
// Special cases are;
//  ticy_f32s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_f32s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_f32s(const f32_t f);
// Returns string (heap-allocated) value of f64_t.
//
// Special cases are;
//  ticy_f64s(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_f64s(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_f64s(const f64_t lf);
// Returns string (heap-allocated) value of char_t.
//
// Special cases are;
//  ticy_cs(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_cs(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_cs(const char_t c);
// Returns string (heap-allocated) value of bool_t.
//
// Special cases are;
//  ticy_bs(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_bs(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_bs(const bool_t d);
// Returns string (heap-allocated) value of sz_t.
//
// Special cases are;
//  ticy_szs(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_szs(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_szs(const sz_t zu);

const str_t ticy_i8s(const i8_t hi) {
  str_t str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(str, "%hi", hi);
  return str;
}

const str_t ticy_i16s(const i16_t d) {
  str_t str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(str, "%d", d);
  return str;
}

const str_t ticy_i32s(const i32_t d)
{ return ticy_i16s(d); }

const str_t ticy_i64s(const i64_t lld) {
  str_t str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(str, "%lld", lld);
  return str;
}

const str_t ticy_u8s(const u8_t hu) {
  str_t str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(str, "%hu", hu);
  return str;
}

const str_t ticy_u16s(const u16_t u) {
  str_t str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(str, "%u", u);
  return str;
}

const str_t ticy_u32s(const u32_t u)
{ return ticy_u16s(u); }

const str_t ticy_u64s(const u64_t llu) {
  str_t str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(str, "%llu", llu);
  return str;
}

const str_t ticy_f32s(const f32_t f) {
  str_t str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(str, "%f", f);
  return str;
}

const str_t ticy_f64s(const f64_t lf) {
  str_t str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(str, "%lf", lf);
  return str;
}

const str_t ticy_cs(const char_t c) {
  str_t str = (str_t)(malloc(sizeof(char_t)));
  if (!str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(str, "%c", c);
  return str;
}

const str_t ticy_bs(const bool_t d)
{ return ticy_i32s(d); }

const str_t ticy_szs(const sz_t zu) {
  str_t str = (str_t)(malloc(Ticy_Buffer_Size*sizeof(char_t)));
  if (!str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  sprintf(str, "%zu", zu);
  return str;
}

// Data representation of TicyDB.
typedef struct TicyData {
  // Type code of data.
  // This type code is important because
  // TicyDB process datas by this type code.
  TicyTypeCode type;
  // Data.
  any_t        data;
} TicyData;

// Returns new TicyData instance heap-allocated by data and type code.
//
// Special case is:
//  ticydata_new(void) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydata_new(void) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyData *ticydata_new(const any_t data, const TicyTypeCode type);
// Frees TicyData instance allocated from heap.
// This is not frees data.
void ticydata_free(struct TicyData *data);

struct TicyData *ticydata_new(const any_t data, const TicyTypeCode type) {
  struct TicyData *td = (struct TicyData*)(malloc(sizeof(struct TicyData)));
  if (!td) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  td->data = data;
  td->type = type;
  return data;
}

void ticydata_free(struct TicyData *data) {
  free(data);
  data = NULL;
}

// Dynamic list implementation of TicyDB.
typedef struct TicyList {
  // Element buffer.
  any_t *buffer;
  // Allocated element count.
  sz_t  used;
  // Total element count.
  sz_t  size;
} TicyList;

// Returns new TicyList instance heap-allocated by specified size.
//
// Special case is:
//  ticylist_new(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticylist_new(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
//  ticylist_new(size) -> accept size as 1 if size < 1
struct TicyList *ticylist_new(sz_t size);
// Frees TicyList instance allocated from heap.
void ticylist_free(struct TicyList *list);
// Appends item to TicyList.
// Returns true if success, returns false if failed.
//
// Special case is;
//  ticylist_push(list, item) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const bool_t ticylist_push(struct TicyList *list, any_t item);
// Removes n elements starts at specified index.
// If n greater than size, uses size instead of n.
// Returns true if success, returns false is not.
//
// Special cases are:
//  ticylist_remrange(list, start, n) -> F if n < 1
//  ticylist_remrange(list, start, n) -> F if start < 0
//  ticylist_remrange(list, start, n) -> F if start > size
//  ticylist_remrange(list, start, n) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const bool_t ticylist_remrange(struct TicyList* list, const sz_t start, sz_t n);
// Returns new TicyList from source list by specified index and n.
// If n greater than size, uses size instead of n.
//
// Special cases are:
//  ticylist_slice(list, start, n) -> NULL if failed
//  ticylist_slice(list, start, n) -> NULL if list == NULL
//  ticylist_slice(list, start, n) -> NULL if n < 1
//  ticylist_slice(list, start, n) -> NULL if start < 0
//  ticylist_slice(list, start, n) -> NULL if start > size
//  ticylist_slice(list, start, n) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyList *ticylist_slice(struct TicyList *list, sz_t start, sz_t n);

struct TicyList *ticylist_new(sz_t size) {
  struct TicyList *list = (struct TicyList*)(malloc(sizeof(struct TicyList)));
  if (!list) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  size = size < 1 ? 1 : size;
  list->buffer = (void**)(malloc(size*sizeof(any_t)));
  if (!list->buffer) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  list->used = 0;
  list->size = size;
  return list;
}

void ticylist_free(struct TicyList *list) {
  if (!list) { return; }
  free(list->buffer);
  list->buffer = NULL;
  list->used = 0;
  list->size = 0;
  free(list);
  list = NULL;
}

const bool_t ticylist_push(struct TicyList* list, any_t item) {
  if (list->size <= list->used) {
    list->size *= 2;
    list->buffer = (any_t*)(realloc(list->buffer, list->size*sizeof(any_t)));
    if (!list->buffer) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return F;
#endif // #ifdef TICY_FAILURE_ALLOC
    }
  }
  list->buffer[list->used++] = item;
  return T;
}

const bool_t ticylist_remrange(struct TicyList *list, const sz_t start, sz_t n) {
       if (start < 0)          { return F; }
  else if (start > list->used) { return F; }
  else if (n < 1)              { return F; }
  if (n > list->used-start) { n = list->used; }
  struct TicyList *new_list = ticylist_new(list->used-n);
#ifndef TICY_FAILURE_ALLOC
  if (!new_list) { return F; }
#endif // #ifndef TICY_FAILURE_ALLOC
  for (sz_t index = 0; index < start; ++index)
  { ticylist_push(new_list, list->buffer[index]); }
  for (sz_t index = start+n; index < list->used; ++index)
  { ticylist_push(new_list, list->buffer[index]); }
  list->used = new_list->used;
  list->size = new_list->size;
  free(list->buffer);
  list->buffer = NULL;
  *list = *new_list;
  new_list->size = 0;
  new_list->used = 0;
  new_list->buffer = NULL;
  free(new_list);
  new_list = NULL;
  return T;
}

struct TicyList *ticylist_slice(struct TicyList *list, sz_t start, sz_t n) {
       if (!list)     { return NULL; }
  else if (start < 0) { return NULL; }
  else if (n < 1)     { return NULL; }
  if (n > list->used-start) { n = list->used; }
  struct TicyList* slice = ticylist_new(n);
#ifndef TICY_FAILURE_ALLOC
  if (!slice) { return NULL; }
#endif // #ifndef TICY_FAILURE_ALLOC
  for (; n >= 0; --n) { ticylist_push(slice, list->buffer[start++]); }
  return slice;
}

// Length of TicyFile's lines.
volatile sz_t TicyFile_line_length = 1024;

// File instance of TicyDB.
typedef struct TicyFile {
  // Path of file.
  str_t           path;
  // File content line-by-line.
  // Lines are heap-allocated.
  struct TicyList *lines;
} TicyFile;

// Returns heap-allocated TicyFile instance by specified path.
//
// Special cases are;
//  ticyfile_open(path) -> NULL if path == NULL
//  ticyfile_open(path) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticyfile_open(path) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyFile *ticyfile_open(const str_t path);
// Closes and frees heap-allocated TicyFile instance.
void ticyfile_close(struct TicyFile *tf);

struct TicyFile *ticyfile_open(const str_t path) {
  if (!path) { return NULL; }
  FILE *f = fopen(path, "r");
  if (!f) { return NULL; }
  struct TicyFile *tf = (struct TicyFile*)(malloc(sizeof(struct TicyFile)));
  if (!tf) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    fclose(f);
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  tf->path = path;
  tf->lines = ticylist_new(1);
  if (!tf->lines) {
    fclose(f);
    ticyfile_close(tf);
    return NULL;
  }
  const sz_t size_line = TicyFile_line_length*sizeof(str_t);
  while (T) {
    str_t line = (str_t)(malloc(size_line));
    if (!line) {
#ifdef TICY_FAILURE_ALLOC
      printf(TICY_ERROR_FAIL_ALLOC "\n");
      exit(ticy_exit_code_failure);
#else
      fclose(f);
      ticyfile_close(tf);
      return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
    }
    if (!fgets(line, size_line, f)) {
      free(line);
      line = NULL;
      break;
    }
    line[strlen(line)-1] = '\0';
    ticylist_push(tf->lines, line);
  }
  return tf;
}

void ticyfile_close(struct TicyFile *tf) {
  if (!tf) { return; }
  if (tf->lines) {
    for (sz_t index = 0; index < tf->lines->used; )
    { free((str_t)(tf->lines->buffer[index++])); }
    ticylist_free(tf->lines);
    tf->lines = NULL;
  }
  free(tf);
  tf = NULL;
}

// Key-Value store of TicyDB.
// Don't touch fields if you not sure that.
typedef struct TicyStore {
  // Keys of store.
  struct TicyList *keys;
  // Values of keys.
  struct TicyList *values;
} TicyStore;

// Returns heap-allocated TicyStore instance.
//
// Special case is;
//  ticystore_new(void) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticytore_new(void) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyStore *ticystore_new(void);
// Frees heap-allocated TicyStore instance.
// It's frees key and value lists but not frees these elements.
void ticystore_free(struct TicyStore *store);
// Set value o specified key.
// Creates a new key-value node if key is not exist.
// Returns true if created a new key-value node, returns false if not.
//
// Special cases are;
//  ticystore_set(store, key, value) -> F if key is can't pushed
//  ticystore_set(store, key, value) -> F if value is can't pushed
//  ticystore_set(store, key, value) -> F if store is NULL
const bool_t ticystore_set(struct TicyStore *store, const any_t key, const any_t value);
// Returns value o specified key.
//
// Special case is;
//  ticystore_get(store, key) -> NULL if store is NULL
//  ticystore_get(store, key) -> NULL if key is not exist
const any_t ticystore_get(const struct TicyStore *store, const any_t key);
// Reports specified TicyStore is have any key-value node or not.
//
// Special case is;
//  ticystore_any(store) -> F if store is NULL
const bool_t ticystore_any(const struct TicyStore *store);
// Returns index of key if key is exist, returns -1 if not in specified TicyStore.
//
// Special case is;
//  ticystore_existk(store, key) -> -1 if store is NULL
const sz_t ticystore_findk(const struct TicyStore *store, const any_t key);
// Returns index of key if value is exist, returns -1 if not in specified TicyStore.
//
// Special case is;
//  ticystore_existk(store, key) -> -1 if store is NULL
const sz_t ticystore_findv(const struct TicyStore *store, const any_t value);

struct TicyStore *ticystore_new(void) {
  struct TicyStore *store = (struct TicyStore*)(malloc(sizeof(struct TicyStore)));
  if (!store) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  store->keys = ticylist_new(1);
  if (!store->keys) {
    free(store);
    store = NULL;
    return NULL;
  }
  store->values = ticylist_new(1);
  if (!store->values) {
    free(store);
    store = NULL;
    return NULL;
  }
  return store;
}

void ticystore_free(struct TicyStore *store) {
  if (!store) { return; }
  if (store->keys) {
    ticylist_free(store->keys);
    store->keys = NULL;
  }
  if (store->values) {
    ticylist_free(store->values);
    store->values = NULL;
  }
  free(store);
  store = NULL;
}

const bool_t ticystore_set(struct TicyStore *store, const any_t key, const any_t value) {
  if (!store) { return F; }
  const sz_t index = ticystore_findk(store, key);
  if (index != -1) {
    store->values->buffer[index] = value;
    return F;
  }
  if (!ticylist_push(store->keys, key)) { return F; }
  if (!ticylist_push(store->values, value)) {
    store->keys->buffer[store->keys->used--] = NULL;
    return F;
  }
  return T;
}

const any_t ticystore_get(const struct TicyStore *store, const any_t key) {
  const sz_t index = ticystore_findk(store, key);
  return index == -1 ? NULL : store->values->buffer[index];
}

const bool_t ticystore_any(const struct TicyStore *store)
{ return (const bool_t)(store && store->keys->used > 0); }

const sz_t ticystore_findk(const struct TicyStore *store, const any_t key) {
  if (!store) { return -1; }
  for (sz_t index = 0; index < store->keys->used; ++index) {
    const any_t current_key = store->keys->buffer[index];
    if (key == current_key) { return index; }
  }
  return -1;
}

const sz_t ticystore_findv(const struct TicyStore *store, const any_t value) {
  if (!store) { return -1; }
  for (sz_t index = 0; index < store->values->used; ++index) {
    const any_t current_value = store->values->buffer[index];
    if (value == current_value) { return index; }
  }
  return -1;
}

// TicyDB connection instance.
typedef struct TicyDB {
  // This is a path of your TicyDB store file.
  // Don't touch this if you not sure that.
  str_t path;
} TicyDB;

// Returns heap-allocated TicyDB instance.
//
// Special case is;
//  ticydb_new(path) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydb_new(path) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyDB *ticydb_new(const str_t path);
// Frees heap-allocated TicyDB instance.
void ticydb_free(struct TicyDB *db);

struct TicyDB *ticydb_new(const str_t path) {
  struct TicyDB *db = (struct TicyDB*)(malloc(sizeof(struct TicyDB)));
  if (!db) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  db->path = path;
  return db;
}

void ticydb_free(struct TicyDB *db) {
  free(db);
  db = NULL;
}

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef __TICYDB_H
