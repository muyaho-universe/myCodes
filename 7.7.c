#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define width 10
#define height 10
int main(void) {
    char plus='+'; //plus
    int num[width*height] = {}; // array for random number
    int num_s[width*height] = {}; //array for random number in series
    int size; // inputted size
    int a = 1; // indext for dots
    int i, j; // variable for loop
    
    printf("Enter size >> ");
    scanf("%d", &size);
    srand(time(0));
    i = 0; 
    while ( i < size){
        num[i] = rand()%100+1;
        for ( j = 0; j < i; j++){
            if (num[i] == num[j]){
                i --;
                break;
            }
        }
        i++;
    }

    for( i = 0; i < size; i++){
        for( j = 0; j < size; j++){

        }
    }
    
    j = 0;
    for ( i = 0; i < height*width; i++){
        for ( j = 0; j < size; j++){
            if(i == num[j] - 1){
                printf("@");
                a = 0;
            }
        }
       
        if (a){
            printf("+");
        }
        a = 1;
        if ((i + 1) % 10 == 0 && i != 0){
            printf("\n");
        }
        
    }
    
    return 0;
}