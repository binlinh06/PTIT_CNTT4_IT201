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

// Ham tim kiem gia tri trong danh sach
int search(struct Node* head, int target) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return 1; // Tim thay
        }
        current = current->next;
    }
    return 0; // Khong tim thay
}

int main() {
    // Tao danh sach: 1->2->3->4->5->NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // In danh sach
    printList(head);

    // Nhan gia tri can tim tu nguoi dung
    int x;
    printf("Nhap so nguyen duong can tim: ");
    scanf("%d", &x);

    // Tim kiem va in ket qua
    if (search(head, x)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
