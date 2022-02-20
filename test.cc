#include <stdio.h>

#define TICY_FAILURE_ALLOC
#include "ticydb.h"

int main() {
  struct TicyFile *tf = ticyfile_open((const str_t)"db.tcy");
  for (sz_t index = 0; index < tf->lines->used; ++index)
  { printf("%s\n", tf->lines->buffer[index]); }
  ticyfile_close(tf);
  return EXIT_SUCCESS;
}
