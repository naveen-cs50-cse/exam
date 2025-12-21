#include <stdio.h>
#include <stdlib.h>

int *a, size, top = -1, i, choice;

void enhance() {
    size = 2 * size;
    a = realloc(a, size * sizeof(int));
}

void push(int ele) {
    if (top == size - 1)
        printf("stack full \n");
    else {
        a[++top] = ele;
    }
}

void pop() {
    if (top == -1)
        printf("stack empty \n");
    else {
        printf("popped element is %d", a[top]);
        top = top - 1;
    }
}

void display() {
    if (top == -1)
        printf("stack is empty");
    else { 
        for (i = top; i >= 0; i--) {
            printf("%d \n", a[i]);
            printf("\n");
        }
    }
}

void peek() {
    if (top == -1)
        printf("stack Empty \n");
    else {
        printf("top element is %d", a[top]);
    }
}

void main() {
    int ele, choice;
    printf("enter size");
    scanf("%d", &size);
    
    a = (int *) malloc(size * sizeof(int));
    printf("** MENU ** \n");
    printf("1. push \n 2. pop \n 3. peek \n 4. display \n 5. enhance \n 6. exit \n");
    
    while(1) {
        printf("\n enter choice \n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                printf("enter ele \n");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2: 
                pop();
                break;
            case 3: 
                peek();
                break;
            case 4: 
                display();
                break;
            case 5: 
                enhance();
                break;
            case 6: 
                exit(1);
                break;
            default: 
                printf("Enter valid choice");
        }
    }
}