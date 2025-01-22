#include <stdio.h>
struct Person
{
    int id;
    char name[100];
    char sex[10];

    struct Student{
        double score1, score2, score3;

        struct Calculate{
            double average;
            double total;
            char grade;
        }calculate; // object3
    }student; // object2
}person;  // object1

int main()
{
    
    printf("Enter Code : ");scanf("%d",&person.id);
    printf("Enter Name : ");scanf("%s",&person.name);
    printf("Enter Sex : ");scanf("%s",&person.sex);
    printf("Enter Student Score 1 : ");scanf("%lf",&person.student.score1);
    printf("Enter Student Score 2 : ");scanf("%lf",&person.student.score2);
    printf("Enter Student Score 3 : ");scanf("%lf",&person.student.score3);
    
    person.student.calculate.total = person.student.score1 + person.student.score2 + person.student.score3;
    person.student.calculate.average = person.student.calculate.total / 3;
    double avg = person.student.calculate.average;

    person.student.calculate.grade = (avg > 90 && avg <= 100)? 'A':
    (avg > 80 && avg <= 90)? 'B':
    (avg > 70 && avg <= 80)? 'C':
    (avg > 60 && avg <= 70)? 'D':
    (avg > 50 && avg <= 60)? 'E': 'F';

    printf("\nStudent Details:\n");
    printf("ID : %d\n",person.id);
    printf("Name : %s\n",person.name);
    printf("Sex : %s\n",person.sex);
    printf("Total Score : %.2lf\n",person.student.calculate.total);
    printf("Average Score : %.2lf\n",person.student.calculate.average);
    printf("Grade : %c\n",person.student.calculate.grade);

    return 0;
}