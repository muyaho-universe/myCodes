// do not modify the main function!!!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int used[50]={0}; // Whether or not numbers are used (0: unused, 1: used). For example, if number 9 is used in bingo, used[8]=1!
// In this function, the number of the selected cell is checked and marked (changed to 0), and then the result is returned by checking whether the bingo is complete.
// At this time, the completion of bingo means a case in which all elements of a row, column or diagonal line are marked as 0.
// Use the used[] array declared as a global variable to check the selected 25 numbers.

int markbingo(int num, int b[25]);
// * Parameters: selected cell number (num), bingo matrix (b)
// * Return value: 
//   * already marked: 0, 
//   * it was not marked, but it has just got marked, and bingo is completed: 1,
//   * it was not marked, and just got marked, but bingo is incomplete: -1,
//   * the number is not in the bingo matrix: -2.
// * Execution: mark the cell after checking the cell corresponding to the cell number, and check if bingo is complete.
// From this function, you might have to print out one of the followings depending on the situation.  
//   - Bingo! ?th row // the row is filled!
//   - Bingo! ?th column // the column is filled!
//   - Bingo! Diagonal // the diagonal is filled!
//   - Duplicated! // This field is already marked as 0
//   - Not in there! // the number is not in the bingo matrix. 

void shufflebingo(int b[25]);
// * Parameter: Bingo matrix (b) 
// * Return value: None
// * Execution: Randomly shuffle the elements of the current bingo matrix. The method of shuffling is to select two cells at random and exchange the values of the two cells about 50 times. In this case, use the used[] array declared as a global variable to register the selected 25 numbers.

void printbingo(int b[25]);

int main(void) {
  int bingo[25]; 	// bingo matrix
	int count=0; 		// number of tries
	int number; 		// input number 
	int check; 			// whether bingo is complete or not.  
	srand(time(0)); 		
	shufflebingo(bingo);  	// shuflling the bingo matrix.
  while(1){
		printf("Enter a number(1~50) > ");
		scanf("%d", &number);
		if((number<1||number>50)) {
		printf("EXIT!");
		break;
    }
		else {
			check = markbingo(number, bingo);
			if(check!=0) count++;
			if(check==1) break;
		}
	}
	printbingo(bingo); 	
	printf("%d tries!\n", count);
	return 0;

}

int markbingo(int num, int b[25]){
	int point;      // the point that the number indicates
	int row, col;
	int sum = 0;
	int k = 0;
	int i, j;      //variable for loop

	for ( i = 0; i < 25; i++){
    if(num == b[i]) {
		point = i;
		used[num] = -2;
		break;
    }
  }

	if(used[num] != -2 && used[num] != 1){
		printf("Not in there!\n");
		return -2;
	}
  else{
		if (used[num] == 1){
			printf("Duplicated!\n");
			return 0;
		}
		else used[num] = 1;

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

void printbingo(int b[25]){
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

void shufflebingo(int b[25]){
    int temp;
    int f_change, s_change;     // two numbers which change their position
    int i = 0, j;                      // variable for loop

    while (i < 25){
		b[i] = rand()%(50 - 1 + 1) + 1;
		for ( j = 0; j < i; j++){
			if (b[j] == b[i]){
				i --;
				break;
			}
		}
		i ++;
	}
  for ( i = 0; i < 50; i++){
    f_change = rand()%25;
    s_change = rand()%25;
    temp = b[f_change];
    b[f_change] = b[s_change];
    b[s_change] = temp;
  }
}