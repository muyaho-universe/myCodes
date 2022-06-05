// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int front=-1;
int rear=-1;
char queue[MAX][20];
int count = 0;

int IsEmpty(){
    if(front==rear)//front와 rear가 같으면 큐는 비어있는 상태 
        return 1;
    else return 0;
}
int IsFull(){
    int tmp=(rear+1) % MAX; //원형 큐에서 rear+1을 MAX로 나눈 나머지값이
    if(tmp==front)//front와 같으면 큐는 가득차 있는 상태 
        return 1;
    else
        return 0;
}
void addq( char value[20]){
    if(IsFull())
        printf("Queue is Full.\n");
    else{
        rear = (rear+1)%MAX;
        strcpy(queue[rear], value);
    }
 
}

const char* deleteq(){
    if(IsEmpty())
        printf("Queue is Empty.\n");
    else{
        front = (front+1)%MAX;
        return queue[front];
    }
}

struct node {
    char item[20];
    struct node* left;
    struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%s ->", root->item);
    addq(root->item);
    inorderTraversal(root->right);
}

// preorderTraversal traversal
void preorderTraversal(struct node* root) {
    if (root == NULL) return;
    printf("%s ->", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// postorderTraversal traversal
void postorderTraversal(struct node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%s ->", root->item);
}

// Create a new Node
struct node* createNode(char value[20]) {
    struct node* newNode = malloc(sizeof(struct node));
    strcpy(newNode->item, value);
    newNode->left = NULL;
    newNode->right = NULL;
    count ++;
    return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, char value[20]) {
    root->left = createNode(value);
    return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, char value[20]) {
    root->right = createNode(value);
    return root->right;
}

// Create a new Node
struct node* createNode2(char value[20]) {
    struct node* newNode = malloc(sizeof(struct node));
    strcpy(newNode->item, value);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert on the left of the node
struct node* insertLeft2(struct node* root, char value[20] ) {
    root->left = createNode2(value);
    return root->left;
}

// Insert on the right of the node
struct node* insertRight2(struct node* root, char value[20]) {
    root->right = createNode2(value);
    return root->right;
}

void insert_node(char t[20], struct node* root) {    
    while (1)
    {
        if (strcmp(root->item,t) ==0)
        {
            printf("Insertion Failed : the Key %d already exists.\n" , t) ;
            return;
        }
        
        if (strcmp(root->item,t) < 0) 
        {
            if (root->right == NULL) 
            {
                insertRight2(root, t);
                return;
            }
            else
                root = root->right;
        }
        
        else 
        {
            if (root->left == NULL) 
            {
                insertLeft2(root, t);
                return;
            }
            else
                root = root->left;
        }
    }
}

struct node * min_value_node(struct node * root){
    struct node *current = root;
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}

struct node * delete_node(struct node * root, char value[20]){
    if(root == NULL) return root;
    if(strcmp(root->item, value) < 0){
        root -> right = delete_node(root->right, value);
    }
    if(strcmp(root->item, value) < 0){
        root -> left = delete_node(root->left, value);
    }
    else{
        if(root->left == NULL){
            struct node * temp = root ->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node * temp = root ->left;
            free(root);
            return temp;
        }
        struct node * temp = min_value_node(root->right);
        strcpy(root->item,temp->item);
        root->right = delete_node(root->right, temp->key)
    }
    return root;
}

int main() {
    struct node* root = createNode("korea");
    
    int q2arr[MAX];

    insertLeft(root, "data");
    insertRight(root, "Ahn");

    insertLeft(root->left, "quick");
    insertLeft(root->left->left, "bubble");
    
    insertRight(root->left, "sort");
    insertLeft(root->left->right, "algorithm");
    insertRight(root->left->right, "computer");
    insertRight(root->left->right->right, "recursive");
    insertRight(root->left->right->right, "hash0");
    insertLeft(root->left->right->right, "tree");
    insertLeft(root->left->right->right->left, "chain");
    insertLeft(root->left->right->right->left->left, "stack");
    insertRight(root->left->right->right->left->left, "queue");
    insertRight(root->right, "university");

    printf("Inorder traversal \n");
    inorderTraversal(root);

    printf("\nPreorder traversal \n");
    preorderTraversal(root);

    printf("\nPostorder traversal \n");
    postorderTraversal(root);

    for (int i = 0; i < count; i++){
        q2arr[i] = deleteq();
    }

    struct node* root2 = createNode2(q2arr[0]);
    for (int i = 1; i < count; i++){
        insert_node(q2arr[i], root2);
    }

    printf("\n-----------------BST-----------------\n");
    printf("Inorder traversal \n");
    inorderTraversal(root2);

    printf("\nPreorder traversal \n");
    preorderTraversal(root2);

    printf("\nPostorder traversal \n");
    postorderTraversal(root2);
    
}

