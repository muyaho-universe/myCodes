//21800059 김대석 나대영교수님 c프로그래밍 01분반 과제 4-2

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void transMatrix(int a[][5], int s);
//parameter: 2차원 배열, 정수
//what to do: 행과 열중에 큰 값을 항상 행으로 하도록 2차원 배열을 변환하여 출력
//return: none

int main(){
    int size=0;                 //사용자로부터 입력받는 행의 크기
    int i, j;                   //variable for loop
    
    printf("행의 크기 입력: ");
    scanf("%d", &size);

    int a[size][5];

    srand(time(0));

    for ( i = 0; i < size; i++){
        for ( j = 0; j < 5; j++){
           a[i][j] = rand()%(10 - 0 + 1)+0;
        }
    }

    printf("배열 생성 결과 츌력.\n");
     for ( i = 0; i < size; i++){
        for ( j = 0; j < 5; j++){
            printf("%3d  ", a[i][j]);
            if(j == 4) printf("\n");
        }
    }

    printf("\n====================================\n");
    transMatrix(a, size);
    return 0;
}

void transMatrix(int a[][5], int s){
    int temp[5][s];             //temporary array for changing
    int i, j;

    if (s >= 5) printf("배열을 변환할 필요가 없습니다.");
    
    else{
        for ( i = 0; i < 5; i++){
            for ( j = 0; j < s; j++){
                temp[i][j] = a[j][i];
                printf("%3d  ", temp[i][j]);
                if(i <4 && j== (s -1)) printf("\n");
            }
        }
    }
}