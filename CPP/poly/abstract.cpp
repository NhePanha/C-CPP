#include <iostream>
using namespace std;
// abstract
class Test{
    public:
        virtual void Input(){

        };
        virtual void Display(){

        };
        virtual int sum(){
            
        };
};
// derived class 1
class Test1: public Test{
    private:
        int a,b;
    public:
    // overrides methods
        void Input(){
            cout<<"Enter two numbers: ";
            cin>>a>>b;
        }
        // overrides methods
        void Display(){
            cout<<"Sum: "<<sum()<<endl;
        }
        // overrides methods
        int sum(){
            return a+b;
        }
};
int main()
{
    Test1 obj;
    obj.Input();
    obj.Display();

    return 0;
}