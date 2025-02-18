#include <iostream>
#include <iomanip>
using namespace std;
// create class
class Library{
    private:
        int id;
        string title;
        string subject;
        string auther;
    public:
        Library()
        {
            id = 0;
            title = "NULL";
            subject = "NULL";
            auther = "NULL";
        }
        void Add()
        {
            cout<<"Enter ID : ";cin>>id;
            cout<<"Enter Title : ";cin>>title;
            cout<<"Enter Subject : ";cin>>subject;
            cout<<"Enter Auther  : ";cin>>auther;
        }
        void Display()
        {
            cout<<setw(12)<<id<<
            setw(12)<<title<<
            setw(12)<<subject<<
            setw(12)<<auther<<endl;
        }
};
int main()
{
    // create object pointer
    Library *lib;
    int n;
    cout<<"Enter Number Of Library : ";cin>>n;
    lib = (Library*)calloc(n,sizeof(Library));
    if(!lib)
    {
        cout<<"Library is null"<<endl;
        return 0; // exit;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            (lib+i)->Add();
        }
        for(int i=0;i<n;i++)
        {
            (lib+i)->Display();
        }
    }
    return 0;
}