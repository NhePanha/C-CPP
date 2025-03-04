#include <iostream>
#include <fstream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
using namespace std;
int main() {
    // Create file stream
    fstream storage;
    // open file stream 
    storage.open("storages.bin",ios::out|ios::binary);
    // check the file
    if(!storage.is_open()) {
        cout << RED << "Error: Unable to open file!" << RESET << endl;
        return 1;
    }
    // write data
    string date;
    cout<<BLUE<<"Enter Data : ";getline(cin, date);
    storage.write((char*)&date, sizeof(date));
    // close the file
    storage.close();
    cout<<GREEN<<"Data stored successfully!"<<RESET<<endl;
    // open the file stream for reading
    storage.open("storages.bin",ios::in|ios::binary);
    // check the file
    if(!storage.is_open()) {
        cout << RED << "Error: Unable to open file!" << RESET << endl;
        return 1;
    }
    // read data
    cout<<YELLOW<<"Stored Data : ";
    string read_date;
    storage.read((char*)&read_date, sizeof(read_date));
    cout<<read_date<<endl;
    // close the file
    storage.close();
    // end of program
    cout<<RESET<<endl;
    return 0;
}