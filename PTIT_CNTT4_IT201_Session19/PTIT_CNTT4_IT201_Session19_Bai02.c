#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
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
    printf("%d", root->data);
    preoderDFS(root->left);
    preoderDFS(root->right);
}
int main() {
    //Xay dung thuat toan nhi phan preorder
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    preoderDFS(root);
    return 0;
}