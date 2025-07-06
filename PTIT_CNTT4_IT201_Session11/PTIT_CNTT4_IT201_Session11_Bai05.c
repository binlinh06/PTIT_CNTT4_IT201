#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d<->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insertAtHead(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    if (*headRef != NULL)
        (*headRef)->prev = newNode;
    *headRef = newNode;
}

int main() {
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* fourth = createNode(4);
    Node* fifth = createNode(5);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    printList(head);

    int x;
    scanf("%d", &x);

    insertAtHead(&head, x);
    printList(head);

    return 0;
}
