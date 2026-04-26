#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    
} Node;

void insert_at_end(Node** head, int value);
void display(Node *head);
void removeDuplicates(Node* head);

void insert_at_end(Node ** head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head==NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp=temp->next;
    }
    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void removeDuplicates(Node *head) {
    Node *current = head;
    while (current!=NULL && current->next !=NULL) {
        if (current->data == current->next->data) {
            Node* dup = current->next;
            current->next = dup->next;
            free(dup);
        }
        else {
            current = current->next;
        }
    }
}

int main() {
    Node *head = NULL;
    int n,value;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &value);
        insert_at_end(&head,value);
    }
    printf("Original List: ");
    display(head);
    removeDuplicates(head);
    printf("\nList after removing duplicates: ");
    display(head);

}
