# library-management-system

## Task
- To Implement a Library Management System in C++ language using Object-oriented programming concepts. 
- Need to implement the system on command line interface.  

## How to run    
* Open the console
* Run 
```
cd src  
g++ src/main.cpp -o a
./a
```

## Directories   
## src
* `main.cpp` : contains the main code to run the program
* `model.h` : contains the required classes
* `urls.cpp` : contains the location of databases stored in `db`  
* `views.cpp` : contains the functions to execute function present in classes

## db
* `user.txt`  
Example: sno name id password role 

* `book.txt`  
Example: sno title author isbn pblication

* `cookie.txt`  
Example: sno name id password role 

* `user_book.txt`  
Example: sno_user sno_book day month year numBooks
