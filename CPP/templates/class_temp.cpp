#include <iostream>
using namespace std;
template <class T>
class Test{
    T a, b;
    public:
    // constructor
        Test(T a, T b)
        {
            this->a = a;
            this->b = b;
        }
        // function to add two numbers
        T Display(){
            return a + b;
        }
};
// template <class T>
// T Test<T>::Display()
// {
//     return a + b;
// }
int main()
{
    Test<int> obj(5, 10);
    cout << "Sum is: " << obj.Display() << endl;
    Test<float> obj2(2.5, 3.7);
    cout << "Sum is: " << obj2.Display() << endl;
    Test<double> obj3(1.2, 4.5);
    cout << "Sum is: " << obj3.Display() << endl;
    return 0;
}