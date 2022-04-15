#include <stdio.h>

int fibonacci(int n); 
//parameter: n:사용자가 원하는 n번째 피보나치 수열의 수
//what to do: n번째 피보나치까지 계산
//return: n번째 피보나치 계산

int main(){
    int num1, num2;                  //결과를 받기 위한 변수
    int i = 1;
    float ratio, ex_ratio = 0.0;

    while (1){
        num1 = fibonacci(i);
        num2 = fibonacci(i+1);
        ratio = (float) num2/num1;
        
            
        printf("%d번째 비율 (%d / %d) : %.6f\n", i, num2, num1, ratio);
        if (ratio >= ex_ratio )
            if (ratio - ex_ratio < 	0.000001) break;
        if (ratio < ex_ratio)
            if (ex_ratio - ratio < 0.000001) break;
        ex_ratio = ratio;
        i++;
    }
    
    return 0;
}

int fibonacci(int n){
  if (n == 1||n==2) return 1;
  else return fibonacci(n-1) + fibonacci(n-2);
}