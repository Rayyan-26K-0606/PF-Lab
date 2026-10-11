#include <stdio.h>

int main() {
    int category, flight_type, docs_valid, age;
    float weight, allowance = 0.0;

    printf("=== Airport Passenger Classification System ===\n");
    printf("Select Passenger Category (1: Adult, 2: Student, 3: Senior Citizen): ");
    scanf("%d", &category);

    printf("Select Destination Type (1: Domestic, 2: International): ");
    scanf("%d", &flight_type);

    printf("Enter baggage weight (in kg): ");
    scanf("%f", &weight);

    printf("Are travel documents valid? (1 for Yes, 0 for No): ");
    scanf("%d", &docs_valid);

    printf("Enter passenger's age: ");
    scanf("%d", &age);

    switch (category) {
        case 1: 
            switch (flight_type) {
                case 1: allowance = 20.0; break;
                case 2: allowance = 30.0; break;
                default: allowance = 0.0; break;
            }
            break;
        case 2:
            switch (flight_type) {
                case 1: allowance = 25.0; break;
                case 2: allowance = 35.0; break;
                default: allowance = 0.0; break;
            }
            break;
        case 3: 
            switch (flight_type) {
                case 1: allowance = 30.0; break;
                case 2: allowance = 40.0; break;
                default: allowance = 0.0; break;
            }
            break;
        default:
            allowance = 0.0;
            break;
    }

    int remainder = age % 5;
    char ver_category;
    switch (remainder) {
        case 0: ver_category = 'A'; break;
        case 1: ver_category = 'B'; break;
        case 2: ver_category = 'C'; break;
        case 3: ver_category = 'D'; break;
        case 4: ver_category = 'E'; break;
    }

    int priority = (category == 3 || (category == 2 && flight_type == 2)) ? 1 : 0;

    const char* decision = !docs_valid ? "Denied Boarding" : 
                           (weight <= allowance ? "Normal Boarding" : "Referred for Enhanced Baggage Screening");

    printf("\n=== Passenger Summary ===\n");
    printf("Category: %s\n", category == 1 ? "Adult" : (category == 2 ? "Student" : "Senior Citizen"));
    printf("Destination: %s\n", flight_type == 1 ? "Domestic" : "International");
    printf("Permitted Allowance: %.1f kg\n", allowance);
    printf("Actual Baggage Weight: %.1f kg\n", weight);
    printf("Document Status: %s\n", docs_valid ? "Valid" : "Invalid");
    printf("Verification Category: %c\n", ver_category);
    printf("Priority Assistance: %s\n", priority ? "Yes" : "No");
    printf("Final Boarding Decision: %s\n", decision);

    return 0;
} 

