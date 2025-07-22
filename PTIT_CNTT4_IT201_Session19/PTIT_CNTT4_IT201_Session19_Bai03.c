
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
void postorderDFS(Node* root) {
    if (root == NULL) return;
    postorderDFS(root->left);
    postorderDFS(root->right);
    printf("%d ", root->data);
}
int main() {
    //Trien khai nhi phan postorder
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;

    node1->left = node3;

    printf("postorder: \n");
    postorderDFS(root);
    return 0;
}
