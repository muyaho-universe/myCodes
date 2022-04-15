#include <stdio.h>

int fibonacci(int n); 

int main(){
    int num;                  //결과를 받기 위한 변수
    int i;
    char* ord[4] ={"st", "nd", "rd", "th"};
    printf("Fibonacci numbers from 1 to 20\n");
    for ( i = 1; i <= 20; i++){
        num = fibonacci(i);
        if(i == 1) printf("%d%s: ", i, ord[0]);
        else if(i == 2) printf("%d%s: ", i, ord[1]);
        else if(i == 3) printf("%d%s: ", i, ord[2]);
        else printf("%d%s: ", i, ord[3]);
        printf("%d\n", num);
    }
    return 0;
}

int fibonacci(int n){
  if (n == 1||n==2) return 1;
  else return fibonacci(n-1) + fibonacci(n-2);
}