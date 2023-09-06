#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertNode(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at the beginning.\n");
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position to insert.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", position);
}

void deleteNode(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted from the beginning.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position to delete.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", position);
}

int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void reversePrint(struct Node* current) {
    if (current == NULL) {
        return;
    }
    reversePrint(current->next);
    printf("%d ", current->data);
}

void reverseList() {
    struct Node *prev = NULL, *current = head, *nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
    printf("Linked list reversed.\n");
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\nLinked List Menu\n");
        printf("1. Insert node\n");
        printf("2. Delete node\n");
        printf("3. Count nodes\n");
        printf("4. Reverse print\n");
        printf("5. Reverse list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &value, &position);
                insertNode(value, position);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNode(position);
                break;
            case 3:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 4:
                printf("Reverse print: ");
                reversePrint(head);
                printf("\n");
                break;
            case 5:
                reverseList();
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
