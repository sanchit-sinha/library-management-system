#include "bits/stdc++.h"
#include "fstream"
#include "model.h"
#include "views.cpp"
#include "urls.cpp"
using namespace std;

void new_user();
void enter_library();

void enter_library() {
    ifstream fin;
    fin.open(DB_COOKIE);

    string username, password;
    fin >> username >> password;

    if (username == "" || password == "") {
        cout << "Welcome to library" << endl;
        new_user();
    }
    else {
        cout << "Welcome " << username << endl;
    }
    return;
}

void new_user() {
    // new user
    cout << "*****************************" << endl;
    cout << "Press 1 to login" << endl;
    cout << "Press 2 to signup" << endl;
    cout << endl;

    int x;
    cin >> x;

    string username, password;
    if (x == 1) { // login 
        cout << "Enter your username" << endl;
        cin >> username;

        cout << "Enter your password" << endl;
        cin >> password;

        ifstream fin;
        fin.open(DB_USER);

        string user_name, user_id, user_password;
        while (fin >> user_name >> user_id >> user_password) {
            if (user_name == username && user_password == password) {
                ofstream fout;
                fout.open(DB_COOKIE);

                fout << username << " " << password << endl;
                fout.close();

                enter_library();
                return;
            }
        }

        fin.close();
        cout << "Invalid Credentials! Kindly repeat the process" << endl;
        new_user();
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    enter_library();
}
