#include <istream>
#include <iomanip>
using namespace std;
// create class
class Employee{
    private:
    // block data members
        int id;
        string name;
        string gender;
        double salary;
    public:
    // block methods
        void Input()
        {
            cout<<"Enter Employee ID : ";cin>>id;
            cout<<"Enter Employee Name : ";cin>>name;
            cout<<"Enter Employee Gender : ";cin>>gender;
            cout<<"Enter Employee Salary : ";cin>>salary;
        }
        void Ouput()
        {
            cout<<setw(12)<<id<<
            setw(12)<<name<<
            setw(12)<<gender<<
            setw(12)<<salary<<endl;
        }
}
int main()
{
    // create object
    Employee emp;
    // calling fuction form class employee
    emp.Input();
    emp.Ouput();

    return 0;
}