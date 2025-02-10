#include <iostream>
#include <iomanip>  // for setw() function
#include <string>  // for string data type
using namespace std;
// create class products 
class Products{
    private:
    // block data members
        int code;
        string name;
        double qty;
        double price;
    public:
    // block methods
    void input(){
        cout<<"Enter Product Code : "; cin>>code;
        cout<<"Enter Product Name : "; cin>>name;
        cout<<"Enter Product Quantity : "; cin>>qty;
        cout<<"Enter Product Price : "; cin>>price;
    }
    void Header()
    {
        cout<<setw(12)<<"Product Code"<<
        setw(12)<<"Product Name"<<
        setw(12)<<"Product Quantity"<<
        setw(12)<<"Product Price"<<endl;
    }
    void output(){
        cout<<setw(12)<<code<<
        setw(12)<<name<<
        setw(12)<<qty<<
        setw(12)<<price<<endl;
    }

};
int main()
{
    // create object the array of products
    Products pro[100];
    int n;
    cout<<"Enter the number of products : "; cin>>n;
    // input data
    for(int i=0; i<n; i++){
        cout<<"Product "<<i+1<<":\n";
        pro[i].input();
    }
    // display header
    cout<<"\nProduct List:\n";
    pro[0].Header();
    // display data
    for(int i=0; i<n; i++){
        pro[i].output();
    }
    return 0;
}