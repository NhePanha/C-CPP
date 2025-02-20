class Person{
    protected:
        int id;
        string name,gender;
        int age;
    public:
        Person()
        {
            id = 0;
            name = "Null";
            gender = "Null";
            age = 0;
        }
        void Input()
        {
            cout<<"Enter ID : ";cin>>id;
            cout<<"Enter Name : ";cin>>name;
            cout<<"Enter Gender : ";cin>>gender;
            cout<<"Enter Age    : ";cin>>age;
        }
        void Output()
        {
            cout<<setw(12)<<id<<
            setw(12)<<name<<
            setw(12)<<gender<<
            setw(12)<<age;
        }
};