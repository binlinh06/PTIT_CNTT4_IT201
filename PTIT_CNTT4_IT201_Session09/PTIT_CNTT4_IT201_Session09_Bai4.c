#include <stdio.h>
#include <stdlib.h>

// Cau truc Node cua danh sach lien ket don
struct Node {
    int data;
    struct Node* next;
};

// Ham tao Node moi
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

// Ham dem so luong phan tu trong danh sach
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    // Tao danh sach: 1->2->3->4->5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // In danh sach
    printList(head);

    // Dem va in so luong node
    int soLuong = countNodes(head);
    printf("Danh sach lien ket co %d phan tu\n", soLuong);

    return 0;
}
