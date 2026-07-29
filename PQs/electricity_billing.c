#include <stdio.h>

int main() {

    int units_consumed;
    double total_charge;
    double meter_charge = 150.0;

    printf("Enter number of units consumed: ");
    scanf("%d", &units_consumed);

    /* Calculate charge based on units consumed */
    if (units_consumed <= 100) {

        total_charge = units_consumed * 150;

    } else if (units_consumed <= 300) {

        total_charge = (100 * 150) + 
                       ((units_consumed - 100) * 200);

    } else {

        total_charge = (100 * 150) + 
                       (200 * 200) + 
                       ((units_consumed - 300) * 255);
    }

    /* Add meter charge */
    total_charge = total_charge + meter_charge;

    printf("\nUnits Consumed  : %d\n", units_consumed);
    printf("Total Charge    : N%.2f\n", total_charge);

    return 0;
}