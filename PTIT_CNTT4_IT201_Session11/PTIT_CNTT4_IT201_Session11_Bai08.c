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

void deleteAtPosition(Node** headRef, int position) {
    if (*headRef == NULL || position < 0) return;

    Node* current = *headRef;

    // Nếu là vị trí đầu
    if (position == 0) {
        *headRef = current->next;
        if (*headRef != NULL)
            (*headRef)->prev = NULL;
        free(current);
        return;
    }

    int index = 0;
    while (current != NULL && index < position) {
        current = current->next;
        index++;
    }

    // Nếu vị trí vượt quá danh sách
    if (current == NULL) return;

    if (current->prev != NULL)
        current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
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

    int pos;
    printf("Nhập vị trí cần xoá: ");
    scanf("%d", &pos);

    deleteAtPosition(&head, pos);

    printList(head);

    return 0;
}
