#include <stdio.h>

int main(){
    int height; //height
    int blank; //blank
    int i, j; //variable for the loop

    printf("height? ");
    scanf("%d", &height);

    printf("blank? ");
    scanf("%d", &blank);
    
    for ( i = 1; i <= height; i++){
        for ( j = 1; j <= blank; j++){
            printf(" ");
        }
        for ( j = 1; j <= height - i; j++){
            printf(" ");
        }
        for ( j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
        
 
    }
    return 0;

}