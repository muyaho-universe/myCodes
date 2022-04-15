//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2-3 반복하는 드모르간의 법칙을 이용한 OR
//2021년 10월 17일
#include <stdio.h>
#include <string.h>

int Morgan(int bool1,int bool2){
    if ((!bool1 && !bool2)==!1){ //드모르간 법칙을 이용하여 or 판단
        return 1; // True
    }
    else{
        return 0; //False
    }
}

int main(){
    int bool1, bool2; //사용자로부터 입력받는 논리값
    int i; //variable for loop

    printf("input bool data:");
    scanf("%d %d", &bool1, &bool2);   
    if(Morgan(bool1,bool2)){ //Morgan에서 1이 return되면 조건문은 참으로 판단
        printf("OR 연산 출력:TRUE");
    }
    else{ //Morgan에서 0이 return되면 조건문은 거짓으로 판단
        printf("OR 연산 출력:FALSE");
    }
    return 0;
}