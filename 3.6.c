#include <stdio.h>

int main() {
    int a, b, c;
    int x_begin, x_end;
    int x, y;
    int i;
    printf("2차 함수의 계수 a와 b와 c를 입력 ");
    scanf("%d %d %d", &a, &b, &c);

    printf("x좌표의 시작 값과 끝 값을 입력 ");
    scanf("%d %d", &x_begin, &x_end);

    for ( i = 0; i < x_end; i++) {
        x = x_begin;
        y = a * x_begin * x_begin + b * x_begin + c;

        printf("좌표 (%d, %d)\n", x, y);
        x_begin ++;
    }
    
    return 0;

}