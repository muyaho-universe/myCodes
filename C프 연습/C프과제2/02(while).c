//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2-2(while)
#include <stdio.h>

int main(void) {
  int i; //반복을 위한 변수
  int count; //반복 횟수
  printf("Input number: ");
  scanf("%d", &count);
  i = 1;
  while(i <= count){ //i가 count보다 작은 동안 작동
    printf("*");
    i++;
  }
  printf("\n");
  return 0;
}