# TicyDB - TicyFile

File instance of TicyDB.

## Fields
+ ``path`` <br>
  Path of file.
+ ``lines`` <br>
  File content line-by-line.
  Lines are heap-allocated.

## Related Functions
```c
struct TicyFile *ticyfile_open(const str_t path);
```
Returns heap-allocated TicyFile instance by specified path. <br>
<br>
Special cases are; <br>
ticyfile_open(path) -> NULL if path == NULL <br>
ticyfile_open(path) -> NULL if allocation is failed and #ifndef TICY_FAILURE_ALLOC <br>
ticyfile_open(path) -> exit if allocation is failed and #ifdef TICY_FAILURE_ALLOC

# 

```c
struct TicyFile *ticyfile_close(struct TicyFile *tf);
```
Closes and frees heap-allocated TicyFile instance.
