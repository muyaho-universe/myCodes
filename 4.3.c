#include <stdio.h>

int main(){
    int mode; //출력모드(1:홀수단, 2:짝수단)
    int i, j; //반복문 사용을 위한 변수

    printf("구구단의 출력모드(1: 홀수단, 2: 짝수단)를 입력하세요. ");
    scanf("%d", &mode);

    if (mode == 2) {
        for(i=2; i <= 8; i += 2){
            for (j = 1; j <= 9; j++) {
                if(j % 3 ==0){
                    printf("%d X %d = %d \n", i, j, i*j);
                }
                else{
                    printf("%d X %d = %d ", i, j, i*j);
                }
            }
            if(i!=8){
                printf("\n");
            }
        }
    }
    else{
        for(i=3; i <= 9; i += 2){
            for (j = 1; j <= 9; j++) {
                if(j % 3 ==0){
                    printf("%d X %d = %d \n", i, j, i*j);
                }
                else{
                    printf("%d X %d = %d ", i, j, i*j);
                }
            }
            if(i!=9){
                printf("\n");
            }
        }
    }
        

    return 0;
}