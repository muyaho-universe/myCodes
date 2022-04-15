#include <stdio.h>

int main(){
    int length; //Length of one side of the received square
    int i, j; //variabl for loop
    printf("Enter the size of the square. ");
    scanf("%d", &length);

    for(i = 1; i <= length; i++){
        for (j = 1; j <= length; j++){
            printf("#");
        }
        printf("\n");
    }
    
    
    return 0;
}