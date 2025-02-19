#include <iostream>
using namespace std;
class A{
    protected:
        int a;
};
class B: public A{
    private:
        int b;
    public:
        void input()
        {
            cout<<"enter a : ";cin>>a;
            cout<<"enter b : ";cin>>b;
        }
        void output()
        {
            cout<<"a : "<<a<<"b : "<<b<<endl;
        }
};
int main()
{
    B b;
    b.input();
    b.output();

    return 0;
}