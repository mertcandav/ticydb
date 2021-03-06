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
  const struct TicyData *_data = ticy_lfds(serialized_data);
  printf(TICY_FMT_LF, *(f64_t*)_data->_data);
}

void test_ticystore_serialize() {
  struct TicyStore *store = ticystore_new();
  ticystore_set(store, ticydata_new("Message", STR_T), ticydata_new("Hello World", STR_T));
  ticystore_set(store, ticydata_new((any_t)((i32_t)5), I32_T), ticydata_new("PI Number", STR_T));
  const str_t serialize_str = ticystore_serialize(store);
  printf("%s", serialize_str);
  struct TicyStore *_store = ticystore_deserialize(serialize_str);
  printf("%s\n", ticystore_get(_store, ticydata_ins("Message", STR_T))->_data);
  printf("%s\n", ticystore_get(_store, ticydata_ins((any_t)(5), I32_T))->_data);
}

void test_ticydata_serialize() {
  struct TicyData *data = ticydata_new("Hello\tTicyDB", STR_T);
  const str_t serialized_str = ticydata_serialize(data);
  printf("%s\n", serialized_str);
  struct TicyData *_data = (TicyData*)(ticydata_deserialize(serialized_str));
  printf("%s\n", _data->_data);
}

void test_ticydb() {
  struct TicyDB *db = ticydb_open("db.tcy");
  printf("%s\n", ticystore_get(db->_Store, ticydata_ins("Message", STR_T))->_data);
  printf("%f\n", *(f32_t*)(ticystore_get(db->_Store, ticydata_ins("PI_Number", STR_T))->_data));
}

void test_ticylist_serialize() {
  struct TicyList *list = ticylist_new(1);
  ticylist_push(list, ticydata_new("Hello World", STR_T));
  ticylist_push(list, ticydata_new((any_t)(89), I32_T));
  struct TicyList *_list = ticylist_new(1);
  ticylist_push(_list, ticydata_new("Hello World 22", STR_T));
  ticylist_push(_list, ticydata_new((any_t)(8989), I32_T));
  ticylist_push(list, ticydata_new(_list, TICYLIST_PTR));
  const str_t serialized_str = ticy_tls(*list);
  printf("%s\n", serialized_str);
  struct TicyData *_list_data = (struct TicyData*)(ticy_tlds(serialized_str));
  printf("%s\n", ticy_tls(*(struct TicyList*)(_list_data->_data)));
}

int main() {
  test_ticylist_serialize();
  return EXIT_SUCCESS;
}
