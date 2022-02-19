# TicyDB - Custom Defines

If you define these defines before include the TicyDB, you can manuplation somewhere of TicyDB.

<table>
  <thead>
    <tr>
      <td>Define</td>
      <td>Description</td>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>TICY_FAILURE_ALLOC</td>
      <td>TicyDB, exits program with exit code if any allocation is failed</td>
    </tr>
  </tbody>
</table>

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
