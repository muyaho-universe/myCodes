#include <stdio.h>

void PrintStar(int size);
// 파라미터:size : 출력할 별의 개수
// 리턴값 : 없음
// 수행내용 : size 개수만큼 '*' 문자 출력 후 개행

int main(){
    int num[10]={}; // input number
    int i;  //variable for loop

    printf("숫자 10개를 입력 ");
    scanf("%d %d %d %d %d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &num[8], &num[9]);
    for ( i = 0; i < 10; i++){
        PrintStar(num[i]);
    }
    return 0;
}

void PrintStar(int size){
    for (int i = 1; i <= size; i++){
        printf("*");
    }
    printf("\n");
}