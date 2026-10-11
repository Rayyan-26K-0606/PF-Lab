#include <stdio.h>

int main() {
    int access_code;
    int hour;
    int is_late_night;
    int entry_granted;

    while (1) {
        printf("\nEnter member access code (9999 to end shift): ");
        if (scanf("%d", &access_code) != 1 || access_code == 9999) {
            break;
        }

        printf("Enter current hour (0-23): ");
        scanf("%d", &hour);

        is_late_night = (hour >= 22 || hour < 6) ? 1 : 0;
        printf("Operating Mode: %s\n", is_late_night ? "LATE NIGHT MODE" : "STANDARD MODE");

        if (is_late_night) {
            entry_granted = (access_code & 8) ? 1 : 0; 
        } else {
            entry_granted = (access_code & (1 | 2 | 4)) ? 1 : 0; 
        }

        if (entry_granted) {
            printf("Access Decision: ENTRY GRANTED\n");
        } else {
            printf("Access Decision: ENTRY DENIED\n");
        }

        if (access_code & 4) {
            printf("Trainer Info: Member has Personal Trainer Access.\n");
        } else {
            printf("Trainer Info: Member does NOT have Personal Trainer Access.\n");
        }
    }

    printf("\nShift ended. Access gate system offline.\n");
    return 0;
}