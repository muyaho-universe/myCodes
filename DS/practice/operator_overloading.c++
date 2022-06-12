#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class weight 
{
public: 
    int kg;
    int gram;
    weight operator+(const weight & t);
};

weight weight::operator+(const  weight & t)
{
    weight  tmp;
    tmp.kg = kg + t.kg;
    tmp.gram = gram + t.gram;
    if (tmp.gram >= 1000) 
    {
        tmp.kg += tmp.gram / 1000;
        tmp.gram = tmp.gram % 1000;
    }
    return tmp;
}

int main()
{
    weight a, b,c;
    a.kg = 2;
    a.gram = 500;
    b.kg = 3;
    b.gram = 700;
    c = a + b;    // c = a.operator+(b);
    cout << c.kg << " kg  and " << c.gram << "grams."  << endl;
    return 0;
}