#include <iostream>
#include <string>
using namespace std;

class node
{

public:
    char ch;
    void set_data(char c);
    node *link;
};

void node::set_data(char c)
{
    ch = c;
}


class palindromeStack
{
    
    node *top;
public:
    palindromeStack();
    void push(node t);
    char pop();
    bool stack_empty();
};

palindromeStack::palindromeStack()
{
    top = NULL;
}

void palindromeStack::push(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = top;
    top = p;
}

char palindromeStack::pop()
{
    if(stack_empty())
    {
        cout << "Stack is empty\n";
        return -1;
    }
    char temp;
    node *t;
    t = top;
    
    temp = top->ch;
    top = top->link;
    delete t;
    return temp;
}

bool palindromeStack::stack_empty()
{
    if(top == NULL) return true;
    return false;
}

bool is_char(char c)
{
    if( (97<=c && c <= 122) ||  (65<=c && c <= 90)) return true; // 문자에 관하여서만 판단
    return false;
}

// char lower(char c)
// {
//     if( (65<=c && c <= 90)) c += 32;
//     return c;
// } // 아스키 코드를 이용하여 소문자로 만드는 함수


int main()
{
    palindromeStack s1;
    node tmp;

    int i, precedence, t_pre;
    bool isPalindrome = true;
    string input, no_space_input; 
    char x;

    cout << "input an expression to check parenthesis : ";
    getline(cin, input);
    for (i = 0; i < input.length(); i++ )
    {
        if(is_char(input[i])) no_space_input += input[i]; 
    }   // 문자에 대해서만 소문자로 변환한 문자열 만듦

    // cout << no_space_input << endl;  // 문자열 변환이 잘 됐는지 파악

    for ( i = 0; i < no_space_input.length(); i++)
    {   
        if (no_space_input.length() % 2 == 0)   // 문자열의 길이가 짝수
        {
            if (i < no_space_input.length() / 2)
            {
                tmp.set_data(no_space_input[i]);
                s1.push(tmp);
            }
            else
            {
                x = s1.pop();
                if (no_space_input[i] != x)
                {
                    isPalindrome = false;
                    break;
                }
            }
        }
        else    // 문자열의 길이가 홀수
        {
            if (i < no_space_input.length() / 2)
            {
                tmp.set_data(no_space_input[i]);
                s1.push(tmp);
            }
            else if (i < ((no_space_input.length() / 2) + 1)) continue;
            else
            {
                x = s1.pop();
                if (no_space_input[i] != x)
                {
                    isPalindrome = false;
                    break;
                }
            }
        }
        
    }
    
    
    if (isPalindrome)
    {
        cout << "Yes, it's a palindrome." << endl;
    }

    else
    {
        cout << "No, it's not a palindrome." << endl;
    }
    
    
    return 0;
}

