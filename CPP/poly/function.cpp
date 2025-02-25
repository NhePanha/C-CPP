#include <iostream>

using namespace std;

void Sum()
{
    cout<<"Empty()"<<endl;

}
void Sum(double value)
{
    cout<<"Sum: "<<value<<endl;
}
void Sum(double value1, double value2)
{
    cout<<"Sum: "<<value1<<"  "<<value2<<endl;
}

int main()
{
    double x = 80;
    double y = 30;
    Sum();
    Sum(x);
    Sum(y);
    Sum(x,y);
    return 0;
}