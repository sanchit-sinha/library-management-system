//  contains the model of the database
// should not work for simultaneous users 

#include "bits/stdc++.h"
using namespace std;
#include "urls.cpp"

class Book {
public:
    string Title;
    string Author;
    string ISBN;
    string Publication;
    Book(string Title, string Author, string ISBN, string Publication) {
        this->Title = Title;
        this->Author = Author;
        this->ISBN = ISBN;
        this->Publication = Publication;
    }
    Book Book_Request(); // doubt
    void show_due_date();
};

class User {
public:
    string Name;
    string ID;
    string password;
    User(string Name, string ID, string password) {
        this->Name = Name;
        this->ID = ID;
        this->password = password;
    }
    void view_issued_books();
    string get_sno();
};

class Professor : public User {
public:
    vector<Book> List_of_Books;
    long double Fine_amount;
    void calculate_fine();
    Professor(string Name, string ID, string password, long double amt) : User(Name, ID, password) {
        this->Fine_amount = amt;
    }
};

class Student : public User {
private:
    vector<Book> List_of_Books;
    long double Fine_amount;
public:
    Student(string Name, string ID, string password, long double amt) : User(Name, ID, password) {
        this->Fine_amount = amt;
    }
    void calculate_fine();
};

class Librarian : public User {
public:
    Librarian(string Name, string ID, string password) : User(Name, ID, password) {}
    void Add(Book);
    void Add(User);

    void Update(Book);
    void Update(User);

    void Delete(Book);
    void Delete(User);

    void Search(Book);
    void Search(User);

    void view_all_users();
    void view_all_books();
};

class book_database {
public:
    map<string, Book*> books;
    void Add();
    void Update();
    void Delete();
    void Search();
    void Display(); // displays all the book
    Book* get_book(string sno);

    book_database() {
        ifstream db_books;
        db_books.open(DB_BOOK);
        string book_sno, book_title, book_author, book_ISBN, book_publication;
        while (db_books >> book_sno >> book_title >> book_author >> book_ISBN >> book_publication) {
            Book* newBook = new Book(book_title, book_author, book_ISBN, book_publication);
            books[book_sno] = newBook;
        }
        db_books.close();
    }
};

class user_database {
public:
    map<string, User*> users;
    void Add();
    void Update();
    void Delete();
    void Search();
    User* get_user(string sno);
};
