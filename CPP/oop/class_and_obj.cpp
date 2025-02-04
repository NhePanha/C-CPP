#include <iostream>
#include <iomanip> // for setw() function
using namespace std;
// create class
class Car{
    private:
        int id;
        string model;
        double price;
    public:
        void Input()
        {
            cout<<"Enter Car ID : ";cin>>id;
            cout<<"Enter Car Model : ";cin>>model;
            cout<<"Enter Car Price : ";cin>>price;
        }
        void Output(){
            cout<<left<<setw(12)<<id<<
            setw(12)<<model<<
            setw(12)<<price<<endl;
        }
};
int main()
{
    // create object
    Car car;
    car.Input();
    car.Output();
    return 0;
}