#include<stdio.h>
// Structure definition
struct Employee {
    int id;
    char name[100];
    double salary;
    char gender[10];
};

// Function to take inputs for an Employee
void Inputs(struct Employee *e) {
    printf("Employee code : ");
    scanf("%d", &e->id);
    printf("Employee name : ");
    scanf("%s", e->name);
    printf("Employee salary : ");
    scanf("%lf", &e->salary);
    printf("Employee gender : ");
    scanf("%s", e->gender);
}
// Function to display details of an Employee
void Output(struct Employee e) {
    printf("\nEmployee Details:\n");
    printf("Employee Code : %d\n", e.id);
    printf("Employee Name : %s\n", e.name);
    printf("Employee Salary : %.2lf\n", e.salary);
    printf("Employee Gender : %s\n", e.gender);
}
int main() {
    struct Employee employee[100];
    int i, n;

    printf("Enter number of employees : ");
    scanf("%d", &n);

    // Input details for each employee
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d Details:\n", i + 1);
        Inputs(&employee[i]);
    }
    // Display details for each employee
    printf("\nAll Employee Details:\n");
    for (i = 0; i < n; i++) {
        Output(employee[i]);
    }
    return 0;
}
