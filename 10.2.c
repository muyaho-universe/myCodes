#include <stdio.h>
void maxMinOfTen(int number[10], int* max, int* min);
// Parameter: Array of numbers input (number), and pointers to max and min.
// Return value: none
// Execution: Find the largest and smallest numbers in the received array and store them in the max and min pointer variables.

int main(void) { 
    int num[10];    // array for inputting 10 numbers
    int max_num;    // variable for returning the max number
    int min_num;    // variable for returning the min number
    char file[20];  // name of file
    int i;          // variable for loop

    FILE* fp;
    printf("Please enter a file name. ");
    scanf("%s", file);
    fp = fopen(file, "r");
    for ( i = 0; i < 10; i++){
        fscanf(fp, "%d", &num[i]);
    }

    max_num = num[0];
    min_num = num[0];

    maxMinOfTen(num, &max_num, &min_num);
    printf("The max and min values are %d and %d.\n", max_num, min_num);
     
    fclose(fp);
    return 0; 
}

void maxMinOfTen(int number[10], int* max, int* min){
    int i;      // variable for loop
    int temp_max, temp_min;
    for ( i = 0; i < 10; i++){
        temp_max = * max;
        temp_min = * min;
        if(number[i] > temp_max) * max = number[i];
        if(number[i] < temp_min) * min = number[i];
    }
}