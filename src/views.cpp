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