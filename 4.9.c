#include <stdio.h>

int main() {
    int size; // size
    int i, j; //variable for the loop

    printf("size? ");
    scanf("%d", &size);
    if (size % 2 == 1){ //odd size
        for (i = 1; i <= size; i++){
            if (i == (size+1)/2){ //mid line
                for ( j = 1; j <= size-i; j++){
                    printf(" ");
                }
                for ( j = 1; j <= (2*i-1); j++){ //midline
                    printf("*");
                }
                for ( j = 1; j <= size - i; j++){
                    printf(" ");
                }
                printf("\n");
            }
            else{
                for ( j = 1; j <= size-i; j++){
                    printf(" ");
                }
                if(i==1){ //first line tip
                  printf("*");
                }
                else{ //other lines
                  printf("*");
                  for ( j = 1; j <= (2*i-3); j++){
                    printf(" ");
                  }
                  printf("*");
                }
                
                for ( j = 1; j <= size-i; j++){
                    printf(" ");
                }
                printf("\n");
            }                
        }    
    }
    else{ //even case
        for (i = 1; i <= size; i++){
            if (i == (size+2)/2){ //mid line
                for ( j = 1; j <= size-i; j++){
                    printf(" ");
                }
                for ( j = 1; j <= (2*i)-1; j++){ //midline
                    printf("*");
                }
                for ( j = 1; j <= size - i; j++){
                    printf(" ");
                }
                printf("\n");
            }
            else{
                for ( j = 1; j <= size-i; j++){
                    printf(" ");
                }
                if(i==1){ //first line tip
                  printf("*");
                }
                else{ //other lines
                  printf("*");
                  for ( j = 1; j <= (2*i-3); j++){
                    printf(" ");
                  }
                  printf("*");
                }
                
                for ( j = 1; j <= size-i; j++){
                    printf(" ");
                }
                printf("\n");
            }                
        }
      
    }
    return 0;
}