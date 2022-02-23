#include <stdio.h>

#define TICY_FAILURE_ALLOC
#include "ticydb.h"

int main() {
  //struct TicyDB *db = ticydb_new("db.tcy");
  //ticystore_set(db->_Store, ticydata_new("Message", STR_T), ticydata_new("Hello World", STR_T));
  //ticystore_set(db->_Store, ticydata_new("Code", STR_T), ticydata_new((i32_t)(0), I32_T));
  //printf("%s", ticystore_serialize(db->_Store));
  //return 0x0;
  struct TicyFile *tf = ticyfile_open("db.tcy");
  //for (sz_t index = 0; index < tf->_lines->_used; ++index)
  //{ printf("%s\n", (char*)(tf->_lines->_buffer[index])); }
  //printf("%s", tf->_text);

}
