#include <stdio.h>
#include <string.h>

struct student {
    int roll_no;
    char name[50];
    float marks[3];
    float percentage;
};

int n;
struct student students[100];

// Function to accept details of n students
void acceptDetails() {
    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter details of student %d:\n", i+1);
        printf("Roll number: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks in three subjects: ");
        scanf("%f%f%f", &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);
        students[i].percentage = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3.0;
    }
}

// Function to search for a student by roll number
void searchStudent() {
    int roll;
    printf("Enter the roll number to search: ");
    scanf("%d", &roll);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].roll_no == roll) {
            printf("Student details:\n");
            printf("Roll number: %d\n", students[i].roll_no);
            printf("Name: %s\n", students[i].name);
            printf("Marks in three subjects: %.2f %.2f %.2f\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
            printf("Percentage: %.2f\n", students[i].percentage);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

// Function to modify a student's details by roll number
void modifyStudent() {
    int roll;
    printf("Enter the roll number to modify: ");
    scanf("%d", &roll);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].roll_no == roll) {
            printf("Enter the new details of student %d:\n", roll);
            printf("Name: ");
            scanf("%s", students[i].name);
            printf("Marks in three subjects: ");
            scanf("%f%f%f", &students[i].marks[0], &students[i].marks[1], &students[i].marks[2]);
            students[i].percentage = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3.0;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    } else {
        printf("Student details modified successfully.\n");
    }
}

// Function to display all student details
void displayAllStudents() {
    printf("Details of all students:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll number: %d\n", students[i].roll_no);
        printf("Name: %s\n", students[i].name);
        printf("Marks in three subjects: %.2f %.2f %.2f\n", students[i].marks[0], students);
    }}