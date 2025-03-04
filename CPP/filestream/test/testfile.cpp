#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream namefile;
    // Open file stream for writing
    namefile.open("names.txt", ios::app);
    
    if (!namefile) {
        cout << "Failed to open name file!" << endl;
        return 0;
    }

    char name[100];
    cout << "Enter Name: ";
    cin.getline(name, 100);

    namefile << name << endl;
    cout << "Your Name Saved Successfully!" << endl;
    namefile.close();
    return 0;
}
