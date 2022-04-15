//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2-5 두 숫자 사이의 random값 찾기
//2021년 10월 17일

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rndnum(num1, num2){
    int result; // random 값 반환을 위한 변수
   
    if (num1 >= num2){
        result = rand()%(num1 - num2 + 1)+num2;
    }
    else{
        result = rand()%(num2 - num1 + 1)+num1;
    }
    return result;
}

int main(){
    int num1, num2; // 사용자로부터 입력받는 2개의 정수
    int i;  //variable for loop
    printf("input:");
    scanf("%d %d", &num1, &num2);
    //srand(time(0)); //테스트 처리를 위한 주석 처리
    for ( i = 0; i < 5; i++){
        printf("random number:%d\n", rndnum(num1, num2));
    }
    return 0;
}