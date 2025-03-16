#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp; // Declare a file pointer
    struct emp{ // Define a structure to store employee details
        char name[40];
        int age;
        float bs; // Basic salary
    } e; // Declare a variable of type struct emp

    char ch = 'Y'; // Variable to control the loop for entering multiple records

    fp = fopen("file1.txt", "w"); // Open the file "file1.txt" in write mode
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (ch == 'Y'){ // Loop to enter multiple records
        printf("Enter name, age and basic salary: ");
        scanf("%s %d %f", e.name, &e.age, &e.bs); // Read employee details from the user
        fprintf(fp, "%s %d %f\n", e.name, e.age, e.bs); // Write the details to the file
        printf("Another record (Y/N): ");
        ch = getchar(); // Read the next character to decide whether to continue
        ch = getchar(); // Read the next character to decide whether to continue
    }

    fclose(fp); // Close the file after writing

    fp = fopen("file1.txt", "r"); // Open the file "file1.txt" in read mode
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %d %f", e.name, &e.age, &e.bs) != EOF) // Read the details from the file
        printf("%s %d %f\n", e.name, e.age, e.bs); // Print the details

    fclose(fp); // Close the file after reading

    return 0;
}