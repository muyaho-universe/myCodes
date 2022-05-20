#include <iostream>
#include <string>
using namespace std;

int menu();

class bst_node 
{
public:
    string s_id;   // 학번
    string name;// 성명
    double  score;  // 점수
    bst_node * left, * right;
    bst_node();
    bst_node(string s1, string s2, double n);
    void set_data(string s1, string s2, double n);
};

bst_node::bst_node()
{
    score = 0;
}

bst_node::bst_node(string s1, string s2, double n)
{
    s_id = s1;
    name = s2;
    score = n;
}

void bst_node::set_data(string s1, string s2, double n)
{
    s_id = s1;
    name = s2;
    score = n;
}

void show_tree_inorder(bst_node* p);

class bst_tree
{
    bst_node * root;
    int csize;
public:
    bst_tree();
    void insert_node(bst_node t);
    bool empty();
    int size();
    void show_inorder();
    bst_node search(string s);  // s_record search(string s);   ...
};

bst_tree::bst_tree()
{
    root = NULL;
    csize = 0;
}

bst_node bst_tree::search(string tid)
{
    bst_node * p;
    p = root;
    if (root == NULL) 
    {// 해당 node 없음 처리 예
        bst_node tmp;
        tmp.set_data("00000000", "None", -1);
        cout << "The key " << tid << " does not exist.\n";
        return tmp;
    }

    while (1) 
    {
        if (p->s_id == tid)
            return (*p);
        if (p->s_id < tid) 
        {
            if (p->right == NULL) 
            {
                bst_node tmp;
                tmp.set_data("00000000", "None", -1);
                cout << "The key " << tid << " does not exist.\n";
                return tmp;
            }
            else
                p = p->right;
        }
        else 
        {
            if (p->left == NULL) 
            {
                bst_node tmp;
                tmp.set_data("00000000", "None", -1);
                cout << "The key " << tid << " does not exist.\n";
                return tmp;
            }
            else
                p = p->left;
        }
    }
}

void bst_tree::insert_node(bst_node t)
{
    bst_node* p;
    bst_node* tmp;
    
    tmp = new bst_node;
    *tmp = t;
    tmp->left = NULL;
    tmp->right = NULL;
    
    if (root == NULL) 
    {
        root = tmp;
        return;
    }
    
    p = root;
    
    while (1)
    {
        if (p->s_id == t.s_id)
        {
            cout << "Insertion Failed : the Key " << t.s_id << " already exists." << endl;
            return;
        }
        
        if (p->s_id < t.s_id) 
        {
            if (p->right == NULL) 
            {
                p->right = tmp;
                return;
            }
            else
                p = p->right;
        }
        
        else 
        {
            if (p->left == NULL) 
            {
                p->left = tmp;
                return;
            }
            else
                p = p->left;
        }
    }
}

bool bst_tree::empty()
{
    if(csize == 0) 
        return true;
    return false;
}

int bst_tree::size()
{
    return csize;
}
void bst_tree::show_inorder()
{
    if (root == NULL)
    {
        cout << "Nothing to print out!" << endl;
        return;
    }
    
    show_tree_inorder(root);
}

int main()
{
    bst_node temp;
    bst_tree t1;       
    temp.set_data("21900013", "Kim", 6.5);      
    t1.insert_node(temp);     
    temp.set_data("21900136", "Lee", 8.8);
    t1.insert_node(temp);
    temp.set_data("21900333", "Park", 9.2);
    t1.insert_node(temp);
    temp.set_data("21800442", "Choi", 7.1);
    t1.insert_node(temp);
    temp.set_data("21900375", "Ryu", 5.4);
    t1.insert_node(temp);
    temp.set_data("21700248", "Cho", 6.3);
    t1.insert_node(temp);
        cout << "\n\n Node List : inorder sequence \n";
    t1.show_inorder();
    string s_key = "21800442";
    temp = t1.search(s_key);

    cout << "\n -- " << s_key << "'s record ---" << endl;
    cout << " Student ID   : "<< temp.s_id << endl;
    cout << " Student Name : "<< temp.name << endl;
    cout << " Score        : " << temp.score << endl;

    return 0;
}

void show_tree_inorder(bst_node* p)
{
    if (p == NULL)
        return;
    show_tree_inorder(p->left);
    cout << p->s_id << " : " << p->name << " : " << p->score << endl;
    show_tree_inorder(p->right);
    
}

int menu()
{
    int m;
    cout<< "1. Add new element"<< endl;
    cout<< "2. Search an element"<< endl;
    cout<< "3. Show all the elements"<< endl;
    cout<< "0. Exit"<< endl;

    cout<< "input the menu number";
    cin >> m;

    return m;
}