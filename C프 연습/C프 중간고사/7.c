//21800059 김대석 나대영 교수님 01분반 중간고사 7번 문제
#include <stdio.h>

int main(){
    char jumin[15] = {""};
    char tmp[100] = {""};
    int i;

    printf("input registration number(991133-1759834):");
    scanf("%s", jumin);
    printf("Birthday\n");
    printf("=====================\n");
    printf("Year:");
    for ( i = 0; i < 2; i++){
        printf("%c", jumin[i]);
    }
    printf("\n");
    printf("Month:");
    if (jumin[2] != '0'){
        printf("1");
    }
    printf("%c\n", jumin[3]);
    printf("Day:");
    if (jumin[4] != '0'){
        printf("%c", jumin[4]);
    }
    printf("%c\n", jumin[5]);
    printf("=====================\n");
    printf("Gender:");
    if (jumin[7] == '1'){
        printf("male\n");
    }
    else{
        printf("female\n");
    }
    
    return 0;
}