#include <stdio.h>

int main()
{
    int balance, amount;

    printf("Enter balance: ");
    scanf("%d", &balance);
    printf("Enter withdrawal amount: ");
    scanf("%d", &amount);

    if (amount % 500 != 0)
    {
        printf("Withdrawal failed: Amount must be a multiple of 500.\n");
    }
    else if (amount > 25000)
    {
        printf("Withdrawal failed: Amount exceeds the daily limit of 25,000.\n");
    }
    else if (amount > balance)
    {
        printf("Withdrawal failed: Insufficient balance.\n");
    }
    else
    {
        balance -= amount;
        printf("Withdrawal successful. Remaining balance: %d\n", balance);
    }

    return 0;
}