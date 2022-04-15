//21800059 김대석 나대영 교수님 01분반 중간고사 2번 문제
#include <stdio.h>

int main(){
    int num;
    int i;
    int sum = 0;

    printf("input number:");
    scanf("%d", &num);

    if (num >= 1 || num <= -1){
        if (num < 0){
            for ( i = -1; i >= num; i--){
                sum += i;
            }
        }
        else{
            for ( i = 1; i <= num; i++){
                sum += i;
            }
            
        }
        printf("%d\n", sum);
    }
    else{
        printf("input error\n");
    }
    
    return 0;
}