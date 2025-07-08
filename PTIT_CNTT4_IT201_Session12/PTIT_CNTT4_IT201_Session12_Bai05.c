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

void printListNode(Node* head) {
    Node* temp = head;
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* removeAll(Node* head, int value) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            Node* toDelete = temp;

            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            temp = temp->next;
            free(toDelete);
        } else {
            temp = temp->next;
        }
    }

    return head;
}

int main() {
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(2);
    Node* node4 = createNode(2);
    Node* node5 = createNode(5);

    head->next = node2;
    node2->prev = head;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    printf("Danh sách ban đầu:\n");
    printListNode(head);

    int value;
    printf("\nNhập số nguyên cần xóa: ");
    scanf("%d", &value);

    head = removeAll(head, value);

    printf("\nDanh sách sau khi xóa tất cả phần tử có giá trị %d:\n", value);
    printListNode(head);

    return 0;
}
