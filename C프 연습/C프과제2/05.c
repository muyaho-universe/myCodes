//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2-5
#include <stdio.h>

int main(void) {
  int i, j; //반복을 위한 변수
  int num = 3; //구구단 곱셈부
  j=1;
  while(1){
    for(i=num; i<=9; i+=3){
      printf("%d*%d=%02d ",i,j,i*j);
    }
    printf("\n");
    if(j>=3 && j<6){
      printf("       "); //3단은 빈칸으로 출력한다
    }
    else if(j>=6){
      printf("              "); //3단과 6단은 빈칸으로 출력한다.
    }
    if(j == num){
      num += 3; //j값이 num과 같을 때 num의 값을 올린다.
    }
    j++;
    if(num > 10){ //num이 9까지만 가도록한다.
      break;
    }
  }
  return 0;
}