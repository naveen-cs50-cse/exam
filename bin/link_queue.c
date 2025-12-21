#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL, *temp;

void enqueue()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter node data \n");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}

void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("linked queue is empty \n");
    }
    else
    {
        temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        free(temp);
    }
}

void front_element()
{
    if (front == NULL && rear == NULL)
    {
        printf("linked queue is empty \n");
    }
    else
    {
        printf("front node data is: %d\n", front->data);
    }
}

void rear_element()
{
    if (front == NULL && rear == NULL)
    {
        printf("linked queue is empty\n");
    }
    else
    {
        printf("rear node data is: %d\n", rear->data);
    }
}

void display()
{
    if (front == NULL && rear == NULL)
    {
        printf("linked queue is empty \n");
    }
    else
    {
        temp = front;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        int choice;
        printf("*** Menu *** \n");
        printf("1. enqueue\n 2. dequeue\n 3. front-element\n 4. rear-element\n 5. display\n 6. exit\n");
        printf("enter choice \n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: front_element(); break;
            case 4: rear_element(); break;
            case 5: display(); break;
            case 6: exit(1);
            default: printf("invalid choice\n");
        }
    }
    return 0;
}