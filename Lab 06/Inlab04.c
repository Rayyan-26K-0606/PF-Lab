#include <stdio.h>

int main() {
    int total_containers;
    int i;
    int weight;
    int cargo_type;
    int can_load;
    int tracking_code;

    printf("Enter total number of containers to check today: ");
    scanf("%d", &total_containers);

    for (i = 1; i <= total_containers; i++) {
        can_load = 0;

        printf("\n--- Container %d of %d ---\n", i, total_containers);
        printf("Enter container weight (kg): ");
        scanf("%d", &weight);
        printf("Enter cargo type (1: General Goods, 2: Hazardous Materials, 3: Refrigerated Goods): ");
        scanf("%d", &cargo_type);

        switch (cargo_type) {
            case 1:
                if (weight <= 20000) {
                    can_load = 1;
                }
                break;
            case 2:
                if (weight <= 15000 && (i % 2 != 0)) {
                    can_load = 1;
                }
                break;
            case 3:
                if (weight <= 18000) {
                    can_load = 1;
                }
                break;
            default:
                printf("Invalid cargo type entered.\n");
                break;
        }

        if (can_load) {
            printf("Loading Decision: APPROVED\n");
        } else {
            printf("Loading Decision: REJECTED\n");
        }

        tracking_code = (weight % 97) % 100;
        printf("Tracking Code: %02d\n", tracking_code);
    }

    printf("\nAll containers for the day have been scanned.\n");
    return 0;
}