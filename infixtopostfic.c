#include <stdio.h>
#include <string.h>

#define STACK_SIZE 100

typedef struct {
    char items[STACK_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == STACK_SIZE - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (ch == ' ') {
            continue;
        }

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);
        } else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0;

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

