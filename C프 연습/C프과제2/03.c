//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2-3
#include <stdio.h>

int main(void) {
  int i; //반복을 위한 변수
  int num; //입력받은 숫자
  printf("Input number: ");
  scanf("%d", &num);
  if(num % 2 == 0){ //짝수일때
    for(i=1; i <= num; i++){
      printf("+");
    }
  }
  else{ //홀수일때
    for(i=1; i <= num; i++){
      printf("*");
    }
  }
  printf("\n");
  return 0;
}