#include <stdio.h>

int main()
{
    int a[100][100][100];
    int i, j, k;
    int block,row,col;
    printf("Enter the number of blocks, rows, and columns: ");
    scanf("%d %d %d", &block, &row, &col);
    for(k = 0; k < block; k++)
    {
        for(i = 0; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                printf("Enter element at block %d, row %d, column %d: ", k+1, i+1, j+1);
                scanf("%d", &a[k][i][j]);
            }
        }
    }
    for(k = 0; k < block; k++)
    {
        printf("\nBlock %d:\n", k+1);
        for(i = 0; i < row; i++)
        {
            printf("\n");
            for(j = 0; j < col; j++)
            {
                printf("%d ",a[k][i][j]);
            }
        }
    }
    return 0;
}