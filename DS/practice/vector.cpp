#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    vector <int> a;
    vector <int> :: iterator p;
    unsigned int k;
    a.push_back(3);
    a.push_back(4);
    a.push_back(7);

    p = a.begin() + 2;
    a.insert(p, p, p+2);

    for(k = 0; k < a.size(); k++)
        cout << a[k] << " : ";
    cout << endl;

    vector <int> b(a);
    b.insert(b.begin()+3, a.begin(), a.begin()+3);

    for(k = 0; k < b.size(); k++)
        cout <<  b[k] << " : ";
    cout << endl;

    p = b.begin()+2;
    b.erase(p, p+2);

    for(k = 0; k < b.size(); k++)
        cout << b[k] << " : ";
    cout << endl;

    // for (int k = 0; k < 10; k ++)
    //     a[k] = k;

    // for ( p = a.begin(); p < a.end(); p++)
    //     cout << *p << endl;
    
    // a.push_back(2);
    // a.push_back(4);
    // a.push_back(6);
    // cout << a.size() << endl;
    // cout << a[1] << endl;

    // a.pop_back();
    // a.push_back(8);
    // cout << a.front() << endl;
    // cout << a.back() << endl;

    return 0;
}

