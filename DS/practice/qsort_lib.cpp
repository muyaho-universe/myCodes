#include <iostream>
#include <cstdlib>

using namespace std;

int compare(const void* a, const void* b);

int main()
{
    int t_list[10] = {25, 32, 17, 24, 22, 41, 87, 33, 16, 44};
    
    qsort(t_list, 10, sizeof(int), compare);

    for (int i = 0; i < 10; i++)
        cout << t_list[i] << endl;
    return 0;
}

int compare(const void* a, const void* b)
{
    int *p1 = (int *) a;
    int *p2 = (int *) b;

    if (*p1 == *p2)
        return 0;
    if(*p1 < *p2)
        return -1;
    return 1;
    
}