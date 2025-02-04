#include <stdio.h>

int main()
{
    int a = 10;
    int b = 50;

    int *point1;
    int *point2;

    point1 = &a;
    point2 = &b;

    printf("Address Value A : %d\n", a);
    printf("Adress pointer : %d\n",*point1);

    printf("Address Value B : %d\n", b);
    printf("Adress pointer : %d\n",*point2);
    return 0;
}