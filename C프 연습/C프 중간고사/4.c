//21800059 김대석 나대영 교수님 01분반 중간고사 4번 문제
#include <stdio.h>

int main(){
    int num;
    int i, j;

    while (1){
        printf("양의 정수를 입력:");
        scanf("%d", &num);
        if (num <= 0){
            printf("입력오류\n");
        }
        else{
            break;
        }
    }
    
    if (num % 2 == 0){
        for ( i = 1; i <= num; i++){
            for ( j = 1; j < i; j++){
                printf("*");
            }
            printf("e\n");
        }
        
    }
    else{
        for ( i = 1; i <= num; i++){
            for ( j = 1; j < i; j++){
                printf("*");
            }
            printf("o\n");
        }
        
    }
    return 0;

}