#include <stdio.h>
#include <string.h>

int main(void)
{
    char inputString[100];
    int leftIndex = 0;
    int rightIndex;
    int isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", inputString);

    rightIndex = strlen(inputString) - 1;

    while (leftIndex < rightIndex)
    {
        if (inputString[leftIndex] != inputString[rightIndex])
        {
            isPalindrome = 0;
            break;
        }

        leftIndex++;
        rightIndex--;
    }

    if (isPalindrome)
        printf("String is a palindrome\n");
    else
        printf("String is not a palindrome\n");

    return 0;
}