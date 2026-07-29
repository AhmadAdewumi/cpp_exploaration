#include <stdio.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0;
    int i = 0;

    // Get the string
    printf("Enter a word: ");
    scanf("%s", str); // Using scanf for a single word.

    // Loop until we hit the Null Terminator '\0'
    while (str[i] != '\0') {
        char ch = str[i];

        // Convert uppercase to lowercase using the ASCII math we discussed
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
        }

        // Check if it's a letter first
        if (ch >= 'a' && ch <= 'z') {
            // Check if it's a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                // If it's a letter but not a vowel, it must be a consonant
                consonants++;
            }
        }

        i++;
    }

    // Print the results
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
