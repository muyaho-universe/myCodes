//21800059 김대석 나대영 교수님 01분반 중간고사 6번 문제
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr_rnd();
void prn_rnd(int nums[100], int size);

int main(){
    int size;
    printf("input size of array:");
    scanf("%d", &size);

    int nums[size];
    int i;
    srand(time(0));

    for ( i = 0; i < size; i++){
        nums[i] = arr_rnd();
    }
    prn_rnd(nums, size);
    return 0;
}

int arr_rnd(){
    int zero = 0;
    int nine = 9;
    int result = rand()%(nine - zero + 1) + zero;
    return result;
}

void prn_rnd(int nums[100], int size){
    int sum = 0;
    float avg = 0;
    int i;
    
    for ( i = 0; i < size; i++){
        printf("%d", nums[i]);
        if(i != 9){
            printf(" ");
        }
        else{
            printf("\n");
        }
        sum += nums[i];
    }
    avg = (float) sum / size;
    printf("sum:%d avg:%.2f", sum, avg);
    
}