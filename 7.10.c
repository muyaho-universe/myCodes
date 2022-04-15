#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rows 5
#define columns 5
#define nums 10
#define first 1
#define last 25
int main(void) {
    int bingo[columns][rows]={0}; // 5*5 matrix
    int i, j, k; //variable for loop
    int x, y; // coordinate of bingo
    int numbers[nums] = {0};

    srand(time(0));
    numbers[0] = rand()%(last - first + 1) + first;
    i = 1;
    while ( i < nums){
        numbers[i] = rand()%(last - first + 1) + first;
        for (j = 0; j < i; j++){
            if (numbers[j] == numbers[i]){
                i--;
                break;
            }
            
        }
        i++;
    }
    // for( i = 0; i < nums; i++){
    //   printf("%d ", numbers[i]);
    // }
    // printf("\n");
    for ( i = 0; i < nums; i++){
        j = 1;
        while (j <= 5){
            if(numbers[i] == 5 * j){
                x = (numbers[i] - 1) / 5;
                y = 4;
            }
            else{
                x = numbers[i]/ 5;
                y = (numbers[i] % 5) - 1;
            }
            j++;    
        }
        bingo[x][y] = 1;
    }
    printf("The result of 10 cells randomly selected is as follows.\n");
    for(i = 0; i < 21; i++){
        printf("-");
    }
    printf("\n");
    for ( i = 0; i < columns; i++){
        for(j = 0; j < rows; j ++){
            printf("| %d ", bingo[i][j]);
        }
        printf("|\n");
        for(k = 0; k < 21; k++){
            printf("-");
        }
        printf("\n");
    }
    
    return 0;
}
    
    
