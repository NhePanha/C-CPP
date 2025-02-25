#include <iostream>
using namespace std;
class Person{
    private:
        int id;
        string name,gender;
    public:
    // overloading constructor
        Person(){
            id = 0;
            name = "";
            gender = "";
        }
        Person(int id, string name, string gender):id(id),name(name),gender(gender)
        {
            this->id = id;
            this->name = name;
            this->gender = gender;
        }
        void Ouptut()
        {
            cout<<"id : "<<id<<" name : "<<name<<" gender : "<<gender<<endl;
        }
};
int main()
{
    Person per(1001,"dara","male");
    per.Ouptut();
    return 0;
}