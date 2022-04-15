//21800059 김대석 나대영 교수님 C 프로그래밍 01분반 과제 2-6
#include <stdio.h>

int main(){
    int i, j; //반복을 위한 변수
    int sum; //둘의 합
    int count = 0; //몇 번 실행했는지 보기 위한 변수

    count = 0;

    for(i=9; i<=90; i+=9)
    {
        for (j = 90; j >= 9; j-=9) 
        {
            sum= i + j;

            if(sum == 99)
            {
                printf("%02d+%02d=%d\n", i, j, sum);
                //continue; //필요한 부분이 실행 됐으면 다음으로 넘기기 위한 continue 
            }
            count ++;
        }
        
    }
    printf("count:%d\n", count);
    return 0;
}