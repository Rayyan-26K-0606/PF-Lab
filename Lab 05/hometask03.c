#include <stdio.h>

int main() {
    int prod_choice, cust_choice, order_no;
    float order_amt, distance;
    float discount_rate = 0.0;
    
    printf("Select Product Category:\n1. Electronics\n2. Clothing\n3. Books\n4. Household\nChoice: ");
    scanf("%d", &prod_choice);
    
    printf("Select Customer Category:\n1. Regular\n2. Premium\n3. Corporate\nChoice: ");
    scanf("%d", &cust_choice);
    
    printf("Enter Order Amount (Rs): ");
    scanf("%f", &order_amt);
    printf("Enter Delivery Distance (km): ");
    scanf("%f", &distance);
    printf("Enter Order Number: ");
    scanf("%d", &order_no);
    
    if (order_amt < 0 || distance < 0 || order_no < 0) {
        printf("\nError: Invalid input. Order amount, distance, and order number cannot be negative.\n");
        return 1;
    }
    
    char* prod_name = "";
    char* cust_name = "";
    
    switch (prod_choice) {
        case 1:
            prod_name = "Electronics";
            switch(cust_choice) {
                case 1: cust_name = "Regular"; discount_rate = 0.05; break;
                case 2: cust_name = "Premium"; discount_rate = 0.10; break;
                case 3: cust_name = "Corporate"; discount_rate = 0.15; break;
                default: printf("Invalid Customer Category.\n"); return 1;
            }
            break;
        case 2:
            prod_name = "Clothing";
            switch(cust_choice) {
                case 1: cust_name = "Regular"; discount_rate = 0.10; break;
                case 2: cust_name = "Premium"; discount_rate = 0.15; break;
                case 3: cust_name = "Corporate"; discount_rate = 0.20; break;
                default: printf("Invalid Customer Category.\n"); return 1;
            }
            break;
        case 3:
            prod_name = "Books";
            switch(cust_choice) {
                case 1: cust_name = "Regular"; discount_rate = 0.08; break;
                case 2: cust_name = "Premium"; discount_rate = 0.12; break;
                case 3: cust_name = "Corporate"; discount_rate = 0.18; break;
                default: printf("Invalid Customer Category.\n"); return 1;
            }
            break;
        case 4:
            prod_name = "Household";
            switch(cust_choice) {
                case 1: cust_name = "Regular"; discount_rate = 0.07; break;
                case 2: cust_name = "Premium"; discount_rate = 0.14; break;
                case 3: cust_name = "Corporate"; discount_rate = 0.20; break;
                default: printf("Invalid Customer Category.\n"); return 1;
            }
            break;
        default:
            printf("Invalid Product Category.\n");
            return 1;
    }
    
    float discount_amt = order_amt * discount_rate;
    float final_payable = order_amt - discount_amt;
    
    int free_shipping = (final_payable >= 5000) || (cust_choice == 2) || (cust_choice == 3);
    
    float delivery_charge = free_shipping ? 0.0 : (distance * 10.0); 
    
    int is_priority = ((cust_choice == 2) || (cust_choice == 3)) && (order_amt >= 10000);
    float priority_charge = is_priority ? 500.0 : 0.0;
    
    float total_amount = final_payable + delivery_charge + priority_charge;
    
    int group_mod = order_no % 4;
    char group = (group_mod == 0) ? 'A' : (group_mod == 1) ? 'B' : (group_mod == 2) ? 'C' : 'D';
    
    printf("\n--- E-Commerce Order Receipt ---\n");
    printf("Product Category: %s\n", prod_name);
    printf("Customer Category: %s\n", cust_name);
    printf("Original Amount: Rs %.2f\n", order_amt);
    printf("Discount (%.0f%%): -Rs %.2f\n", discount_rate * 100, discount_amt);
    printf("Final Payable (after discount): Rs %.2f\n", final_payable);
    
    printf("\nDelivery Distance: %.1f km\n", distance);
    printf("Shipping Status: %s\n", free_shipping ? "Free Shipping" : "Standard Paid Shipping");
    printf("Delivery Charge: Rs %.2f\n", delivery_charge);
    
    printf("Priority Delivery: %s\n", is_priority ? "Yes (+Rs 500)" : "No");
    printf("Priority Charge: Rs %.2f\n", priority_charge);
    
    printf("\nProcessing Group: %c\n", group);
    printf("Total Amount Payable: Rs %.2f\n", total_amount);
    
    return 0;
}