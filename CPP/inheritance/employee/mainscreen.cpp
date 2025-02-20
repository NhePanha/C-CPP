#include <iostream>
#include <iomanip>
// #include "date.h"

using namespace std;

void Header() {
    cout << setw(12) << "ID"
         << setw(12) << "Name"
         << setw(12) << "Gender"
         << setw(12) << "Age"
         << setw(12) << "Salary"
         << setw(12) << "Hour"
         << setw(12) << "Rate"
         << setw(12) << "DD/MM/YYYY" << endl;
}

int main() {
    Date date;
    date.Input();
    Header();
    date.Output();
    return 0;
}
