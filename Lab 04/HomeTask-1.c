#include <stdio.h>

int main()
{
    float weight, height, bmi;

    printf("Enter weight (kg): ");
    scanf("%f", &weight);
    printf("Enter height (m): ");
    scanf("%f", &height);

    printf("BMI = %.2f -> Category: ", bmi = weight / (height * height));

    if (bmi < 18.5)
    {
        printf("Underweight\n");
    }
    else if (bmi <= 24.9)
    {
        printf("Normal\n");
    }
    else if (bmi <= 29.9)
    {
        printf("Overweight\n");
    }
    else
    {
        printf("Obese\n");
    }

    return 0;
}