#include <stdio.h>

#define rows 5
#define columns 5

int markBingo(int num, int b[columns][rows]);
//파라미터 : 선택된 칸번호(num), 빙고매트릭스(b)
//리턴값 : 이미 마크되어 있었음 0, 마크 안되어 마크하였는데 빙고 완성됨 1, 마크 안되어 마크하였는데 빙고는 미완성 -1,
//수행내용 : 현재의 빙고매트릭스에 선택된 칸번호에 해당되는 칸 검사한 후 마크함

void printBingo(int b[columns][rows]);
//파라미터 : 빙고매트릭스(b)
//리턴값 : 없음 
//수행내용 : 현재의 빙고매트릭스 내용 표현

int main(void) {
	int bingo[columns][rows]={0}; // bingo matrix
    int i; //variable for loop
    int x, y; // coordinate of bingo
    int num;    // input number by user
    int go = 1; //making the loop work
    int result;  //get return value from other function

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
            result = markBingo(num, bingo);
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

    printBingo(bingo);

    return 0;
}

int markBingo(int num, int b[columns][rows]){
    int x, y;
    int i;
    int count;
    int sum = 0;
    if(num == 5 || num == 10 || num == 15 || num == 20 || num == 25){
        x = num / 5 - 1;
        y = 4;
    }
    else{
        x = num / 5;
        y = num % 5 - 1;
    }
    
    if (b[x][y] == 1){
        return 0;
    }
    else{
        b[x][y] = 1;
    }
    if (x == y || x + y == 4){

        for ( i = 0; i < rows; i++) sum += b[x][i];
        if (sum == 5) return 1;
        else sum = 0;

        for ( i = 0; i < columns; i++) sum += b[i][y];
        if (sum == 5) return 1;
        else sum = 0;
        
    
        for ( i = 0; i < 5; i++) sum += b[i][i];
        if (sum == 5) return 1;
        else sum = 0;

        for ( i = 0; i < 5; i++) sum += b[i][4 - i];
        if (sum == 5) return 1;
        else return -1;
    }

    else{
        for ( i = 0; i < rows; i++) sum += b[x][i];
        if (sum == 5) return 1;
        else sum = 0;

        for ( i = 0; i < columns; i++) sum += b[i][y];
        if (sum == 5) return 1;
        else return -1;
    }
}

void printBingo(int b[columns][rows]){
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