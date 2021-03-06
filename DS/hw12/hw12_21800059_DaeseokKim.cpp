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

int summation(element a[], int troot, int n);
int delete_node(element a[], int troot, string tname, int n);
void heap_adjust(element a[], int troot, int size);

class my_heap {
    element h[HSIZE];
    int csize; // the number of elements
    void adjust(int t_root);
public :
    my_heap();
    my_heap(element ele[], int num);
    int h_size(); 
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
    int score_sum();
    double score_average();
    int node_delete_by_name(string name);
};

my_heap::my_heap()
{
    csize = 0;
}

my_heap::my_heap(element ele[], int num)
{
    int k;
    for (k = 1; k <= num; k++)
        h[k] = ele[k-1];
    csize = num;
    for (k = num / 2; k >= 1; k--)
        adjust(k);
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
    int k;
    csize++;
    k = csize;
    while ((k != 1) && (t.score > h[k / 2].score)) 
    {
        h[k] = h[k / 2];
        k /= 2;
    }
    h[k] = t;
}

element my_heap::delete_heap()
{
    element t;
    element tmp;
    int parent, child;
    t = h[1]; // for return value
    tmp = h[csize]; // 끝원소
    csize--;
    parent = 1; // root
    child = 2; // root의 left child
    while (child <= csize) 
    {
        if ((child < csize) && (h[child].score < h[child + 1].score))
            child++; // right child를 선택
        if (tmp.score >= h[child].score)
            break;
        h[parent] = h[child];
        parent = child; // 한단계 아래로
        child *= 2;
    }
    h[parent] = tmp;
    return t;
}

int my_heap::score_sum()
{
    return summation(h, 1, csize);
}

double my_heap::score_average()
{
    if (csize == 0)
        return 0;
    
    return (double) score_sum() / csize;
}

int my_heap::node_delete_by_name(string tname)
{
    if (csize == 0)
        return 0;
    if ( delete_node(h, 1, tname, csize) == 1)
    {
        csize--;
        return 1;
    }
    else
        return 0;
}

void my_heap::adjust(int t_root)
{
    double tmpkey;
    int child;
    element tmp;
    tmp = h[t_root];
    tmpkey = h[t_root].score;
    child = 2 * t_root;
    while (child <= csize) 
    {
        if ((child < csize) && (h[child].score < h[child + 1].score))
            child++;
        if (tmpkey > h[child].score)
            break;
        else 
        {
            h[child / 2] = h[child];
            child *= 2;
        }
    }
    h[child / 2] = tmp;
}

int main()
{
    element a[10] = { {"Kim",88}, {"Lee", 77}, {"Park", 98}, {"Choi", 74}, {"Ryu",94}, {"Cho", 85}};
    my_heap h1(a, 6);
    element temp;

    cout << "Number of nodes : " << h1.h_size() << endl;
    cout << "Score Sum = " << h1.score_sum() << endl;
    cout << "Score average = " << h1.score_average() << endl;
    h1.node_delete_by_name("Kim");
    cout << "\n-- After the deletion operation. --\n\n";
    cout << "Number of nodes : " << h1.h_size() << endl;
    cout << "Score Sum = " << h1.score_sum() << endl;
    cout << "Score average = " << h1.score_average() << endl;
    while (h1.h_size() > 0) {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
    }
}

int summation(element a[], int troot, int n)
{
    if (troot > n)
        return 0;
    return (a[troot].score + summation(a, 2*troot, n) + summation(a, 2*troot+1, n)); 
}

int delete_node(element a[], int troot, string tname, int n)
{
    int temp = 0;
    if(troot > n)
        return 0;
    if (a[troot].name == tname)
    {
        a[troot] = a[n];
        for (int i = troot / 2; i >= 1; i--)
            heap_adjust(a, i, n);
        return 1;
    }
    temp = delete_node(a, troot * 2, tname, n);
    if(temp != 1)
        temp = delete_node(a, troot * 2 + 1, tname, n);
    return temp;
}

void heap_adjust(element a[], int troot, int size)
{
    double tmpkey;
    int child;
    element tmp;
    tmp = a[troot];
    tmpkey = a[troot].score;
    child = 2 * troot;
    while (child <= size) 
    {
        if ((child < size) && (a[child].score < a[child + 1].score))
            child++;
        if (tmpkey > a[child].score)
            break;
        else 
        {
            a[child / 2] = a[child];
            child *= 2;
        }
    }
    a[child / 2] = tmp;
}