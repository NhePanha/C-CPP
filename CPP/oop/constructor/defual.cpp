#include <iostream>
using namespace std;
class Employee{
    private:
        int id;
        string name;
        string gender;
        double salary;
    public:
        Employee()
        {
            id = 0;
            name = "NULL";
            gender = "NULL";
            salary = 0.0;
        }
        Employee(int id, string name, string gender, double salary)
        {
            this->id = id;
            this->name = name;
            this->gender = gender;
            this->salary = salary;
        }
        void display()
        {
            cout<<"ID : "<<id<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Gender : "<<gender<<endl;
            cout<<"Salary : "<<salary<<endl;
        }
};
int main()
{
    // create object 
    Employee emp;
    emp.display();

    Employee emp1(191, "John", "Male", 500.0);
    emp1.display();
    return 0;
}