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

int main()
{
    my_list a;
    node tmp;

    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);           // head 위치로 2개의 원소 추가
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  // 1단계 점검
    tmp.set_data("Park", 91.3);   
    a.add_to_tail(tmp);             // tail 위치로 1개의 원소 추가
    cout << a.num_nodes() << " : " << a.score_sum() << "\n";  //2단계 점검
    tmp = a.delete_from_head();
    cout  << tmp.name << " is deleted.\n";   // 3단계 점검
    tmp.set_data("Choi", 85.1);   
    a.add_to_tail(tmp);              
    tmp.set_data("Ryu", 94.3);   
    a.add_to_head(tmp);             // 2개의 원소 추가

    cout << a.num_nodes()<< " : " << a.score_sum() << "\n";

    cout << "Park’s score: " << a.get_score("Park")<< "\n";  // 4단계 점검
    
    if ( a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list. \n";     // 5단계 점검

    cout << a.num_nodes()<< ":" << a.score_sum() << "\n";  // 최종 점검       

    return 0;
}