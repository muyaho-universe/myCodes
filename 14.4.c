#include <stdio.h>

int power( int n, int a ); 

int main(){
    int num, a;
    int pow;
    printf("숫자 2개를 입력 ");
    scanf("%d %d", &num, &a);
    pow = power(num, a);
    printf("%d의 %d승은 %d", num, a, pow);
}

int power(int n, int a ){
    if (a == 0) return 1;
    else if(a == 1) return n;
    else if (a % 2 ==0) return power(n, a/2) * power(n, a/2);
    else return power(n, a/2) * power(n, a/2) * n;
} 