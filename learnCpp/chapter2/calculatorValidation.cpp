//
// Created by ahmad on 6/10/26.
//
#include <iostream>

/**
 * Forward Declarations
 * @return
 */
int getNumber();

char getOperator();

int add(int a, int b);

int subtract(int a, int b);

int multiply(int a, int b);

double divide(int a, int b);

bool isValidDivision(int divisor);

void printResult(double result);

double calculate(int a, int b, char theOperator);

void printWelcomeMessage();
void printGoodbyeMessage();
bool shouldContinue();

int main() {
    printWelcomeMessage();

    bool running{true};
    while (running) {
        int num1{getNumber()};
        int num2{getNumber()};

        char op{getOperator()};

        if (op == '/' && !isValidDivision(num2)) {
            std::cout << "Cannot divide by zero \n";
            continue; //-- meaning exit with error code
        }

        double result = calculate(num1, num2, op);
        printResult(result);

        if (!shouldContinue()) {
            running = false;
        }
    }

    printGoodbyeMessage();

    return 0;
}

int getNumber() {
    std::cout << "Enter number: ";
    int num{};
    std::cin >> num;

    // std::cout << "Enter second number";
    // int num2{};
    // std::cin >> num2;

    return num;
}

char getOperator() {
    std::cout << "Enter operator: ";
    char operand{};
    std::cin >> operand;

    return operand;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    return static_cast<double>(a) / b;
}

bool isValidDivision(int divisor) {
    return divisor != 0;
}


void printResult(double result) {
    std::cout << "The result of the operation is: " << result << "\n";
}

void printWelcomeMessage() {
    std::cout << "Welcome to calculator \n";
}

void printGoodbyeMessage() {
    std::cout << "Goodbye!";
}

bool shouldContinue() {
    char input{};
    std::cout << "Do you want to continue (y/n) : ";

    std::cin >> input;

    if (input == 'y') {
        return true;
    }

    return false;
}

double calculate(int a, int b, char theOperator) {
    switch (theOperator) {
        case '+':
            return add(a, b);
        case '-':
            return subtract(a, b);
        case '*':
            return multiply(a, b);
        case '/':
            return divide(a, b);
        default:
            std::cout << "Unsupported Operation" << "\n";
            return 0;
    }
}
