#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    char name[50];
    int roll_number;
    struct tm birthday;
    struct tm admission_date;
} Student;


int calculate_age(struct tm birth_date, struct tm admission_date) {
    int age = admission_date.tm_year - birth_date.tm_year;
    if (admission_date.tm_mon < birth_date.tm_mon ||
        (admission_date.tm_mon == birth_date.tm_mon && admission_date.tm_mday < birth_date.tm_mday)) {
        age--;
    }
    return age;
}

int main() {
    Student student;
    memset(&student, 0, sizeof(Student)); 

   
    printf("Enter student name: ");
    fgets(student.name, sizeof(student.name), stdin);
    printf("Enter roll number: ");
    scanf("%d", &student.roll_number);
    printf("Enter birthday (yyyy-mm-dd): ");
    scanf("%d-%d-%d", &student.birthday.tm_year, &student.birthday.tm_mon, &student.birthday.tm_mday);
    printf("Enter admission date (yyyy-mm-dd): ");
    scanf("%d-%d-%d", &student.admission_date.tm_year, &student.admission_date.tm_mon, &student.admission_date.tm_mday);

    
    time_t birth_time = mktime(&student.birthday);
    time_t admission_time = mktime(&student.admission_date);

    
    int age = calculate_age(*localtime(&birth_time), *localtime(&admission_time));

   
    printf("Student Name: %s", student.name);
    printf("Roll Number: %d\n", student.roll_number);
    printf("Birthday: %d-%d-%d\n", student.birthday.tm_year, student.birthday.tm_mon, student.birthday.tm_mday);
    printf("Admission Date: %d-%d-%d\n", student.admission_date.tm_year, student.admission_date.tm_mon, student.admission_date.tm_mday);
    printf("Age at admission: %d\n", age);

    return 0;
}

