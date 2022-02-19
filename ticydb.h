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
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

typedef   enum _ {F = 0, T = !F}   bool_t   ; // Boolean type.
typedef   __INT8_TYPE__            i8_t     ; // Signed 8-bit integer type.
typedef   __INT16_TYPE__           i16_t    ; // Signed 16-bit integer type.
typedef   __INT32_TYPE__           i32_t    ; // Signed 32-bit integer type.
typedef   __INT64_TYPE__           i64_t    ; // Signed 64-bit integer type.
typedef   __UINT8_TYPE__           u8_t     ; // Unsigned 8-bit integer type.
typedef   __UINT16_TYPE__          u16_t    ; // Unsigned 16-bit integer type.
typedef   __UINT32_TYPE__          u32_t    ; // Unsigned 32-bit integer type.
typedef   __UINT64_TYPE__          u64_t    ; // Unsigned 65-bit integer type.
typedef   float                    f32_t    ; // 32-bit float type.
typedef   double                   f64_t    ; // 64-bit float type.
typedef   wchar_t                  *str_t   ; // String type.
typedef   void                     *any_t   ; // Any type for any data.

// Dynamic list implementation of TicyDB.
typedef struct TicyList {
  any_t  *array;
  size_t used;
  size_t size;
} TicyList;

// Create new TicyList instance allocated from heap by specified size.
//
// Special case is:
//  ticylist_new(size) -> NULL if allocation is failed
//  ticylist_new(size) -> accept size as 1 if size < 1
struct TicyList *ticylist_new(size_t size);
// Free TicyList instance allocated from heap.
void ticylist_free(struct TicyList *list);
// Appends item to TicyList.
// Returns true if success, returns false if failed.
bool_t ticylist_push(struct TicyList *list, any_t item);
// Removes n elements starts at specified index.
// If n greater than size, uses size instead of n.
// Returns true if success, returns false is not.
//
// Special cases are:
//  ticylist_remrange(list, start, n) -> F if n < 1
//  ticylist_remrange(list, start, n) -> F if start < 0
//  ticylist_remrange(list, start, n) -> F if start > size
bool_t ticylist_remrange(struct TicyList* list, const size_t start, size_t n);
// Returns new TicyList from source list by specified index and n.
// If n greater than size, uses size instead of n.
//
// Special cases are:
//  ticylist_slice(list, start, n) -> NULL if failed
//  ticylist_slice(list, start, n) -> NULL if list == NULL
//  ticylist_slice(list, start, n) -> NULL if n < 1
//  ticylist_slice(list, start, n) -> NULL if start < 0
//  ticylist_slice(list, start, n) -> NULL if start > size
struct TicyList *ticylist_slice(struct TicyList *list, size_t start, size_t n);

struct TicyList *ticylist_new(size_t size) {
  struct TicyList *list = (struct TicyList*)(malloc(sizeof(struct TicyList)));
  if (!list) { return NULL; }
  size = size < 1 ? 1 : size;
  list->array = (void**)(malloc(size*sizeof(any_t)));
  if (!list->array) { return NULL; }
  list->used = 0;
  list->size = size;
  return list;
}

void ticylist_free(struct TicyList *list) {
  if (!list) { return; }
  free(list->array);
  list->array = NULL;
  list->used = 0;
  list->size = 0;
  free(list);
  list = NULL;
}

bool_t ticylist_push(struct TicyList* list, any_t item) {
  if (list->size <= list->used) {
    list->size *= 2;
    list->array = realloc(list->array, list->size*sizeof(any_t));
    if (!list->array) { return F; }
  }
  list->array[list->used++] = item;
  return T;
}

bool_t ticylist_remrange(struct TicyList *list, const size_t start, size_t n) {
       if (start < 0)          { return F; }
  else if (start > list->used) { return F; }
  else if (n < 1)              { return F; }
  if (n > list->used-start) { n = list->used; }
  struct TicyList *new_list = ticylist_new(list->used-n);
  if (!new_list) { return F; }
  for (size_t index = 0; index < start; ++index)
  { ticylist_push(new_list, list->array[index]); }
  for (size_t index = start+n; index < list->used; ++index)
  { ticylist_push(new_list, list->array[index]); }
  list->used = new_list->used;
  list->size = new_list->size;
  free(list->array);
  list->array = NULL;
  *list = *new_list;
  new_list->size = 0;
  new_list->used = 0;
  new_list->array = NULL;
  free(new_list);
  new_list = NULL;
  return T;
}

struct TicyList *ticylist_slice(struct TicyList *list, size_t start, size_t n) {
       if (!list)     { return NULL; }
  else if (start < 0) { return NULL; }
  else if (n < 1)     { return NULL; }
  if (n > list->used-start) { n = list->used; }
  struct TicyList* slice = ticylist_new(n);
  if (!slice) { return NULL; }
  for (; n >= 0; --n) { ticylist_push(slice, list->array[start++]); }
  return slice;
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
//  ticydb_new(path) -> NULL if allocation is failed
struct TicyDB *ticydb_new(const str_t path);
// Frees heap-allocated TicyDB instances.
void ticydb_free(struct TicyDB *db);

struct TicyDB *ticydb_new(const str_t path) {
  struct TicyDB *db = (struct TicyDB*)(malloc(sizeof(struct TicyDB)));
  if (!db) { return NULL; }
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
