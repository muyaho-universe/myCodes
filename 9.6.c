#include <stdio.h>
void sort3Num(int* n1, int* n2, int* n3);
// 파라미터 : 정수포인터 3개
// 리턴값 : 없음
// 수행내용 : 정수포인터 3개의 실제 값을 기준으로 가장 큰 수부터 정렬되도록 변수값 변경함

int main(void) {
    int num1, num2, num3;
    printf("숫자 3개 입력 ");
    scanf("%d %d %d", &num1, &num2, &num3); 
    sort3Num(&num1, &num2, &num3);
    printf("정렬 결과 %d %d %d\n", num1, num2, num3); return 0;
}

void sort3Num(int* n1, int* n2, int* n3){
    int temp;

    if (*n3> *n1){  
        if (*n2 > *n1){ //n3> n2> n1
            temp = *n1;
            *n1 = *n3;
            *n3 = temp;
        }
        else{   //n3> n1> n2
            temp = *n1;
            *n1 = *n3;
            *n3 = *n2;
            *n2 = temp;
        }
    }
    
    if (*n2 > *n1){
        if (*n1 > *n3){ //n2> n1> n3
            temp = *n1;
            *n1 = *n2;
            *n2 = temp;
        }
        else{ //n2> n3> n1
            temp = *n1;
            *n1 = *n2;
            *n2 = *n3;
            *n3 = temp;
        }
    }
    
    if (*n1 > *n2){
        if (*n3 > *n2){ //n1> n3> n2
            temp = *n2;
            *n2 = *n3;
            *n3 = temp;
        }
    }
}