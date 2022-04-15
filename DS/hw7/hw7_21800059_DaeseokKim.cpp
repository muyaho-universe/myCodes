#include <iostream>
#include <string>
using namespace std;

#define Q_SIZE 100

class element
{
public:
    string s_title;
    int npages;
    int price;
    void set_data(string s, int page, int pr);  
};

class my_queue
{
    element queue_arr[Q_SIZE];
    int front, rear;
public:
    my_queue();
    void insert_q(element x);
    element delete_q();
    bool queue_full();
    bool empty();

};

my_queue::my_queue()
{
    front = 0;
    rear = 0;
}

void my_queue::insert_q(element x)
{
    if ( !queue_full()) 
    {
        queue_arr[rear] = x;
        rear = (rear+1) % Q_SIZE;
    }
    else
    {
        cout << "Queue is full!" << endl;
    }
}

element my_queue::delete_q()
{
    element tmp;
    if (!empty()) 
    {
        tmp = queue_arr[front];
        front = (front+1) % Q_SIZE;
        return (tmp);
    }
    else
    {
        return ("NULL", 0, 0);
    }
    
}

bool my_queue::queue_full()
{
    if ( (rear+1)%Q_SIZE == front )
        return true;
    else
        return false;
}

bool my_queue::empty( )
{
    if (rear == front )
        return true;
    else
        return false;
}



void element:: set_data(string s, int page, int pr)
{
    s_title = s;
    npages = page;
    price = pr; 
}

int main()
{
    my_queue  a;
    element  tmp;
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