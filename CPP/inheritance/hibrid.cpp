#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
using namespace std;
class Person{
    protected:
        int id;
        string name;
    public:
        Person()
        {
            id = 0;
            name = "NULL";
        }
        void Input()
        {
            cout<<"Enter ID : ";cin>>id;
            cout<<"Enter Name : ";cin>>name;
        }
        void Output()
        {
            cout<<setw(12)<<id<<setw(12)<<name;
        }
    
};
class DateTime:public Person{
    protected:
        string date;
        string time;
    public:
        DateTime()
        {
            Person:Person();
            date = "NULL";
            time = "NULL";
        }
        void Input()
        {
            Person::Input();
            cout<<"Enter Date : ";cin>>date;
            cout<<"Enter Time : ";cin>>time;
        }
        void Output()
        {
            Person::Output();
            cout<<setw(12)<<date<<setw(12)<<time;
        }
};
class Employee:public DateTime{
    private:
        double salary;
    public:
        Employee()
        {
            DateTime:DateTime();
            salary = 0.00;
        }
        void Input()
        {
            DateTime::Input();
            cout<<"Enter Salary : ";cin>>salary;
        }
        void Output()
        {
            DateTime::Output();
            cout<<setw(12)<<salary<<endl;
        }
};
class Student:public DateTime{
    private:
        double score;
    public:
        Student()
        {
            DateTime:DateTime();
            score = 0.00;
        }
        void Input()
        {
            DateTime::Input();
            cout<<"Enter Score : ";cin>>score;
        }
        void Output()
        {
            DateTime::Output();
            cout<<setw(12)<<score<<endl;
        }
};
int main()
{
    vector<Employee> employees;
    vector<Student> students;
    
    int choice, num;
    do{
        cout<<"[==============[ MENU ]==============]"<<endl;
        cout<<"[1. Add Employee     ]"<<endl;
        cout<<"[2. Add Student      ]"<<endl;
        cout<<"[0. Exit             ]"<<endl;
        cout<<"Enter Your Choice : ";cin>>choice;
        switch(choice){
            case 1:{
                int op;
                do{
                    cout<<"[==============[ Add Employee ]==============]"<<endl;
                    cout<<"1. Add Full Time Employee"<<endl;
                    cout<<"2. Show Full Time Employee"<<endl;
                    cout<<"Enter Your Choice : ";cin>>op;
                    switch(op){
                        case 1:{
                            cout<<"Enter Number of Employee : ";cin>>num;
                            for(int i=0;i<num;i++){
                                Employee emp;
                                emp.Input();
                                employees.push_back(emp);
                            }
                        }break;
                        case 2:{
                            for(auto emp : employees){
                                emp.Output();
                            }
                        }break;
                    }
                }while(op!=0);
            }break;
            case 2:{
                int op;
                do{
                    cout<<"[==============[ Add Student ]==============]"<<endl;
                    cout<<"1. Add Student"<<endl;
                    cout<<"2. Show Student"<<endl;
                    cout<<"Enter Your Choice : ";cin>>op;
                    switch(op){
                        case 1:{
                            cout<<"Enter Number of Student : ";cin>>num;
                            for(int i=0;i<num;i++){
                                Student stu;
                                stu.Input();
                                students.push_back(stu);
                            }
                        }break;
                        case 2:{
                            for(auto stu : students){
                                stu.Output();
                            }
                        }break;
                    }
                }while(op!=0);
            }break;
        }
    }while(choice!=0);
    return 0;
}