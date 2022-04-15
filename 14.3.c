#include <stdio.h>

int ackermann(int i, int j); 

int main(){
    int i, j;
    int num;
    for ( i = 0; i < 4; i++){
        for ( j = 0; j < 4; j++){
            num = ackermann(i, j);
            printf("Ackermann(%d, %d) = %d\n", i, j, num);
        }
    }
    return 0;
}

int ackermann(int i, int j){
    if (i == 0 && j >= 0) return j + 1;
    else if (i > 0 && j == 0) return ackermann(i-1, 1);
    else return ackermann(i-1, ackermann(i, j-1));
}