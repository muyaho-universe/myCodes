#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int markBingo(int num, int b[25]);
/*Parameters: selected cell number (num), bingo matrix (b)
 Return value: 
   already marked 0, 
   it was not marked, but it has just got marked, and bingo is completed 1,
   it was not marked, and just got marked, but bingo is incomplete -1,
 Execution: mark the cell after checking the cell corresponding to the cell number, and check if bingo is complete. */

void shuffleBingo(int b[25]);
// Parameter: Bingo matrix (b) 
// Return value: None
// Execution: Randomly shuffle the elements of the current bingo matrix.
void printBingo(int b[25]);


int main(void) { 
    int bingo[25];  // bingo matrix
    int count=0;    // the number of tries
    int number;     // input
    int check;      // whether bingo is complete or not
    int i;
    srand(time(0)); 
    // bingo initialization 
    for(i=0;i<25;i++) bingo[i]= i+1;

    shuffleBingo(bingo); // shuffling the bingo matrix
    printBingo(bingo);   // printing the bingo matrix
    while(1){
        printf("Enter a number(1~25) > "); 
        scanf("%d", &number); 
		if((number<1||number>25)) break;
		else {
			check = markBingo(number, bingo);
			if(check!=0) count++;
			if(check==1) break;
		}
	}
	printBingo(bingo); 
	printf("%d tries!\n", count);
	return 0;

}


int markBingo(int num, int b[25]){
    int point;      // the point that the number indicates
    int row, col;
    int sum = 0;
    int k = 0;
    int i, j;      //variable for loop

    for ( i = 0; i < 25; i++){
        if(num == b[i]) {
            point = i;
            break;
        }
    }
    
    if (b[point] == 0) {
        printf("Duplicated!\n");
        return 0;
    }
    else{
        b[point] = 0;
        col = point % 5;
        row = (point / 5) * 5;

        for ( i = col; i < 25; i += 5) sum += b[i];
        
        if (sum == 0){
            printf("Bingo! %d", col + 1);
            if(col == 0) printf("st column\n");
            else if(col == 1) printf("nd column\n");
            else if(col == 2) printf("rd column\n");
            else printf("th column\n");
            return 1;
        }
        else sum = 0;

        for ( i = row; i < row + 5; i++) sum += b[i];

        if (sum == 0){
            printf("Bingo! %d", row + 1);
            if(row == 0) printf("st row\n");
            else if(row == 1) printf("nd row\n");
            else if(row == 2) printf("rd row\n");
            else printf("th column\n");
            return 1;
        }
        else sum = 0;
        
        if(point == 0 || point == 6 || point == 12 || point == 18 || point == 24){
            for ( i = 0; i < 25; i+= 6) sum += b[i];
            if(sum == 0){
                printf("Bingo! Diagonal\n");
                k = 1;
            }  
        }
        if(k) return 1;
        else sum = 0;

        if(point == 4 || point == 8 || point == 12 || point == 16 || point == 20){
            for ( i = 4; i < 21; i+= 4) sum += b[i];
            if(sum == 0){
                printf("Bingo! Diagonal\n");
                k = 1;
            }  
        }
        if(k) return 1;
        else return -1; 
    }

}

void shuffleBingo(int b[25]){
    int temp;
    int f_change, s_change;     // two numbers which change their position
    int i;                      // variable for loop
    
    for ( i = 0; i < 50; i++){
        f_change = rand()%25;
        s_change = rand()%25;
        temp = b[f_change];
        b[f_change] = b[s_change];
        b[s_change] = temp;
    }
    
}

void printBingo(int b[25]){
	int i;
	printf("BINGO MATRIX\n");
	for(i=0;i<25;i++){
		if(i%5==0) 
			printf("--------------------------\n|");
		printf(" %2d |",b[i]);
		if(i%5==4) printf("\n");
	}
	printf("--------------------------\n");
}