#include <iostream>
#include <string>
using namespace std;

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

}

bst_node::bst_node(string s1, string s2, double n)
{
    
}

void bst_node::set_data(string s1, string s2, double n)
{

}

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

bst_node bst_tree::search(string tid)
{
    bst_node * p;
    p = root;
    if (root == NULL) 
    {// 해당 node 없음 처리 예
    bst_node tmp;
    tmp.set_data("00000000", "None", -1);
    cout << "The key " << tid << " does not exist.\n";return tmp;
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