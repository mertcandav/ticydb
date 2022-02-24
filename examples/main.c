#include <stdlib.h>
#include <stdio.h>

#include "../ticydb.h"

int main() {
  struct TicyDB *db = ticydb_new("examples/admins.tcy");
  struct TicyData key = ticydata_ins("Admins", STR_T);
  struct TicyList *admins = (struct TicyList*)(ticystore_get(db->_Store, key)->_data);
  char_t username[Ticy_Buffer_Size];
  char_t password[Ticy_Buffer_Size];
  bool_t login = F;
  while (!login) {
    printf("Username: ");
    scanf("%s", &username);
    printf("Password: ");
    scanf(" %s", &password);
    const struct TicyData username_data = ticydata_ins(username, STR_T);
    const struct TicyData password_data = ticydata_ins(password, STR_T);
    for (sz_t index = 0; index < admins->_used; ++index) {
      struct TicyList *admin_profile = (struct TicyList*)(((struct TicyData*)(admins->_buffer[index]))->_data);
      const struct TicyData admin_username = *(struct TicyData*)(admin_profile->_buffer[0]);
      const struct TicyData admin_password = *(struct TicyData*)(admin_profile->_buffer[1]);
      if (!ticydata_eqs(username_data, admin_username)) { continue; }
      if (!ticydata_eqs(password_data, admin_password)) { continue; }
      login = T;
      break;
    }
    if (!login) { printf("Username or password is wrong\n"); }
  }
  printf("Successful login\n");
  ticydb_free(db);
  return EXIT_SUCCESS;
}
