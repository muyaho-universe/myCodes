//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2-2 반복하는 계산기 만들기
//2021년 10월 17일
#include <stdio.h>

int add(int num1, int num2){ // 더하기 함수
    int plus = num1 + num2;
    return plus;
}
int sub(int num1, int num2){ // 빼기 함수
    int minus = num1 - num2;
    return minus;
}
int times(int num1, int num2){ // 곱하기 함수
    int multi = num1 * num2;
    return multi;
}
float div(int num1, int num2){ // 나누기 함수
    float divide = (float) num1 / num2;
    return divide;
}
int remains(num1, num2){ // 나머지 함수
    int result = num1 * num2;
    return result;
}


int main() {
    int num1, num2; // 사용자로부터 입력받는 정수
    int count; //사용자로부터 입력받는 반복할 횟수
    int i; //반복문을 위한 변수

    printf("loop count:");
    scanf("%d", &count);
    printf("input numbers:");
    scanf("%d %d", &num1, &num2);

    for ( i = 1; i <= count; i++){
        if (i % 5 == 1){
            printf("%d + %d=%d", num1, num2, add(num1, num2));
        }
        else if (i % 5 == 2){
            printf("%d - %d=%d", num1, num2, sub(num1, num2));
        }
        else if (i % 5 == 3){
            printf("%d * %d=%d", num1, num2, times(num1, num2));
        }
        else if (i % 5 == 4){
            printf("%d / %d=%.2f", num1, num2, div(num1, num2));
        }
        else{
            printf("%d * %d=%d", num1, num2, remains(num1, num2));
        }
        printf("\n");
    }
    
    return 0;
}