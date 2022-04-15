#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 10
#define S_NUM 1
#define E_NUM 99

int main(){
    int data[ROW][10];
    int i, j;
    int count =0;
    srand(time(0));
    printf("===============data===================\n");
    for ( i = 0; i < ROW; i++){
        for ( j = 0; j < 10; j++){
            data[i][j] = rand()%(E_NUM - S_NUM + 1) + S_NUM;
            printf("%02d ", data[i][j]);
        }
        printf("\n");
    }
    
    printf("\n=============Odd list==========\n");
    for ( i = ROW-1; i >=0 ; i--){
        for ( j = 9; j >= 0; j--){
            if (data[i][j]%2 == 1) {
                printf("%d %d: %-2d", i, j, data[i][j]);
                count++;
            }
            if (count == 5) {
              printf("\n");
              count = 0;
            }
        }
        
    }
    
    return 0;
}