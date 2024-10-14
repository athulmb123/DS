#include <stdio.h>

int stack[100];
int top = -1;

void push(int item) {
    if (top < 99) {
        stack[++top] = item;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return 0;  // Should handle underflow better in a production scenario
}

int isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

int evaluatePostfix(char* postfix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (ch == ' ') {
            continue;  // Skip spaces
        }

        if (isDigit(ch)) {
            int num = 0;
            // Parse the entire number
            while (isDigit(ch)) {
                num = num * 10 + (ch - '0');
                ch = postfix[++i];
            }
            push(num);
            i--;  // Adjust for the outer loop's increment
        } else {
            int b = pop();
            int a = pop();
            switch (ch) {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    push(a / b);
                    break;
            }
        }
    }
    return pop();  // Final result
}

int main() {
    char postfix[100];

    printf("Enter a postfix expression: ");
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        postfix[i++] = ch;
    }
    postfix[i] = '\0';

    int result = evaluatePostfix(postfix);
    
    // Output the result
    printf("Result: %d\n", result);

    return 0;
}

