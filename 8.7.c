#include <stdio.h>
int maxOfTen(int number[10]);
// 파라미터 : 입력받은 숫자 배열(number)
// 리턴값 : 가장 큰 값
// 수행내용 : 받은 배열에서 가장 큰 수를 찾아서 메인에게 리턴

int minOfTen(int number[10]);
// 파라미터 : 입력받은 숫자 배열(number)
// 리턴값 : 가장 작은 값
// 수행내용 : 받은 배열에서 가장 작은 수를 찾아서 메인에게 리턴

int main(void) {
    int number[10]={0};
    int i;  //variable for loop

    for( i = 0; i < 10; i++){
        printf("%d번째 숫자를 입력하시오. ",i+1);
        scanf("%d",&number[i]);
    }
    
    printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.", maxOfTen(number), minOfTen(number));
    return 0;
}

int maxOfTen(int number[10]){
    int max = number[0];
    for (int i = 1; i < 10; i++){
        if(number[i] > max) max = number[i];
    }
    return max;
}

int minOfTen(int number[10]){
    int min = number[0];
    for(int i = 1; i < 10; i++){
        if(min>number[i]) min = number[i];
    }
    return min;
}