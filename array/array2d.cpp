// #include <stdio.h>
// int main()
// {
//     int i,j;
//     for(int k=0;k<3;k++)
//     {
//         printf("\n");
//         for(i=0;i<10;i++)
//         {
//             printf("\n");
//             for(j=0;j<10;j++)
//             {
//                 printf("%d ", j);
//             }
//         }
//     }
//     return 0;
// }
#include <stdio.h>

int main()
{
    int id[100][100];
    char name[100][100][30];
    int qty[100][100];
    double price[100][100];
    int row;
    int column;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &column);
    printf("\nEnter the product details:\n");
    for(int i=0; i<row; i++)
    {
        printf("Row %d:\n", i+1);
        for(int j=0; j<column; j++)
        {
            printf("ID: ");
            scanf("%d", &id[i][j]);
            printf("Name: ");
            scanf("%s", name[i][j]);
            printf("Quantity: ");
            scanf("%d", &qty[i][j]);
            printf("Price: ");
            scanf("%lf", &price[i][j]);
        }
    }
    printf("\nProduct Details:\n");
    for(int i=0; i<row; i++)
    {
        printf("\nRow %d:\n", i+1);
        for(int j=0; j<column; j++)
        {
            printf("%-12d %-12s %-12d %-12.2lf\n",id[i][j], name[i][j], qty[i][j],price[i][j]);
        }
        printf("\n");
    }
    return 0;
}