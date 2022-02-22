# TicyDB - TicyFile

## Define
```c
// File instance of TicyDB.
typedef struct TicyFile {
  // Path of file.
  str_t           path;
  // File content line-by-line.
  // Lines are heap-allocated.
  struct TicyList *lines;
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
//  ticyfile_open(path) -> NULL if path == NULL
//  ticyfile_open(path) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC
//  ticyfile_open(path) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC
struct TicyFile *ticyfile_open(const str_t path);
```

```c
// Closes and frees heap-allocated TicyFile instance.
void ticyfile_close(struct TicyFile *tf);
```
