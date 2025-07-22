#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findMax(Node* root) {
    if (root == NULL) return -1000000;

    int maxLeft = findMax(root->left);
    int maxRight = findMax(root->right);

    int max = root->data;
    if (maxLeft > max) max = maxLeft;
    if (maxRight > max) max = maxRight;

    return max;
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int maxValue = findMax(root);
    printf("Gia tri lon nhat trong cay: %d\n", maxValue);  // Kết quả: 5

    return 0;
}
