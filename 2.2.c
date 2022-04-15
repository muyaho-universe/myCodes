#include <stdio.h>

int main() {
    int height, weight, height_sq; //신장(cm), 체중(kg)
    float bmi; //비만도 수치

    printf("height? ");
    scanf("%d", &height);

    printf("weight? ");
    scanf("%d", &weight);

    height = height * 0.01;
    height_sq = height * height;
    bmi = weight / height_sq;

    if (bmi < 25) {
        printf("You are not overweight.");
    }
    else{
        printf("You are overweight");
    }

    return 0;
    
}