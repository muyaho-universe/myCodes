#include <stdio.h>

int markbingo(int num, int b[]);
// Parameters: selected cell number (num), bingo matrix (b)
// Return value:
//     already marked 0,
//     it was not marked, but it has just got marked, and bingo is completed 1,
//     it was not marked, and just got marked, but bingo is incomplete -1,
// Execution: mark the cell after checking the cell corresponding to the cell number, and check if bingo is complete.
void printbingo(int b[]);
// Parameter: bingo matrix (b)
// Return value: none
// Execution: print the current bingo matrix

int main(void) {
	int bingo[25]={0}; // bingo matrix
    int num;    // input number by user
    int go = 1;
    int result;
    int i, j;
    

    printf("Enter a number(1~25) > ");
    scanf("%d",&num);
    if (num >= 1 && num <= 25){
        markbingo(num, bingo);
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
            result = markbingo(num, bingo);
            if(result == 1){
                printf("Bingo!\n");
                break;   
            }
            else if (result == 0){
                printf("Duplicate!\n");
            }
            else continue;
        }
    }

    printf("BINGO MATRIX\n");

    printbingo(bingo);

    return 0;

}

int markbingo(int num, int b[]){
    int i;
    int sum = 0;
    int col = 0;
    int row = 0;
	if (* (b + num - 1) == 1) return 0;
    
    else{
        *(b + num - 1) = 1;
        row = (num - 1) % 5;
        col = ((num - 1) / 5) * 5;
        for ( i = row; i < 25; i += 5) sum += b[i];
        if (sum == 5) return 1;
        else sum = 0;

        for ( i = col; i < col + 5; i++) sum += b[i];
        
        if (sum == 5) return 1;
        else return -1;
    }
    
	
}

void printbingo(int b[]){
    for(int i = 0; i < 21; i++) printf("-");
    printf("\n");

    for ( int i = 0; i < 25; i++){
        printf("| %d ", b[i]);
        if(i % 5 == 4) printf("|\n");
    }
	for(int i = 0; i < 21; i++) printf("-");
        printf("\n");
}