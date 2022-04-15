//21800059 김대석 김호준 교수님 데이타 구조 과제 1

#include <iostream>
using namespace std;

void my_sort(int [], int);

int main()
{
    int  list[10] = { 23, 11, 15, 8, 17, 33, 7, 14, 19, 21 };
    int  i ;
    my_sort(list, 10);   // 배열 list의 원소 10개를 sort하는 함수
    for (i = 0; i< 10; i++)
        cout << list[i] << "\n";
    return 0;
}

void my_sort(int list[], int num)
{
    int i, j;
    int min;
    int temp;

    for ( i = 0; i < num; i++)
    {
        min = i;
        for ( j = i + 1; j < num; j++)
        {
            if (list[j] < list[min])
                min = j;
        }
        temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
    
}