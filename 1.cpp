#include <iostream>

using namespace std;

class pita
{
    
public:
    bool isRightAngle(int a, int b, int c);
}
    

bool pita::isRightAngle(int a, int b, int c)
{
    if((a*a+b*b) == (c*c)) return true;
    else false;
}

int main()
{
    int a = 1;
    int b = 1;
    int c = 5;
    int top;
    pita p;
    int count = 0;

    cout << "원하는 숫자를 입력하세요";
    cin >> top;

    while (c <= top)
    {
        while (b < c)
        {
            if(p.isRightAngle(a, b, c))
            {
                count++;
                cout << a << b << c << endl;
            }
            b++;
        }
        a++;
        b = a+1;
        c++;
    }
    count << "총" << count << "개 입니다." << endl;
    return 0;

}