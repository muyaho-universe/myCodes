#include <stdio.h>

int main(){
    int height, weight; //
    float bmi; //
    int people = 0; //
    int i;
    float height_m;

    for ( i = 1; i < 6; i++) {
        printf("%d번째 사람의 신장(cm)과 체중(kg)을 입력하시오. ", i);
        scanf("%d %d", &height, &weight);
        height_m = height * 0.01;
        bmi = weight / (height_m * height_m);
        if (bmi >= 25)
        {
            people ++;
        }
        

    }
    
    printf("비만인 사람은 총 %d명입니다.", people);
    return 0;
    
}