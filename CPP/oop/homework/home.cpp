#include <iostream>
#include <iomanip>
using namespace std;

class Employee{
    private:
    // block data members
        int id;
        string name;
        string gender;
        double salary;
    public:
    // block methods
        // Default contructor
        Employee(){
            id = 0;
            name = "NULL";
            gender = "NULL";
            salary = 0.0;
        }
        // contructor with parameters
        Employee(int id, string name, string gender, double salary){
            this->id = id;
            this->name = name;
            this->gender = gender;
            this->salary = salary;
        }
        // function to input data
        void Input()
        {
            cout<<"Enter Employee ID : ";cin>>id;
            cout<<"Enter Employee Name : ";cin>>name;
            cout<<"Enter Employee Gender : ";cin>>gender;
            cout<<"Enter Employee Salary : ";cin>>salary;
        }
        void Header()
        {
            cout<<setw(12)<<"ID"<<
            setw(12)<<"Name"<<
            setw(12)<<"Gender"<<
            setw(12)<<"Salary"<<endl;
            cout<<"---------------------------------------------"<<endl;
        }
        void Output(){
            cout<<setw(12)<<id<<
            setw(12)<<name<<
            setw(12)<<gender<<
            setw(12)<<salary<<endl;
        }
};
int main()
{
    // create object
    Employee emp;
    // default value
    emp.Header();
    emp.Output();
    emp.Input();
    emp.Header();
    emp.Output();

    return 0;
}