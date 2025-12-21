#include <stdio.h>
#include <stdlib.h>

int cqueue[100], size, front = -1, rear = -1;

void enqueue(int ele) {
    if (front == (rear + 1) % size) printf("queue is full");
    else {
        rear = (rear + 1) % size;
        cqueue[rear] = ele;
        if (front == -1) front = 0;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) printf("Queue empty");
    else {
        printf("deleted element is %d", cqueue[front]);
        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
    }
}

void display() {
    if (front == -1 && rear == -1) printf("queue empty");
    else if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d\t", cqueue[i]);
        }
        printf("\n");
    }
    else {
        printf("queue elements are: \n");
        for (int i = front; i < size; i++) printf("%d\t", cqueue[i]);
        for (int i = 0; i <= rear; i++) printf("%d\t", cqueue[i]);
        printf("\n");
    }
}

void main() {
    int size;
    printf("enter size of queue");
    scanf("%d", &size);
    while (1) {
        int choice, element;
        printf("\n** MENU **\n");
        printf("1. Enqueue\n 2. Dequeue\n 3. Display\n 4. front-ele\n 5. rear-ele\n 6. exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter element to insert: \n");
                    scanf("%d", &element);
                    enqueue(element);
                    break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 6: exit(1); break;
            default: printf("Enter valid choice \n");
        }
    }
}