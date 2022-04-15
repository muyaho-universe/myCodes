#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int bingo[5][5]={0}; // 5*5 matrix
    int num; // entered number by user
    int i, j; //variable for loop
    int x, y; // coordinate of bingo
    int count = 1;
    int numbers[25] = {0};

    printf("Enter a number(1~25) > ");
    scanf("%d",&num);

    if (num >= 1 && num <= 25){
        numbers[0] = num;
        for ( i = 1; i <= 5; i++){
            if(num == 5 * i){
                x = (num - 1) / 5;
                y = 4;
            }
            else{
                x = num / 5;
                y = (num % 5) - 1;
            }
        }
        bingo[x][y] = 1;

        for ( i = 1; i < 25; i++){
            printf("Enter a number(1~25) > ");
            scanf("%d",&num);
            if (num > 25 || num < 1){
                printf("EXIT!");
                break;
            }

            j = 0;
            while (j < count){
                if (num == numbers[j]){
                    printf("Duplicate!\n");
                    
                    printf("Enter a number(1~25) > ");
                    scanf("%d", &num);
                    j = 0;
                }
                else{
                    j ++;
                }
            }
            j = 0;
            
            numbers[i] = num;
            
            if (num > 25 || num < 1){
                printf("EXIT");
                break;
            }
            
            else{
                for ( j = 1; j <= 5; j++){
                    if(num == 5 * j){
                        x = (num - 1) / 5;
                        y = 4;
                    }
                    else{
                        x = num / 5;
                        y = (num % 5) - 1;
                    }
                }
                bingo[x][y] = 1;              
            }
            count ++;
        }

    }
    else{
        printf("EXIT!");
    }
    printf("\n");
    printf("The current matrix is as follows:\n");

    for(i = 0; i < 21; i++){
        printf("-");
    }
    printf("\n");

    for(i = 0; i < 5; i ++){
        printf("| %d ", bingo[0][i]);
    }
    printf("|\n");

    for(i = 0; i < 21; i++){
        printf("-");
    }
    printf("\n");

    for(i = 0; i < 5; i ++){
        printf("| %d ", bingo[1][i]);
    }
    printf("|\n");

    for(i = 0; i < 21; i++){
        printf("-");
    }
    printf("\n");

    for(i = 0; i < 5; i ++){
        printf("| %d ", bingo[2][i]);
    }
    printf("|\n");

for(i = 0; i < 21; i++){
        printf("-");
    }
    printf("\n");

    for(i = 0; i < 5; i ++){
        printf("| %d ", bingo[3][i]);
    }
    printf("|\n");

    for(i = 0; i < 21; i++){
        printf("-");
    }
    printf("\n");

    for(i = 0; i < 5; i ++){
        printf("| %d ", bingo[4][i]);
    }
    printf("|\n");
    for(i = 0; i < 21; i++){
        printf("-");
    }
    printf("\n");
    
    return 0;
}