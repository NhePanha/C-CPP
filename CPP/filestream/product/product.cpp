#include <iostream>
#include <string.h>
#include <iomanip>
#include <vector>
#include <fstream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

using namespace std;
// storage for product
fstream storage;
// storage for register
fstream register_storage;
bool check_login = false;
class Register{
    protected:
        char usernae[100];
        char password[100];
        char email[100];
        char confirm[100];
    public:
        void Sign_In();
        void Sign_Up();
};
void Register::Sign_Up()
{
    register_storage.open("register.bin", ios::app|ios::binary);
    if (!register_storage.is_open()) {
        cout << RED << "Error Opening File!" << RESET << endl;
        return;
    }
    cout << GREEN << "============ SIGN UP ============" << RESET << endl;
    cout << BLUE << "| Enter Username   : | " << RESET; cin.getline(usernae,100);
    cout << BLUE << "| Enter Email      : | " << RESET; cin.getline(email,100);
    cout << BLUE << "| Enter Password   : | " << RESET; cin.getline(password,100);
    cout << BLUE << "| Confirm Password : | " << RESET; cin.getline(confirm,100);
    if (strcmp(password,confirm) != 0) {
        cout << RED << "Passwords do not match! Registration failed.\033[0m" << endl;
        register_storage.close();
        return;
    }
    register_storage << usernae << " " << password << " " << email << endl;
    register_storage.close();
    cout << GREEN << "Sign Up Successful!" << RESET << endl;
}
void Register::Sign_In(){
    register_storage.open("register.bin",ios::in|ios::binary);
    if (!register_storage.is_open()) {
        cout << RED << "Error Opening File!" << RESET << endl;
        return;
    }
    char stored_usernae[100], stored_password[100], stored_email[100];
    cout << GREEN << "============ LOGIN ============" << RESET << endl;
    cout << BLUE << "| Enter Username   : | " << RESET; cin.ignore(); cin.getline(stored_usernae,100);
    cout << BLUE << "| Enter Password   : | " << RESET; cin.getline(stored_password,100);
    while(register_storage >> usernae >> password >> email) {
        if (strcmp(usernae, stored_usernae) == 0 && strcmp(password, stored_password) == 0) {
            cout << GREEN << "Login Successful! Welcome, " << usernae << "!" << RESET << endl;
            check_login = true;
            break;
        }
    }
    if(register_storage.eof()){
        cout << RED << "Invalid Username or Password!" << RESET << endl;
    }
    register_storage.close();
}
class Product{
    protected:
        int id;
        string name;
        double price;
        int quantity;
        double discount;
        bool status;
        double total_price;
    public:
        void Add_Product();
        void Display_Product();
};
void Product::Add_Product()
{
    storage.open("products.bin", ios::app|ios::binary);
    if (!storage.is_open()) {
        cout << RED << "Error Opening File!" << RESET << endl;
        return;
    }
    cout << GREEN << "============ ADD PRODUCT ============" << RESET << endl;
    cout << BLUE << "| Enter ID          : | " << RESET; cin >> id;
    cout << BLUE << "| Enter Name        : | " << RESET; cin.ignore();getline(cin, name);
    cout << BLUE << "| Enter Price       : | " << RESET; cin >> price;
    cout << BLUE << "| Enter Quantity    : | " << RESET; cin >> quantity;
    cout << BLUE << "| Enter Discount (%) : | " << RESET; cin >> discount;
    status = true;
    total_price = price * quantity * (1);
    storage.write((char*)&id, sizeof(id));
    storage.write((char*)&name, sizeof(name));
    storage.write((char*)&price, sizeof(price));
    storage.write((char*)&quantity, sizeof(quantity));
    storage.write((char*)&discount, sizeof(discount));
    storage.write((char*)&status, sizeof(status));
    storage.write((char*)&total_price, sizeof(total_price));
    storage.close();
}
void Product::Display_Product()
{
    storage.open("products.bin",ios::in|ios::binary);
    if (!storage.is_open()) {
        cout << RED << "Error Opening File!" << RESET << endl;
        return;
    }
    int stored_id;
    string stored_name;
    double stored_price, stored_discount;
    int stored_quantity;
    double stored_total_price;
    bool stored_status;
    while(storage.read((char*)&stored_id, sizeof(stored_id))){
        storage.read((char*)&stored_name, sizeof(stored_name));
        storage.read((char*)&stored_price, sizeof(stored_price));
        storage.read((char*)&stored_quantity, sizeof(stored_quantity));
        storage.read((char*)&stored_discount, sizeof(stored_discount));
        storage.read((char*)&stored_status, sizeof(stored_status));
        storage.read((char*)&stored_total_price, sizeof(stored_total_price));
        if(stored_status){
            cout<<BLUE<<setw(12)<<stored_id<<
            setw(12)<<stored_name<<
            setw(12)<<stored_price<<
            setw(12)<<stored_quantity<<
            setw(12)<<stored_discount<<
            setw(12)<<stored_total_price<<endl;
        }
    }
}
int main()
{
    Register reg;
    int op;
    do{
        cout <<YELLOW<< "==============[ M E N U ]==============\n";
        cout <<YELLOW<< "[ 1 - Sign Up      ]\n";
        cout <<YELLOW<< "[ 2 - Sign In      ]\n";
        cout <<YELLOW<< "[ 0 - Exit         ]\n";
        cout <<YELLOW<< "==========================================" << endl;
        cout <<YELLOW<< "Enter your choice : "; cin >> op;
        switch(op){
            case 1:
                reg.Sign_Up();
                break;
            case 2:
                reg.Sign_In();
                if(check_login){
                    Product p;
                    vector<Product> products;
                    int choice,i,n;
                    do{
                        cout << RED<< "==============[ Product Menu ]==============\n";
                        cout << GREEN<< "[ 1 - Write Product   ]\n";
                        cout << GREEN<< "[ 2 - Read Product    ]\n";
                        cout << GREEN<< "[ 3 - Search Product  ]\n";
                        cout << GREEN<< "[ 3 - Update Produ    ]\n";
                        cout << GREEN<< "[ 3 - Delete Product  ]\n";
                        cout << GREEN<< "[ 3 - Sort Product    ]\n";
                        cout << GREEN<< "[ 3 - Add Product     ]\n";
                        cout << RED<< "==========================================" << endl;
                        cout << GREEN<< "Enter your choice : "; cin >> choice;
                        switch(choice){
                            case 1:{
                                cout << GREEN << "Enter the number of products to add: "; cin >> n;
                                for(int i=0; i< n;i++){
                                    products[i].Add_Product();
                                    products.push_back(p);
                                }
                            }break;
                            case 2:{
                                for(auto p : products){
                                    p.Display_Product();
                                }
                            }break;
                        }
                    }while(choice!=0);
                }
                break;
            default:
                cout << RED << "Invalid Choice!" << RESET << endl;
        }
    }while(op!=0);
    return 0;
}