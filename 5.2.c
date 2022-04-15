/*This code is showing the number of obesity
    Daeseok Kim Oct 1st, 2021 */

#include <stdio.h>

int main(){
    int height[10], weight[10]; //Height (cm), weight (kg) of 10 people
    float bmi[10]; // Obesity figures for 10 people
    int count = 0; // number of obese people
    float height_sq[10];
    int i; //variable fo loop

    for(i = 0; i < 10; i++){
        printf("Person %d: height and weight? ", i + 1);
        scanf("%d %d", &height[i], &weight[i]);

        height_sq[i] = height[i] * 0.01 * height[i] * 0.01;
        bmi[i] = weight[i] / height_sq[i];

        
    }
    printf("\n");
    printf("\n");
    for(i = 0; i < 10; i++){
      if (bmi[i] >= 25){
          printf("Person %d is obese.\n", i + 1);
          count ++;
      }
    }

    printf("In total, %d people are obese.", count);

    return 0;
}