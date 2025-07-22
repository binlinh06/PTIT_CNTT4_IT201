#include <stdio.h>
#include <stdlib.h>

// ==== STRUCT NODE ====
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// ==== CREATE NODE ====
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ==== DFS TRAVERSALS ====
// Preorder (NLR)
void preorderDFS(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderDFS(root->left);
    preorderDFS(root->right);
}

// Inorder (LNR)
void inorderDFS(Node* root) {
    if (root == NULL) return;
    inorderDFS(root->left);
    printf("%d ", root->data);
    inorderDFS(root->right);
}

// Postorder (LRN)
void postorderDFS(Node* root) {
    if (root == NULL) return;
    postorderDFS(root->left);
    postorderDFS(root->right);
    printf("%d ", root->data);
}

// ==== QUEUE (Tuyến tính, không size, không % capacity) ====
typedef struct Queue {
    Node **arr;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (Node**)malloc(sizeof(Node*) * capacity);
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

void enqueue(Queue* queue, Node* node) {
    if (queue->rear + 1 >= queue->capacity) {
        printf("Queue full!\n");
        return;
    }
    queue->arr[++queue->rear] = node;
}

Node* dequeue(Queue* queue) {
    if (isEmpty(queue)) return NULL;
    return queue->arr[queue->front++];
}

// ==== LEVEL ORDER (BFS) ====
void levelOrderBFS(Node* root) {
    if (root == NULL) return;
    Queue* queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        Node* node = dequeue(queue);
        printf("%d ", node->data);
        if (node->left != NULL) enqueue(queue, node->left);
        if (node->right != NULL) enqueue(queue, node->right);
    }

    free(queue->arr);
    free(queue);
}

// ==== MAIN ====
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

    printf("Preorder:\n");
    preorderDFS(root);
    printf("\n");

    printf("Inorder:\n");
    inorderDFS(root);
    printf("\n");

    printf("Postorder:\n");
    postorderDFS(root);
    printf("\n");

    printf("Level order:\n");
    levelOrderBFS(root);
    printf("\n");

    return 0;
}