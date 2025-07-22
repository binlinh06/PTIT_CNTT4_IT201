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

int findLevel(Node* root, int value, int level) {
    if (root == NULL) return 0;

    if (root->data == value)
        return level;

    int leftLevel = findLevel(root->left, value, level + 1);
    if (leftLevel != 0) return leftLevel;

    return findLevel(root->right, value, level + 1);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int value = 5;
    int level = findLevel(root, value, 1);
    if (level)
        printf("Gia tri %d nam o tang %d\n", value, level);
    else
        printf("Khong tim thay gia tri %d trong cay\n", value);

    return 0;
}
