//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2-4
#include <stdio.h>

int main(void) {
  int i, j; //반복을 위한 변수
  int num; //입력받은 숫자

  printf("Input number: ");
  scanf("%d", &num);

  if(num % 2 == 0){ //num이 짝수일 시 수행한다.
    num ++;
    for(i=1; i <= num; i++){
      for(j=1; j <= num; j++){
        if(j == i || j == (num-i+1)){ //필요한 위치에만 기호를 나타내기 위해 설정한 범위
          printf("+");
        }
        else{
          printf(" ");
        }
      }
      printf("\n");
    }
  }
  
  else{ //홀수일때
    for(i=1; i <= num; i++){
      for(j=1; j <= num; j++){
        if(j == i || j == (num-i+1)){
          printf("*");
        }
        else{
          printf(" ");
        }
      }
      printf("\n");
    }
  }
  printf("\n");
  return 0;
}