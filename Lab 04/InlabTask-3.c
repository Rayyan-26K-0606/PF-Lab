#include <stdio.h>
int main()
{
	int marks;
	printf("Enter your marks: ");
	scanf("%d", &marks);
	if (marks < 0 || marks > 100)
	{

		if (marks >= 85)
			printf("A Grade");

		else if (marks >= 70 && marks < 85)
			printf("B Grade");

		else if (marks >= 60 && marks < 69)
			printf("C Grade");

		else
			printf("F Grade");
	}
	else
		printf("Enter valid marks!");
}