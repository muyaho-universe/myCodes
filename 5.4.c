/*This code is for searching the second large number
    Daeseok Kim 21800059 Oct 2nd, 2021 */

#include <stdio.h>

int main(){
    int num[10]; // 10개의 숫자
    int first = 0; //first num
    int second = 0; //second num
    int second_max_idex; //second num index
    int i; // variable for loop

    for ( i = 0; i < 10; i++){
      printf("%d번째 수를 입력하시오. ", i + 1);
      scanf("%d", &num[i]);
    }

    first = num[0];
    second_max_idex = 1;

    for( i = 1; i < 10; i++){
      if(num[i] >= first){
        second = first;
        first = num[i];
      }
      else if(num[i] >= second){
        second = num[i];
      }
    }

    for( i = 0; i < 10; i++){
      if(num[i] == second){
        second_max_idex = i + 1;
      }
    }
        
    
    printf("두번째로 큰 수는 %d번째 수 %d입니다.\n", second_max_idex, second);
    return 0;
    
}