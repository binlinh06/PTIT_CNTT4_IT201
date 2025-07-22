#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorderDFS(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderDFS(root->left);
    preorderDFS(root->right);
}

int main() {
    Node* root = NULL;
    root = createNode(5);

    printf("Duyệt cây theo preorder: ");
    preorderDFS(root);
    return 0;
}
