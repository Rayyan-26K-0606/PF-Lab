#include <stdio.h>

int main()
{
    int s1, s2, s3;

    printf("Enter three side lengths: ");
    scanf("%d %d %d", &s1, &s2, &s3);

    if ((s1 + s2 > s3) && (s1 + s3 > s2) && (s2 + s3 > s1))
    {
        printf("Valid triangle -> Type: ");

        if (s1 == s2 && s2 == s3)
        {
            printf("Equilateral\n");
        }
        else if (s1 == s2 || s2 == s3 || s1 == s3)
        {
            printf("Isosceles\n");
        }
        else
        {
            printf("Scalene\n");
        }
    }
    else
    {
        printf("Invalid triangle. The given sides cannot form a triangle.\n");
    }

    return 0;
}