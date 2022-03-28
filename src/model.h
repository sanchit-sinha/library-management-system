//  contains the model of the database
#include "bits/stdc++.h"
using namespace std;

class User {
private:
    string password;
public:
    string Name;
    string ID;
};

class Professor : public User {
private:
    vector<Book> List_of_Books;
    long double Fine_amount;
public:
    void view_issued_books();
    void calculate_fine();
};

class Student : public User {
private:
    vector<Book> List_of_Books;
    long double Fine_amount;
public:
    void view_issued_books();
    void calculate_fine();
};

class Librarian : public User {
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

class Book {
private:
    string Title;
    string Author;
    string ISBN;
    string Publication;
public:
    Book Book_Request(); // doubt
    void show_due_date();
};

