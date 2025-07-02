#include <stdio.h>
#include <stdlib.h>

// Cau truc Node
struct Node {
    int data;
    struct Node* next;
};

// Ham tao node moi
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

// Ham in danh sach
void printList(struct Node* head) {
    struct Node* current = head;
    printf("Danh sach lien ket: ");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Ham them phan tu vao dau danh sach
struct Node* insertAtHead(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode; // tra ve node moi la head moi
}

int main() {
    // Tao danh sach ban dau: 1->2->3->4->5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // In danh sach ban dau
    printList(head);

    // Nhan gia tri tu nguoi dung
    int x;
    printf("Nhap so nguyen duong can them vao dau: ");
    scanf("%d", &x);

    // Them vao dau danh sach
    head = insertAtHead(head, x);

    // In danh sach sau khi them
    printList(head);

    return 0;
}
