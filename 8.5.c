#include <stdio.h>

void PrintChar(int size, char ch);
// 파라미터: size : 출력할 문자의 개수, ch : 출력할 문자
// 리턴값 : 없음
// 수행내용 : size 개수만큼 ch 문자 출력 후 개행

int main(){
    char ch; // input character
    int num[10]={}; // input number
    int i;  //variable for loop
    printf("사용할 문자? ");
    scanf("%c", &ch);
    printf("숫자 10개? ");
    scanf("%d %d %d %d %d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &num[8], &num[9]);
    for ( i = 0; i < 10; i++){
        PrintChar(num[i], ch);
    }
    return 0;
}

void PrintChar(int size, char ch){
    for (int i = 1; i <= size; i++){
        printf("%c", ch);
    }
    printf("\n");
}