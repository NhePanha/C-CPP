#include <iostream>
using namespace std;
template<typename T>
T Sum(T x, T y)
{
    return x * y;
}

int main() {
    int a1 = 5, b1 = 10;
    double a2 = 2.5, b2 = 3.7;

    cout << "Sum of " << a1 << " and " << b1 << ": " << Sum(a1, b1) << endl;
    cout << "Sum of " << a2 << " and " << b2 << ": " << Sum(a2, b2) << endl;
    return 0;
}