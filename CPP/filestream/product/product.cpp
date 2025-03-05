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
    cout << GREEN << "============ SIGN UP ============" << RESET << endl;cin.ignore();
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
        double payment;
    public:
    // block methods
        int getId()
        {
            return id;
        }
        string getName()
        {
            return name;
        }
        void Add_Product();
        void Display_Product();
};
void Product::Add_Product()
{
    cout << GREEN << "============ ADD PRODUCT ============" << RESET << endl;
    cout << BLUE << "| Enter ID          : | " << RESET; cin >> id;
    cout << BLUE << "| Enter Name        : | " << RESET; cin.ignore();getline(cin, name);
    cout << BLUE << "| Enter Price       : | " << RESET; cin >> price;
    cout << BLUE << "| Enter Quantity    : | " << RESET; cin >> quantity;
    cout << BLUE << "| Enter Discount (%): | " << RESET; cin >> discount;
    total_price = price - (price * discount / 100);
    payment = total_price - (total_price * discount / 100);
}
void Product::Display_Product()
{
    cout<<BLUE << setw(12)<<id<<
    setw(12)<<name<<
    setw(12)<<price<<
    setw(12)<<quantity<<
    setw(12)<<discount<<
    setw(12)<<total_price<<
    setw(12)<<payment<<endl;
        
}
void Header()
{
    cout<<RED<<setw(12)<<"CODE"<<
    setw(12)<<"NAME"<<
    setw(12)<<"PRICE"<<
    setw(12)<<"QUANTITY"<<
    setw(12)<<"DISCOUNT(%)"<<
    setw(12)<<"TOTAL PRICE"<<
    setw(12)<<"PAYMENT"<<endl;
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
                    Product pro;
                    vector<Product> products;
                    int choice,i,n;
                    do{
                        cout << RED<< "==============[ Product Menu ]==============\n";
                        cout << GREEN<< "[ 1 - Write Product   ]\n";
                        cout << GREEN<< "[ 2 - Read Product    ]\n";
                        cout << GREEN<< "[ 3 - Search Product  ]\n";
                        cout << GREEN<< "[ 4 - Update Produ    ]\n";
                        cout << GREEN<< "[ 5 - Delete Product  ]\n";
                        cout << GREEN<< "[ 6 - Sort Product    ]\n";
                        cout << GREEN<< "[ 7 - Add Product     ]\n";
                        cout << RED<< "==========================================" << endl;
                        cout << GREEN<< "Enter your choice : "; cin >> choice;
                        switch(choice){
                            case 1:{
                                storage.open("storages.bin",ios::app|ios::binary);
                                if(!storage.is_open()){
                                    cout << RED << "Error Opening File!" << RESET << endl;
                                    return 1;
                                }
                                cout<<"Enter Number of Product : ";cin>>n;
                                for(i=0;i<n;i++)
                                {
                                    pro.Add_Product();
                                    storage.write((char*)&pro, sizeof(pro));
                                    storage.close();
                                }
                            }break;
                            case 2:{
                                storage.open("storages.bin",ios::in|ios::binary);
                                if (!storage.is_open()) {
                                    cout << "Error Opening File!" << endl;
                                    return 1;
                                }
                                Header();
                                while (storage.read(reinterpret_cast<char*>(&pro), sizeof(Product))) {
                                    pro.Display_Product();
                                }
                                storage.close();
                            }break;
                            case 3:{
                                int search_id;
                                bool check = false;
                                storage.open("storages.bin",ios::in|ios::binary);
                                if (!storage.is_open()) {
                                    cout << "Error Opening File!" << endl;
                                    return 1;
                                }
                                cout << "Enter Product ID To Search.. : "; cin >> search_id;
                                Header();
                                while (storage.read(reinterpret_cast<char*>(&pro), sizeof(Product))) {
                                    if(search_id == pro.getId())
                                    {
                                        pro.Display_Product();
                                    }
                                }
                                storage.close();
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