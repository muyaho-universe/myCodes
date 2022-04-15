//21800059 김대석 나대영교수님 c프로그래밍 01분반 과제 5-2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define S_NUM 10
#define E_NUM 100               //배열의 시작과 끝 숫자

void input_array(int [], int); // 배열에 데이터 입력 함수
void output_array(int [], int); // 배열 출력 함수
bool sort(int [], int); // 배열 정렬
void swap(int*, int*); //두 개의 데이터를 받아서 교환하는 함수

int main(){
    int size = 0;           //input size
    while (1){
        printf("input number of data:");
        scanf("%d", &size);
        if (size<=0) printf("Please input greater than 0\n");
        else break;
    }
    int ary[size];
    srand(time(0));     //랜덤값을 위한 srand 호출
    input_array(ary, size);     //input_array 호출

    printf("Array:\n");
    output_array(ary, size);        //배열 출력

    if(sort(ary, size)) printf("Called swap function\n");       //sort 함수에서 true반환시 실행

    printf("=============sorted array================\n");
    printf("Array:\n");
    output_array(ary, size);

    printf("min:%4d, max:%d", ary[0], ary[size-1]);             //정렬된 배열의 첫 값과 마지막 값은 각각 최소와 최대값.
    return 0;
}

void input_array(int a[], int s){
    int i;
    for ( i = 0; i < s; i++) a[i] = rand()%(E_NUM - S_NUM + 1) + S_NUM;     //10과 100사이 무작위 숫자 입력;
}

void output_array(int a[], int s){
    for (int i = 0; i < s; i++) printf("%4d", a[i]);                    //만들어진 배열 출력
    printf("\n");
}

bool sort(int a[], int s){
    int i, j;
    int k = 0;                          //if문을 위한 변수
    for ( i = 0; i < s; i++){
        for ( j = 0; j < i; j++){
            if (a[j] > a[i]){
                k = 1;                  //정렬이 필요하면 k는 1로 바뀜
                swap((a+j), (a+i));     //함수 호출
            }
        }
    }
    if (k) return true;
    else return false;
}

void swap(int* a, int* b){
    int temp;       //sorting을 위한 변수
    temp = *a;
    *a = *b;
    *b = temp;
}