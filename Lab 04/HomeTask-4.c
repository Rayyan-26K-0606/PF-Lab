#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    if (isalpha(ch))
    {
        char lower_ch = tolower(ch);

        switch (lower_ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("%c is a Vowel\n", ch);
            break;
        default:
            printf("%c is a Consonant\n", ch);
        }
    }
    else
    {
        printf("Error: Input is not a valid alphabet letter.\n");
    }

    return 0;
}