#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

class palindromeStack
{
    char my_stack[SIZE];
    int top;
public:
    palindromeStack();
    void push(char c);
    int pop();
    bool stack_empty();
    bool stack_full();
    char top_element();
};

palindromeStack::palindromeStack()
{
    my_stack[0] = '$'; // EOS 지정
    top = 1;
}

void palindromeStack::push(char c)
{
    if(stack_full())
        printf("Stack is full\n");
    else
    {
        my_stack[top] = c;
        top++;
    }
}

int palindromeStack::pop()
{
    top--;
    return(my_stack[top]);
}

bool palindromeStack::stack_empty()
{
    if(top == 1) return true;
    return false;
}

bool palindromeStack::stack_full()
{
    if(top == SIZE) return true;
    return false;
}

char palindromeStack::top_element()
{
    return(my_stack[top-1]);
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
                s1.push(no_space_input[i]);
            }
            else
            {
                if (no_space_input[i] != s1.pop())
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
                s1.push(no_space_input[i]);
            }
            else if (i < ((no_space_input.length() / 2) + 1)) continue;
            else
            {
                if (no_space_input[i] != s1.pop())
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

