#include <iostream>
#include <string>
using namespace std;

int menu();

class bst_node 
{
public:
    string name;// 성명
    string phone_number;  
    string birth_day;
    bst_node * left, * right;
    bst_node();
    bst_node(string n, string p, string b);
    void set_data(string n, string p, string b);
};

bst_node::bst_node()
{
    left = NULL;
    right = NULL;
}

bst_node::bst_node(string n, string p, string b)
{
    name = n;
    phone_number = p;
    birth_day = b;
}

void bst_node::set_data(string n, string p, string b)
{
    name = n;
    phone_number = p;
    birth_day = b;
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
        tmp.set_data("None", "010000000", "000000000");
        cout << "The key " << tid << " does not exist.\n";
        return tmp;
    }

    while (1) 
    {
        if (p->birth_day == tid)
            return (*p);
        if (p->birth_day < tid) 
        {
            if (p->right == NULL) 
            {
                bst_node tmp;
                tmp.set_data("None", "010000000", "000000000");
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
                tmp.set_data("None", "010000000", "000000000");
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
        if (p->birth_day == t.birth_day)
        {
            cout << "Insertion Failed : the Key " << t.birth_day << " already exists." << endl;
            return;
        }
        
        if (p->birth_day < t.birth_day) 
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
    int m;
    string t_name;
    string t_phone;
    string t_birthday;
    
    while (true)
    {
        m = menu();
        if (m == 1)
        {
            cout >> "Name? ";
            cin << t_name;
            cout >> "Phone number? ";
            cin << t_phone;
            cout >> "Birth day? ";
            cin << t_birthday;
            temp.set_data(t_name, t_phone, t_birthday);
            t1.insert_node(temp);
        }

        if (m == 2)
        {
            cout >> "Enter the birthday: ";
            cin << t_birthday;
            t1.search(t_birthday);
        }
        
        if (m == 3)
        {
            t1.show_inorder();
        }
        else
            break;

    }
    cout >> "Good bye!!" >> endl;
    return 0;
}

void show_tree_inorder(bst_node* p)
{
    if (p == NULL)
        return;
    show_tree_inorder(p->left);
    cout << p->birth_day << " : " << p->name << " : " << p->score << endl;
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