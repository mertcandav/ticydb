#include <stdio.h>

#define TICY_FAILURE_ALLOC
#include "ticydb.h"

int main() {
  struct TicyData *data = ticydata_new("Hel\tlo", STR_T);
  const str_t serialized_data = ticydata_serialize(data);
  printf("%s\n", serialized_data);
  printf("%s\n", ticy_sds(serialized_data));
  return 0x0;
  //struct TicyDB *db = ticydb_new("db.tcy");
  //ticystore_set(db->_Store, ticydata_new("Message", STR_T), ticydata_new("Hello World", STR_T));
  //ticystore_set(db->_Store, ticydata_new("Code", STR_T), ticydata_new((i32_t)(0), I32_T));
  //printf("%s", ticystore_serialize(db->_Store));
  //return 0x0;
  struct TicyFile *tf = ticyfile_open("db.tcy");
  //for (sz_t index = 0; index < tf->_lines->_used; ++index)
  //{ printf("%s\n", (char*)(tf->_lines->_buffer[index])); }
  //printf("%s", tf->_text);
  //struct TicyStore *ticys = ticystore_deserialize(tf->_text);
  ticyfile_close(tf);
  return EXIT_SUCCESS;
}
