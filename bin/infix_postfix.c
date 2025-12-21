#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char a[100];
int top = -1;

void push(char ch) { 
    a[++top] = ch;
}

char pop() { 
    return a[top--];
}

int priority(char op) { 
    if (op == '^')
        return 3; 
    else if (op == '*' || op == '/')
        return 2; 
    else if (op == '+' || op == '-')
        return 1; 
    else 
        return 0;
}

void main() { 
    char infix[100], postfix[100], symbol;
    int j = 0, i;
    printf("enter infix exp ");
    scanf("%s", infix);
    
    for (i = 0; infix[i] != '\0'; i++) { 
        symbol = infix[i];
        if (symbol == '(')
            push('(');
        else if (isalnum(symbol))
            postfix[j++] = symbol;
        else if (symbol == ')') { 
            while (a[top] != '(')
                postfix[j++] = pop();
            pop(); 
        } 
        else { 
            while (top != -1 && priority(a[top]) >= priority(symbol)) { 
                if (a[top] == '(')
                    break; 
                postfix[j++] = pop();
            } 
            push(symbol);
        } 
    } 
    while (top != -1) { 
        postfix[j++] = pop();
    } 
    postfix[j] = '\0';
    printf("%s\n", postfix);
}