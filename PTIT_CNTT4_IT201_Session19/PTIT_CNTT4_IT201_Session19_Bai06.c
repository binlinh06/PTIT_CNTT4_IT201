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
}
typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
}Queue;
//Tao ham cap phat bo nho dong
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (Node**)malloc(sizeof(Node*) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
//Tao ham check full
int isFull(Queue* queue) {
    if (queue->rear == queue->capacity - 1) return 1;
    return 0;
}
//tao ham check rong
int isEmpty(Queue* queue) {
    if (queue->front > queue->rear) return 1;
    return 0;
}
//Them vao Queue
void enqueue(Queue* queue, Node* node) {
    if (isFull(queue)) return;
    queue->arr[++queue->rear] = node;
}
//Lay ra
Node* dequeue(Queue* queue) {
    if (isEmpty(queue)) return NULL;
    return queue->arr[queue->front++];
}
//leverorder
void leveroderDFS(Node* root) {
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


    printf("leverorder: \n");
    leveroderDFS(root);
    return 0;
}