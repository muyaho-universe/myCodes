#include <iostream>
#include <cstdlib>
#include <string>
#include <list>

using namespace std;

class weight 
{
public: 
    int kg;
    int gram;
    weight operator+(const weight & t);
};

class s_record 
{
public: 
    string s_id;
    string name;
    double score;
    void set_data(string s1, string s2, double n);
    bool operator< (const s_record & t);
};

bool s_record::operator< (const s_record & t)
{
    if (s_id < t.s_id)
        return true;
    else
        return false;
}

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
    // weight a, b,c;
    // a.kg = 2;
    // a.gram = 500;
    // b.kg = 3;
    // b.gram = 700;
    // c = a + b;    // c = a.operator+(b);
    // cout << c.kg << " kg  and " << c.gram << "grams."  << endl;

    list <s_record> a = { 
        {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 },
        { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
        { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
        { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };
    a.sort();
    list <s_record>::iterator p;
    for (p = a.begin(); p != a.end(); p++)
        cout << p->s_id << endl;
    return 0;
}