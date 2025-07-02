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

// Ham xoa node dau tien
struct Node* deleteHead(struct Node* head) {
    if (head == NULL) {
        printf("Danh sach rong, khong the xoa\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp); // Giai phong bo nho
    return head; // Tra ve head moi
}

int main() {
    // Tao danh sach ban dau: 1->2->3->4->5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // In danh sach truoc khi xoa
    printList(head);

    // Xoa phan tu dau tien
    head = deleteHead(head);

    // In danh sach sau khi xoa
    printList(head);

    return 0;
}
