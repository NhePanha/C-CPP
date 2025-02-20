#include "employee.h"
#include "person.h"

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