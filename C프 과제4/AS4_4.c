//21800059 김대석 나대영교수님 c프로그래밍 01분반 과제 4-4

#include <stdio.h>

int Fibo(int n, int c[3]);
//parameter: n:사용자가 원하는 n번째 피보나치 수열의 수, c[3] 수열값을 가지고 있는 베열
//what to do: n번째 피보나치까지 계산
//return: n번째 피보나치 계산

int main(){
    int n;                  //사용자에게 입력받는 변수
    int a;                  //결과를 받기 위한 변수
    int cal[3] ={0, 1, 1}; //0번째, 1번째 2번째 수
    while(1){
        printf("fibonaci number: ");
        scanf("%d", &n);
        if(n<1) printf("1 이상의 값을 입력해주세요\n");
        else break;
    }
    
    a = Fibo(n, cal);
    printf("%d번째 피보나치 수열의 값은 %d", n, a);
    return 0;
}

int Fibo(int n,  int c[3]){
    if (n == 0) return c[0];
    else{
        int temp = c[2];
        c[2] = c[0] + c[1];
        c[0] = c[1];
        c[1] = temp;
        n--;
        return Fibo(n, c);
    }
}