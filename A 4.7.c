#include<stdio.h>
#include<string.h>

struct student {
    int roll_no;
    char stud_name[50];
    int mark1;
    int mark2;
    int mark3;
    int total_marks;
    float avg_marks;
};

void arrange_records(struct student *students, int num_students) {
    struct student temp;
    for(int i=0; i<num_students; i++) {
        for(int j=i+1; j<num_students; j++) {
            if(students[i].total_marks < students[j].total_marks) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    struct student students[num_students];
    for(int i=0; i<num_students; i++) {
        printf("Enter details of student %d:\n", i+1);
        printf("Roll No.: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].stud_name);
        printf("Mark 1: ");
        scanf("%d", &students[i].mark1);
        printf("Mark 2: ");
        scanf("%d", &students[i].mark2);
        printf("Mark 3: ");
        scanf("%d", &students[i].mark3);
        students[i].total_marks = students[i].mark1 + students[i].mark2 + students[i].mark3;
        students[i].avg_marks = (float)students[i].total_marks / 3;
    }

   
    arrange_records(students, num_students);

    printf("\nRoll No.\tName\t\tTotal Marks\tAverage Marks\n");
    for(int i=0; i<num_students; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", students[i].roll_no, students[i].stud_name, students[i].total_marks, students[i].avg_marks);
    }

    return 0;
}

