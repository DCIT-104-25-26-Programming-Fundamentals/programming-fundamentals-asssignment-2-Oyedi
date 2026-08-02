// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function Prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
bool divide(double a, double b, double &result);
bool modulus(int a, int b, int &result);
double power(double base, double exp);
void displayMenu();

// Function 1: Addition
double add(double a, double b) {
    return a + b;
}

// Function 2: Subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function 3: Multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function 4: Division (Returns false if division by zero occurs)
bool divide(double a, double b, double &result) {
    if (b == 0) {
        return false;
    }
    result = a / b;
    return true;
}

// Function 5: Modulus (Returns false if division/modulus by zero occurs)
bool modulus(int a, int b, int &result) {
    if (b == 0) {
        return false;
    }
    result = a % b;
    return true;
}

// Function 6: Exponentiation using pow() from <cmath>
double power(double base, double exp) {
    return pow(base, exp);
}

// Function to display the calculator menu interface
void displayMenu() {
    cout << "\n============================\n";
    cout << "     SIMPLE CALCULATOR\n";
    cout << "============================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
    cout << "Select an operation (1-7): ";
}

int main() {
    int choice = 0;

    while (choice != 7) {
        displayMenu();
        cin >> choice;

        // Input validation for menu choices (e.g. non-numeric input)
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 7.\n";
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Invalid choice! Please select an operation between 1 and 7.\n";
            continue;
        }

        // Operation execution
        if (choice >= 1 && choice <= 4 || choice == 6) {
            double num1, num2;
            cout << "Enter first number : ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            cout << fixed << setprecision(2);

            switch (choice) {
                case 1:
                    cout << "Result: " << num1 << " + " << num2 << " = " << add(num1, num2) << "\n";
                    break;
                case 2:
                    cout << "Result: " << num1 << " - " << num2 << " = " << subtract(num1, num2) << "\n";
                    break;
                case 3:
                    cout << "Result: " << num1 << " * " << num2 << " = " << multiply(num1, num2) << "\n";
                    break;
                case 4: {
                    double result;
                    if (divide(num1, num2, result)) {
                        cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
                    } else {
                        cout << "Error: Cannot divide by zero.\n";
                    }
                    break;
                }
                case 6:
                    cout << "Result: " << num1 << " ^ " << num2 << " = " << power(num1, num2) << "\n";
                    break;
            }
        } else if (choice == 5) {
            // Modulus operation uses integer types
            int num1, num2, result;
            cout << "Enter first integer : ";
            cin >> num1;
            cout << "Enter second integer: ";
            cin >> num2;

            if (modulus(num1, num2, result)) {
                cout << "Result: " << num1 << " % " << num2 << " = " << result << "\n";
            } else {
                cout << "Error: Cannot divide/modulus by zero.\n";
            }
        }
    }

    return 0;
}
// =============================================================================

