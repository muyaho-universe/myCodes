#include <stdio.h>
#include <string.h>

void reverseString(char* str); 
// 파라미터 : 문장 1개
// 리턴값 : 없음
// 수행내용 : 이 문자열을 역순으로 변경함

int main(void) {
    char str[100] = {};

    printf("문자열 입력 ");
    fgets(str, 100, stdin);
    str[strlen(str)-1] ='\0';
    reverseString(str);
    printf("역순으로 변환한 문자열은 %s", str);


    return 0;
}

void reverseString(char * str){
    int i;
    int j = strlen(str);
    
    char temp;
    for ( i = 0; i < j/2; i++){
        temp = *(str + i);
        *(str + i) = *(str + j - i - 1);
        *(str + j - i - 1) = temp;
    }
    *(str + strlen(str)) = '\0';
}