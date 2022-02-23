# TicyDB - TicyFile

## Define
```c
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
```

## Releated Defines
```c
// Length of TicyFile's lines.
volatile sz_t TicyFile_Line_Length;
```

## Related Functions
```c
// Returns heap-allocated TicyFile instance by specified path.
//
// Special cases are;
//  ticyfile_open(_Path) -> NULL if path == NULL
//  ticyfile_open(_Path) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticyfile_open(_Path) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyFile *ticyfile_open(const str_t _Path);
```

```c
// Closes and frees heap-allocated TicyFile instance.
void ticyfile_close(struct TicyFile * _Ticyf);
```
