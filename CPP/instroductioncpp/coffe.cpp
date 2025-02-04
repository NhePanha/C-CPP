#include <iostream>
using namespace std;
int main()
{
    int id;
    string name;
    double price;
    int qty;

    cout<<"Enter Coffe ID : ";cin>>id;
    cout<<"Enter Coffe Name : ";cin.ignore();getline(cin,name);// string name
    cout<<"Enter Coffe Price : ";cin>>price;
    cout<<"Enter Coffe Quantity : ";cin>>qty;

    cout<<"Coffe ID : "<<id<<endl;
    cout<<"Coffe Name : "<<name<<endl;
    cout<<"Coffe Price : "<<price<<endl;
    cout<<"Coffe Quantity : "<<qty<<endl;
    double totalPrice = price * qty;
    return 0;
}