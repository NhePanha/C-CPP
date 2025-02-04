// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//     int *p;

//     p = (int*)malloc(sizeof(int));
//     if(p == NULL){
//         printf("error: malloc failed");
//     }

//     printf("Enter Pointer : ");scanf("%d",p);

//     printf("Vlue Pointer : %d\n",*p);
//     free(p);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *text;
    int n;
    printf("Enter number : ");scanf("%d",&n);

    text = (char *)malloc(n*sizeof(char));
    if(!text){
        printf("error: memory allocation");
    }
    printf("\n");
    printf("Enter Text : ");scanf(" ");
    fgets(text);
    printf("%s\n",*text);
    return 0;
}