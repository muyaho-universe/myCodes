#include <stdio.h>

int powerOfTwo(int n);

int main(){
    int num;
    int pow;
    while (1){
        printf("숫자 입력 (0 종료) : ");
        scanf("%d", &num);
        if (num == 0) break;
        else{
            pow = powerOfTwo(num);
            printf("2의 %d승은 %d\n", num, pow);
        }
    }
    return 0;
}

int powerOfTwo(int n){
    if (n == 0) return 1;
    else return 2*powerOfTwo(n-1);
}