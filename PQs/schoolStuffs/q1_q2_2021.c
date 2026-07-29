#include <math.h>
#include <stdio.h>

int main(void) {
  double amountBorrowed;      //-- total amount borrowed
  double mortgageTermYears;   //-- how many years to repay
  double interestRatePercent; //-- yearly interest rate

  double
      interestRateDecimal; //-- interest rate converted from percent to decimal
  double compoundFactor;   //-- result of compound interest calculation
  double annualRepayment;  //-- final yearly repayment

  printf("Enter amount borrowed (Naira): ");
  scanf("%lf", &amountBorrowed);

  printf("Enter mortgage term (year): ");
  scanf("%lf", &mortgageTermYears);

  printf("Enter interest rate (percent): ");
  scanf("%lf", &interestRatePercent);

  interestRateDecimal = interestRatePercent / 100.0;
  compoundFactor =
      pow(1 + interestRateDecimal, mortgageTermYears); //-- computes (1+r)^n

  //-- mortgage repayment forumla
  annualRepayment = amountBorrowed * (interestRateDecimal * compoundFactor) /
                    (compoundFactor - 1);

  printf("Annual mortgage payment is: %.2lf\n", annualRepayment);
  
  return 0;
}
