
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preoderDFS(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preoderDFS(root->left);
    preoderDFS(root->right);
}

int main() {
    Node *root = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);
    Node* node5 = createNode(6);

    // Gắn các node vào cây
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;

    printf("Chua them\n");
    preoderDFS(root);
    int value;
    printf("\nMoi ban them phan tu moi");
    scanf("%d", &value);
    Node* node6 = createNode(value);
    node2->left = node6;
    printf("\nKet qua sau khi them\n");
    preoderDFS(root);
    return 0;
}
