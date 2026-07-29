#include <stdio.h>

int main() {

    char student_name[50][50];
    char matric_number[50][20];
    int i;
    int total_students = 50;

    /* Read names and matric numbers */
    for (i = 0; i < total_students; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]", student_name[i]);

        printf("Enter matric number: ");
        scanf(" %s", matric_number[i]);
    }

    /* Display the list */
    printf("\n\n========== STUDENT LIST ==========\n");
    printf("%-5s %-30s %-20s\n", "S/N", "Name", "Matric Number");
    printf("-------------------------------------------\n");

    for (i = 0; i < total_students; i++) {
        printf("%-5d %-30s %-20s\n", 
               i + 1, 
               student_name[i], 
               matric_number[i]);
    }

    return 0;
}