
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
int preoderDFS(Node* root, int value) {
    if (root == NULL) return 0;
    if (root->data == value) return 1;
    int fount = preoderDFS(root->left,value);
    if (fount) return 1;
    fount = preoderDFS(root->right,value);
    return fount;
}
int main() {
    //Tim kiem nhi phan
    Node* root = createNode(2);
    Node* node1 = createNode(3);
    Node* node2 = createNode(4);
    Node* node3 = createNode(5);

    root->left = node1;
    root->right = node2;

    node1->left = node3;

    int value;
    printf("Moi ban nhap so can tim: ");
    scanf("%d", &value);
    if (preoderDFS(root, value)) {
        printf("True");
    }else {
        printf("False");
    }
    return 0;
}
