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

// Returns TicyDB data-type code of specified data.
// The return value is TicyTypeCode.
// Example: ticy_typename(x) -> U32_T
//
// Special cases are;
//  ticy_typecode(x) -> U32_T if x is bool_t
//  ticy_typecode(x) -> U8_T if x is byte_t
//  ticy_typecode(x) -> I8_T if x is sbyte_t
//  ticy_typecode(x) -> U32_T if x is sz_t
#define ticy_typecode(x) _Generic((x), \
  i8_t:        I8_T,                   \
  i16_t:       I16_T,                  \
  i32_t:       I32_T,                  \
  i64_t:       I64_T,                  \
  u8_t:        U8_T,                   \
  u16_t:       U16_T,                  \
  u32_t:       U32_T,                  \
  u64_t:       U64_T,                  \
  f32_t:       F32_T,                  \
  f64_t:       F64_T,                  \
  char_t:      CHAR_T,                 \
  str_t:       STR_T,                  \
  any_t:       ANY_T,                  \
  TicyList:    TICYLIST,               \
  TicyList*:   TICYLIST_PTR,           \
  default:     OTHER_T                 \
)

// Dynamic list implementation of TicyDB.
typedef struct TicyList {
  // Element buffer.
  any_t *buffer;
  // Allocated element count.
  sz_t  used;
  // Total element count.
  sz_t  size;
} TicyList;

// Create new TicyList instance allocated from heap by specified size.
//
// Special case is:
//  ticylist_new(size) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticylist_new(size) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
//  ticylist_new(size) -> accept size as 1 if size < 1
struct TicyList *ticylist_new(sz_t size);
// Free TicyList instance allocated from heap.
void ticylist_free(struct TicyList *list);
// Appends item to TicyList.
// Returns true if success, returns false if failed.
//
// Special case is;
//  ticylist_push(list, item) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
bool_t ticylist_push(struct TicyList *list, any_t item);
// Removes n elements starts at specified index.
// If n greater than size, uses size instead of n.
// Returns true if success, returns false is not.
//
// Special cases are:
//  ticylist_remrange(list, start, n) -> F if n < 1
//  ticylist_remrange(list, start, n) -> F if start < 0
//  ticylist_remrange(list, start, n) -> F if start > size
//  ticylist_remrange(list, start, n) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
bool_t ticylist_remrange(struct TicyList* list, const sz_t start, sz_t n);
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

bool_t ticylist_push(struct TicyList* list, any_t item) {
  if (list->size <= list->used) {
    list->size *= 2;
    list->buffer = realloc(list->buffer, list->size*sizeof(any_t));
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

bool_t ticylist_remrange(struct TicyList *list, const sz_t start, sz_t n) {
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
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(ticy_exit_code_failure);
#else
    fclose(f);
    ticyfile_close(tf);
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
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
