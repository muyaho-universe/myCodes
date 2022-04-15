//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2-2(for)
#include <stdio.h>

int main(void) {
  int i; //반복을 위한 변수
  int count; //반복 횟수
  printf("Input number: ");
  scanf("%d", &count);

  for(i=1; i<=count; i++){ //count 크기 만큼 반복
    printf("*");

  }
  printf("\n");
  return 0;
}