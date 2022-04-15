#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

class operandstack
{
    char my_stack[SIZE];
    int top;
public:
    void init();
    void push(char c);
    int pop();
    bool stack_empty();
    bool stack_full();
    char top_element();
};

void operandstack::init()
{
    my_stack[0] = '$'; // EOS 지정
    top = 1;
}

void operandstack::push(char c)
{
    if(stack_full())
        printf("Stack is full\n");
    else
    {
        my_stack[top] = c;
        top++;
    }
}

int operandstack::pop()
{
    top--;
    return(my_stack[top]);
}

bool operandstack::stack_empty()
{
    if(top == 1) return true;
    return false;
}

bool operandstack::stack_full()
{
    if(top == SIZE) return true;
    return false;
}

char operandstack::top_element()
{
    return(my_stack[top-1]);
}

bool is_operand(char c)
{
    if( (97<=c && c <= 122) ||  (65<=c && c <= 90) ||  (48<=c && c <= 57)) return true; //숫자, 문자S일 경우 operand이므로 true 반환
    return false;
}

int get_precedence(char op)
{
    if((op == '(') || (op == '$'))
    {
        return 0;
    }
    else if ((op == '+') || (op == '-'))
    {
        return 1;
    }
    else if((op == '*') || (op == '/') || (op == '%'))
    {
        return 2;
    }
    else
        return -1;    
}

int main()
{
    operandstack s1;

    int i, precedence, t_pre;
    
    string operandstr, output; 
    char x;

    s1.init();
    cout << "input an infix expression to convert : ";
    cin >> operandstr;
    for (i = 0; i < operandstr.length(); i++ )
    {
        if (is_operand(operandstr[i]))
        {
            output += operandstr[i];
        }
        else
        {
            precedence = get_precedence(operandstr[i]);
            if (precedence == -1)
            {
                while (true)
                {
                    x = s1.pop();
                    if (x== '(')
                      break;
                    output += x;  
                }
              
            }

            else if (precedence == 1)
            {
                while (true)
                {
                    x = s1.top_element();
                    t_pre = get_precedence(x);
                    if(t_pre <= precedence)
                    {
                        s1.push(operandstr[i]);
                        break;
                    }
                        
                    else
                    {
                        x = s1.pop();
                        output += x;
                    }     
                }                
            }

            else         
                s1.push(operandstr[i]);            
        }
            

    }
         
    while (!s1.stack_empty())
    {
        x = s1.pop();
        output += x; 
    }

    cout << output << endl;

    return 0;
}

