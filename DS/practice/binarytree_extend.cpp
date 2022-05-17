#include <iostream>
#include <string>
using namespace std;

class node {
public :
    string name;
    double score;
    node *left, *right;
    void set_data(string s, double n);
};

class stack_node
{
public:
    stack_node();
    node n;
    stack_node *link;
};

stack_node::stack_node()
{
    link = NULL;
}

class nstack
{
    stack_node *top;
public:
    nstack();
    void push(node* t);
    node* pop();
    bool stack_empty();
};

nstack::nstack()
{
    top = NULL;
}

void nstack::push(node* t)
{
    stack_node *p;
    p = new stack_node;
    (*p).n = *t;
    p->link = top;
    top = p;
}

node* nstack::pop()
{
    if(stack_empty())
    {
        node tmp;
        cout << "Stack is empty\n";
        return tmp;
    }
    node* temp;
    stack_node *t;
    t = top;
    
    temp = top->n;
    top = top->link;
    delete t;
    return temp;
}

bool nstack::stack_empty()
{
    if(top == NULL) 
        return true;
    return false;
}

class queue_node
{
public:
    node n;
    queue_node *link;  
};

class my_queue
{
    queue_node *front, *rear;
public:
    my_queue();
    void insert_q(node x);
    node delete_q();
    bool empty();

};

my_queue::my_queue()
{
    front = NULL;
    rear = NULL;
}

void my_queue::insert_q(node x)
{
    queue_node *p;
    p = new queue_node;
    (*p).n = x;
    p->link = NULL;
    if(!empty())
        rear->link = p; // 이전 상태가 empty가 아니라면
    else
        front = p;       // 이전 상태가 empty였다면 front도 변경
    rear = p;  
}

node my_queue::delete_q()
{
    node temp;
    queue_node *t;
    t = front;
    temp = (*front).n;
    front = t->link;
    delete t;
    if(front==NULL)
        rear = NULL;
    return temp;
}

bool my_queue::empty()
{
    if ((rear == NULL) &&(front == NULL))
        return true;
    return false;
}

int node_insert_left(node *p, string tname, node tnode); 
int node_insert_right(node *p, string tname, node tnode);
double sum_allnodes(node *p);
void inorder_print(node *p);
void preorder_print(node *p);
void postorder_print(node *p);

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

class my_tree {
public :
    int node_count; // 현재 node 수
    node *root; // root를 가리키는 pointer
    my_tree(); // 초기화
    int insert_root(node t); // root로 node내용 t추가
    int insert_left(string tname, node t); // tname의 node 왼쪽에 t 추가
    int insert_right(string tname, node t); // tname의 node 오른쪽에 t 추가
    double score_sum(); // 모든 node의 score 합
    double score_average(); // 모든 node의 core 평균
    void print_data_inorder(); // inorder 순서로 모든 node의 값 출력
    void print_data_preorder(); // preorder 순서로 모든 node의 값 출력
    void print_data_postorder(); // postorder 순서로 모든 node의 값 출력

    void nonrecursive_inorder();
    void print_data_levelorder();
};

my_tree::my_tree() // constructor : 초기 empty 상태 설정
{
    node_count = 0;
    root = NULL;
}

int my_tree::insert_root(node t)
{
    if (root != NULL)
        return 0;
    node *p;
    p = new node;
    (*p) = t;
    p->left = NULL;
    p->right = NULL;
    root = p;
    node_count++;
    return 1;
}

int my_tree::insert_left(string tname, node tnode)
{
    int result;
    result = node_insert_left(root, tname, tnode); // member 함수가 아님
    if (result == 1)
        node_count++;
    return result;
}

int my_tree::insert_right(string tname, node tnode)
{
    int result;
    result = node_insert_right(root, tname, tnode); // member 함수가 아님
    if (result == 1)
        node_count++;
    return result;
}

double my_tree:: score_sum()
{
    return sum_allnodes(root);
}

double my_tree:: score_average()
{
    return sum_allnodes(root) / node_count;
}

void my_tree::print_data_inorder()
{
    inorder_print(root);
}

void my_tree::print_data_preorder()
{
    preorder_print(root);
}

void my_tree::print_data_postorder()
{
    postorder_print(root);
}

void my_tree::nonrecursive_inorder()
{
    nstack s1;
    node *t;
    
    t = root;
    while (true)
    {
        while (t != NULL)
        {
            s1.push(t);
            t = t->left;
        }
        while (t == NULL)
        {
            if(s1.stack_empty())
                return;
            t = s1.pop();
        }
        cout << t->name << " : " << t->score << endl;
        t = t->right;        
    }
    
}

int node_insert_left(node *p, string tname, node tnode)
{
    if (p == NULL) return 0;
    if (p->name == tname)
    {
        if (p->left != NULL)
            return -1;
        node *t;
        t = new node;
        (*t) = tnode;
        t->left = NULL;
        t->right = NULL;
        p->left = t;
        return 1;
    }
    else 
    {
        int result = node_insert_left(p->left, tname, tnode);
        if (result != 0)
            return result;
        return node_insert_left(p->right, tname, tnode);
    }
}

int node_insert_right(node *p, string tname, node tnode)
{
    if (p == NULL) return 0;
    if (p->name == tname)
    {
        if (p->right != NULL)
            return -1;
        node *t;
        t = new node;
        (*t) = tnode;
        t->left = NULL;
        t->right = NULL;
        p->right = t;
        return 1;
    }
    else 
    {
        int result = node_insert_right(p->right, tname, tnode);
        if (result != 0)
            return result;
        return node_insert_right(p->left, tname, tnode);
    }
}

double sum_allnodes(node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}

void inorder_print(node *p)
{
    if (p == NULL) return;
    
    inorder_print(p->left);
    cout << p->name << ":" << p->score << endl;
    inorder_print(p->right);
}

void preorder_print(node *p)
{
    if (p == NULL) return;

    cout << p->name << ":" << p->score << endl;
    preorder_print(p->left);
    preorder_print(p->right);
}

void postorder_print(node *p)
{
    if (p == NULL) return;

    postorder_print(p->left);
    postorder_print(p->right);
    cout << p->name << ":" << p->score << endl;
}


int main()
{
    my_tree thetree;
    node tmp;

    tmp.set_data("Kim", 8.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 6.5);
    thetree.insert_left("Kim", tmp);
    tmp.set_data("Park", 8.3);
    thetree.insert_right("Kim", tmp);
    tmp.set_data("Choi", 7.2);
    thetree.insert_left("Lee", tmp);
    tmp.set_data("Ryu", 9.0);
    thetree.insert_right("Lee", tmp);
    tmp.set_data("Cho", 7.7);
    thetree.insert_right("Park", tmp);
    
    cout << "\nNon-recursive Inorder Result \n";
    thetree.nonrecursive_inorder();
    cout << "\nLevel-Order traversal Result \n";
    thetree.print_data_levelorder();
    
    my_tree tree2;
    copy_tree(tree2, thetree);
    cout << "\nThe inorder traversal Result of the new tree \n";
    tree2.print_data_inorder();
   
    if (equal_tree(tree2, thetree))
        cout << "Yes\n";
    else 
        cout << "No\n";
    tmp.set_data("Youn", 7.7);
    thetree.insert_right("Cho", tmp);
    
    if (equal_tree(tree2, thetree))
        cout << "Yes\n";
    else cout << "No\n";

    return 0;
}