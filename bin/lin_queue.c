#include<stdio.h>
#include<stdlib.h>

int queue[100];
int front = -1, rear = -1, size;

void enqueue(int ele) {
    if (rear == size - 1)
        printf("queue full");
    else {
        rear = rear + 1;
        queue[rear] = ele;
        if (front == -1)
            front = 0;
    }
}

void dequeue() {
    if (front == -1 && rear == -1)
        printf("Queue empty");
    else {
        printf("deleted ele is %d\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = front + 1;
    }
}

void display() {
    if (front == -1 && rear == -1)
        printf("queue empty");
    else {
        printf("queue elements are: \n");
        for (int i = front; i <= rear; i++) {
            printf("%d \t", queue[i]);
        }
        printf("\n");
    }
}

void rear_ele() {
    if (front == -1 && rear == -1)
        printf("queue empty");
    else
        printf("rear ele is %d\n", queue[rear]);
}

void front_ele() {
    if (front == -1 && rear == -1)
        printf("queue empty");
    else
        printf("front ele is %d \n", queue[front]);
}

void main() {
    int size;
    printf("enter size of queue: \n");
    scanf("%d", &size);
    while (1) {
        int choice, ele;
        printf("** MENU ** \n");
        printf("1. Enqueue\n 2. Dequeue\n 3. Display\n 4. front-ele\n 5. rear-ele\n 6. exit\n");
        printf("Enter choice");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("enter ele to insert: ");
                    scanf("%d", &ele);
                    enqueue(ele);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: front_ele();
                    break;
            case 5: rear_ele();
                    break;
            case 6: exit(1);
                    break;
            default: printf("Enter correct choice");
        }
    }
}