#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string input;
size_t index = 0;

// Function prototypes
double E();  // Expression
double E_prime(double left);
double T();  // Term
double T_prime(double left);
double F();  // Factor
bool match(char c);
void skipSpaces();

// Parse and evaluate expressions
double E() { // E -> T E'
    double left = T();
    return E_prime(left);
}

double E_prime(double left) { // E' -> * T E' | / T E' | ε
    skipSpaces();
    if (match('*')) {
        double right = T();
        return E_prime(left * right);
    }
    if (match('/')) {
        double right = T();
        if (right == 0) {
            cout << "Error: Division by zero!\n";
            exit(1);
        }
        return E_prime(left / right);
    }
    return left; // Return accumulated result
}

double T() { // T -> F T'
    double left = F();
    return T_prime(left);
}

double T_prime(double left) { // T' -> + F T' | - F T' | ε
    skipSpaces();
    if (match('+')) {
        double right = F();
        return T_prime(left + right);
    }
    if (match('-')) {
        double right = F();
        return T_prime(left - right);
    }
    return left; // Return accumulated result
}

double F() { // F -> ( E ) | NUMBER
    skipSpaces();
    if (match('(')) {  // If '(' is found, process subexpression
        double value = E();
        if (!match(')')) {
            cout << "Error: Missing closing parenthesis!\n";
            exit(1);
        }
        return value;
    }

    // Parse numbers
    if (isdigit(input[index])) {
        double num = 0;
        while (isdigit(input[index])) {  // Parse digits
            num = num * 10 + (input[index] - '0');
            index++;
        }

        // Handle decimal numbers
        if (input[index] == '.') {
            index++;
            double decimalPart = 0.1;
            while (isdigit(input[index])) {
                num += (input[index] - '0') * decimalPart;
                decimalPart /= 10;
                index++;
            }
        }

        return num;
    }

    cout << "Error: Invalid character in expression!\n";
    exit(1);
}

// Match function to compare the current character with the expected one
bool match(char c) {
    if (index < input.length() && input[index] == c) {
        index++;
        return true;
    }
    return false;
}

void skipSpaces() {
    while (index < input.length() && isspace(input[index])) {
        index++;
    }
}

int main() {
    cout << "Enter an arithmetic expression: ";
    getline(cin, input);

    index = 0;
    skipSpaces();

    double result = E();  

    if (index == input.length()) {
        cout << "Result: " << result << endl;
    } else {
        cout << "Error: Invalid expression!\n";
    }

    return 0;
}
