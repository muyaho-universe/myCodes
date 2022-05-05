#include <iostream>
using namespace std;

#define SIZE 5

class mystack
{
    int my_stack[SIZE];
    int top;
public:
    void init();
    void push(int num);
    int pop();
    bool stack_empty();
    bool stack_full();
};

void mystack::init()
{
    top = 0;
}

void mystack::push(int num)
{
    if(stack_full())
        printf("Stack is full\n");
    else
    {
        my_stack[top] = num;
        top++;
    }
}

int mystack::pop()
{
    if(stack_empty()) return NULL;
    top--;
    return(my_stack[top]);
}

bool mystack::stack_empty()
{
    if(top == 0) return true;
    return false;
}

bool mystack::stack_full()
{
    if(top == SIZE) return true;
    return false;
}

int main()
{
    mystack s1;

    int list[5] = { 32, 123, 27, 131, 242 }, i, x;

    s1.init();

    for (i = 0; i < 5; i++ )
        if (list[i]> 100)
            s1.push(list[i]);

    while (!s1.stack_empty())
    {
        x = s1.pop( );
        cout << x << endl; 
    }

    return 0;
}

