#include <stdio.h>

int main(void) {
  int i, j; //반복문을 위한 변수  
  int num1, num2; // 사용자로부터 입력받은 값
  printf("Input number:");
  scanf("%d",&num1);
  
  if (num1%2==0){
    num1 ++;
    for (i=0; i<num1; i++){
      for(j=0; j<num1; j++){
        if(i==j || (i+j==num1-1))
        printf("+");
        else
        printf(" ");
      }
      printf("\n");
    }
  }
  else
  {
   for (i=0; i<num1; i++)
    {
      for(int j=0; j<num1; j++)
      {
        if(i==j || (i+j==num1-1))
        printf("*");
        else
        printf(" ");
      }
      printf("\n");
    } 
  }

  return 0;
}