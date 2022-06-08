#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    stack <int> s1;
    int i;
    s1.push(1);
    s1.push(2);
    i = s1.top();
    s1.pop();
    cout << i <<endl;
    return 0;
}