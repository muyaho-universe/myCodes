//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2-3 반복하는 드모르간의 법칙을 이용한 OR
//2021년 10월 17일
#include <stdio.h>
#include <string.h>

int Morgan(bool1,bool2){
    int result = bool1 + bool2;
    if (result >= 1){ //1보다 크면 True return
        return 1;
    }
    else{
        return 0; //False
    }
    
}

int main(){
    int bool1, bool2; //사용자로부터 입력받는 논리값
    char tf[100] ; //True인지 False인지 출력을 위한 문자형 변수
    char True[100] = "TRUE";
    char False[100] = "FALSE";
    int i; //variabl for loop


    printf("input bool data:");
    scanf("%d %d", &bool1, &bool2);   
    if(Morgan(bool1,bool2)){ // or상 참일때
        for ( i = 0; i < strlen(True); i++){
            tf[i] = True[i];
        }
        
        
    }
    else{ //or상 거짓일때
        for ( i = 0; i < strlen(False); i++){
            tf[i] = False[i];
        }
    }

    tf[(strlen(tf))] = '\0'; //문자형 배열로 변환을 위한 '\0' 붙이기
        
    printf("OR 연산 출력:%s", tf);
    return 0;
}