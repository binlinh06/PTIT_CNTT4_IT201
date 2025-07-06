#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
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

void insertAtPosition(Node** headRef, int value, int position) {
    Node* newNode = createNode(value);

    // Thêm vào đầu danh sách
    if (position <= 0 || *headRef == NULL) {
        newNode->next = *headRef;
        if (*headRef != NULL)
            (*headRef)->prev = newNode;
        *headRef = newNode;
        return;
    }

    Node* current = *headRef;
    int index = 0;

    // Di chuyển đến node trước vị trí cần chèn
    while (current->next != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    // Chèn vào giữa hoặc cuối danh sách
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL)
        current->next->prev = newNode;

    current->next = newNode;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->prev = head->next->next->next;

    printList(head);

    int value, position;
    printf("value: ");
    scanf("%d", &value);
    printf("position: ");
    scanf("%d", &position);

    insertAtPosition(&head, value, position);

    printList(head);

    return 0;
}
