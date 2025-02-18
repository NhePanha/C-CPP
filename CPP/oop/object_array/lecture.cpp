#include <iostream>
#include <iomanip>
using namespace std;
int i;
// create claas lectures
class Lecture{
    private:
    // block data members  
        int code;
        string name,gender,subject;
    public:
    // block methods
        // properties set
        void setCode(int c){
            code = c;
        }
        void setName(string n){
            name = n;
        }
        void setGender(string g){
            gender = g;
        }
        void setSubject(string s){
            subject = s;
        }
        // properties get
        int getCode(){
            return code;
        }
        string getName(){
            return name;
        }
        string getGender(){
            return gender;
        }
        string getSubject(){
            return subject;
        }
        // functions
        void AddLecture();
        void ShowLecture();
};
void Lecture::AddLecture()
{
    cout << "Enter Lecture Code   : ";cin >> code;
    cout << "Enter Lecture Name   : ";cin.ignore();getline(cin,name);
    cout << "Enter Lecture Gender : ";cin >> gender;
    cout << "Enter Lecture Subject: ";cin.ignore();getline(cin,subject);
}
void Header(){
    cout<<setw(12)<<"Code"<<
    setw(12)<<"Name"<<
    setw(12)<<"Gender"<<
    setw(12)<<"Subject"<<endl;
    cout<<"----------------------------------------------------"<<endl;
}
void Lecture::ShowLecture()
{
    cout<<setw(12)<<code<<
    setw(12)<<name<<
    setw(12)<<gender<<
    setw(12)<<subject<<endl;
}
void SearchLecture(Lecture lec[],int n)
{
    int code;
    bool check = false;
    cout<<"Enter Lecture Code : ";cin>>code;
    for(i=0;i<n;i++)
    {
        if(lec[i].getCode()==code)
        {
            cout<<"=============[ IT000"<<i+1<<"]==============="<<endl;
            lec[i].ShowLecture();
            check = true;
        }
    }
    if(!check)
    {
        cout<<"Lecture not found....!"<<endl;
    }
    else{
        cout<<"Total "<<n<<" Lectures Found....!"<<endl;
    }
}
void UpdateLecture(Lecture lec[],int n)
{
    int code;
    bool check = false;
    string n_name;
    cout<<"Enter Lecture Code : ";cin>>code;
    for(i=0;i<n;i++)
    {
        if(lec[i].getCode()==code)
        {
            int op;
            cout<<"[1. Update Name  ]"<<endl;
            cout<<"[2. Update Gender ]"<<endl;
            cout<<"[3. Update Subject]"<<endl;
            cout<<"Enter Your Choice : ";cin>>op;
            switch(op)
            {
                case 1:{
                    cout<<"Enter New Name : ";cin.ignore();getline(cin,n_name);
                    lec[i].setName(n_name);
                    check = true;
                    
                }break;
                case 2:{
                    string n_gender;
                    cout<<"Enter New Gender : ";cin>>n_gender;
                    lec[i].setGender(n_gender);
                    check = true;
                    
                }break;
                case 3:{
                    string n_subject;
                    cout<<"Enter New Subject : ";cin.ignore();getline(cin,n_subject);
                    lec[i].setSubject(n_subject);
                    check = true;
                    
                }break;
            }
        }
    }
    if(!check)
    {
        cout<<"Lecture not found....!"<<endl;
    }
    else
    {
        cout<<"Update successfully....!"<<endl;
    }
}
// pass by reference
void DeleteLecture(Lecture lec[],int *n)
{
    int deletecode;
    bool check = false;
    cout<<"Enter code to delete : ";cin >> deletecode;
    for(i=0;i<*n;i++)
    {
        if(lec[i].getCode()==deletecode)
        {
            for(int j = i ; j < *n - 1; j++)
            {
                lec[j] = lec[j+1];
                check = true;
            }
            (*n)--;
            cout<<"Delete successfully....!"<<endl;
            return; // exit function 
        }
    }
    if(!check)
    {
        cout<<"Lecture not found....!"<<endl;
    }
}
//pass by reference
void SortLecture(Lecture lec[],int *n)
{
    bool check = false;
    for(int i=0; i<*n-1; i++)
    {
        for(int j=0; j<*n-i-1; j++)
        {
            if(lec[j].getCode() > lec[j+1].getCode())
            {
                swap(lec[j],lec[j+1]);
                check = true;
            }
        }
    }
    if(check)
    {
        cout<<"Sort successfully....!"<<endl;
    }
    else
    {
        cout<<"No need to sort....!"<<endl;
    }
}
int main()
{
    // create object the array
    Lecture lec[100];
    int n,op;
    do{
        cout<<"=============[ ME NU]==============="<<endl;
        cout<<"[1. Add Lecture   ]"<<endl;
        cout<<"[2. Show Lecture  ]"<<endl;
        cout<<"[3. Search Lecture]"<<endl;
        cout<<"[4. Update Lecture]"<<endl;
        cout<<"[5. Delete Lecture]"<<endl;
        cout<<"[6. Sort Lecture  ]"<<endl;
        cout<<"[0. Exit          ]"<<endl;
        cout<<"Enter Your Choice : ";cin>>op;
        switch(op)
        {
            case 1:{
                cout<<"Enter Number of Lectures : ";cin>>n;
                for(i=0;i<n;i++)
                {
                    cout<<"=============[ IT000"<<i+1<<"]==============="<<endl;
                    lec[i].AddLecture();
                }
            }break;
            case 2:{
                cout<<"=============[ Show Lecture]==============="<<endl;
                Header();
                for(i=0;i<n;i++)
                {
                    lec[i].ShowLecture();
                }
            }break;
            case 3:{
                cout<<"=============[ Search Lecture]==============="<<endl;
                SearchLecture(lec,n);
            }break;
            case 4:{
                cout<<"=============[ Update Lecture]==============="<<endl;
                UpdateLecture(lec,n);
            }break;
            case 5:{
                DeleteLecture(lec,&n);
            }break;
            case 6:{
                SortLecture(lec,&n);
            }break;
        }
    }while(op!=0);
    return 0;
}