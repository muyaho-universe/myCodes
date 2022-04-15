#include <stdio.h>

float evalBmi(int h, int w);
// h : height (in cm)
// w : weight (in kg)
// return value: bmi
// Execution: Calculate and return the degree of obesity using the height and weight received as parameters

struct st_bmi{
    int height, weight; // Height (cm), Weight (kg)
    float bmi; // obesity
    int bmi_index; // 1,2,3,4
};

int main(void) {
    struct st_bmi input;    //inputted values which is made of struct
    int i;                  //variable for loop

    input.bmi_index = 0;

    FILE * fp;
    fp = fopen("data.txt", "r");

    for ( i = 0; i < 5; i++){
        fscanf(fp, "%d %d", &input.height, &input.weight);
        printf("Person %d: height (cm) and weight (kg): %d %d\n", i + 1, input.height, input.weight);
        input.bmi = evalBmi(input.height, input.weight);
        if (input.bmi >= 25) input.bmi_index ++;
        
    }

    printf("%d people are obese.\n", input.bmi_index); 
    fclose(fp);
    return 0;
}

float evalBmi(int h, int w){
    float result;
    result = w / (float) ((h * 0.01) * (h * 0.01));
    return result;
}