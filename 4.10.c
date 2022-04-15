#include <stdio.h>

int main() {
    int size; //size
    int i, j; //variable for the loop
    int a = 1; //makes loop work 
    printf("size? > ");
    scanf("%d", &size);

    for ( i = 1; i <= 2*size - 1; i++){
        if (i==size){ //mid line
            for ( j = 1; j <= 2*size; j++){
                printf("*");
            }
            printf("\n");
        }
        else if (i<size){ //upper lines
            for ( j = 1; j <= i; j++){
                printf("*");
            }
            for ( j = 1; j <= 2*size - 2*i ; j++){
                printf(" ");
            }
            for ( j = 1; j <= i; j++){
                printf("*");
            }          
            printf("\n");
        }
        else{ //lower lines
            for(j = 1; j <= i-2*a; j++){
              printf("*");
            }
            for(j = 1; j <= 2*size - 2* (i - 2 * a);j++){
              printf(" ");
            }
            for(j = 1; j <= i-2*a; j++){
              printf("*");
            }
            a++;
            printf("\n");
        }
        
        
    }
    
    return 0;
}