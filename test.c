#include <stdio.h>

#define TICY_FAILURE_ALLOC
#include "ticydb.h"

int main() {
  struct TicyStore *store = ticystore_new();
  ticystore_set(store, ticydata_new("Message", STR_T), ticydata_new("Hello World", STR_T));
  ticystore_set(store, ticydata_new("Code", STR_T), ticydata_new((i32_t)(0), I32_T));
  printf("%s", ticystore_serialize(store));
  return 0x0;
  struct TicyFile *tf = ticyfile_open("db.tcy");
  for (sz_t index = 0; index < tf->_lines->_used; ++index)
  { printf("%s\n", (char*)(tf->_lines->_buffer[index])); }
  ticyfile_close(tf);
  return EXIT_SUCCESS;
}
