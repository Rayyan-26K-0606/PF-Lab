#include <stdio.h>
int main()
{
	int num1;
	printf("Enter first number : ");
	scanf("%d", &num1);

	int num2;
	printf("Enter second number: ");
	scanf("%d", &num2);

	int num3;
	printf("Enter third number: ");
	scanf("%d", &num3);

	if (num1 > num2 && num1 > num3)
		printf("1st is greater");
	else if (num2 > num3)
		printf("2nd is greater");
	else
		printf("3rd is greater");
}