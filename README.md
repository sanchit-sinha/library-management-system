# library-management-system

## Task
- To Implement a Library Management System in C++ language using Object-oriented programming concepts. 
- Need to implement the system on command line interface.  

## Functionality Requirements
1. Implement Login Logout ayatem
2. Professor, Student and Librarian are child classes of User class.  
– Professor Can see all the books. Can see list of books s/he has. Can check if book is available for issue or not. Can issue infinite number of books. Can issue a book for 60 days. Fine is 5 rupees/day after due date.  
– Student Can see all the books. Can see list of books s/he has. Can check if book is available for issue or not. Can issue at max 5 books. Can issue a book for 30 days. Fine is 2 rupees/day after due date.  
– Librarian Can add/update/delete user or book. Can list down all books/users. Can check which book is issued to which user. Can check list of books issue to user.  

Every functionality must be in appropriate class. (Ex. Professor can see all the books. This should be performed by calling Display() method of “Book database” class. You don’t need to put Display all books() method in professor class.)

• List of classes: Use classes shown in figure below to implement above functionalities. You can add more classes or change the structure of classes (add attributes or methods in particular class)  
<p align="center">
    <img src = "https://user-images.githubusercontent.com/68417985/160256127-18de6fb2-ae71-4995-b248-d5e9e336af98.png" width=60% />
</p>
