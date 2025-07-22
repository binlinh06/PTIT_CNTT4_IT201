
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
}
void inorderDFS(Node* root) {
    if (root == NULL) return;

    inorderDFS(root->left);
    printf("%d ", root->data);
    inorderDFS(root->right);
}
int main() {
    //Trien khai thuat toan nhi phan inoder
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;

    node1->left = node3;

    printf("Inorder:\n");
    inorderDFS(root);
    return 0;
}
