//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2-1 계산기 만들기
//2021년 10월 17일
#include <stdio.h>

int main() {
    int num1, num2; // 사용자로부터 입력받는 두 숫자
    char oper;         //  사칙연사자 (42-*, 43-+, 45-- 47-/)
    int sum, sub, times; //덧셈, 뺄셈, 곱셈
    float  div; // 나눗셈

    while (1){
        printf("input expression with arithmetic operator(ex. 12+13):");
        scanf("%d%c%d", &num1, &oper, &num2);
        if (oper == 42){ //ASCII상 *, +, -, / 인지 확인
            times = num1 * num2;
            printf("%4d", times);
            break;
        }
        else if (oper == 43){
            sum = num1 + num2;
            printf("%4d", sum);
            break;
        }
        else if (oper == 45){
            sub = num1 - num2;
            printf("%4d", sub);
            break;
        }
        else if (oper == 47){
            div = (float) num1 / num2; // int를 float형으로 바꿈
            printf("%.2f", div); // 소수점 두 자리까지 표시
            break;
        }

        else{
            printf("input error\n");
        }
    }
    

    return 0;
}