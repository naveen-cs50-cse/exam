#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL, *temp;


void push()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter node data \n");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    if (top == NULL)
    {
        top = ptr;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("linked stack is empty \n");
    }
    else
    {
        temp = top;
        top = top->next;
        free(temp);
    }
}


void peek()
{
    if (top == NULL)
    {
        printf("linked stack is empty\n");
    }
    else
    {
        printf("top element is %d \n", top->data);
    }
}


void display()
{
    if (top == NULL)
    {
        printf("linked stack is empty \n");
    }
    else
    {
        temp = top;
        while (temp != NULL)
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
        printf("1. push\n 2. pop\n 3. peek\n 4. display\n 5. exit\n");
        printf("enter choice \n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(1);
            default: printf("invalid choice\n");
        }
    }
    return 0;
}