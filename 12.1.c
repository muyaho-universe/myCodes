#include <stdio.h>
#include <stdlib.h>

struct bmi_struct{
    int height, weight; 
    float bmi;  
    int bmi_index; // 1,2,3,4 --> underweight, normal, overweight, obese. 
};

struct bmi_struct * add_bmi ();
// Parameters: None
// Return value: structure pointer to bmi_struct allocated for weight, bmi, bmi_index. 

void eval_bmi (struct bmi_struct * p);
// Parameters: bmi_struct pointer
// Return value: None
// Execution: save the bmi, and bmi_index to the structure that p is pointing. 

int main(void) {
    struct bmi_struct* one;
	char *bmi_string[4]={"underweight", "normal", "overweight", "obese"};

	one = add_bmi();

	printf("Height: %d, ", one->height);
	printf("Weight: %d, ", one->weight);
	printf("BMI: %.1f, ", one->bmi);    
    printf("BMI Index: %s\n", bmi_string[one->bmi_index-1]);
    free(one);
	return 0;
}

struct bmi_struct* add_bmi(){
    struct bmi_struct* p = (struct bmi_struct*)malloc(sizeof(struct bmi_struct));
    printf("Height and weight? ");
    scanf("%d %d", &(p->height), &(p->weight));
    eval_bmi(p);
    return p;
}

void eval_bmi(struct bmi_struct* p){
	p->bmi = (float) p->weight / ( (p->height * 0.01) * (p->height * 0.01));
    if (p->bmi < 18.5) p->bmi_index = 1;
    else if (p->bmi < 23) p->bmi_index = 2;
    else if (p->bmi < 25) p->bmi_index = 3;
    else p->bmi_index = 4;
}
