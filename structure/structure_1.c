#include<stdio.h>
// structure structure_name
struct Employee{
    int id;
    char name[100];
    double salary;
    char gender[10];
};
int main()
{
    // structure / object structure
    struct Employee employee;
    printf("Employee code : ");scanf("%d",&employee.id);
    printf("Employee name : ");scanf("%s",employee.name);
    printf("Employee salary : ");scanf("%lf",&employee.salary);
    printf("Employee gender : ");scanf("%s",employee.gender);

    printf("\nEmployee Details:\n");
    printf("Employee Code : %d\n",employee.id);
    printf("Employee Name : %s\n",employee.name);
    printf("Employee Salary : %.2lf\n",employee.salary);
    printf("Employee Gender : %s\n",employee.gender);
    return 0;
}