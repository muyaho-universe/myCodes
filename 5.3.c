/*This code is for calculating the score
    Daeseok Kim 21800059 Oct 2nd, 2021 */

#include <stdio.h>

int main(){
    float score[10]; //test score
    float max = 0, min = 0; // highest score, smallest score
    float total = 0; //total score
    float average = 0; //average score
    int i; //variable for loop

    for ( i = 0; i < 10; i++){
        printf("score %d? ", i+1);
        scanf("%f", &score[i]);
        if ( i == 0){
          max = score[0];
          min = score[0];
        }
        if (score[i] > max){
            max = score[i];
        }
        if ( score[i] < min){
            min = score[i];
        }
        total += score[i];
    }
    
    average = (total - (max + min)) / 8.0;
    printf("\n");
    printf("The average without the largest and smallest scores is %.1f.", average);

    return 0;
}