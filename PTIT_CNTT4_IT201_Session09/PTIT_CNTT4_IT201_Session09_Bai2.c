#include <stdio.h>
#include <stdlib.h>

// Cau truc phan tu (node) cua danh sach lien ket don
struct Node {
    int data;             // Du lieu la mot so nguyen
    struct Node* next;    // Con tro tro den phan tu tiep theo
};

// Ham tao node moi, truyen vao gia tri can luu
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Ham in danh sach theo dinh dang yeu cau
void printList(struct Node* head) {
    struct Node* current = head;
    int count = 1;

    // In theo dang: 1->2->3->4->5->NULL
    printf("Danh sach lien ket: ");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // In tung Node
    current = head;
    while (current != NULL) {
        printf("Node %d: %d\n", count, current->data);
        count++;
        current = current->next;
    }
}

int main() {
    // Tao cac node
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    // In toan bo danh sach
    printList(head);

    return 0;
}
