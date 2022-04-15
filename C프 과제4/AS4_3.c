//21800059 김대석 나대영교수님 c프로그래밍 01분반 과제 4-3

#include <stdio.h>

float funcForce(float w, float v, float t, float g);
//parameter: w:로켓의 무게, v:로켓의 평균속도, t:시간, g:중력가속도
//what to do: 로켓의 전체 힘을 계산
//return: 로켓의 힘

float funcThrust(float w, float f);
//parameter: w:로켓의 무게 f:로켓의 힘
//what to do:로켓의 추진력 계산
//return: 로켓의 추진력

int main(){
    float w, v, t, g = 32.2; //w:로켓의 무게, v:로켓의 평균속도, t:시간, g:중력가속도
    float f, th;    //f:로켓의 힘 th:로켓의 추진력

    printf("INPUT DATA(ex. weight velocity time):");
    scanf("%f %f %f", &w, &v, &t);
    printf("OUTPUT DATA:\n%.2f\n%.2f\n%.2f\n\n", w, v, t);

    f = funcForce(w, v, t, g);
    th = funcThrust(w, f);
    printf("Force due to accelerattion: %.2f\n", f);
    printf("Total thrust due to accelerattion: %.2f", th);

    return 0;
}

float funcForce(float w, float v, float t, float g){
    float result = (w * v) / (t * g);
    return result;
}

float funcThrust(float w, float f){
    float result = w + f;
    return result;
}