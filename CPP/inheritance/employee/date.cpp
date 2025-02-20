#include "date.h"

Date::Date() : Person(), Employee() {} // Constructor initialization

void Date::Input() {
    Person::Input();
    Employee::Input();
    cout << "Enter (dd/mm/yyyy): ";
    cin >> day >> month >> year;
}

void Date::Output() {
    Person::Output();
    Employee::Output();
    cout << setw(12) << day << "/" << month << "/" << year << endl;
}
#endif // DATE_H
