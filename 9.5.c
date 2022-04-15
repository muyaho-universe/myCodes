#include <stdio.h>

void maxMinOfTen(int number[10], int* maxmin[]);
// 파라미터 : 입력받은 숫자 배열(number), 최댓값과 최솟값의 포인터가 저장된 배열(mixmin)
// 리턴값 : 없음
/*수행내용 : 받은 배열에서 가장 큰 수와 가장 작은 수를 찾아서 maxmin 포인터배열의 0,1번 포인터 변수에 주소를 저장함. 
maxmin[0] -> 최댓값의 포인터, maxmin[1] -> 최솟값의 포인터*/

int main(void) {

    int num[10];      // 10개의 숫자를 받을 배열
    int* max_min[2];  // 최댓값과 최솟값을 가리킬 포인터 배열 
    for(int i=0;i<10;i++){
        printf("%d번째 숫자를 입력하시오. ", i+1);
        scanf("%d", &num[i]); 
    }
    maxMinOfTen(num, max_min);
    printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.\n", *max_min[0], *max_min[1]); 
    return 0;
}

void maxMinOfTen(int number[10], int* maxmin[]){
    *maxmin  = &number[0];
    *(maxmin+1) = &number[0];

    for (int i = 2; i < 10; i++){
        if (number[i] >= *maxmin[0]) *maxmin = &number[i];
        else if (number[i] <= *maxmin[1]) *(maxmin+1) = &number[i];
    }
    
}