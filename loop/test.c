#include<stdio.h>
#include <ncurses.h>
#include <stdlib.h>
int main()
{
    double dollar,reil, bath;
    int op;
    do{
        printf("1 - Reil to Dollar\n");
        printf("2 - Dollar to Reil\n");
        printf("3 - Reil to Bath\n");
        printf("Please Choose One Option : ");scanf("%d",&op);
        switch(op)
        {
            case 1 :{
                printf("Enter Reil : ");scanf("%lf",&reil);
                dollar = reil / 4000;
                printf("Equivalent Dollar : %.2lf\n",dollar);
            }break;
            case 2 :{
                printf("Enter Dollar : ");scanf("%lf",&dollar);
                reil = dollar * 4000;
                printf("Equivalent Reil : %.2lf\n",reil);
            }break;
            case 3 :{
                printf("Enter Reil : ");scanf("%lf",&reil);
                bath = reil * 0.0084;
                printf("Equivalent Bath : %.2lf\n",bath);
            }break;
            default : printf("Invalid Option\n");
        }
    }while(op!=0);
    return 0;
}