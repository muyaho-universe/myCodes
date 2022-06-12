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