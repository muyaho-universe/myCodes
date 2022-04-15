#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int coins;      // 사용자의 코인 수. (최초에 입력받음)
    int number[3];  // 랜덤하게 만들어진 슬롯머신의 숫자 3개 
    int dummy;      // 게임스타트를 위한 의미 없는 입력 숫자
    int rest;       // 남은 횟수 
    int count;      // 룰렛에서 같은 숫자들 갯수
    int i = 1, j, k;          // 반복문을 위한 변수 

    printf("사용하실 코인의 개수를 입력하세요. ");
    scanf("%d", &coins);

    while (i <= coins){
        count = 0;
        printf("게임 %d회 Start!!! (아무 숫자나 입력하세요) ", i);
        scanf("%d", &dummy);

        srand(time(0));
        for ( j = 0; j < 3; j++){
            number[j] = rand()%9+1;     
        }

        for ( j = 0; j < 3; j++){
            for ( k = 0; k < j; k++){
                if(j == k) continue;
                else if (number[j] == number[k]){
                    count ++;
                }
            }
        }

        printf("게임 결과 : ");
        for ( j = 0; j < 3; j++){
            printf("%d ", number[j]);
        }

        printf(" ----> ");
        if (count == 0){
            printf("꽝입니다... 아쉽군요\n");
        }
        
        else if (count == 1){
            printf("숫자 2개 일치... 코인 2개 증정\n");
            coins += 2;
        }
        else{
            printf("숫자 3개 일치... 코인 4개 증정\n");
            coins += 4;
        }
        printf("남아있는 코인은 %d개입니다.\n", coins - i);
        i++; 
    }
    printf("\n게임 종료!!");
}