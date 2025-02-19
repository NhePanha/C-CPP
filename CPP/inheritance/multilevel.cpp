#include <iostream>
using namespace std;
class A{
    protected:
        int x;
};
class B: public A{
    protected:
        int y;
};
class C: public B{
    private:
        int z;
    public:
        void Input()
        {
            cout<<"Ener X : ";cin>>x;
            cout<<"Ener Y : ";cin>>y;
            cout<<"Ener Z : ";cin>>z;
        }
        void Output(){
            cout<<"x : "<<x<<" y : "<<y<<" z : "<<z<<endl;
        }
};
int main()
{
    C obj;
    obj.Input();
    obj.Output();
    return 0;
}