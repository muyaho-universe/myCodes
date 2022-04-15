/*This code is for 
    Daeseok Kim 21800059 Oct 2nd, 2021 */

#include <stdio.h>

int main(){
    int number[5][3]; // 각 집의 거주자 수
    int floor_total[5] = {0}; // 층별 거주자 합계 (1층, 2층, 3층, 4층, 5층)
    int line_total[3] = {0}; // 호수별 거주자 합계 (1호라인, 2호라인, 3호라인)
    int total = 0; // 아파츠의 총 거주자 수
    int ho; // 아파트 호를 나타내는 변수
    int i, j; // 반복문 사용을 위한 변수

    for ( i = 0; i < 5; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%d0%d호에 살고 있는 사람의 수? ", i + 1, j + 1);
            scanf("%d", &number[i][j]);
            if (j + 1 == 1) //1호 라인에 사는 사람의 수
            {
                line_total[j] += number[i][j];
            }
            else if (j + 1 == 2) //2호 라인에 사는 사람의 수
            {
                line_total[j] += number[i][j];
            }
            else //3호 라인에 사는 사람의 수
            {
                line_total[j] += number[i][j];
            }

            if (i + 1 == 1) //1층에 사는 사람의 수
            {
                floor_total[i] += number[i][j];
            }
            else if (i + 1 == 2) //2층에 사는 사람의 수
            {
                floor_total[i] += number[i][j];
            }
            else if (i + 1 == 3) //3층에 사는 사람의 수
            {
                floor_total[i] += number[i][j];
            }
            else if (i + 1 == 4) //4층에 사는 사람의 수
            {
                floor_total[i] += number[i][j];
            }
            else //5층에 사는 사람의 수
            {
                floor_total[i] += number[i][j];
            }

            total += number[i][j]; //전체 인원
        }
  
    }
    
    printf("\n");

    for( i = 0; i < 5; i++)
    {
       printf("%d층에 살고 있는 사람의 수 %d\n", i + 1, floor_total[i]); //i층에 사는 사람의 수 출력
    }

    printf("\n");

    for ( ho = 0; ho < 3; ho++)
    {
        printf("%d호 라인에 살고 있는 사람의 수 %d명\n", ho + 1, line_total[ho]);
    }

    printf("\n");

    printf("이 아파트에 사는 사람 모두 %d명", total);

    return 0;
}