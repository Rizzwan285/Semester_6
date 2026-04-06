#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
void insertEnd(struct Node **head, int value);
void display(struct Node *head);
void removeDuplicates(struct Node *head);


void insertEnd(struct Node **head, int value) {

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        //display(*head);
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    //display(*head);
}

void display(struct Node *head) {

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void removeDuplicates(struct Node *head) {

    struct Node *current = head;
    while (current != NULL && current->next != NULL) {

        if (current->data == current->next->data) {
            struct Node *dup = current->next;
            current->next = dup->next;
            free(dup);
        }
        else {
            current = current->next;
        }
    }
}

int main() {

    struct Node *head = NULL;
    int n, value;

    // printf("Enter number of elements: ");
    scanf("%d", &n);

    // printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);   // Insert each value entered by the user
    }

    //printf("Original List: ");
    display(head);

    removeDuplicates(head);

    // printf("\nList after removing duplicates: ");
    display(head);

    return 0;
}