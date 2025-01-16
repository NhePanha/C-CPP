/*#include <stdio.h>
// global variables
int code,qty,diss;
char name[256],size[10];
double price, total, dis, payment,tax,pay_reil;
void Input()
{
    printf("Enter Code  : "); scanf("%d",&code);
    printf("Enter Name  : "); scanf("%s",name);
    printf("Enter Size  : "); scanf("%s",size);
    printf("Enter Qty   : "); scanf("%d",&qty);
    printf("Enter Price : "); scanf("%lf",&price);
    printf("Enter Dis   : "); scanf("%d",&diss);

    total = price * qty;  // Total price before discount
    dis = (total * diss) / 100;  //# Discount amount
    tax = (total * 5) / 100; //# Tax based on total before discount
    payment = (tax + total) - dis;  //# Final payment after applying tax and discount

}
void Display(){
    printf("%12d %12s %12s %12d %12.2lf %12.2lf %12.2lf %12.2lf %12.2lf\n",code,name,size,qty,price,total,dis,tax,payment);
}
void Header()
{
    printf("%12s %12s %12s %12s %12s %12s %12s %12s %12s\n","Code","Name","Size","Qty","Price","Total","Dis","Tax","Payment");
}
void Changetoreil()
{
    pay_reil = payment * 4100;
    printf("Payment in Reil : %.2lf KHR\n",pay_reil);
}

int main()
{
    // local variables
    int op;

    do{
        printf("===============[MENU]===================\n");
        printf("[1. Input       ]\n");
        printf("[2. Display     ]\n");
        printf("[3. Pay Dollar  ]\n");
        printf("[4. Pay Reil    ]\n");
        printf("[5. Exit        ]\n");
        printf("Enter Your Choice : "); scanf("%d",&op);
        switch(op)
        {
            case 1:{
                Input();
            }break;
            case 2:{
                Header();
                Display();
            }break;
            case 3:{
                printf("Payment : %.2lf $\n",payment);
            }break;
            case 4:{
                Changetoreil();
            }break;
            case 5:{
                // exit(0);
                return 0;
            }break;
            default : printf("Invalid Option\n");
        }
    }while(op!=0);
    return 0;
}*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// global variables
int code,qty;
char name[256],size[10];
double price;
// block function
void AddProduct()
{
    printf("===============[Add Product]===================\n");
    printf("Enter Code  : "); scanf("%d",&code);
    printf("Enter Name  : "); scanf("%s",name);
    printf("Enter Size  : "); scanf("%s",size);
    printf("Enter Qty   : "); scanf("%d",&qty);
    printf("Enter Price : "); scanf("%lf",&price);
}
double CalculateTotal()
{
    return price * qty;
}
-double CalculateDis()
{
    double total = CalculateTotal();
    return (total >= 1 && total <= 20)? total * 0.1 :
    (total >= 21 && total <= 40)? total * 0.2 :
    (total > 41 && total <= 60)? total * 0.3 :
    (total > 61 && total <= 80)? total * 0.4 : total * 0.5;
}
double CalculateTax()
{
    return CalculateTotal() * 0.05;
}
double CalculatePay()
{
    return CalculateTotal() + CalculateTax() - CalculateDis();
}
double KHR()
{
    return CalculatePay() * 4100;
}
void Header()
{
    printf("%12s %12s %12s %12s %12s %12s %12s %12s %12s\n","Code","Name","Size","Qty","Price","Total","Discount","TAX","Payments");
}
void Display()
{
    printf("%12d %12s %12s %12d %12.2lf %12.2lf %12.2lf %12.2lf %12.2lf\n",code,name,size,qty,price,CalculateTotal(),CalculateDis(),CalculateTax(),CalculatePay());
}
void MENU()
{
    int op;
    do{
        printf("===============[MENU PRODUCTS]=============\n");
        printf("[ 1 - Add Products]\n");
        printf("[ 2 - Display     ]\n");
        printf("[ 3 - Pay Dollar  ]\n");
        printf("[ 4 - Pay KHR     ]\n");
        printf("Please select one option of products : ");scanf("%d",&op);
        switch(op)
        {
            case 1:{
                AddProduct();
            }break;
            case 2:{
                Header();
                Display();
            }break;
            case 3:{
                printf("Payment : %.2lf $\n",CalculatePay());
            }break;
            case 4:{
                printf("Payment in Reil : %.2lf KHR\n",KHR());
            }break;
            default : printf("Invalid Option\n");
        }
    }while(op!=0);
}
void Login()
{
    char username[100],pass[100],confi[100];
    printf("\t\t\tEnter Email      : ");scanf("%s",&username);
    printf("\t\t\tEnter Password   : ");scanf("%s",&pass);
    printf("\t\t\tConfirm Password : ");scanf("%s",&confi);
    if(strcmp(username, "") == 0 || strcmp(pass, "") == 0 || strcmp(confi, "") == 0){
        printf("\n\t\t\tRegistration Failed! All fields are required.\n");
    }
    else{
        if(strcmp(username,"admin@gmail.com")==0)
        {
            if(strcmp(pass,confi)==0)
            {
                MENU();
            }
        }
    }
}
int main()
{
    Login();
    return 0;
}


#include <stdio.h>

int main()
{
    char status[100];
    int str = 0, spl = 0, num = 0;
    printf("Enter Status : ");
    fgets(status, sizeof status, stdin);

    for (int i = 0; status[i] != '\0'; i++)
    {
        if ((status[i] >= 'A' && status[i] <= 'Z') || (status[i] >= 'a' && status[i] <= 'z'))
        {
            str++;
        }
        else if (status[i] >= '0' && status[i] <= '9')
        {
            num++;
        }
        else // to avoid counting space and newline
        {
            spl++;
        }
    }

    printf("Number of Letters : %d\n", str);
    printf("Number of Digits  : %d\n", num);
    printf("Number of Special Characters : %d\n", spl);

    return 0;
}



// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char arrayname[][20] = {"dara","lyna","sovan","nary","phya","yaya"};

//     printf("%s",arrayname[5]);
//     return 0;
// }


#include <stdio.h>
#include <string.h>
int i,op;
int code[] = {1001,1002,1003,1004,1005,1006,1007};
char name[][20] = {"Americano","Espresso","Cappuccino","Latte","Mocha","Tea","Hot Chocolate"};
int qty[] = {35,55,65,23,56,77,89};
double price[] = {3.5,5.5,6.5,2.3,5.6,7.7,8.9};
void Display()
{
    printf("%-15d %-15s %-15d %-15.2lf\n",code[i],name[i],qty[i],price[i]);
}
void Header()
{
    printf("%-15s %-15s %-15s %-15s\n","Code","Name","Quantity","Price");
    printf("-------------------------------------------------------------\n");
}
int main()
{
    double paykhr,paydol;
    int orderqty;
    do{
        printf("===============[ MENU ]=================\n");
        printf("[1. Display Stock]\n");
        printf("[2. Order Coffee ]\n");
        printf("[3. Payments KHR ]\n");
        printf("[4. Payments $   ]\n");
        printf("Please select one option : ");scanf("%d",&op);
        switch(op)
        {
            case 1:{
                Header();
                for(i=0;i<7;i++)
                {
                    Display();
                }
            }break;
            case 2:{
                char ordername[100];
                printf("Order Name : ");scanf("%s",&ordername);
                for(i=0;i<7;i++)
                {
                    if(strcmp(ordername,name[i])==0)
                    {
                        printf("Order Quantity : ");scanf("%d",&orderqty);
                        if(qty[i] >= orderqty)
                        {
                            qty[i] -= orderqty;
                            paydol = orderqty * price[i];
                            printf("Order Placed Successfully\n");
                            break;
                        }
                        else
                        {
                            printf("Not enough stock\n");
                        }
                    }
                }
                // Add other coffee code here
            }break;
            case 3:{
                paykhr = paydol * 4000;
                printf("Payment = %.2lf KHR\n",paykhr);
                // Add payment in KHR code here
            }break;
            case 4:{
                printf("Payments = %.2lf Dollar\n",paydol);
                // Add payment in $ code here
            }break;
            default : printf("Invalid Option\n");
        }
    }while(op!=0);


    return 0;
}