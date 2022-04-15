#include <stdio.h>

int main(){
    float m2_area; //
    float pyung_area; //
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int i;


    for (i = 0; i <= 9; i ++) {
        printf("아파트의 분양 면적(제곱미터)을 입력하시오. ");
        scanf("%f", &m2_area);

        pyung_area = m2_area / 3.305;
        printf("이 아파트의 평형은 %.1f 입니다.\n", pyung_area);
        if (pyung_area < 15) {
            count1 ++;
        }
        else if(pyung_area < 30) {
            count2 ++;
        }
        else if (pyung_area < 50) {
            count3 ++;
        }
        else{
            count4 ++;
        }
    }
    printf("\"소형 아파트\"의 개수는 %d 입니다.\n", count1);
    printf("\"중소형 아파트\"의 개수는 %d 입니다.\n", count2);
    printf("\"중형 아파트\"의 개수는 %d 입니다.\n", count3);
    printf("\"대형 아파트\"의 개수는 %d 입니다.\n", count4);

    return 0;

}