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

// Ham xoa node tai vi tri bat ky
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("Danh sach rong, khong the xoa\n");
        return NULL;
    }

    if (position < 0) {
        printf("Vi tri khong hop le\n");
        return head;
    }

    // Xoa node dau
    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    int index = 0;

    // Duyet den node dung truoc node can xoa
    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    // Neu vi tri vuot qua do dai danh sach
    if (current == NULL || current->next == NULL) {
        printf("Vi tri khong ton tai trong danh sach\n");
        return head;
    }

    // Xoa node tai vi tri
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);

    return head;
}

int main() {
    // Tao danh sach: 1->2->3->4->5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // In danh sach ban dau
    printList(head);

    // Nguoi dung nhap vi tri can xoa
    int pos;
    printf("Nhap vi tri can xoa (bat dau tu 0): ");
    scanf("%d", &pos);

    // Xoa tai vi tri
    head = deleteAtPosition(head, pos);

    // In danh sach sau khi xoa
    printList(head);

    return 0;
}
