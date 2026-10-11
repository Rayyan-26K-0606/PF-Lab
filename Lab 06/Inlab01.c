#include <stdio.h>

int main() {
    int age = 0;
    int movie;
    int day;
    float total;
    
    printf("---------HELLO CUSTOMER---------- \n");
    
    do {
        printf("\nEnter your age (OR zero to shutdown): ");
        scanf("%d", &age);
        
        if (age == 0) {
            break; 
        }
        
        printf("Enter day of the month: ");
        scanf("%d", &day);
        
        if (day < 1 || day > 31) {
            printf("Invalid day! Skipping day calculations.\n");
            continue; 
        }
        
        printf("Select movie category:\n");
        printf("1. Regular movie(Rs. 500)\n");
        printf("2. 3D movie(Rs. 800) \n");
        printf("3. Premiere movie(Rs. 1200) \n");
        printf("Your choice: ");
        scanf("%d", &movie);
        
        switch(movie) {
            case 1:
                total = 500;
                break;
                
            case 2:
                total = 800;
                break;
                
            case 3:
                total = 1200;
                break;
                
            default:
                printf("Invalid selection!!! Resetting current transaction.\n");
                continue; 
        }
    
        if (age == 13) {
            total = total - (total * 0.30); 
        }
        else if (age < 13) {
            total = total - (total * 0.30); 
        }
        else if (age > 59) {
            total = total - (total * 0.20); 
        }
    
        if (day % 5 == 0) {
            total = total - 50;
        }
    
        if (total < 100) {
            total = 100;
        }
    
        printf("Final calculated price: Rs. %.2f\n", total);
        printf("--------------------------------- \n");

    } while (age != 0);
    
    printf("\nShutting down\n");
    return 0;
}