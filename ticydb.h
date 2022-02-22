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
  TICYLIST     = 13, // TicyList instance code.
  TICYLIST_PTR = 14, // TicyList instance pointer code.
  SZ_T         = 15, // Size type code.
  OTHER_T      = 16  // Code of other data-types.
} TicyTypeCode;

#ifdef TICY_FAILURE_ALLOC
// Exit code of TicyDB for failures.
volatile i32_t Ticy_Exit_Code_Failure = 1;

// Error message of allocation failures.
#define TICY_ERROR_FAIL_ALLOC "allocation is failed"
#endif // #ifdef TICY_FAILURE_ALLOC

// Buffer size of various operations of TicyDB.
volatile sz_t Ticy_Buffer_Size = 128;

// Returns specified any_t as string (heap-allocated) with i8_t type format.
//
// Special cases are;
//  ticy_i8s(_Hi) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_i8s(_Hi) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_his(const any_t _Hi);
// Returns specified any_t as string (heap-allocated) with i16_t, i32_t, bool_t type formats.
//
// Special cases are;
//  ticy_ds(_D) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_ds(_D) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_ds(const any_t _D);
// Returns specified any_t as string (heap-allocated) with i64_t type format.
//
// Special cases are;
//  ticy_lds(_Lld) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_lds(_Lld) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_llds(const any_t _Lld);
// Returns specified any_t as string (heap-allocated) with u8_t type format.
//
// Special cases are;
//  ticy_hus(_Hu) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_hus(_Hu) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_hus(const any_t _Hu);
// Returns specified any_t as string (heap-allocated) with u16_t, u32_t, sz_t type format.
//
// Special cases are;
//  ticy_us(_U) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_us(_U) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_us(const any_t _U);
// Returns specified any_t as string (heap-allocated) with u64_t type format.
//
// Special cases are;
//  ticy_u64s(_Llu) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_u64s(_Llu) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_llus(const any_t _Llu);
// Returns specified any_t as string (heap-allocated) with f32_t type format.
//
// Special cases are;
//  ticy_f32s(_F) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_f32s(_F) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_fs(const any_t _F);
// Returns specified any_t as string (heap-allocated) with f64_t type format.
//
// Special cases are;
//  ticy_f64s(_Lf) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticy_f64s(_Lf) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticy_lfs(const any_t _Lf);

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
  sprintf(_str, "%hi", (intptr_t)(_Hi));
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
  sprintf(_str, "%d", (intptr_t)(_D));
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
  sprintf(_str, "%lld", _Lld);
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
  sprintf(_str, "%hu", (uintptr_t)(_Hu));
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
  sprintf(_str, "%u", (uintptr_t)(_U));
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
  sprintf(_str, "%llu", _Llu);
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
  sprintf(_str, "%f", *(f32_t*)(_F));
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
  sprintf(_str, "%lf", *(f64_t*)(_Lf));
  return _str;
}

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

// Returns new TicyData instance heap-allocated by data and type code.
//
// Special case is:
//  ticydata_new(_Data, _Ticytc) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydata_new(_Data, _Ticytc) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyData *ticydata_new(const any_t _Data, const TicyTypeCode _Ticytc);
// Frees TicyData instance allocated from heap.
// This is not frees data.
void ticydata_free(struct TicyData *_Ticyd);
// Returns string (heap-allocated) value of specified TicyData.
//
// Special cases are;
//  ticydata_s(_Ticyd) -> NULL if data is NULL
//  ticydata_s(_Ticyd) -> "" if type code is not supported
//  ticydata_s(_Ticyd) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydata_s(_Ticyd) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticydata_s(const struct TicyData *_Ticyd);

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
  _ticyd->_data = _Data;
  _ticyd->_type = _Ticytc;
  return _ticyd;
}

void ticydata_free(struct TicyData *_Ticyd) {
  free(_Ticyd);
  _Ticyd = NULL;
}

const str_t ticydata_s(const struct TicyData *_Ticyd) {
  if (!_Ticyd) { return NULL; }
  if (_Ticyd->_type == STR_T) {
    str_t _str = (str_t)(malloc(2*sizeof(char_t)));
    if (!_str) {
#ifdef TICY_FAILURE_ALLOC
      printf(TICY_ERROR_FAIL_ALLOC "\n");
      exit(Ticy_Exit_Code_Failure);
#else
      return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
    }
    _str[0] = '"';
    _str[1] = '\0';
    const str_t _data_str = strdup((const char*)(_Ticyd->_data));
    strcat(_str, _data_str);
    strcat(_str, "\"\0");
    return _str;
  } else if (_Ticyd->_type == CHAR_T) {
    str_t _str = (str_t)(malloc(4*sizeof(char_t)));
    if (!_str) {
#ifdef TICY_FAILURE_ALLOC
      printf(TICY_ERROR_FAIL_ALLOC "\n");
      exit(Ticy_Exit_Code_Failure);
#else
      return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
    }
    _str[0] = '\'';
    _str[1] = (char_t)(_Ticyd->_data);
    _str[2] = '\'';
    _str[3] = '\0';
    return _str;
  }
  switch (_Ticyd->_type) {
  // case SBYTE_T:
  case I8_T:   return ticy_his(_Ticyd->_data);
  case I16_T:  return ticy_ds(_Ticyd->_data);
  case I32_T:  return ticy_ds(_Ticyd->_data);
  case I64_T:  return ticy_llds(_Ticyd->_data);
  // case BYTE_T:
  case U8_T:   return ticy_hus(_Ticyd->_data);
  case U16_T:  return ticy_us(_Ticyd->_data);
  // case BOOL_T:
  case SZ_T:
  case U32_T:  return ticy_us(_Ticyd->_data);
  case U64_T:  return ticy_llus(_Ticyd->_data);
  case F32_T:  return ticy_fs(_Ticyd->_data);
  case F64_T:  return ticy_lfs(_Ticyd->_data);
  default:     break;
  }
  str_t _str = (str_t)(malloc(2*sizeof(char_t)));
  if (!_str) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _str[0] = '"';
  _str[1] = '\0';
  strcat(_str, "\"\0");
  return _str;
}

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
  else if (_Start > _Ticyl->_used) { return F; }
  else if (_Count < 1)             { return F; }
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
  else if (_Start < 0) { return NULL; }
  else if (_Count < 1) { return NULL; }
  if (_Count > _Ticyl->_used-_Start) { _Count = _Ticyl->_used; }
  struct TicyList* _slice = ticylist_new(_Count);
#ifndef TICY_FAILURE_ALLOC
  if (!_slice) { return NULL; }
#endif // #ifndef TICY_FAILURE_ALLOC
  for (; _Count >= 0; --_Count)
  { ticylist_push(_slice, _Ticyl->_buffer[_Start++]); }
  return _slice;
}

// Length of TicyFile's lines.
volatile sz_t TicyFile_Line_Length = 1024;

// File instance of TicyDB.
typedef struct TicyFile {
  // Path of file.
  str_t           _path;
  // File content line-by-line.
  // Lines are heap-allocated.
  // Don't change if you not sure that.
  struct TicyList *_lines;
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
  _ticyf->_path = _Path;
  _ticyf->_lines = ticylist_new(1);
  if (!_ticyf->_lines) {
    fclose(_file);
    ticyfile_close(_ticyf);
    return NULL;
  }
  const sz_t _line_length = TicyFile_Line_Length*sizeof(str_t);
  while (T) {
    str_t _line = (str_t)(malloc(_line_length));
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
    if (!fgets(_line, _line_length, _file)) {
      free(_line);
      _line = NULL;
      break;
    }
    _line[strlen(_line)-1] = '\0';
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
  free(_Ticyf);
  _Ticyf = NULL;
}

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
const TicyData *ticystore_get(const struct TicyStore *_Ticys, const any_t *_Key);
// Reports specified TicyStore is have any key-value node or not.
//
// Special case is;
//  ticystore_any(_Ticys) -> F if store is NULL
const bool_t ticystore_any(const struct TicyStore *_Ticys);
// Returns index of key value if key value is exist, returns -1 if not in specified TicyStore.
//
// Special case is;
//  ticystore_existk(_Ticys, _Key) -> -1 if store is NULL
const sz_t ticystore_findk(const struct TicyStore *_Ticys, const any_t *_Key);
// Returns index of key of value if value is exist, returns -1 if not in specified TicyStore.
//
// Special case is;
//  ticystore_existk(_Ticys, _Key) -> -1 if store is NULL
const sz_t ticystore_findv(const struct TicyStore *_Ticys,
                           const any_t _Value);
// Returns serialize TicyStore as string (heap-allocated).
//
// Special cases are;
//  ticystore_serialize(_Ticys) -> NULL if store is NULL
//  ticystore_serialize(_Ticys) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticystore_serialize(_Ticys) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
const str_t ticystore_serialize(const struct TicyStore *_Ticys);

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
  const sz_t _index = ticystore_findk(_Ticys, _Key->_data);
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
                              const any_t *_Key) {
  const sz_t _index = ticystore_findk(_Ticys, _Key);
  return _index == -1 ? NULL : (TicyData*)(_Ticys->_values->_buffer[_index]);
}

const bool_t ticystore_any(const struct TicyStore *_Ticys)
{ return (const bool_t)(_Ticys && _Ticys->_keys->_used > 0); }

const sz_t ticystore_findk(const struct TicyStore *_Ticys,
                           const any_t *_Key) {
  if (!_Ticys) { return -1; }
  for (sz_t _index = 0; _index < _Ticys->_keys->_used; ++_index) {
    const TicyData *_key = (TicyData*)(_Ticys->_keys->_buffer[_index]);
    if (_Key == _key->_data) { return _index; }
  }
  return -1;
}

const sz_t ticystore_findv(const struct TicyStore *_Ticys,
                           const any_t _Value) {
  if (!_Value) { return -1; }
  for (sz_t _index = 0; _index < _Ticys->_values->_used; ++_index) {
    const TicyData *_value = (TicyData*)(_Ticys->_values->_buffer[_index]);
    if (_Value == _value->_data) { return _index; }
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
    const str_t _key_str = ticydata_s(_key);
    if (!_key_str) {
#ifndef TICY_FAILURE_ALLOC
      free(_str);
      _str = NULL;
      return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
    }
    const TicyData *_value = (TicyData*)(_Ticys->_values->_buffer[_index]);
    const str_t _value_str = ticydata_s(_value);
    if (!_key_str) {
#ifndef TICY_FAILURE_ALLOC
      free(_key_str);
      _key_str = NULL;
      free(_str);
      _str = NULL;
      return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
    }
    strcat(_str, _key_str);
    strcat(_str, " ");
    strcat(_str, _value_str);
    strcat(_str, "\n\0");
  }
  return _str;
}

// TicyDB connection instance.
typedef struct TicyDB {
  // This is a path of your TicyDB store file.
  // Don't touch this if you not sure that.
  str_t _path;
} TicyDB;

// Returns heap-allocated TicyDB instance.
//
// Special case is;
//  ticydb_new(_Path) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticydb_new(_Path) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyDB *ticydb_new(const str_t _Path);
// Frees heap-allocated TicyDB instance.
void ticydb_free(struct TicyDB *_Ticydb);

struct TicyDB *ticydb_new(const str_t _Path) {
  struct TicyDB *_Ticydb = (struct TicyDB*)(malloc(sizeof(struct TicyDB)));
  if (!_Ticydb) {
#ifdef TICY_FAILURE_ALLOC
    printf(TICY_ERROR_FAIL_ALLOC "\n");
    exit(Ticy_Exit_Code_Failure);
#else
    return NULL;
#endif // #ifdef TICY_FAILURE_ALLOC
  }
  _Ticydb->_path = _Path;
  return _Ticydb;
}

void ticydb_free(struct TicyDB *_Ticydb) {
  free(_Ticydb);
  _Ticydb = NULL;
}

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef __TICYDB_H
