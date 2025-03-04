#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream namefile;  // Use ifstream for reading
    // Open file stream for reading
    namefile.open("names.txt", ios::in);
    if (!namefile) {
        cout << "Failed to open name file!" << endl;
        return 0;
    }
    string name;
    while (getline(namefile, name)) {  // Read line by line
        cout << "Name: " << name << endl;
    }
    namefile.close();
    return 0;
}
