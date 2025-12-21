#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *temp, *prev;


void insert_begin() {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter node data \n");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        ptr->next = head;
        head = ptr;
    }
}


void insert_end() {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter node data \n");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}


void insert_pos() {
    int pos;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter node data \n");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    printf("enter position to insert node \n");
    scanf("%d", &pos);
    if (pos == 1) {
        ptr->next = head;
        head = ptr;
    } else {
        temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("invalid position it cannot be inserted\n");
            return;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}


void del_begin() {
    if (head == NULL) {
        printf("SLL is empty\n");
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
}


void del_end() {
    if (head == NULL) {
        printf("SLL is empty \n");
    } else {
        temp = head;
        if (head->next == NULL) {
            head = NULL;
            free(temp);
        } else {
            while (temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            free(temp);
        }
    }
}

void delete_pos() {
    int pos;
    printf("enter a position to delete \n");
    scanf("%d", &pos);
    if (head == NULL) {
        printf("SLL is empty \n");
    } else {
        temp = head;
        if (pos == 1) {
            head = head->next;
            free(temp);
        } else {
            for (int i = 1; i < pos && temp != NULL; i++) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL) {
                printf("invalid position \n");
                return;
            }
            prev->next = temp->next;
            free(temp);
        }
    }
}


void Search() {
    int se, found = 0;
    struct node *temp = head;
    printf("enter search element \n");
    scanf("%d", &se);
    for (int i = 1; temp != NULL; i++) {
        if (temp->data == se) {
            printf("search element is at position %d\n", i);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (found == 0) {
        printf("search element is not found \n");
    }
}

void reverse() {
    struct node *curnode, *prevnode, *nextnode;
    if (head == NULL) {
        printf("SLL is empty \n");
    } else {
        prevnode = NULL;
        curnode = head;
        while (curnode != NULL) {
            nextnode = curnode->next;
            curnode->next = prevnode;
            prevnode = curnode;
            curnode = nextnode;
        }
        head = prevnode;
    }
}


void display() {
    if (head == NULL) {
        printf("SLL is empty \n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("*** Menu *** \n");
        printf("1. Insert-begin\n 2. Insert-end\n 3. Insert-pos\n 4. delete-begin\n 5. delete_end\n 6. delete-pos\n 7. Search\n 8. reverse\n 9. display\n 10. exit \n");
        printf("enter choice\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_pos(); break;
            case 4: del_begin(); break;
            case 5: del_end(); break;
            case 6: delete_pos(); break;
            case 7: Search(); break;
            case 8:reverse();
            break;
            case 9: display();
            break;
            case 10:exit(1);
        }
    }
}