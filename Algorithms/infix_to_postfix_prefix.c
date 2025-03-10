#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void strrev(char* str){
    int start = 0;
    int end= strlen(str) -1;
    char temp;
    while(start<end){
        temp = str[start];
        if(temp == '(')temp = ')';
        else if(temp == ')')temp = '(';
        
        if(str[end] == '(')str[end] = ')';
        else if(str[end] == ')')str[end] = '(';
        
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    if(start == end && str[start] == '(')str[start]  =')';
    else if(start == end && str[start] == ')')str[start]  ='(';
}


int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to return associativity of operators
char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}

// The main function to convert infix expression to postfix expression
void infixToPrefix(char s[]) {
    strrev(s);
    char result[MAX_SIZE];
    int resultIndex = 0;
    int len = strlen(s);
    char stack[MAX_SIZE];
    int stackIndex = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // If the scanned character is an operand, add it to the output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[resultIndex++] = c;
        }
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (c == '(') {
            stack[++stackIndex] = c;
        }
        // If the scanned character is an ‘)’, pop and add to the output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (stackIndex >= 0 && stack[stackIndex] != '(') {
                result[resultIndex++] = stack[stackIndex--];
            }
            stackIndex--; // Pop '('
        }
        // If an operator is scanned
        else {
            while (stackIndex >= 0 && (prec(s[i]) < prec(stack[stackIndex]) ||
                                       prec(s[i]) == prec(stack[stackIndex]) &&
                                           associativity(s[i]) == 'L')) {
                result[resultIndex++] = stack[stackIndex--];
            }
            stack[++stackIndex] = c;
        }
    }

    // Pop all the remaining elements from the stack
    while (stackIndex >= 0) {
        result[resultIndex++] = stack[stackIndex--];
    }

    result[resultIndex] = '\0';
    strrev(result);
    printf("%s\n", result);
}




// The main function to convert infix expression to postfix expression
void infixToPostfix(char s[]) {
    char result[MAX_SIZE];
    int resultIndex = 0;
    int len = strlen(s);
    char stack[MAX_SIZE];
    int stackIndex = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // If the scanned character is an operand, add it to the output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[resultIndex++] = c;
        }
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (c == '(') {
            stack[++stackIndex] = c;
        }
        // If the scanned character is an ‘)’, pop and add to the output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (stackIndex >= 0 && stack[stackIndex] != '(') {
                result[resultIndex++] = stack[stackIndex--];
            }
            stackIndex--; // Pop '('
        }
        // If an operator is scanned
        else {
            while (stackIndex >= 0 && (prec(s[i]) < prec(stack[stackIndex]) ||
                                       prec(s[i]) == prec(stack[stackIndex]) &&
                                           associativity(s[i]) == 'L')) {
                result[resultIndex++] = stack[stackIndex--];
            }
            stack[++stackIndex] = c;
        }
    }

    // Pop all the remaining elements from the stack
    while (stackIndex >= 0) {
        result[resultIndex++] = stack[stackIndex--];
    }

    result[resultIndex] = '\0';
    printf("%s\n", result);
}


int main(){
    char expression[MAX_SIZE];
    char prefix[MAX_SIZE];
    char infix[MAX_SIZE];
    fgets(infix, MAX_SIZE, stdin);
    
    infixToPostfix(infix);
    infixToPrefix(infix);
}




