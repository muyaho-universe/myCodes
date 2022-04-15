#include <stdio.h>
#include <string.h>

int which_first(char * str1, char * str2);
//파라미터 : 영어단어 2개의 문자열을 나타내는 포인터
// 리턴값 : 사전상 먼저 나타날 문자열의 순서, 1(첫 번째 문자열) 또는 2(두번째 문자열)
//수행내용 : 두 문자열을 문자순서대로 비교해서 사전적으로 먼저나오는 문자열을 찾아 1,2 중에 하나를 리턴한다.

int main(){
    char str1[100], str2[100];    // input string by user
    int result; //variable for return value from function

    printf("첫번째 문자열을 입력하시오. -->");
    scanf("%s", str1);

    printf("두번째 문자열을 입력하시오. -->");
    scanf("%s", str2);

    result = which_first(str1, str2);
    if (result == 1) printf("첫번째 문자열이 사전에 먼저 나옵니다.");
    if (result == 2) printf("두번째 문자열이 사전에 먼저 나옵니다.");
   

    return 0;
}

int which_first(char * str1, char * str2){
    int i;
    int r = 0;
    

    for ( i = 0; i < strlen(str1); i++){
        if ( * (str1 + i)>= 97 && *(str1 + i) <= 122){
            *(str1 + i) -= 32;
        }
    }
    for ( i = 0; i < strlen(str2); i++){
        if (* (str2 + i) >= 97 && * (str2 + i) <= 122){
            * (str2 + i) -= 32;
        }
    }
    if (strlen(str1) > strlen(str2)){
        for ( i = 0; i < strlen(str1); i++){
            if (* (str1 + i) > * (str2 + i)){
                r = 2;
                break;
            }
            else if(* (str1 + i) < * (str2 + i)){
                r = 1;
                break;
            }
            else continue;
        }
    }
    else{
        for ( i = 0; i < strlen(str2); i++){
            if (* (str1 + i) > * (str2 + i)){
                r = 2;
                break;
            }
            else if(* (str1 + i) < * (str2 + i)){
                r = 1;
                break;
            }
            else continue;
        }
    }
    //printf("%d\n", r);
    if (r == 1) return 1;
    else return 2;
    
}