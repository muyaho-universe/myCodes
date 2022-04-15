#include <stdio.h>

#define rows 5
#define columns 5

int mark_Bingo(int num, int b[columns][rows]);
//Parameters: selected cell number (num), bingo matrix (b)
//Return value: it was already marked, 0, it was unmarked and just marked, 1.
// Execution: mark the cell after checking the cell corresponding to the cell number

void print_Bingo(int b[columns][rows]);
// Parameter: bingo matrix (b)
// Return value: none
// Execution: express the contents of the current bingo matrix

int main(void) {
	int bingo[columns][rows]={0}; // bingo matrix
    int i;  //variable for loop
    int x, y; // coordinate of bingo
    int num;    // input number by user
    int go = 1; //making the loop work

    printf("Enter a number(1~25) > ");
    scanf("%d",&num);
    if (num >= 1 && num <= 25){
        for ( i = 1; i <= 5; i++){
            if(num == 5 * i){
                x = (num- 1) / 5;
                y = 4;
            }
            else{
                x = num / 5;
                y = (num % 5) - 1;
            }
        }
        bingo[x][y] = 1;
    }
    else{
        printf("EXIT!\n");
        go = 0;
    }

    while (go){
        printf("Enter a number(1~25) > ");
        scanf("%d",&num);
        if (num < 1 || num > 25){
            printf("EXIT!\n");
            break;
        }
        else{
            if(!mark_Bingo(num, bingo)){
                printf("Duplicate!\n");   
            }
        }
    }
    printf("BINGO MATRIX\n");

    print_Bingo(bingo);

    return 0;
}

int mark_Bingo(int num, int b[columns][rows]){
    int x, y;
	for ( int i = 1; i <= 5; i++){
        if(num == 5 * i){
            x = (num - 1) / 5;
            y = 4;
        }
        else{
            x = num / 5;
            y = (num % 5) - 1;
        }
    }
    if (b[x][y] == 1){
        return 0;
    }
    else{
        b[x][y] = 1;
        return 1;
    }
}

void print_Bingo(int b[columns][rows]){
    for(int i = 0; i < 21; i++){
        printf("-");
    }
    printf("\n");
    for ( int i = 0; i < columns; i++){
        for( int j = 0; j < rows; j ++){
            printf("| %d ", b[i][j]);
        }
        printf("|\n");
        for(int k = 0; k < 21; k++){
            printf("-");
        }
        printf("\n");
    }
}
