//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 3

#include <stdio.h>

int main(){
    int a,b,c,d,e; //숫자를 받을 5 정수
    int sum; // 받은 숫자의 합을 표현하기 위한 변수
    float avg; //소숫점을 표현하기 위해 실수형으로 선언된 평균을 나타내는 변수

    printf("Input numbers:\n");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    sum=a+b+c+d+e; //합계를 계산
    avg= (a+b+c+d+e)/5.0; //평균을 계산(소수점을 표시하기 위해 5.0으로 나눔)

    printf("sum=%d / avg=%f", sum, avg);
    return 0;

}