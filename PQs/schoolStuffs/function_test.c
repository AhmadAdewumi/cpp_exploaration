#include <stdio.h>

int process_val(int x) {
  if (x >= 10) {
    return x + 100;
  } else{
      return x - 50;
  }
}

int main(void){
    int userInputValue;
    int adjustedResult;
    
    printf("Enter imput number (x): ");
    scanf("%d", &userInputValue);
    
    adjustedResult = process_val(userInputValue);
    
    printf("Adjusted value is: %d\n", adjustedResult);
    
    return 0;
}
