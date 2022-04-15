/*This code is for 
    Daeseok Kim 21800059 Oct 3rd, 2021 */

#include <stdio.h>

int main(){
    int number[10] = {0};  // 10 numbers entered by the user
    int count = 0; // Number of numbers entered so far (0~10)
    int i, j; // variable for loop

    printf("Enter 10 numbers between 1 and 100.\n");
    printf("Enter number 1: ");
    scanf("%d", &number[0]);
    for (i = 1; i <10; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &number[i]);
        count ++;
        
        for ( j = 0; j < count; j++)
        {
            if ( number[j] == number[i])
            {
                printf("You entered it incorrectly. Please re-enter.\n");
                printf("Enter number %d: ", i + 1);
                scanf("%d", &number[i]);
                
            }
            
        }   
    }
    printf("\n");
    printf("The numbers are");
    for (i = 0; i <9; i++){
        printf(" %d,", number[i]);
    }
    printf(" %d", number[9]);
    printf(".");

    return 0;
}