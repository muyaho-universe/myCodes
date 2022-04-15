#include <stdio.h>
float evalBmi(int h, int w);
// Parameters: h: height (in cm), w: weight (in kg)
// Return value: obesity
// Execution: Calculate and return the degree of obesity using the height and weight received as parameters.

int main(void) {
    float height, weight, bmi;
    int count=0;
    int i;  //variable for loop

    FILE * fp;
    fp = fopen("data.txt", "r");

    for ( i = 0; i < 5; i++){
        fscanf(fp, "%f %f", &height, &weight);
        printf("Person %d: height (cm) and weight (kg): %.0f %.0f\n", i + 1, height, weight);
        bmi = evalBmi(height, weight);
        if (bmi >= 25) count ++;
        printf("%.1f\n", bmi);
    }

    printf("%d people are obese.\n", count); 
    fclose(fp);
    return 0;
}

float evalBmi(int h, int w){
    float result;
    result = w / (float) ((h * 0.01) * (h * 0.01));
    return result;
}