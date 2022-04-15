#include <stdio.h>

#define low_weight 18.5
#define normal_weight 23
#define overweight 25
#define pig 30
#define man 10

int askBiman(int height, int weight);
// 파라미터) height : 신장(cm), weight : 체중(kg)
// 수행내용) 비만도 계산 후 판정결과 리턴
// 리턴값) 저체중 0, 정상체중 1, 과체중 2, 경도비만 3, 고도비만 4

int main(){
    int height, weight;
    int i;  //variable for loop

    for ( i = 1; i <= man; i++){
        printf("%d번째 사람 신장과 체중? ", i);
        scanf("%d %d", &height, &weight);
        if (askBiman(height, weight) == 0){
            printf("저체중\n");
        }
        else if (askBiman(height, weight) == 1){
            printf("정상\n");
        }
        else if (askBiman(height, weight) == 2){
            printf("과체중\n");
        }
        else if (askBiman(height, weight) == 3){
            printf("경도비만\n");
        }
        else if (askBiman(height, weight) == 4){
            printf("고도비만\n");
        }
        else{
            printf("잘못 입력하셨습니다.\n");
        }
    }
    
    return 0;
}

int askBiman(int height, int weight){
    if(height <= 0 || weight <= 0){
      return 5;
    }
    float height_f = height *0.01;
    float bmi = weight /(height_f * height_f) ;          //비만도 수치 = 체중(kg) / (신장(m)의 제곱)
    if (bmi < low_weight){ //저체중 0, 정상체중 1, 과체중 2, 경도비만 3, 고도비만 4
        return 0;
    }
    else if (bmi < normal_weight){
        return 1;
    }
    else if (bmi < overweight){
        return 2;
    }
    else if (bmi < pig){
        return 3;
    }
    else{
        return 4;
    }
}