//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2-4 MIN, MAX 찾기
//2021년 10월 17일

#include <stdio.h>

int main(){
    int num;    // 사용자로부터 정수를 입력받기 위한 변수
    int min, max;   // 가장 작은 값과 큰 값
    int i = 1;  // 사용자로부터 받은 첫 값이 0일 경우 반복문 실행을 하지 않기 위한 i

    printf("input number(program exit-0):");
    scanf("%d", &num);
    if (num == 0){
        i = 0;
    }
    else{
        min = num;
        max = num;
    }
    printf("min:%d max:%d", min, max);

    while (i){
        printf("input number(program exit-0):");
        scanf("%d", &num);
        if (num == 0){
            break;
        }
        else{
            if (num < min){
                min = num;
            }
            if (num > max){
                max = num;
            }
        }
        printf("min:%d max:%d", min, max);
    }
    printf("Goodbye");

    

}