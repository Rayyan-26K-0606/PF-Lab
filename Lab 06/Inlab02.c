#include <stdio.h>

int main() {
    int value;
    int option;

    while (1) {
        printf("\nEnter resident's combined appliance value (-1 to end shift): ");
        if (scanf("%d", &value) != 1 || value == -1) {
            break;
        }

        printf("Menu Options:\n");
        printf("1. Switch Water Heater ON\n");
        printf("2. Switch Air Conditioner OFF\n");
        printf("3. Toggle Main Lights\n");
        printf("4. Report Security Camera Status\n");
        printf("Choose option (1-4): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                value |= 2; 
                printf("Water Heater has been switched ON.\n");
                break;
            case 2:
                value &= ~4; 
                printf("Air Conditioner has been switched OFF.\n");
                break;
            case 3:
                value ^= 1; 
                printf("Main Lights state toggled.\n");
                break;
            case 4:
                if (value & 8) { 
                    printf("Security Camera: ACTIVE (ON)\n");
                } else {
                    printf("Security Camera: INACTIVE (OFF)\n");
                }
                break;
            default:
                printf("Invalid option selected.\n");
                break;
        }

        printf("Updated combined appliance value: %d\n", value);

        if ((value & 2) && (value & 4)) {
            printf("WARNING: OVERLOAD RISK - Air Conditioner and Water Heater are both switched ON!\n");
        }
    }

    printf("\nShift completed. Smart Utility Panel shutting down.\n");
    return 0;
}