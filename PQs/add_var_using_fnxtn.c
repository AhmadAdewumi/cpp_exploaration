#include <stdio.h>

/* Function that modifies x based on its value */
int modify_value(int x) {

    if (x >= 10) {
        return x + 100;
    } else {
        return x - 50;
    }
}

int main() {

    int input_value;
    int result_value;

    printf("Enter value of x: ");
    scanf("%d", &input_value);

    result_value = modify_value(input_value);

    printf("\nOriginal value : %d\n", input_value);
    printf("Result value   : %d\n", result_value);

    return 0;
}