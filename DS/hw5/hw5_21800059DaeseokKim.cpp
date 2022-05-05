#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

class parenthesisStack
{
    char my_stack[SIZE];
    int top;
public:
    parenthesisStack();
    void push(char c);
    int pop();
    bool stack_empty();
    bool stack_full();
    char top_element();
};

parenthesisStack::parenthesisStack()
{
    my_stack[0] = '$'; // EOS 지정
    top = 1;
}

void parenthesisStack::push(char c)
{
    if(stack_full())
        printf("Stack is full\n");
    else
    {
        my_stack[top] = c;
        top++;
    }
}

int parenthesisStack::pop()
{
    top--;
    return(my_stack[top]);
}

bool parenthesisStack::stack_empty()
{
    if(top == 1) return true;
    return false;
}

bool parenthesisStack::stack_full()
{
    if(top == SIZE) return true;
    return false;
}

char parenthesisStack::top_element()
{
    return(my_stack[top-1]);
}

bool is_operand(char c)
{
    if( (97<=c && c <= 122) ||  (65<=c && c <= 90) ||  (48<=c && c <= 57)) return true; //숫자, 문자S일 경우 operand이므로 true 반환
    return false;
}

bool is_parenthesis(char c)
{
    if((c == '(') || (c == ')') || (c == '{') || (c == '}') || (c == '[') || (c == ']')) return true;
    else return false;
}

int main()
{
    parenthesisStack s1;

    int i, precedence, type;
    bool isPerfect = true;
    string input; 
    char x;

    cout << "input an expression to check parenthesis : ";
    cin >> input;
    for (i = 0; i < input.length(); i++ )
    {
        if (!is_operand(input[i])) // opearand 인지 opearator 인지 확인. operand일 경우 판단할 필요 없음
        {
            if (is_parenthesis(input[i])) // 괄호인지 판단.
            {
                if ((input[i] == '(') || (input[i] == '{') || (input[i] == '[')) // 여는 괄호일 경우 스택에 집어 넣기
                {
                    s1.push(input[i]);
                }
                else    // 닫는 괄호일 경우 스택의 맨 위의 원소를 불러온 뒤 아스키 코드를 이용하여 짝이 맞는지 판단
                {
                    x = s1.top_element();
                    if(((x == '(') && (input[i] == ')')) || ((x == '{') && (input[i] == '}')) || ((x == '[') && (input[i] == ']'))) s1.pop();
                    else
                    {
                        isPerfect = false;
                        type = 1;
                        break;
                    }
                }
            }
        }

        else continue;
    }
         
    if (!s1.stack_empty()&& isPerfect)  // 반복문이 마무리 되었을 때 스택 안에 원소가 남아 있으면 짝이 완벽하지 않으므로 거짓
    {
        x = s1.pop();
        isPerfect = false;
        type = 2;
    }
    
    if (isPerfect)
    {
        cout << "It's a nomarl expression!" << endl;
    }

    else
    {
        if (type == 1)      // 닫는 괄호가 없을 때
        {
            if (x == '(')
            {
                cout << "Error: mis-matched parenthesis, \')\' is expected."<< endl;
            }
            else
                printf("Error: mis-matched parenthesis \'%c\' is expected.\n", x+2);
        }
        else    // 짝이 안맞을때
        {
            if (x == '(')
            {
                cout << "Error: An extra parenthesis \')\' is found."<< endl;
            }
            else
                printf("Error: An extra parenthesis \'%c\' is found.\n", x+2);
        }
    }
        
    return 0;
}