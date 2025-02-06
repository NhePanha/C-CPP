#include <iostream>
using namespace std;
class Person{
    private:
        int id;
        string name;
        string gender;
        double salary;
    public:
        void setId(int id){
            this->id = id;
        }
        void setName(string name){
            this->name = name;
        }
        void setGender(string gender){
            this->gender=gender;
        }
        void setSalary(double salary){
            this->salary = salary;
        }
        int getId() { 
            return id; 
        }
        string getName() { 
            return name;
        }
        string getGender() {
            return gender;
        }
        double getSalary() {
            return salary;
        }
};
int main()
{
    // create object
    Person per;
    per.setId(191);
    per.setName("John");
    per.setGender("Male");
    per.setSalary(500);

    cout<<"ID : "<<per.getId()<<endl;
    cout<<"Name : "<<per.getName()<<endl;
    cout<<"Gender : "<<per.getGender()<<endl;
    cout<<"Salary : "<<per.getSalary()<<endl;
    return 0;
}