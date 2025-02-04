#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <iomanip>

using namespace std;

class Car {
private:
    int id;
    string model;
    double price;

public:
    void Input() {
        cout << "Enter Car ID: ";
        cin >> id;
        cout << "Enter Car Model: ";
        cin >> model;
        cout << "Enter Car Price: ";
        cin >> price;
    }

    void Output() {
        cout << left << setw(12) << id
             << setw(12) << model
             << setw(12) << price << endl;
    }
};

#endif Car.h
