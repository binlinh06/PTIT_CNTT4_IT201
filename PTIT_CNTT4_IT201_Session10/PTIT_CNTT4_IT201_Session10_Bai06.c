#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int length(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void findMiddle(Node* head) {
    int len = length(head);
    int midIndex = len / 2;

    Node* current = head;
    for (int i = 0; i < midIndex; i++) {
        current = current->next;
    }

    printf("Node %d: %d\n", midIndex + 1, current->data);
}

int main() {
    Node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);
    // head->next->next->next->next->next = createNode(6); // bật dòng này để thử với danh sách chẵn

    printList(head);
    findMiddle(head);

    return 0;
}
