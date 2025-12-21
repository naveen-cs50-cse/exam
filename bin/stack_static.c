#include <stdio.h>
#include <stdlib.h>

int a[100], size, top = -1, choice;

void push(int ele)
 {
    if (top == size - 1) {
        printf("stack full\n");
    } else {
        a[++top] = ele;
    }
}

void pop() {
    if (top == -1) {
        printf("stack is empty\n");
    } else {
        printf("poped ele is %d", a[top]);
        top = top - 1;
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("stack is Empty\n");
    } else {
        for (i = top; i >= 0; i--) {
            printf("|__ %d __|\n", a[i]);
            printf("|       |\n");
        }
    }
}

void peek() {
    if (top == -1) {
        printf("stack Empty\n");
    } else {
        printf("top element is %d", a[top]);
    }
}

void main() {
    int ele, choice;
    printf("Enter size");
    scanf("%d", &size);
    
    while (1) {
        printf("~~ MENU ~~");
        printf("\n1-push\n2-pop\n3-peek\n4-display\n5-exit\n");
        
        printf("\n enter choice \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("enter element");
                scanf("%d", &ele);
                push(ele);
                break;

            case 2 :
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(1);
                break;

            default:
                printf("enter valid choice");
        }
    }
}