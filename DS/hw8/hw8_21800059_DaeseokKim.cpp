#include <iostream>
#include <string>
using namespace std;

int find_max(int arr[], int count);

int main()
{
    int  a[10] = { 24, 12, 33, 27, 41, 15, 84, 52, 16, 72 };
    int m;
    m = find_max(a, 10);
    cout << m;
    return 0;
}

int find_max(int arr[], int num)
{
    if (num == 0)
        return arr[0];

    int max = find_max(arr, num-1);
    arr[num] = max < arr[num] ? arr[num] : max;
    return arr[num];
}