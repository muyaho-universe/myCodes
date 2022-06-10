#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    stack <int> s1;
    // int i;
    // s1.push(1);
    // s1.push(2);
    // i = s1.top();
    // s1.pop();
    // cout << i <<endl;

    queue <int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.pop();
    cout << q1.front() << endl;
    cout << q1.back() << endl;
    cout << q1.size() << endl;
    
    return 0;
}