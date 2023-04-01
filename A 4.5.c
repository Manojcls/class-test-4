#include <stdio.h>
#define MAX_EMPLOYEES 100

struct employee {
    int eno;
    char ename[50];
    float salary;
};

int main() {
    struct employee emp[MAX_EMPLOYEES];
    int n, i, highest_salary_index = 0;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

   
    for (i = 0; i < n; i++) {
        printf("\nEnter details of Employee %d:\n", i+1);
        printf("Employee Number: ");
        scanf("%d", &emp[i].eno);
        printf("Employee Name: ");
        scanf("%s", emp[i].ename);
        printf("Employee Salary: ");
        scanf("%f", &emp[i].salary);
    }

 
    for (i = 1; i < n; i++) {
        if (emp[i].salary > emp[highest_salary_index].salary) {
            highest_salary_index = i;
        }
    }

    
    printf("\nEmployee with highest salary:\n");
    printf("Employee Number: %d\n", emp[highest_salary_index].eno);
    printf("Employee Name: %s\n", emp[highest_salary_index].ename);
    printf("Employee Salary: %.2f\n", emp[highest_salary_index].salary);

    return 0;
}

