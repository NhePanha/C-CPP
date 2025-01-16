#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int code[100];
char name[100][20];
double qty[100];
double price[100];
double total[100];
double tax[100];
double discount[100];
double payment[100];
int i;

void AddProduct()
{
    printf("Enter Product Code   : ");scanf("%d",&code[i]);
    printf("Enter Product Name   : ");scanf("%s",&name[i]);
    printf("Enter Product Price  : ");scanf("%lf",&price[i]);
    printf("Enter Product Qty    : ");scanf("%lf",&qty[i]);
}
double Total()
{
    total[i] = qty[i] * price[i];
    return total[i];
}
double Tax()
{
    tax[i] = Total() * 0.05;
    return tax[i];
}
double Discount()
{
    // ternary
    double t = Total();
    discount[i] = (t >= 1 && t <= 100)?  t * 0.1 :
    (t > 100 && t <= 200)? t * 0.2 :
    (t > 200 && t <= 300)? t * 0.3 :
    (t > 300 && t <= 400)? t * 0.4 : t * 0.5;
    return discount[i];
}
double Payment()
{
    payment[i] = Total() + Tax() - Discount();
    return payment[i];
}
void Header()
{
    printf("%-12s %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n",
    "Code","Name","Price","Qty","Total","Tax","Discount","Payment");
}
void Display()
{
    printf("%-12d %-12s %-12.lf %-12.2lf %-12.2lf %-12.2lf %-12.2lf %-12.2lf\n",
    code[i],name[i],price[i],qty[i],Total(),Tax(),Discount(),Payment());
}
int main()
{
    int op,j,n;
    do{
        printf("==============[ M E N U ]==============\n");
        printf("[ 1 - Add Product      ]\n");
        printf("[ 2 - Display Product  ]\n");
        printf("[ 3 - Search Product   ]\n");
        printf("[ 4 - Sort Product     ]\n");
        printf("[ 5 - Update Product   ]\n");
        printf("[ 6 - Delete Product   ]\n");
        printf("[ 7 - Insert Product   ]\n");
        printf("[ 8 - Add Product      ]\n");
        printf("[ 9 - Total Payment    ]\n");
        printf("[ 10- Exit(0) MENU     ]\n");
        printf("[Please select one option ] : ");scanf("%d",&op);
        switch(op)
        {
            case 1:{
                printf("Enter Number Of Product : ");scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("***********[IT000%d]***********\n",i+1);
                    AddProduct();
                }
            }break;
            case 2:{
                Header();
                for(i=0;i<n;i++)
                {
                    Display();
                }
            }break;
            case 3:{
                char searchname[100];
                int searchid,op;
                printf("\t\t\t======[ Search by ]=====\n");
                printf("\t\t\t\t[ 1 - Name  ]\n");
                printf("\t\t\t\t[ 2 - Code  ]\n");
                printf("Enter Your Choice : ");scanf("%d",&op);
                switch(op)
                {
                    bool check = false;
                    case 1:{
                        printf("Enter Product Name : ");scanf("%s",&searchname);
                        for(i=0;i<n;i++)
                        {
                            if(strcmp(name[i],searchname)==0)
                            {
                                Header();
                                Display();
                                check = true;
                                printf("Search found....\n");
                                break;
                            }
                        }
                        if(!check){
                            printf("Search not found....\n");
                        }
                        
                    }break;
                    case 2:{
                        printf("Enter Product ID : ");scanf("%d",&searchid);
                        for(i=0;i<n;i++)
                        {
                            if(code[i]==searchid)
                            {
                                Header();
                                Display();
                                printf("Search found....\n");
                                break;
                            }
                        }
                        if(i==n){
                            printf("Search not found....\n");
                        }
                    }break;
                }
            }break;
            case 4:{
                int check = 0;
                // bool check = false;
                int n_code;
                char n_name[100];
                double n_price,n_qty,n_total,n_dis,n_tax,n_pay;
                int op;
                char status[100];
                do{
                    printf("===========[Sort By]==============\n");
                    printf("\t[1 - Sort By Code    ]\n");
                    printf("\t[2 - Sort By Name    ]\n");
                    printf("\t[3 - Sort By Payment ]\n");
                    printf("[Please select one option ] : ");scanf("%d",&op);
                    switch(op)
                    {
                        case 1:{
                            for(i=0;i<n;i++)
                            {
                                for(j=i+1;j<n;j++)
                                {
                                    if(code[i] > code[j])
                                    {
                                        n_code = code[i];
                                        code[i] = code[j];
                                        code[j] = n_code;

                                        strcpy(n_name,name[i]);
                                        strcpy(name[i],name[j]);
                                        strcpy(name[j],n_name);

                                        n_price = price[i];
                                        price[i] = price[j];
                                        price[j] = n_price;

                                        n_qty = qty[i];
                                        qty[i] = qty[j];
                                        qty[j] = n_qty;

                                        n_total = total[i];
                                        total[i] = total[j];
                                        total[j] = n_total;

                                        n_tax = tax[i];
                                        tax[i] = tax[j];
                                        tax[j] = n_tax;

                                        n_dis = discount[i];
                                        discount[i] = discount[j];
                                        discount[j] = n_dis;

                                        n_pay = payment[i];
                                        payment[i] = payment[j];
                                        payment[j] = n_pay;
                                        check = 1;
                                    }
                                }
                            }
                            if(check==0)
                            {
                                printf("sorting error\n");
                            }
                            else
                            {
                                printf("Sorting successfully\n");
                            }
                        }break;
                        case 2:{
                            bool check = false;
                            for(i=0;i<n;i++){
                                for(int j=i+1;j<n;j++)
                                {
                                    if(strcmp(name[j],name[i])>0)
                                    {
                                        n_code = code[i];
                                        code[i] = code[j];
                                        code[j] = n_code;

                                        strcpy(n_name,name[i]);
                                        strcpy(name[i],name[j]);
                                        strcpy(name[j],n_name);

                                        n_price = price[i];
                                        price[i] = price[j];
                                        price[j] = n_price;

                                        n_qty = qty[i];
                                        qty[i] = qty[j];
                                        qty[j] = n_qty;

                                        n_total = total[i];
                                        total[i] = total[j];
                                        total[j] = n_total;

                                        n_tax = tax[i];
                                        tax[i] = tax[j];
                                        tax[j] = n_tax;

                                        n_dis = discount[i];
                                        discount[i] = discount[j];
                                        discount[j] = n_dis;

                                        n_pay = payment[i];
                                        payment[i] = payment[j];
                                        payment[j] = n_pay;
                                        check = true;
                                    }
                                }
                            }
                            if(check==false)
                            {
                                printf("sorting error\n");
                            }
                            else
                            {
                                printf("Sorting successfully\n");
                            }
                        }break;
                        case 3:{
                            for(i=0;i<n;i++)
                            {
                                for(j=i+1;j<n;j++)
                                {
                                    if(payment[i] < payment[j])
                                    {
                                        n_code = code[i];
                                        code[i] = code[j];
                                        code[j] = n_code;

                                        strcpy(n_name,name[i]);
                                        strcpy(name[i],name[j]);
                                        strcpy(name[j],n_name);

                                        n_price = price[i];
                                        price[i] = price[j];
                                        price[j] = n_price;

                                        n_qty = qty[i];
                                        qty[i] = qty[j];
                                        qty[j] = n_qty;

                                        n_total = total[i];
                                        total[i] = total[j];
                                        total[j] = n_total;

                                        n_tax = tax[i];
                                        tax[i] = tax[j];
                                        tax[j] = n_tax;

                                        n_dis = discount[i];
                                        discount[i] = discount[j];
                                        discount[j] = n_dis;

                                        n_pay = payment[i];
                                        payment[i] = payment[j];
                                        payment[j] = n_pay;
                                        check = 1;
                                    }
                                }
                            }
                            if(check==0)
                            {
                                printf("sorting error\n");
                            }
                            else
                            {
                                printf("Sorting successfully\n");
                            }
                        }break;
                    }
                    printf("press enter key to cotinue yes/no to exit :");scanf("%s",&status);
                }while(strcmp(status, "yes")==0 || strcmp(status, "YES")==0);
            }break;
            case 5:{
                char updatename[100];
                int updatecode,op;
                printf("\t\t\t======[ Update by ]=====\n");
                printf("\t\t\t\t[ 1 - Name  ]\n");
                printf("\t\t\t\t[ 2 - Code  ]\n");
                printf("Enter Your Choice : ");scanf("%d",&op);
                switch(op)
                {
                    bool check = false;
                    case 1:{
                        printf("Enter Product Name : ");scanf("%s",&updatename);
                        for(i=0;i<n;i++)
                        {
                            if(strcmp(name[i],updatename)==0)
                            {
                                AddProduct();
                                check = true;
                                printf("Update successfully\n");
                                break;
                            }
                        }
                        if(!check){
                            printf("Search not found....\n");
                        }
                        
                    }break;
                    case 2:{
                        printf("Enter Product ID : ");scanf("%d",&updatecode);
                        for(i=0;i<n;i++)
                        {
                            if(code[i]==updatecode)
                            {
                                AddProduct();
                                printf("Update Successfully....\n");
                                break;
                            }
                        }
                        if(i==n){
                            printf("Search not found....\n");
                        }
                    }break;
                }
            }break;
            case 6:{
                char searchname[50];
                bool check = false;
                printf("Enter name to delete : ");scanf("%s",&searchname);
                for(i=0;i<n;i++)
                {
                    if(strcmp(searchname,name[i])==0){
                        for(int j = n ; j< i + 1; j++)
                        {
                            code[j] = code[j+1];
                            strcpy(name[j],name[j+1]);
                            price[j] = price[j+1];
                            qty[j] = qty[j+1];
                            total[j] = total[j+1];
                            tax[j] = tax[j+1];
                            discount[j] = discount[j+1];
                            payment[j] = payment[j+1];
                        }
                        n--;
                        check = true;
                        printf("Delete value successfully....\n");
                    }
                }
                if(check==false)
                {
                    printf("Delete not success..!!!!\n");
                }
            }break;
            case 7:{
                int insertid;
                printf("Enter id to insert : ");sscanf("%d",&insertid);
                bool check = false;
                for(i=0;i<n;i++)
                {
                    if(insertid==code[i])
                    {
                        for(int j = n ;j >= i ; j--)
                        {
                            code[j] = code[j-1];
                            strcpy(name[j],name[j-1]);
                            price[j] = price[j-1];
                            qty[j] = qty[j-1];
                            total[j] = total[j-1];
                            tax[j] = tax[j-1];
                            discount[j] = discount[j-1];
                            payment[j] = payment[j-1];
                        }
                        n++;
                        AddProduct();
                        check = true;
                        printf("Insert successfully...\n");
                    }
                }
                if(check==false)
                {
                    printf("Insert Error...!\n");
                }
            }break;
            case 8:{
                int add;
                bool check = false;
                printf("Add New Product : ");scanf("%d",&add);
                for(i= n ; i < n+add ; i++)
                {
                    AddProduct();
                    check = true;
                    printf("Add Product Successfully...!\n");
                }
                n+=add;
                if(check == false)
                {
                    printf("Error Add.......\n");
                }
            }break;
            case 9:{
                double total_payment;
                for(i=0;i<n;i++)
                {
                    total_payment += payment[i];
                }
                printf("_____________________________________\n");
                printf("Total Payment : %.2lf\n",total_payment);
                printf("           thank you\n");
            }break;
        }
    }while(op!=0);
    return 0;
}