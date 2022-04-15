#include <stdio.h>

int main(){
    int mode; //출력모드(1:홀수단, 2:짝수단)
    int column; //열 개수
    int i, j; //반복문 사용을 위한 변수

    printf("구구단의 출력모드(1: 홀수단, 2: 짝수단)를 입력하세요. ");
    scanf("%d", &mode);
    printf("한 줄에 출력할 개수를 입력하세요. ");
    scanf("%d", &column);

    if (mode == 2) { //mode가 2일때
        for (i = 2; i <= 8; i += 2){
            for (j = 1; j <= 9; j++){
                if( j % column == 0){ //column의 숫자와 같을때 줄을 변경
                    printf("%d X %d = %d \n", i, j, i*j);
                }
                else{
                    printf("%d X %d = %d ", i, j, i*j);
                }
                if(j==9 && column != 3){ //column이 3일 경우 2번 줄을 바꿈
                  printf("\n");
                }
            }
          if(i!=8){
            printf("\n");
          }   
                 
        }
    }
    else{ //mode가 1일때
        for(i=3; i <= 9; i += 2){
            for (j = 1; j <= 9; j++) {
                if(j % column ==0){
                    printf("%d X %d = %d \n", i, j, i*j);
                }
                else{
                    printf("%d X %d = %d ", i, j, i*j);
                }
                if(j==9 && column != 3){
                  printf("\n");
                }                
            }
            if(i!=9){
                printf("\n");
            }
        }
    }
    
    return 0;
}