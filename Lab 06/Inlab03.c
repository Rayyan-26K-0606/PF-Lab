#include <stdio.h>

int main() {
    int totalStudents;
    int sub1, sub2, sub3;
    float average;
    int scaledValue;
    char grade;
    int i; 
    
    printf("=========================================\n");
    printf("    SUNDALE SCHOOL REPORT GENERATOR     \n");
    printf("=========================================\n");

    printf("Enter the total number of students in the class: ");
    scanf("%d", &totalStudents);

    for (i = 1; i <= totalStudents; i++) {
        printf("\n-----------------------------------------");
        printf("\nProcessing Student #%d", i);
        printf("\n-----------------------------------------\n");

        printf("Enter marks for Subject 1 (0-100): ");
        scanf("%d", &sub1);
        printf("Enter marks for Subject 2 (0-100): ");
        scanf("%d", &sub2);
        printf("Enter marks for Subject 3 (0-100): ");
        scanf("%d", &sub3);

        average = (sub1 + sub2 + sub3) / 3.0;
        scaledValue = (int)(average + 0.5) / 10; 

        switch (scaledValue) {
            case 10:
            case 9:
                grade = 'A';
                break;
            case 8:
                grade = 'B';
                break;
            case 7:
                grade = 'C';
                break;
            case 6:
                grade = 'D';
                break;
            default:
                grade = 'F';
                break;
        }

        const char* status = (average >= 59.95 && sub1 >= 40 && sub2 >= 40 && sub3 >= 40) ? "PASS" : "FAIL";

        printf("\n=========== STUDENT #%d REPORT ===========", i);
        printf("\nAverage Score:      %.2f", average);
        printf("\nAssigned Grade:     %c", grade);
        printf("\nFinal Status:       %s", status);
        printf("\n=========================================\n");
    }

    printf("\nAll %d student reports have been successfully generated!\n", totalStudents);
    return 0;
}