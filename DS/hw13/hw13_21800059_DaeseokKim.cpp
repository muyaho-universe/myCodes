#include <iostream>
#include <string>
using namespace std;

class bst_node
{
public:
    string name;
    string s_id;
    double score;
    bst_node * left, * right;
};

class bst_tree
{
    bst_node * root;
    int csize;
public:
    bst_tree();
    void insert_node(bst_nodet);
    bool empty();
    int size();
    bst_node search(string s);  // s_record search(string s);   ...
};

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