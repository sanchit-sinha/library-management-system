#include "bits/stdc++.h"
#include "fstream"
using namespace std;

// function protypes
void login();
void enter_library();
void student_page();
void librarian_page();
void professor_page();
void logout();

#include "utils.cpp"

// global containers for storing databases
map<string, Book*> books;
map<string, User*> users;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    // db_users.open(DB_USER);
    // string user_sno, user_name, user_id, user_password, user_role;
    // while (db_users >> user_sno >> user_name >> user_id >> user_password >> user_role) {
    //     User* new_user = new User(user_name, user_id, user_password);
    //     users[user_sno] = new_user;
    // }
    // db_users.close();

    enter_library();
}
