#include <stdio.h>
#include <stdlib.h>

// Cấu trúc phần tử (node) của danh sách liên kết đơn
struct Node {
    int data;             // Dữ liệu là một số nguyên
    struct Node* next;    // Con trỏ trỏ đến phần tử tiếp theo
};
// Hàm tạo node mới, truyền vào giá trị cần lưu
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
int main() {
    // Tạo các node
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    // In danh sách ra màn hình
    struct Node* current = head;
    printf("Danh sách liên kết: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
