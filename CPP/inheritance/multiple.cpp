#include <iostream>
#include <iomanip>

using namespace std;
class Person{
    protected:
        int id;
        string name,gender;
        int age;
    public:
        Person()
        {
            id = 0;
            name = "Null";
            gender = "Null";
            age = 0;
        }
        void Input()
        {
            cout<<"Enter ID : ";cin>>id;
            cout<<"Enter Name : ";cin>>name;
            cout<<"Enter Gender : ";cin>>gender;
            cout<<"Enter Age    : ";cin>>age;
        }
        void Output()
        {
            cout<<setw(12)<<id<<
            setw(12)<<name<<
            setw(12)<<gender<<
            setw(12)<<age;
        }
};
class Employee{
    protected:
        double salary,hour,rate;
    public:
        Employee()
        {
            salary = 0.00;
            hour = 0.00;
            rate = 0;
        }
        void Input()
        {
            cout<<"Enter Salary : ";cin>>salary;
            cout<<"Enter Hour : ";cin>>hour;
            cout<<"Enter Rate : ";cin>>rate;
        }
        void Output()
        {
            cout<<setw(12)<<salary<<
            setw(12)<<hour<<
            setw(12)<<rate;
        }
};
class Date:public Employee, public Person{
    private:
        string day,month,year;
    public:
        Date()
        {
            Person:Person();
            Employee:Employee();
            day = "dd";
            month = "mm";
            year = "yyyy";
        }
        void Input()
        {
            Person::Input();
            Employee::Input();
            cout<<"Enter (dd/mm/yyyy) : ";cin>>day;cin>>month;cin>>year;
        }
        void Output()
        {
            Person::Output();
            Employee::Output();
            cout<<setw(12)<<day<<"/"<<month<<"/"<<year<<endl;
        }
};
void Header()
{
    cout<<setw(12)<<"ID"<<
    setw(12)<<"Name"<<
    setw(12)<<"Gender"<<
    setw(12)<<"Age"<<
    setw(12)<<"Salary"<<
    setw(12)<<"Hour"<<
    setw(12)<<"Rate"<<
    setw(12)<<"DD/MM/YYYY"<<endl;
}
int main()
{
    Date date;
    date.Input();
    Header();
    date.Output();
    return 0;
}