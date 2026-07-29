#include <stdio.h>

int main() {

    int how_many_terms;
    int first_term  = 1;
    int second_term = 1;
    int next_term;
    int i;

    printf("How many Fibonacci numbers do you want? ");
    scanf("%d", &how_many_terms);

    printf("\nFibonacci Series:\n");

    /* Handle first two terms specially */
    if (how_many_terms >= 1) {
        printf("%d ", first_term);
    }

    if (how_many_terms >= 2) {
        printf("%d ", second_term);
    }

    /* Calculate and print remaining terms */
    for (i = 3; i <= how_many_terms; i++) {

        next_term   = first_term + second_term;
        first_term  = second_term;
        second_term = next_term;

        printf("%d ", next_term);
    }

    printf("\n");

    return 0;
}