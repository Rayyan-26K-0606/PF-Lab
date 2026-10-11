#include <stdio.h>

int main() {
    int DOOR = 1 << 0;   
    int ALARM = 1 << 1;  
    int CCTV = 1 << 2;   
    int MOTION = 1 << 3; 
    
    int status = 0; 
    int operation, device, mode;
    
    printf("--- Smart Home Security Controller ---\n");
    printf("Select Operation:\n");
    printf("1. Activate a device\n2. Deactivate a device\n3. Check a device status\n4. Toggle a device\n5. Enter Security Mode\n");
    printf("Choice: ");
    scanf("%d", &operation);
    
    switch (operation) {
        case 1:
        case 2:
        case 3:
        case 4:
            printf("\nSelect Device:\n1. Door Lock\n2. Alarm System\n3. CCTV Camera\n4. Motion Sensor\nChoice: ");
            scanf("%d", &device);
            
            int selected_flag = 0;
            switch (device) {
                case 1: selected_flag = DOOR; break;
                case 2: selected_flag = ALARM; break;
                case 3: selected_flag = CCTV; break;
                case 4: selected_flag = MOTION; break;
                default: printf("Invalid device.\n"); return 1;
            }
            
            switch (operation) {
                case 1:
                    status = status | selected_flag;
                    printf("Device activated.\n");
                    break;
                case 2: 
                    status = status & ~selected_flag;
                    printf("Device deactivated.\n");
                    break;
                case 3: 
                    (status & selected_flag) ? printf("Device is currently ACTIVE.\n") : printf("Device is currently INACTIVE.\n");
                    break;
                case 4: 
                    status = status ^ selected_flag;
                    printf("Device toggled.\n");
                    break;
            }
            break;
            
        case 5:
            printf("\nSelect Security Mode:\n1. Home Mode\n2. Away Mode\n3. Night Mode\nChoice: ");
            scanf("%d", &mode);
            switch (mode) {
                case 1:
                    status = DOOR | CCTV; 
                    printf("Home Mode engaged.\n");
                    break;

                case 2:
                    status = DOOR | ALARM | CCTV | MOTION; 
                    printf("Away Mode engaged.\n");
                    break;

                case 3:
                    status = DOOR | ALARM | MOTION | (status & CCTV); 
                    printf("Night Mode engaged.\n");
                    break;
                    
                default:
                    printf("Invalid mode.\n");
                    return 1;
            }
            break;
            
        default:
            printf("Invalid operation.\n");
            return 1;
    }
    
    printf("\n--- System Status ---\n");
    printf("Door Lock: %s\n", (status & DOOR) ? "Active" : "Inactive");
    printf("Alarm: %s\n", (status & ALARM) ? "Active" : "Inactive");
    printf("CCTV: %s\n", (status & CCTV) ? "Active" : "Inactive");
    printf("Motion Sensor: %s\n", (status & MOTION) ? "Active" : "Inactive");
    
    int isFullyArmed = (status == (DOOR | ALARM | CCTV | MOTION));
    printf("System Fully Armed: %s\n", isFullyArmed ? "YES" : "NO");
    
    return 0;
}