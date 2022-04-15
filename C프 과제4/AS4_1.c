//21800059 김대석 나대영교수님 c프로그래밍 01분반 과제 4-1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_matrix(int a[4][5], int b[4][5]);
//parameter: 2차원 배열 2개
//what to do:생성된 배열 2개의 값을 화면에 출력
//return: none

void Matrixoper(int a[4][5], int b[4][5], char c);
//parameter: 2 차원 배열 2 개, 문자 1 개(합인지 차인지 결정하는 문자)
//what to do:2 차원 배열 2 개를 받아 연산과 연산결과를 출력
//return: none

int main(){
    int a[4][5], b[4][5];   //4 행 5 열의 배열 2 개
    char pm;                //사용자로부터 plus인지 -인지 받는 변수
    int i,j;                  //variable for loop

    srand(time(0));

    for ( i = 0; i < 4; i++){
        for ( j = 0; j < 5; j++){
            a[i][j] = rand()%(10 - 1 + 1)+1;
            b[i][j] = rand()%(30 - 21 + 1)+21;
        }
    }
    while (1){
        printf("input operator: ");
        scanf("%c", &pm); 
        while (getchar() != '\n');
        if (pm == '+' || pm == '-') break;
        else printf("Input Error! Please input \'+\' or \'-\'.\n");   
    }

    print_matrix(a, b);

    printf("============== RESULT ==================\n");
    Matrixoper(a, b, pm);
    return 0;
}

void print_matrix(int a[4][5], int b[4][5]){
    int n = 0;          //variable for making it work if statement
    int i=0,j;            //variable for loop
    
    while (i < 4){
        for ( j = 0; j < 5; j++) printf("%-2d   ", a[i][j]);
        printf("        ");
        for ( j = 0; j < 5; j++) printf("%-2d   ", b[i][j]);
        printf("\n");
        i++;
    }
}

void Matrixoper(int a[4][5], int b[4][5], char c){
    int i, j;
    int temp[4][5];     //array to print the result of calculating
    if (c == '+'){
        for ( i = 0; i < 4; i++){
            for ( j = 0; j < 5; j++){
                temp[i][j] = a[i][j] + b[i][j];
            }
        }
    }
    else if (c == '-'){
        for ( i = 0; i < 4; i++){
            for ( j = 0; j < 5; j++){
                temp[i][j] = a[i][j] - b[i][j];
            }
        }
    }
    
    for ( i = 0; i < 4; i++){
        for ( j = 0; j < 5; j++){
            printf("%-6d", temp[i][j]);
            if(i<3 && j==4) printf("\n");
        }
    }
}