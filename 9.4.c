#include <stdio.h>

float bmiFromHW(float* h, float* w);
// 파라미터 : 키(h)과 몸무게(w) 값을 저장할 변수의 포인터
// 리턴값 : 계산된 bmi 지수
/* 수행내용 : 키(cm)과 몸무게(kg)을 화면에서 입력받아 h포인터에 미터(float)로 환산한 키, 
w포인터에 몸무게 (float)값을 저장하고, bmi 지수를 계산해서 리턴함 */

int main(void) {
	float height, weight, bmi;
	int count=0;
	for(int i=0;i<5;i++){
        printf("신장(cm)과 체중(kg)을 입력하시오.");
        scanf("%f %f", &height, &weight);
        
		bmi = bmiFromHW(&height, &weight);
		if (bmi > 25) {
			printf("비만입니다. 키:%.2f미터 몸무게:%.1fkg\n",height, weight);
			count++;
		}
	}
	printf("비만인 사람은 %d명입니다.\n", count);
	return 0;
}

float bmiFromHW(float* h, float* w){
	float bmi;
	*h *= 0.01;

    bmi = *w / (*h * *h);

	return bmi;
}