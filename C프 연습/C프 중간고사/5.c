//21800059 김대석 나대영 교수님 01분반 중간고사 5번 문제
#include <stdio.h>

int main(){
    int nums[10];
    int i;

    for ( i = 0; i < 10; i++){
        printf("input %d", i + 1);
        if (i + 1 == 1){
            printf("st");
        }
        else if (i + 1 == 2){
            printf("nd");
        }
        else if (i + 1 == 3){
            printf("rd");
        }
        else{
            printf("th");
        }
        printf(":");
        scanf("%d", &nums[i]);
    }
    
    for ( i = 9; i >= 0; i--){
        printf("%2d", nums[i]);
        if (i != 0){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
    
    return 0;

}