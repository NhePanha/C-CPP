#include <iostream>
using namespace std;
class Sum{
    private:
        int sum;
    public:
    Sum():sum(5){}
    void operator ++()
    {
        sum++;
    }
    void operator --()
    {
        sum--;
    }
    void Display()
    {
        cout<<"sum : "<<sum<<endl;
    }
};
int main() {
    Sum s;
    ++s;
    s.Display();
    --s;
    s.Display();
    return 0;

}