#include <stdio.h>

int main(void)
{
    char firstString[100];
    char secondString[100];
    int letterCount[26] = {0};
    int index = 0;

    printf("Enter first string: ");
    scanf("%s", firstString);

    printf("Enter second string: ");
    scanf("%s", secondString);

    // Count letters in first string
    while (firstString[index] != '\0')
    {
        char character = firstString[index];

        if (character >= 'a' && character <= 'z')
            letterCount[character - 'a']++;
        else if (character >= 'A' && character <= 'Z')
            letterCount[character - 'A']++;

        index++;
    }

    index = 0;

    // Subtract letters using second string
    while (secondString[index] != '\0')
    {
        char character = secondString[index];

        if (character >= 'a' && character <= 'z')
            letterCount[character - 'a']--;
        else if (character >= 'A' && character <= 'Z')
            letterCount[character - 'A']--;

        index++;
    }

    // Check if all counts are zero
    for (index = 0; index < 26; index++)
    {
        if (letterCount[index] != 0)
        {
            printf("Not an anagram\n");
            return 0;
        }
    }

    printf("Strings are anagrams\n");

    return 0;
}