#include <stdlib.h>
#include <stdio.h>

#include "../ticydb.h"

struct TicyDB *db;
struct TicyList *admins;

static inline void init() {
  db = ticydb_open("examples/admins.tcy");
  struct TicyData key = ticydata_ins("Admins", STR_T);
  admins = (struct TicyList*)(ticystore_get(db->_Store, key)->_data);
}

const i32_t find_admin(const str_t username) {
  struct TicyData username_data = ticydata_ins(username, STR_T);
  for (sz_t index = 0; index < admins->_used; ++index) {
    const struct TicyList *profile = (struct TicyList*)(((struct TicyData*)(admins->_buffer[index]))->_data);
    const struct TicyData admin_username = *(struct TicyData*)(profile->_buffer[0]);
    if (ticydata_eqs(username_data, admin_username)) { return index; }
  }
  return -1;
}

void login() {
  char_t username[Ticy_Buffer_Size];
  char_t password[Ticy_Buffer_Size];
  printf("Login to admin terminal;\n");
  while (T) {
    printf("Username: ");
    scanf(" %s", &username);
    printf("Password: ");
    scanf(" %s", &password);
    const i32_t index = find_admin(username);
    if (index == -1) { goto wrong; }
    const struct TicyList *profile = (struct TicyList*)(((struct TicyData*)(admins->_buffer[index]))->_data);
    const struct TicyData admin_password = *(struct TicyData*)(profile->_buffer[1]);
    const struct TicyData password_data = ticydata_ins(password, STR_T);
    if (!ticydata_eqs(admin_password, password_data)) { goto wrong; }
    printf("Successful login\n\n");
    break;
  wrong:
    printf("Username or password is wrong\n\n");
  }
}

void manuplate_admin() {
  printf("Username: ");
  char username[Ticy_Buffer_Size];
  scanf(" %s", &username);
  printf("Password (write - to delete admin profile): ");
  char password[Ticy_Buffer_Size];
  scanf(" %s", &password);
  const sz_t index = find_admin(username);
  if (index == -1) {
    if (strcmp(password, "-") == 0) {
      printf("Admin profile is can't deleted becaused not exist in this username: %s\n", username);
      return;
    }
    const struct TicyData *username_data = ticydata_new(username, STR_T);
    const struct TicyData *password_data = ticydata_new(password, STR_T);
    struct TicyList *admin_profile = ticylist_new(2);
    ticylist_push(admin_profile, (any_t)(username_data));
    ticylist_push(admin_profile, (any_t)(password_data));
    ticylist_push(admins, ticydata_new(admin_profile, TICYLIST_PTR));
    ticydb_keep(db);
    printf("Created new admin profile: %s\n", username);
    return;
  }
  if (strcmp(password, "-") == 0) {
    ticylist_remrange(admins, index, 1);
    ticydb_keep(db);
    printf("Deleted admin profile: %s\n", username);
    return;
  }
  const struct TicyList *profile = (struct TicyList*)(((struct TicyData*)(admins->_buffer[index]))->_data);
  struct TicyData *admin_password = (struct TicyData*)(profile->_buffer[1]);
  admin_password->_data = password;
  ticydb_keep(db);
  printf("Updated admin profile: %s\n", username);
}

void list_admins() {
  printf("USERNAME - PASSWORDS\n");
  for (sz_t index = 0; index < admins->_used; ++index) {
    const struct TicyList *profile = (struct TicyList*)(((struct TicyData*)(admins->_buffer[index]))->_data);
    const struct TicyData *username = (struct TicyData*)(profile->_buffer[0]);
    const struct TicyData *password = (struct TicyData*)(profile->_buffer[1]);
    printf("%s - %s\n", ticydata_serialize(username), ticydata_serialize(password));
  }
}

int main() {
  init();
  login();
  printf("%s\n%s\n%s\n", "0 - Exit", "1 - Manuplate admins", "2 - List admin profiles");
  char_t input[Ticy_Buffer_Size];
  while (T) {
    printf("Choice your operation: ");
    scanf(" %s", &input);
    if (strcmp(input, "0") == 0) { break; }
    if (strcmp(input, "1") == 0) {
      manuplate_admin();
      continue;
    }
    if (strcmp(input, "2") == 0) {
      list_admins();
      continue;
    }
    printf("Invalid choice\n");
  }
  ticydb_close(db);
  return EXIT_SUCCESS;
}
