// contains the function assossiated with the models 
#include "bits/stdc++.h"
#include "fstream"
using namespace std;

// book database 
void book_database::Display() {
    cout << "------------------------Books----------------------------" << endl;
    for (auto& book : books) {
        Book* x = book.second;
        cout << x->Title << " " << x->Author << " " << x->ISBN << " " << x->Publication << endl;
    }
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

Book* book_database::get_book(string sno) {
    ifstream db_books;
    db_books.open(DB_BOOK);
    Book* book = NULL;

    string book_sno, book_title, book_author, book_ISBN, book_publication;
    while (db_books >> book_sno >> book_title >> book_author >> book_ISBN >> book_publication) {
        if (book_sno == sno) {
            book = new Book(book_title, book_author, book_ISBN, book_publication);
        }
    }
    db_books.close();
    return book;
}


// user 
string User::get_sno() {
    string sno;

    ifstream db_users;
    db_users.open(DB_USER);
    string user_sno, user_name, user_id, user_password, user_role;
    while (db_users >> user_sno >> user_name >> user_id >> user_password >> user_role) {
        if (user_name == this->Name && user_password == this->password && user_id == this->ID) {
            sno = user_sno;
            break;
        }
    }
    db_users.close();
    return sno;
}

void User::view_issued_books() {
    string user_sno = this->get_sno();

    ifstream db_user_book;
    db_user_book.open(DB_USER_BOOK);

    string sno_user, sno_book;
    vector<string> books_sno;
    while (db_user_book >> sno_user >> sno_book) {
        if (sno_user == user_sno) {
            books_sno.push_back(sno_book);
        }
    }

    book_database* bookdb = new book_database();
    cout << "------------------------Books Issued----------------------------" << endl;
    for (auto& sno : books_sno) {
        Book* this_book = bookdb->books[sno];
        cout << this_book->Title << " " << this_book->Author << " " << this_book->ISBN << " " << this_book->Publication << endl;
    }
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;

    return;
}

// librarian
void Librarian::Add(User* new_user) {
    ifstream db_user;
    db_user.open(DB_USER);

    string sno, name, pwd, id, role;
    while (db_user >> sno >> name >> id >> pwd >> role) {
        if (name == new_user->Name || id == new_user->ID) {
            cout << "User already exists !" << endl;
            cout << endl;
            return;
        }
    }

    user_database* userdb = new user_database();
    long long num = stoll(sno) + 1;
    string new_sno = to_string(num);
    userdb->users[new_sno] = new_user;

    ofstream fout;
    fout.open(DB_USER);
    for (auto& user : userdb->users) {
        fout << user.first << " ";
        User* cur_user = user.second;
        fout << cur_user->Name << " " << cur_user->ID << " " << cur_user->password << " " << cur_user->role << endl;
    }
    fout.close();

    cout << "User successfully registered" << endl;
    cout << endl;
}

void Librarian::Update(string user_name, string user_id) {
    ifstream db_user;
    db_user.open(DB_USER);

    string sno, name, pwd, id, role;
    string current_sno;
    while (db_user >> sno >> name >> id >> pwd >> role) {
        if (name == user_name && id == user_id) {
            current_sno = sno;
            break;
        }
    }

    if (current_sno == "") {
        cout << "There is no such user" << endl;
        cout << endl;
        return;
    }
    db_user.close();

    user_database* userdb = new user_database();

    cout << "------------------------------------" << endl;
    cout << "The current details of the user is as : " << endl;
    cout << "User Name : " << userdb->users[current_sno]->Name << endl;
    cout << "User ID : " << userdb->users[current_sno]->ID << endl;
    cout << "User Password : " << userdb->users[current_sno]->password << endl;
    cout << "User Role : " << userdb->users[current_sno]->role << endl;
    cout << "------------------------------------" << endl;
    cout << endl;

    cout << "Enter the new details of the user : " << endl;
    cout << "Enter the new user name" << endl;
    string new_username; cin >> new_username;

    cout << "Enter the new user id " << endl;
    string new_userid; cin >> new_userid;

    cout << "Enter the new user password" << endl;
    string new_userpassword; cin >> new_userpassword;

    cout << "Enter the new user role" << endl;
    cout << "Enter `a` for Student" << endl;
    cout << "Enter `b` for Professor" << endl;
    cout << "Enter `c` for Librarian" << endl;
    string c, user_role;
    string new_userrole; ;
    cin >> c;
    if (c == "a") new_userrole = "Student";
    else if (c == "b") new_userrole = "Professor";
    else if (c == "c") new_userrole = "Librarian";
    else {
        cout << "Please select from the given options" << endl;
        cout << endl;
        return;
    }

    userdb->users[current_sno] = new User(new_username, new_userid, new_userpassword, new_userrole);

    // write to files
    ofstream fout;
    fout.open(DB_USER);
    for (auto& user : userdb->users) {
        fout << user.first << " ";
        User* cur_user = user.second;
        fout << cur_user->Name << " " << cur_user->ID << " " << cur_user->password << " " << cur_user->role << endl;
    }
    fout.close();

    cout << "User successfully updated" << endl;
    cout << endl;
}

void Librarian::Delete(string user_name, string user_id) {
    ifstream db_user;
    db_user.open(DB_USER);

    string sno, name, pwd, id, role;
    string current_sno;
    while (db_user >> sno >> name >> id >> pwd >> role) {
        if (name == user_name && id == user_id) {
            current_sno = sno;
            break;
        }
    }
    db_user.close();

    if (current_sno == "") {
        cout << "There is no such user" << endl;
        cout << endl;
        return;
    }

    user_database* userdb = new user_database();

    cout << "------------------------------------" << endl;
    cout << "The current details of the user is as : " << endl;
    cout << "User Name : " << userdb->users[current_sno]->Name << endl;
    cout << "User ID : " << userdb->users[current_sno]->ID << endl;
    cout << "User Password : " << userdb->users[current_sno]->password << endl;
    cout << "User Role : " << userdb->users[current_sno]->role << endl;
    cout << endl;

    auto it = (userdb->users).find(current_sno);
    if (it == (userdb->users).end()) {
        cout << "There is no such user" << endl;
        cout << endl;
        return;
    }
    else {
        (userdb->users).erase(it);
    }


    // write to files
    ofstream fout;
    fout.open(DB_USER);
    for (auto& user : userdb->users) {
        fout << user.first << " ";
        User* cur_user = user.second;
        fout << cur_user->Name << " " << cur_user->ID << " " << cur_user->password << " " << cur_user->role << endl;
    }
    fout.close();

    cout << "User successfully deleted!" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
}