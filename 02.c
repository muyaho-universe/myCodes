//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2

#include <stdio.h>

int main(){
    int a, b; //두 정수를 받는 a와 b를 선언

    printf("Input first number:");
    scanf("%d", &a); //첫번째 숫자를 받음
    printf("Input second number:");
    scanf("%d", &b); //두번째 숫자를 받음
    printf("\n");
    printf("**** result ****\n");

    printf("sum:%d+%d=%d\n", a, b, a+b); //덧셈
    printf("sub:%d-%d=%d\n", a, b, a-b); //뺄셈
    printf("mul:%d*%d=%d\n", a, b, a*b); //곱셈
    printf("div:%d/%d=%d\n", a, b, a/b); //나눗셈
    printf("mod:%d%%%d=%d\n", a, b, a%b); //나머지


    return 0;

}