#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL, *temp, *temp1, *prevnode;


struct node* create() {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    printf("enter node data: ");
    scanf("%d", &nn->data);
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}


void insert_begin() {
    struct node *ptr = create();
    if (head == NULL) {
        head = ptr;
    } else {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
}

void insert_end() {
    struct node *ptr = create();
    if (head == NULL) {
        head = ptr;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
}


void insert_pos() {
    int pos;
    printf("enter position to insert node\n");
    scanf("%d", &pos);
    if (pos == 1) {
        insert_begin();
    } else {
        struct node *ptr = create();
        temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position, cannot insert\n");
            free(ptr);
            return;
        }
        ptr->next = temp->next;
        ptr->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = ptr;
        }
        temp->next = ptr;
    }
}


void delete_begin() {
    if (head == NULL) {
        printf("DLL is empty\n");
    } else {
        temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    }
}


void delete_end() {
    if (head == NULL) {
        printf("DLL is empty\n");
    } else {
        temp = head;
        if (head->next == NULL) {
            head = NULL;
            free(temp);
        } else {
            while (temp->next != NULL) {
                prevnode = temp;
                temp = temp->next;
            }
            prevnode->next = NULL;
            free(temp);
        }
    }
}


void delete_pos() {
    int pos;
    printf("enter position to delete: ");
    scanf("%d", &pos);
    if (head == NULL) {
        printf("DLL is empty\n");
    } else if (pos == 1) {
        delete_begin();
    } else {
        temp = head;
        for (int i = 1; i < pos && temp != NULL; i++) {
            prevnode = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position to delete\n");
            return;
        }
        if (temp->next == NULL) {
            prevnode->next = NULL;
        } else {
            prevnode->next = temp->next;
            temp->next->prev = prevnode;
        }
        free(temp);
    }
}


void forward_display() {
    if (head == NULL) {
        printf("DLL is empty\n");
    } else {
        temp = head;
        printf("DLL elements are: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


void backward_display() {
    if (head == NULL) {
        printf("DLL IS Empty\n");
    } else {
        temp = head;
        printf("DLL elements in reverse order are: ");
        while (temp->next != NULL) {
            temp = temp->next;
        }
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n*** Menu ***\n");
        printf("1. insert-begin\n2. forward-display\n3. exit\n4. insert_end\n5. insert-pos\n6. delete_begin\n7. delete_end\n8. delete_pos\n9. backward-display\n");
        printf("enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert_begin(); break;
            case 2: forward_display(); break;
            case 3: exit(1);
            case 4: insert_end(); break;
            case 5: insert_pos(); break;
            case 6: delete_begin(); break;
            case 7: delete_end(); break;
            case 8: delete_pos(); break;
            case 9: backward_display(); break;
            default: printf("invalid choice\n");
        }
    }
    return 0;
}