#include <iostream>
#include <string>
using namespace std;

class node
{
    
public:
    string name;
    double score;
    void set_data(string n, double s);
    node *link;
    
};

bool is_equal(node *p1, node *p2);
bool equal_data(node t1, node t2);

void node::set_data(string n, double s)
{
    name = n;
    score = s;
}

class my_list
{
    node *head, *tail;
public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    double score_sum();
    double get_score(string t_name);
    int remove_a_node(string t_name);
    void invert();
    friend bool list_equal(my_list a, my_list b);
};

my_list::my_list()
{
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
    if (tail == NULL) // 이전 상태가 empty였다면, Tail도 첫 node로
    {
        tail = p;
    }
    
}

void my_list::add_to_tail(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if(tail != NULL)
        tail->link = p; // 이전 상태가 empty가 아니라면
    else
        head = p;       // 이전 상태가 empty였다면 head도 변경
    tail = p;  
}

node my_list::delete_from_head()
{
    node temp;
    node *t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if(head == NULL)
        tail = NULL;
    return temp;
}

int my_list::num_nodes()
{
    node *t;
    int count = 0;
    for (t = head; t != NULL; t=t->link)
        count++;
    return count;
}

bool my_list::list_empty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

double my_list::score_sum()
{
    node *t;
    double sum = 0;
    for (t = head; t != NULL; t=t->link)
        sum += t->score;
    return sum;
}

double my_list::get_score(string t_name)
{
    node *t;
    for (t = head; t != NULL; t=t->link)
    {
        if(t->name == t_name)
            return t->score;
    }
    return -1;
}

int my_list::remove_a_node(string t_name)
{
    node *t, *pre = head; // pre는 이전 node를 기억
    int go = 0;
    for (t = head; t != NULL; t=t->link)
    {
        if(t->name == t_name)
        {
            go = 1;
            if((pre == head)&& (t==head)) head = t->link;
            else  pre->link= t->link;           
            delete t;
            break;
        }
        pre = t;
    }
        
    return go;    
}

void my_list::invert()
{
    node *newhead = NULL, *oldhead, *tmp;
    oldhead = head;
    while (oldhead != NULL)
    {
        tmp = newhead;
        newhead = oldhead;
        oldhead = oldhead->link;
        newhead->link = tmp;
    }
    tail = head;
    head = newhead;
}

bool list_equal(my_list a, my_list b)
{
    return is_equal(a.head, b.head);
}

bool is_equal(node *p1, node *p2)
{
    if ((p1 == NULL) && (p2 == NULL))
        return true;
    if ((p1 == NULL) || (p2 == NULL))
        return false;
    if (equal_data(*p1, *p2))
    {
        return is_equal(p1->link, p2->link);
    }
    else
        return false;
}

bool equal_data(node t1, node t2)
{
    if(t1.name != t2.name)
        return false;
    if(t1.score != t2.score)
        return false;
    return true;
}

int main()
{
    my_list a,b;
    node tmp;

    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 85.1);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 85.1);
    b.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    b.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    b.add_to_head(tmp);
    tmp.set_data("Kim", 83.5);
    b.add_to_head(tmp);  
    // b.invert();
    if (list_equal(a, b) )
        cout << "Yes, the two lists are identical. \n";
    else
        cout << "No, They are not identical.\n";
    tmp = b.delete_from_head();
    cout << tmp.name << " : " << tmp.score << "\n";

    return 0;
}