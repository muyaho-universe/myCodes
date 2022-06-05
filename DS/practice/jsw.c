// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;

#define ESC 0x1b //ESC의 아스키 코드 값을 정의
#define MAX_QUEUE_SIZE 100
#define MAX_STRING_SIZE 256
#define MAX 100

typedef struct
{
  char body[MAX_QUEUE_SIZE][MAX_STRING_SIZE];
  int front;
  int rear;
  int length;
} QUEUE ;

QUEUE* Q_Create();
void Q_Free(QUEUE *queue);
void Q_Insert(QUEUE *queue, char value[20]);
char* Q_Delete(QUEUE *queue);
int Q_Length(QUEUE *queue);
void Q_PrintAll(QUEUE *queue);
void usage();
int Q_IsFull(QUEUE *queue);
int Q_IsEmpty(QUEUE *queue);

struct node {
    char item[20];
    struct node* left;
    struct node* right;
};


// Inorder traversal
void inorderTraversal(struct node* root, QUEUE* q) {
    if (root == NULL) return;
    inorderTraversal(root->left, q);
    printf("%s ->", root->item);
    Q_Insert(q,root->item);
    inorderTraversal(root->right, q);
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
        root->right = delete_node(root->right, temp->item);
    }
    return root;
}

int main() {
    struct node* root = createNode("korea");
    QUEUE* queue =  Q_Create();
    char q2arr[MAX][20];

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
    inorderTraversal(root, queue);

    printf("\nPreorder traversal \n");
    preorderTraversal(root);

    printf("\nPostorder traversal \n");
    postorderTraversal(root);

    for (int i = 0; i < count; i++){
        strcpy(q2arr[i], Q_Delete(queue));
    }

    struct node* root2 = createNode2(q2arr[0]);
    for (int i = 1; i < count; i++){
        insert_node(q2arr[i], root2);
    }

    printf("\n-----------------BST-----------------\n");
    printf("Inorder traversal \n");
    inorderTraversal(root2, queue);

    printf("\nPreorder traversal \n");
    preorderTraversal(root2);

    printf("\nPostorder traversal \n");
    postorderTraversal(root2);
    
}

QUEUE *Q_Create()
{
    /*
    생성된 QUEUE 구조체를 초기화 (front=0, rear=0, length=0)
    첫번째 인자 : QUEUE 구조체 포인터 변수
    리턴 값 : 큐 구조체 포인터
    */

    QUEUE *queue = (QUEUE *) malloc (sizeof(QUEUE)); // 동적 메모리 할당

    // 구조체 초기화
    queue->front = 0;
    queue->rear = 0;
    queue->length = 0;

    return queue;  // 주소 반환
}

void Q_Free(QUEUE *queue)
{
    /*  메모리에 동적으로 생성된 QUEUE 구조체를 삭제
    첫번째 인자 : QUEUE 구조체 포인터 변수 */
    
    /*프로그램의 내용이 배열인 관계로
    큐 구조체 생성시에만 동적 메모리 할당을 했으므로
    그 부분만 해제 한다.*/
    
    free(queue);
}
void Q_Insert(QUEUE *queue, char value[20])
{
    /*
    큐의 Body에 아이템을 추가하는 함수.(Length 증가)
    Q_IsFull() 함수를 통해 먼저 큐의 모든 공간이 꽉 차있는지 검사
    gets()  함수를 통해 사용자로부터 문자열을 입력 받아 큐에 저장한다.

    큐의 rear를 1증가하여 최초 배열의 1번 인덱스 위치에 값을 저장한다.
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE
    %연산을 통해 큐의 index값을 0~MAX_QUEUE_SIZE-1 범위 내로 한정한다.
    이로 인해 rear가 MAX_QUEUE_SIZE-1, 즉 배열의 마지막 인덱스까지 값을 채웠을 경우
    아직 큐의 size가 MAX_QUEUE_SIZE보다 작다면 그 다음 다시 0번 index로 값을 채우기 시작한다.

    첫 번째 인자 : QUEUE 구조체 포인터 변수
    */
    
    if(Q_IsFull(queue) == 0)  //꽉차 있지 않으면 즉, 조금이라도 비어 있으면
    {
       

        (queue->rear) = (queue->rear+1) % MAX_QUEUE_SIZE;
        //인덱스 값을 증가 시킨다.
        strcpy(queue->body[queue->rear],value);
        (queue->length)++;
        //데이터가 하나 증가 했으므로 길이값을 1올린다.
        
    }

    else // 꽉 차있으면.
    {printf("Circular_Queue space is FULL !!! \n");}
 
}

char* Q_Delete(QUEUE *queue)
{ /*
 큐의 front 인덱스가 가르키는 아이템(문자열)을 반환하는 함수.(Length 감소)
 Q_IsEmpty() 함수를 통해 먼저 큐의 모든 공간이 비어 있는지 검사
 front 인덱스 값을 증가시켜 최초 큐의 1번째 인덱스의 값을 참조 할 수 있도록 한다.
 q->front = (q->front+1) % MAX_QUEUE_SIZE;

 그 다음 strcpy() 함수를 통해 아이템(문자열)을 복사한다.
 char * strcpy(char *, const char *);  - string.h 해더추가
 앞 문자열의 처음에 뒤 문자열을 복사하여 그 복사된 문자열을 반환한다.
 앞 문자열은 수정되지만 뒤 문자열은 수정될 수 없다.
 첫 번째 인자 : QUEUE 구조체 포인터 변수
 리턴 값 : 큐의 front가 가르키고 있던 아이템(문자열)
 */
    char save_string[20];
    if(Q_IsEmpty(queue) == 0) // 조금이라도 차 있으면
    {
        (queue->front) = (queue->front+1) % MAX_QUEUE_SIZE;
        //front의 인덱스 값을 변경 시킨다.
        
        strcpy( save_string,  queue->body[queue->front] );
        // 어떤 값이 제거가 되었는지 출력하기 위해 복사. 후에 리턴 값
        
        (queue->length)--; //데이터가 제거가 되었으므로 길이 값과 포인터 값을 변경합니다.
        
        return save_string;
    }
}

int Q_Length(QUEUE *queue)
{ 
    return queue->length;
}

void Q_PrintAll(QUEUE *queue)
{ 
    int counter = 0;

    printf("<Front> ");
    if(Q_IsEmpty(queue) == 0)
    {
        counter = (queue->front+1) % MAX_QUEUE_SIZE ;
        /*인덱스 값을 맞추기 위해서 +1을 저정합니다.
        실제 프로그램 시작후 front 에는 쓰레기 값이 저장되어 있습니다.*/

        while( counter != (queue->rear + 1)%MAX_QUEUE_SIZE ) // front ~ rear 까지 출력
        { 
            printf(" \"%s\" ", queue->body[counter]);
            counter = (counter +1) % MAX_QUEUE_SIZE;
        }
    
    }
    printf(" <Rear>\n");
}


int Q_IsFull(QUEUE *queue)
{
    if(queue->front == (queue->rear+1) % MAX_QUEUE_SIZE)
    { return 1; }
    else
    { return 0; }
}

int Q_IsEmpty(QUEUE *queue)
{
    if(queue->front == queue->rear)
    {return 1; }
    else
    {return 0; }
}