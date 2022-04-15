#include <stdio.h>
void maxMinOfTen(int number[10], int* max, int* min);
// Parameter: Array of numbers input (number), and pointers to max and min.
// Return value: none
// Execution: Find the largest and smallest numbers in the received array and store them in the max and min pointer variables.

int main(void) { 
    int num[10];      // array for 10 numbers
    int max_num;      // max number 
    int min_num;      // min number
    char *ordinals[3] = {"st", "nd", "rd"}; 

    for(int i=0;i<10;i++){
        if(i<3) printf("Enter %d%s number ", i+1, ordinals[i]);
        else printf("Enter %dth number ", i+1);
        scanf("%d", &num[i]); 
    }
    maxMinOfTen(num, &max_num, &min_num);
    printf("The max and min values are %d and %d.\n", max_num, min_num); 
    return 0;
}

void maxMinOfTen(int number[10], int* max, int* min){
    int i;
    *max = number[0];
    *min = number[0];
    for ( i = 1; i < 10; i++){
        if (number[i] >= *max) *max = number[i];
        else if (number[i] <= *min) *min = number[i];
    }
}

