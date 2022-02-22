# TicyDB - Custom Preprocessor Defines

If you define these defines before include the TicyDB, you can manuplation somewhere of TicyDB.

## ``TICY_FAILURE_ALLOC``
TicyDB, exits program with exit code if any allocation is failed.

### Related Defines
```c
// Exit code of TicyDB for failures.
volatile i32_t Ticy_Exit_Code_Failure;
```

### Related Preprocessor Defines
```c
// Error message of allocation failures.
#define TICY_ERROR_FAIL_ALLOC
```


## Example
```c
#include <stdio.h>

#define TICY_FAILURE_ALLOC
#include "ticydb.h"

int main() {
  // ticyfile_open is exits with error message if any allocation failed
  struct TicyFile *tf= ticyfile_open("db.tcy");
  for (sz_t index = 0; index < tf->lines->used; ++index)
  { printf("%s\n", tf->lines->buffer[index]); }
  ticyfile_close(tf);
  return EXIT_SUCCESS;
}
```
