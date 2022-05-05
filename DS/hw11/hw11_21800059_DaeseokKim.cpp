#include <iostream>
#include <string>
using namespace std;

#define HSIZE 100

class element {
public:
    string name;
    double score; // Key
    void set_data(string n, double s);
};

void element::set_data(string n, double s)
{
    name = n;
    score = s;
}

class my_heap {
    element h[HSIZE];
    int csize; // the number of elements
public :
    my_heap();
    int h_size(); 
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
};

my_heap::my_heap()
{
    csize = 0;
}

bool my_heap::heap_empty()
{
    // return (csize == 0);
    if (csize == 0)
    return true;
    else
    return false;
}

bool my_heap::heap_full()
{
    // return (csize >= HSIZE-1);
    if (csize >= HSIZE-1)
    return true;
    else
    return false;
}

int my_heap::h_size()
{
    return csize;
}

void my_heap::insert_heap(element t)
{
    
}

element my_heap::delete_heap()
{

}

int main()
{
    my_heap   h1;
    element   temp;
    temp.set_data("Kim", 88);
    h1.insert_heap(temp);
    temp.set_data("Lee", 77);
    h1.insert_heap(temp);
    temp.set_data("Park", 98);
    h1.insert_heap(temp);
    temp.set_data("Choi", 74);
    h1.insert_heap(temp);
    temp.set_data("Ryu", 94);
    h1.insert_heap(temp);
    temp.set_data("Cho", 85);
    h1.insert_heap(temp);
    while (h1.h_size() > 0) 
    {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
    }
   return 0;
}