#include <stdio.h>
int main()
{
	int num1;
	char opr;
	printf("Enter 1st number: ");
	scanf("%d", &num1);

	int num2;
	printf("Enter 2nd number: ");
	scanf("%d", &num2);

	printf("Enter the operator: ");
	scanf(" %c", &opr);

	switch (opr)
	{
	case '+':
		printf("%d", num1 + num2);
		break;

	case '-':
		printf("%d", num1 - num2);
		break;

	case '/':
		if (num2 != 0)
		{
			printf("%d", num1 / num2);
		}
		else
		{
			printf("Error: Division by zero");
		}
		break;

	case '*':
		printf("%d", num1 * num2);
		break;

	default:
		printf("invalid");
	}
}