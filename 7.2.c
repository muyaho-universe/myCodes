#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define num 6
#define start 1
#define end 45

int main(){
    
    int lotto[num] = {};  // computer generated lottery numbers
    int count = 0;     // The order of the lottery numbers currently being created (0, 1, 2, 3, 4, 5)
    char onemore[16];   // Input whether to repeat "Yes" or "No"
    int i = 1, j, k;         // variable for loop
    
    
    while (1){
        srand(time(0));
        lotto[0] = rand()%(end - start + 1)+start;
        while (i < num){
            lotto[i] = rand()%(end - start + 1)+start;
            for ( j = 0; j < i; j++){
                if (lotto[j] == lotto[i]){
                    i --;
                    break;
                }
            }
            i++;
        }
        printf("The generated lottery number is ");
        for ( i = 0; i < num; i++){
            printf("%d ", lotto[i]);
        }
        printf("\n");

        printf("Would you like to make more? (Yes/No) >> ");
        scanf("%s", onemore);

        if (strcmp(onemore,"No") == 0){
            break;
        }
        i = 0; 
    }
    return 0;


}