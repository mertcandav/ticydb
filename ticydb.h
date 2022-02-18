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

typedef   __INT8_TYPE__                            i8_t     ; // Signed 8-bit integer type.
typedef   __INT16_TYPE__                           i16_t    ; // Signed 16-bit integer type.
typedef   __INT32_TYPE__                           i32_t    ; // Signed 32-bit integer type.
typedef   __INT64_TYPE__                           i64_t    ; // Signed 64-bit integer type.
typedef   __UINT8_TYPE__                           u8_t     ; // Unsigned 8-bit integer type.
typedef   __UINT16_TYPE__                          u16_t    ; // Unsigned 16-bit integer type.
typedef   __UINT32_TYPE__                          u32_t    ; // Unsigned 32-bit integer type.
typedef   __UINT64_TYPE__                          u64_t    ; // Unsigned 65-bit integer type.
typedef   float                                    f32_t    ; // 32-bit float type.
typedef   double                                   f64_t    ; // 64-bit float type.
typedef   wchar_t*                                 str_t    ; // String type.
typedef   enum bool_t {false = 0, true = !false}   bool_t   ; // Boolean type.

// TicyDB connection instance.
typedef struct TicyDB {
  str_t path;
} TicyDB;

// Returns heap-allocated TicyDB instance.
//
// Special case is;
//  ticydb_new(path) -> NULL if allocation is failed.
struct TicyDB *ticydb_new(const str_t path) {
  struct TicyDB *db = (struct TicyDB*)(malloc(sizeof(struct TicyDB)));
  if (!db) { return NULL; }
  db->path = path;
  return db;
}

// Frees heap-allocated TicyDB instances.
void ticydb_free(struct TicyDB *db) {
  free(db);
  db = NULL;
}

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef __TICYDB_H
