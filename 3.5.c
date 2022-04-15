#include <stdio.h>

int main() {
    int number = 0;
    int count = 0;
    int totalsum = 0;
    float average = 0;
    int i = 0;

    while (i == 0) {
        printf("0초과의 숫자를 입력하세요 ");
        scanf("%d", &number);
        if (number > 0)
        {
            count ++;
            totalsum += number;
        }
        else{
            i = 1;
        }
        number = 0;


    }
    average = totalsum * 1.0 / count;    
    printf("입력한 %d개의 숫자들의 합계는 %d이고, 평균 값은 %.1f입니다.", count, totalsum, average);


}