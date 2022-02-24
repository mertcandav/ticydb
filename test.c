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

void test_lf_serialize() {
  const f64_t _lf = 90.5;
  const struct TicyData *data = ticydata_new((any_t)(&_lf), F64_T);
  const str_t serialized_data = ticydata_serialize(data);
  printf("%s\n", serialized_data);
  const f64_t lf = ticy_lfds(serialized_data);
  printf(TICY_FMT_LF, lf);
}

void test_ticystore_serialize() {
  struct TicyStore *store = ticystore_new();
  ticystore_set(store, ticydata_new("Message", STR_T), ticydata_new("Hello World", STR_T));
  ticystore_set(store, ticydata_new("Code", STR_T), ticydata_new((i32_t)(0), I32_T));
  printf("%s", ticystore_serialize(store));
}

int main() {
  test_ticystore_serialize();
  return EXIT_SUCCESS;
}
