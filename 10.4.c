#include <stdio.h>

float get_max(float num[], int size);
// Parameters: num[]: number array, size: number of elements in the array
// Returns: the largest value in the array of numbers

float get_min(float num[], int size);
// Parameters: num[] : number array, size : number of elements in the array
// Returns: the smallest value in the array of numbers.

int main(void) {
    float number[10]; 
    float max, min;
    float sum = 0, avg;
    int i;  //variable for loop

    FILE* data;
    data = fopen("data.txt", "r");
    for ( i = 0; i < 10; i++){
        fscanf(data, "%f", &number[i]);
        printf("%d", i + 1);
        if(i == 0) printf("st ");
        else if(i == 1) printf("nd ");
        else if(i == 2) printf("rd ");
        else printf("th ");
        printf("score: %.1f\n", number[i]);
        sum += number[i];
    }
    max = get_max(number, 10);
    min = get_min(number, 10);
    sum = sum - max - min;
    avg = sum / 8.0;
    printf("The average for the eight scores is %.1f.", avg);
    return 0;
}

float get_max(float num[], int size){
    float max = num[0];
    int i;
    for ( i = 1; i < size; i++){
        if (num[i] > max) max = num[i];
    }
    return max;
}

float get_min(float num[], int size){
    float min = num[0];
    int i;
    for ( i = 1; i < size; i++){
        if (num[i] < min) min = num[i];
    }
    return min;
}