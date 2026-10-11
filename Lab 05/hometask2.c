#include <stdio.h>

int main() {
    int dept_choice, theory, practical;
    float attendance;
    
    int req_theory = 0, req_practical = 0;
    float req_att = 0.0;
    
    printf("Select Department:\n1. Computer Science\n2. Electrical Engineering\n3. Business Administration\n4. Mathematics\nChoice: ");
    scanf("%d", &dept_choice);
    
    printf("Enter Theory Marks (out of 100): ");
    scanf("%d", &theory);
    printf("Enter Practical Marks (out of 100): ");
    scanf("%d", &practical);
    printf("Enter Attendance Percentage (0-100): ");
    scanf("%f", &attendance);
    
    if (attendance < 0.0 || attendance > 100.0) {
        printf("Error: Invalid input. Attendance must be between 0%% and 100%%.\n");
        return 1; 
    }
    if (theory < 0 || theory > 100 || practical < 0 || practical > 100) {
        printf("Error: Invalid input. Marks must be between 0 and 100.\n");
        return 1; 
    }
    
    char* dept_name;
    
    switch (dept_choice) {
        case 1:
            dept_name = "Computer Science";
            req_theory = 50; req_practical = 40; req_att = 75.0;
            break;
        case 2:
            dept_name = "Electrical Engineering";
            req_theory = 55; req_practical = 45; req_att = 75.0;
            break;
        case 3:
            dept_name = "Business Administration";
            req_theory = 50; req_practical = 35; req_att = 80.0;
            break;
        case 4:
            dept_name = "Mathematics";
            req_theory = 60; req_practical = 40; req_att = 75.0;
            break;
        default:
            printf("Error: Invalid department selected.\n");
            return 1;
    }
    
    int is_pass = (theory >= req_theory) && (practical >= req_practical) && (attendance >= req_att);
    int is_distinction = (theory >= 85) && (practical >= 80) && (attendance >= 90.0);
    
    int seat_cat = theory % 3;
    
    printf("\n--- Final Report ---\n");
    printf("Department: %s\n", dept_name);
    printf("Marks - Theory: %d | Practical: %d | Attendance: %.2f%%\n", theory, practical, attendance);
    printf("Requirements - Theory: >=%d | Practical: >=%d | Attendance: >=%.2f%%\n", req_theory, req_practical, req_att);
    
    printf("Result: %s\n", is_pass ? "Passed" : "Failed");
    printf("Distinction: %s\n", is_distinction ? "Eligible" : "Not Eligible");
    
    switch (seat_cat) {
        case 0: printf("Seat Category: A\n"); break;
        case 1: printf("Seat Category: B\n"); break;
        case 2: printf("Seat Category: C\n"); break;
    }
    
    return 0;
}