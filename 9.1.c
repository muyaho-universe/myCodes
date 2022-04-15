#include <stdio.h>
void askHW(float* h, float* w);
// 파라미터 : 키와 몸무게 값을 저장할 변수의 포인터 (h, w)
// 리턴값 : 없음
// 수행내용 : 키(cm)와 몸무게(kg)을 화면에서 입력받아 h포인터를 통해 미터(float)로 환산한 키, w포인터를 통해 몸무게(float)값을 저장

#define man 5
int main(void) {

    float height, weight, bmi; 
    int count=0;
    int i;  //variable for loop

    

    for( i = 0; i < man; i++){
        printf("%d번째 사람의 신장(cm)과 체중(kg)을 입력하시오. ", i + 1);
        scanf("%f %f", &height, &weight);
        askHW(&height, &weight);
        bmi = weight / (height*height); 
        if (bmi > 25) count++;
    }
    printf("비만인 사람은 %d명입니다.\n", count); 
    
    return 0;

}

void askHW(float* h, float* w){
    *h *= 0.01;
}