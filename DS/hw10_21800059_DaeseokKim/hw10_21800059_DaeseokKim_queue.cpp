#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    string s_title;
    int npages;
    int price;
    void set_data(string s, int page, int pr);
    node *link;  
};

class my_queue
{
    node *front, *rear;
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
   node *p;
    p = new node;
    (*p) = x;
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
    node *t;
    t = front;
    temp = *front;
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

void node:: set_data(string s, int page, int pr)
{
    s_title = s;
    npages = page;
    price = pr; 
}

int main()
{
    my_queue  a;
    node  tmp;
    tmp.set_data("C++ Programming", 534, 35000);
    a.insert_q(tmp);
    tmp.set_data("Data Structure", 621, 42000);
    a.insert_q(tmp);
    tmp.set_data("JAVA Programming", 485, 38000);
    a.insert_q(tmp);
    tmp.set_data("Logic Design", 532, 44000);
    a.insert_q(tmp);

    while (!a.empty()) 
    {
        tmp = a.delete_q();
        cout << tmp.s_title << " : " << tmp.npages  << " : " << tmp.price << "\n";
    }
    return 0;

}