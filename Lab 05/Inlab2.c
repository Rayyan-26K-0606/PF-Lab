#include <stdio.h>

int main() {
    int dept, age, hr, conscious, severity;
    float temp;
    int dept_priority = 0;

    printf("=== Hospital Emergency Triage System ===\n");
    printf("Select Department (1: General, 2: Cardiology, 3: Neurology, 4: Trauma): ");
    scanf("%d", &dept);

    printf("Enter patient's age: ");
    scanf("%d", &age);

    printf("Enter heart rate (bpm): ");
    scanf("%d", &hr);

    printf("Enter body temperature (Celsius): ");
    scanf("%f", &temp);

    printf("Is the patient conscious? (1 for Yes, 0 for No): ");
    scanf("%d", &conscious);

    printf("Enter severity level (1 for Low, 2 for Medium, 3 for High): ");
    scanf("%d", &severity);

    switch (dept) {
        case 1: 
            switch (severity) {
                case 3: dept_priority = 1; break; 
                default: dept_priority = 0; break;
            }
            break;
            
        case 2: 
            switch ((hr > 100 || hr < 60) ? 1 : 0) {
                case 1: dept_priority = 1; break;
                case 0: dept_priority = 0; break;
            }
            break;
            
        case 3: 
            switch (conscious) {
                case 0: dept_priority = 1; break;
                case 1: dept_priority = 0; break;
            }
            break;
            
        case 4: 
            switch (severity) {
                case 3: dept_priority = 1; break;
                default: dept_priority = 0; break;
            }
            break;
            
        default:
            printf("Invalid Department selected.\n");
            break;
    }

    int critical = ((hr < 50 || hr > 120) && conscious == 0) ? 1 : 0;
    int temp_alert = (temp < 36.0 || temp > 38.0) ? 1 : 0;
    int senior = (age >= 65) ? 1 : 0;

    int case_rem = (age + hr) % 4;
    char case_cat;
    switch (case_rem) {
        case 0: case_cat = 'A'; break;
        case 1: case_cat = 'B'; break;
        case 2: case_cat = 'C'; break;
        case 3: case_cat = 'D'; break;
    }

    const char* triage_decision = critical ? "Immediate medical attention" :
                                 (dept_priority || senior || temp_alert ? "Priority assessment" : "Routine medical assessment");

    printf("\n=== Patient Triage Summary ===\n");
    printf("Department: ");
    switch (dept) {
        case 1: printf("General Emergency\n"); break;
        case 2: printf("Cardiology\n"); break;
        case 3: printf("Neurology\n"); break;
        case 4: printf("Trauma\n"); break;
        default: printf("Unknown\n"); break;
    }
    
    printf("Age: %d (Senior Status: %s)\n", age, senior ? "Yes" : "No");
    printf("Heart Rate: %d bpm\n", hr);
    printf("Body Temperature: %.1f C (Alert: %s)\n", temp, temp_alert ? "Yes" : "No");
    printf("Consciousness: %s\n", conscious ? "Conscious" : "Unconscious");
    printf("Critical Condition: %s\n", critical ? "Yes" : "No");
    printf("Case Category: %c\n", case_cat);
    printf("Final Triage Decision: %s\n", triage_decision);

    return 0;
}