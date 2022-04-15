#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A 65
#define Z 90
#define zero 48
#define nine 57

int main(void){
    srand(time(0));
	char code[10][20];
    int i, j; // variable for loop

    for ( i = 0; i < 10; i++){
        for ( j = 0; j < 3; j++){
            code[i][j] = rand()%(Z - A + 1)+A;
        }
        code[i][3] = '-';
    }
    for ( i = 0; i < 10; i++){
        code[i][4] = rand()%(nine - zero)+(zero + 1);
        for ( j = 5; j < 10; j++){
            code[i][j] = rand()%(nine - zero + 1)+(zero);
        }
    }
    
    printf("10개의 코드가 생성되었습니다.\n");
    for( i = 0; i < 10; i++){
        for( j = 0; j < 10 ; j++){
            printf("%c", code[i][j]);
        }
        printf("\n");
    }
	return 0;
}