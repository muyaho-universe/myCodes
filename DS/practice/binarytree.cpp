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
    cout<< "Score Sum : " << thetree.score_sum() << "\n";
    cout<< "Score Average : " << thetree.score_average() << "\n";
    cout <<"\n Inorder Traversal Result \n";
    thetree.print_data_inorder();
    cout << "\n Preorder Traversal Result \n";
    thetree.print_data_preorder();
    cout << "\n Postorder Traversal Result \n";
    thetree.print_data_postorder();
    return 0;
}