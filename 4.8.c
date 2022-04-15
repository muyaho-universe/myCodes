#include <stdio.h>

int main() {
    int height; //height
    int i,j; //variable for the loop

    printf("height? ");
    scanf("%d", &height);

    for ( i = 1; i <= height; i++){
        for ( j = 1; j <= height-i; j++){
            printf(" ");
        }
        for ( j = 1; j <= (2*i-1); j++){
            printf("*");
        }
        for ( j = 1; j <= height-i; j++){
            printf(" ");
        }
        printf("\n");
        
        
    }
    

    return 0;
}