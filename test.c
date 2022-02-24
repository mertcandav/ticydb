#include <stdio.h>

#define TICY_FAILURE_ALLOC
#include "ticydb.h"

void test_str_serialize() {
  const struct TicyData *data = ticydata_new("Hel\tlo", STR_T);
  const str_t serialized_data = ticydata_serialize(data);
  printf("%s\n", serialized_data);
  printf("%s\n", ticy_sds(serialized_data));
}

void test_ticyfile() {
  const struct TicyFile *tf = ticyfile_open("db.tcy");
  for (sz_t index = 0; index < tf->_lines->_used; ++index)
  { printf("%s\n", (char*)(tf->_lines->_buffer[index])); }
  printf("%s", tf->_text);
  ticyfile_close((TicyFile*)tf);
}

void test_lf_deserialize() {
  const str_t lf_str = "lf 90.5";
  const f64_t lf = ticy_lfds(lf_str);
  printf(TICY_FMT_LF, lf);
}

int main() {
  test_lf_deserialize();
  //struct TicyDB *db = ticydb_new("db.tcy");
  //ticystore_set(db->_Store, ticydata_new("Message", STR_T), ticydata_new("Hello World", STR_T));
  //ticystore_set(db->_Store, ticydata_new("Code", STR_T), ticydata_new((i32_t)(0), I32_T));
  //printf("%s", ticystore_serialize(db->_Store));
  //return 0x0;
  return EXIT_SUCCESS;
}
