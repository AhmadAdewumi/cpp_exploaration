#include <stdio.h>
#include <math.h>

int main() {

    double amount_borrowed;
    double interest_rate;
    double years;
    double annual_repayment;
    double rate_per_100;
    double rate_plus_one_to_power_n;

    /* Get inputs from user */
    printf("Enter amount borrowed (A): ");
    scanf("%lf", &amount_borrowed);

    printf("Enter interest rate in percent (r): ");
    scanf("%lf", &interest_rate);

    printf("Enter term of mortgage in years (n): ");
    scanf("%lf", &years);

    /* Calculate intermediate values */
    rate_per_100 = interest_rate / 100;
    rate_plus_one_to_power_n = pow(1 + rate_per_100, years);

    /* Apply the mortgage formula */
    annual_repayment = amount_borrowed * 
                       (rate_per_100 * rate_plus_one_to_power_n) / 
                       (rate_plus_one_to_power_n - 1);

    /* Display result */
    printf("\nAnnual Mortgage Repayment (R) = %.2f\n", annual_repayment);

    return 0;
}