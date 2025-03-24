/*****************************************
 * Postfix Expression Evaluator
 * This program evaluates mathematical expressions written in postfix notation (Reverse Polish Notation).
 * It uses a stack to perform operations on operands
 *   
 * Author: Kiet Phan
 * Version: 03/23/2025
******************************************/

// main.cpp
#include <iostream>
#include <string>
#include <sstream>
#include "Stack.h"

using namespace std;

// Check if a token is an operator
bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// Check if a token is an operand (a number)
bool isOperand(const string& token) {
    istringstream iss(token);
    double value;
    iss >> value;
    // Returns true if successfully converted to a number
    return !iss.fail() && iss.eof();
}

// Calculate operations based on the operator
double calOperation(double operand1, double operand2, const string& operand) {
    if (operand == "+")
        return operand1 + operand2;
    if (operand == "-")
        return operand1 - operand2;
    if (operand == "*")
        return operand1 * operand2;
    if (operand == "/") {
        if (operand2 == 0) {
            cout << "Error: Division by zero" << endl; // Handle division by zero
            return 0;
        }
        return operand1 / operand2;
    }
    return 0; // Return 0 for invalid operators
}

// Function to evaluate a postfix expression
bool evaluatePostfix(const string& expression, double& result) {
    Stack stack;
    istringstream iss(expression);
    string token;

    // Read each token in the expression
    while(iss >> token) {
        if (isOperand(token)) {
            // Convert string to double and push onto the stack
            stack.push(stod(token));
        }
        else if (isOperator(token)) {
            if(stack.size() < 2) { // Ensure there are at least two operands
                return false;
            }
            
            // Peek and pop to get the result
            double operand2 = stack.peek();
            stack.pop();
            double operand1 = stack.peek();
            stack.pop();
            double operandResult = calOperation(operand1, operand2, token);
            stack.push(operandResult); // Push result back to stack
        }
        else {
            return false;
        }
    }
    // After evaluation, there should be exactly one result
    if (stack.size() != 1) {
        return false;
    }

    result = stack.peek(); // Store the final result
    return true;
}

// Main function to read the input and evaluate postfix expressions
int main() {
    string expression;
    double result;
    // Get number into postfix
    cout << "Enter a postfix expression: ";
    getline(cin, expression);

    // Get the result
    if (evaluatePostfix(expression, result)) {
        cout << "Result is: " << result << endl;
    } else {    // Invalid expression when typing incorrect
        cout << "Invalid expression - missing an operator" << endl;
    }

    return 0;
}