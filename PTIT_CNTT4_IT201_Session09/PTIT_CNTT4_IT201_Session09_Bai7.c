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

// Ham chen node tai vi tri bat ky (vi tri tinh tu 0)
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    if (position < 0) {
        printf("Vi tri khong hop le\n");
        return head;
    }

    // Neu chen vao dau
    if (position == 0) {
        struct Node* newNode = createNode(value);
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    int index = 0;

    // Duyet toi node dung truoc vi tri can chen
    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    // Neu vi tri vuot qua do dai danh sach
    if (current == NULL) {
        printf("Vi tri vuot qua do dai danh sach\n");
        return head;
    }

    struct Node* newNode = createNode(value);
    newNode->next = current->next;
    current->next = newNode;

    return head;
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

    // Nhap gia tri va vi tri can chen
    int value, position;
    printf("Nhap gia tri can chen: ");
    scanf("%d", &value);
    printf("Nhap vi tri can chen (bat dau tu 0): ");
    scanf("%d", &position);

    // Chen vao danh sach
    head = insertAtPosition(head, value, position);

    // In danh sach sau khi chen
    printList(head);

    return 0;
}
