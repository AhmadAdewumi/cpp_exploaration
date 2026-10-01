#include "utility"
#include <iostream>

void selectionSort(int numbers[], int size){
    for(int i{0}; i < size-1; ++i){
        int minIndex = i;

        for(int j{i+1}; j < size; j++){
            if (numbers[j] < numbers[minIndex]) {
                minIndex=j;
            }
        }

         std::swap(numbers[i], numbers[minIndex]);
    }
}

int main(){
    int numbers[]{6, 3, 8, 2, 7, 1, 5, 4};

    selectionSort(numbers, 8);

    for (int num : numbers) {
        std::cout << num << ' ';
    }
    std::cout << "\n";
    return 0;
}