//  contains the model of the database
#include "bits/stdc++.h"
using namespace std;

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
};

class Professor : public User {
private:
    vector<Book> List_of_Books;
    long double Fine_amount;
public:
    Professor(string user_name, string user_password, string user_id) : User(Name, ID, user_password) {}
    void view_issued_books();
    void calculate_fine();
};

class Student : public User {
private:
    vector<Book> List_of_Books;
    long double Fine_amount;
public:
    Student(string user_name, string user_password, string user_id) : User(Name, ID, user_password) {}
    void view_issued_books();
    void calculate_fine();
};

class Librarian : public User {
public:
    Librarian(string user_name, string user_password, string user_id) : User(Name, ID, user_password) {}
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
    map<int, Book> books;
    void Add();
    void Update();
    void Delete();
    void Search();
    void Display(); // displays all the book
};

class user_database {
public:
    map<int, User> users;
    void Add();
    void Update();
    void Delete();
    void Search();
};
