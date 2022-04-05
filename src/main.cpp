#include "bits/stdc++.h"
#include "fstream"
using namespace std;

#include "model.h"
#include "views.cpp"
#include "urls.cpp"


// function protypes
void login();
void enter_library();
void student_page();
void librarian_page();
void professor_page();
void logout();

// global containers for storing databases
map<string, Book*> books;
map<string, User*> users;


void enter_library() {
    ifstream fin;
    fin.open(DB_COOKIE);
    string s_no, user_name, user_id, user_password, role; // in user.txt
    fin >> s_no >> user_name >> user_id >> user_password >> role;
    fin.close();

    if (s_no == "") {
        cout << "Welcome to library" << endl;
        login();
    }
    else {
        if (role == "Student") {
            cout << "Welcome " << user_name << endl;
            cout << "You are logged in as Student" << endl;
            cout << endl;
            student_page();
        }
        else if (role == "Librarian") {
            cout << "Welcome " << user_name << endl;
            cout << "You are logged in as Librarian" << endl;
            cout << endl;
            librarian_page();
        }
        else if (role == "Professor") {
            cout << "Welcome " << user_name << endl;
            cout << "You are logged in as Professor" << endl;
            cout << endl;
            professor_page();
        }
        return;
    }
    return;
}

// login in to the system
void login() {
    cout << "Welcome to Library Management System !" << endl;
    cout << "*****************************" << endl;

    string username, password;
    cout << "Enter your username" << endl;
    cin >> username;

    cout << "Enter your password" << endl;
    cin >> password;

    cout << endl;

    ifstream fin;
    fin.open(DB_USER);

    string s_no, user_name, user_id, user_password, role; // in user.txt
    while (fin >> s_no >> user_name >> user_id >> user_password >> role) {
        if (user_name == username && user_password == password) {
            ofstream fout;
            fout.open(DB_COOKIE);
            fout << s_no << " " << user_name << " " << user_id << " " << user_password << " " << role << endl;
            fout.close();

            enter_library();
            return;
        }
    }

    fin.close();
    cout << "Invalid Credentials! Kindly repeat the process" << endl;
    login();

    return;
}

// logout the user 
void logout() {
    ofstream fout;
    fout.open(DB_COOKIE);
    fout.close();

    login();
    return;
}

// Student , Librarian, Professor
void student_page() {
    ifstream fin;
    fin.open(DB_COOKIE);
    string s_no, user_name, user_id, user_password, role; // in user.txt
    fin >> s_no >> user_name >> user_id >> user_password >> role;
    fin.close();

    assert(s_no != "");
    assert(role == "Student");

    cout << "************COMMANDS*****************" << endl;
    cout << "Press " << 1 << " to see all the books" << endl;
    cout << "Press " << 2 << " to see the list of books you have" << endl;
    cout << "Press " << 3 << " to check if book is available for issue or not" << endl;
    cout << "Press " << 4 << " to issue a book" << endl;
    cout << "Press " << 5 << " logout" << endl;
    cout << "************************************" << endl;
    cout << endl;

    Student* user = new Student(user_name, user_id, user_password, 0.0);
    int op;
    cin >> op;

    if (op == 1) {
        book_database* bookdb = new book_database();
        bookdb->Display();
    }
    else if (op == 2) {
        user->view_issued_books();
    }
    else if (op == 3) {

    }
    else if (op == 4) {

    }
    else if (op == 5) {
        logout();
    }
    student_page();
    return;
}


void librarian_page() {
    ifstream fin;
    fin.open(DB_COOKIE);
    string s_no, user_name, user_id, user_password, role; // in user.txt
    fin >> s_no >> user_name >> user_id >> user_password >> role;
    fin.close();

    assert(s_no != "");
    assert(role == "Librarian");

    cout << "************COMMANDS*****************" << endl;
    cout << "Press " << 1 << " add an user" << endl;
    cout << "Press " << 2 << " update an user" << endl;
    cout << "Press " << 3 << " delete an user" << endl;
    cout << "Press " << 4 << " add a book" << endl;
    cout << "Press " << 5 << " update a book" << endl;
    cout << "Press " << 6 << " delete a book" << endl;
    cout << "Press " << 7 << " to get the list of books" << endl;
    cout << "Press " << 8 << " to get the list of users" << endl;
    cout << "Press " << 9 << " to see which book is issued to which user" << endl;
    cout << "Press " << 10 << " to check list of books issued to user" << endl;
    cout << "Press " << 11 << " logout" << endl;
    cout << "************************************" << endl;
    cout << endl;

    Librarian* user = new Librarian(user_name, user_id, user_password);
    int op;
    cin >> op;

    if (op == 1) {
        // add an user
        cout << "--------Register user----------" << endl;
        cout << "Enter the Name of the User" << endl;
        string user_name; cin >> user_name;

        cout << "Enter the ID of the User" << endl;
        string user_id; cin >> user_id;

        cout << "Enter the password for the User" << endl;
        string user_password; cin >> user_password;

        cout << "Enter the role of the User" << endl;
        cout << "Enter `a` for Student" << endl;
        cout << "Enter `b` for Professor" << endl;
        cout << "Enter `c` for Librarian" << endl;
        string c, user_role;
        cin >> c;
        if (c == "a") user_role = "Student";
        else if (c == "b") user_role = "Professor";
        else if (c == "c") user_role = "Librarian";
        else {
            cout << "Please select from the given options" << endl;
            cout << endl;
            librarian_page();
        }

        User* new_user = new User(user_name, user_id, user_password, user_role);
        user->Add(new_user);
    }
    else if (op == 2) {
        // update an user
        cout << "--------Update User---------" << endl;
        cout << "Enter the Name of the User" << endl;
        string user_name; cin >> user_name;

        cout << "Enter the ID of the User" << endl;
        string user_id; cin >> user_id;

        user->Update(user_name, user_id);
    }
    else if (op == 3) {
        // delete an user
        cout << "--------Delete User---------" << endl;
        cout << "Enter the Name of the User" << endl;
        string user_name; cin >> user_name;

        cout << "Enter the ID of the User" << endl;
        string user_id; cin >> user_id;

        user->Delete(user_name, user_id);
    }
    else if (op == 4) {

    }
    else if (op == 5) {

    }
    else if (op == 6) {

    }
    else if (op == 7) {
        book_database* bookdb = new book_database();
        bookdb->Display();
    }
    else if (op == 8) {

    }
    else if (op == 9) {

    }
    else if (op == 10) {

    }
    else if (op == 11) {
        logout();
    }
    librarian_page();
    return;
}


void professor_page() {
    ifstream fin;
    fin.open(DB_COOKIE);
    string s_no, user_name, user_id, user_password, role; // in user.txt
    fin >> s_no >> user_name >> user_id >> user_password >> role;
    fin.close();

    assert(s_no != "");
    assert(role == "Professor");

    cout << "************COMMANDS*****************" << endl;
    cout << "Press " << 1 << " to see all the books" << endl;
    cout << "Press " << 2 << " to see your list of books" << endl;
    cout << "Press " << 3 << " to see if a book is available for issue or not" << endl;
    cout << "Press " << 4 << " to calculate your fine amount" << endl;
    cout << "Press " << 5 << " to clear your fine amount" << endl;
    cout << "Press " << 6 << " to logout" << endl;
    cout << "************************************" << endl;
    cout << endl;

    Professor* user = new Professor(user_name, user_id, user_password, 0.0);

    int op;
    cin >> op;

    if (op == 1) {
        book_database* bookdb = new book_database();
        bookdb->Display();
    }
    else if (op == 2) {
        user->view_issued_books();
    }
    else if (op == 3) {

    }
    else if (op == 4) {

    }
    else if (op == 5) {

    }
    else if (op == 6) {
        logout();
    }

    professor_page();
    return;
}




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
