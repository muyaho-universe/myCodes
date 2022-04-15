#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int answer = rand()%100+1;       // 컴퓨터가 만들어 낸 1부터 100사이의 임의의 숫자
    int number_try;   // 사용자가 제시한 숫자
    int count = 0;        // 사용자가 맞추려고 시도한 횟수
    int i = 1; //variable for loop

    while (i){
        printf("1부터 100까지의 숫자 하나를 맞춰보세요 ");
        scanf("%d", &number_try);
        if (number_try == answer){
            i = 0;
        }
        else if (number_try > answer){
            printf("좀 더 작은 수입니다.\n");
            count++;
        }
        else{
            printf("좀 더 큰 수입니다.\n");
            count++;
        }
        
    }
    

    printf("%d번만에 숫자를 맞추셨습니다.", count);

    return 0;
}