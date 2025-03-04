#include <iostream>
#include <fstream>
#include <string>
// add colors 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
using namespace std;

fstream data;

void Signup() {
    data.open("user.txt", ios::app);
    if (!data.is_open()) {
        cout << RED << "Error Opening File!" << RESET << endl;
        return;
    }

    int id;
    string name, email, password, confirm;

    cout << GREEN << "============ SIGN UP ============" << RESET << endl;
    cout << BLUE << "| Enter Code       : | " << RESET; cin >> id;
    cin.ignore();  // Ignore newline character

    cout << BLUE << "| Enter Name       : | " << RESET; getline(cin, name);
    cout << BLUE << "| Enter Email      : | " << RESET; getline(cin, email);
    
    do {
        cout << BLUE << "| Enter Password   : | " << RESET; getline(cin, password);
        cout << BLUE << "| Confirm Password : | " << RESET; getline(cin, confirm);
        if (password != confirm) {
            cout << RED << "Passwords do not match! Try again.\n" << RESET;
        }
    } while (password != confirm);

    data << id << " " << name << " " << email << " " << password << endl;
    data.close();
    cout << GREEN << "Sign Up Successful!" << RESET << endl;
}

void Signin() {
    ifstream data("user.txt");
    if (!data.is_open()) {
        cout << RED << "Error Opening File!" << RESET << endl;
        return;
    }

    string email, password, stored_email, stored_password, stored_name;
    int stored_id;
    
    cout << GREEN << "============ SIGN IN ============" << RESET << endl;
    cout << BLUE << "| Enter Email      : | " << RESET; cin.ignore(); getline(cin, email);
    cout << BLUE << "| Enter Password   : | " << RESET; getline(cin, password);
    
    bool login_success = false;

    while (data >> stored_id >> stored_name >> stored_email >> stored_password) {
        if (stored_email == email && stored_password == password) {
            cout << GREEN << "Login Successful! Welcome, " << stored_name << "!" << RESET << endl;
            login_success = true;
            break;
        }
    }

    if (!login_success) {
        cout << RED << "Invalid email or password!" << RESET << endl;
    }
    data.close();
}

int main() {
    int op;
    do {
        cout << GREEN << "=============[ MENU ]==================" << RESET << endl;
        cout << GREEN << "[1 - Sign In ]" << RESET << endl;
        cout << GREEN << "[2 - Sign Up ]" << RESET << endl;
        cout << GREEN << "[0 - Exit(0) MENU ]" << RESET << endl;
        cout << GREEN << "Enter Your Choice : " << RESET;
        cin >> op;

        switch (op) {
            case 1:
                Signin();
                break;
            case 2:
                Signup();
                break;
            case 0:
                cout << "Exiting the Program..." << endl;
                break;
            default:
                cout << RED << "Invalid Choice... Please Try Again!" << RESET << endl;
        }
    } while (op != 0);

    return 0;
}
