#include <stdio.h>
#include <ctype.h>
#include <math.h>

int a[100], top = -1;

void push(int num) {
    a[++top] = num;
}

int pop() {
    return a[top--];
}

void main() {
    char postfix[100];
    printf("enter postfix expression");
    scanf("%s", postfix);
    
    int i, num, num1, num2;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            num = postfix[i] - '0';
            push(num);
        }
        else {
            num2 = pop();
            num1 = pop();
            switch (postfix[i]) {
                case '+': push(num1 + num2); break;
                case '-': push(num1 - num2); break;
                case '*': push(num1 * num2); break;
                case '/': push(num1 / num2); break;
                case '^': push(pow(num1, num2)); break;
            }
        }
    }
    printf("postfix exp evaluation %d \n", a[top]);
}