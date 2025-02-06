#include <iostream>
#include <iomanip>
using namespace std;
class Student{
    private:
        int id;
        string name;
        char gender[10];
        double sc1,sc2,sc3;
    public:
        void Input()
        {
            cout<<"Enter Student ID      : ";cin>>id;
            cout<<"Enter Student Name    : ";cin.ignore();getline(cin,name); // for string 
            cout<<"Enter Student Gender  : ";cin.ignore();cin.getline(gender,10); // for charaters
            cout<<"Enter Student Math    : ";cin>>sc1;
            cout<<"Enter Student Khmer   : ";cin>>sc2;
            cout<<"Enter Student English : ";cin>>sc3;
        }
        double Total()
        {
            return sc1+sc2+sc3;
        }
        double Average()
        {
            return Total()/3;
        }
        char Grade()
        {
            double avg = Average();
            return (avg > 90 && avg <= 100)?'A':
            (avg > 80 && avg <= 90)? 'B':
            (avg > 70 && avg <= 80)? 'C':
            (avg > 60 && avg <= 70)? 'D':
            (avg > 50 && avg <= 60)? 'E':'F';
        }
        
        void Display()
        {
            cout<<setw(12)<<id<<
            setw(12)<<name<<
            setw(12)<<gender<<
            setw(12)<<sc1<<
            setw(12)<<sc2<<
            setw(12)<<sc3<<
            setw(12)<<Total()<<
            setw(12)<<Grade()<<
            setw(12)<<Average()<<endl;
        }
};
void Header()
{
    cout<<setw(12)<<"CODE"<<
    setw(12)<<"NAME"<<
    setw(12)<<"GENDER"<<
    setw(12)<<"MATH"<<
    setw(12)<<"KHMER"<<
    setw(12)<<"ENGLISH"<<
    setw(12)<<"TOTAL"<<
    setw(12)<<"GRADE"<<
    setw(12)<<"AVG"<<endl;
}
int main()
{
    // create object
    Student stu;
    // calling functions
    stu.Input();
    Header();
    stu.Display();
    return 0;
}