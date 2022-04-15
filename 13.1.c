#include <stdio.h>
#include <stdlib.h>

struct bmi_struct{
    int height, weight; 		
    float bmi; 				
    int bmi_index; 			// 1,2,3,4 --> underweight, normal, overweight, obese. 
};

int load_bmi(struct bmi_struct* list[], char* filename);
// Parameter: file name to read
// Return value: the number of created structure data sets
// Execution: Read the height and weight data from the file and put them in the list pointer array, each of which allocates memory for a structure (bmi_struct) to store height, weight, bmi, bmi_index. Then the number of completed data is returned.

void eval_bmi(struct bmi_struct* p);
// Parameter: Pointer to body fatness structure
// Return value: none
// Execution: Store bmi and bmi_index calculated by height and weight in the same structure.  

int main(void) {
    struct bmi_struct* bmilist[50];  // at most 50 
    char *bmi_string[4]={"underweight", "normal", "overweight", "obese"};
    int count = load_bmi(bmilist, "data.txt");
    int i, index;
    
    for ( i = 0; i < count; i++){
        index = bmilist[i]->bmi_index - 1;
        printf("#%d Height: %d, Weight: %d, BMI: %.1f, BMI Index: %s\n", i + 1, bmilist[i]->height, bmilist[i]->weight, bmilist[i]->bmi, bmi_string[index]);
    }
    for(i = 0; i < count; i++) free(bmilist[i]);
	return 0;
}

int load_bmi(struct bmi_struct* list[], char* filename){
    FILE * fp;
    fp = fopen(filename, "r");
    int i = 0;
    while (!feof(fp)){
        int t_height, t_weight;     //temporary variable for reading from file
        int t = fscanf(fp,"%d %d", &t_height, &t_weight);
        if (t <= 0) break;
        list[i] = (struct bmi_struct*) malloc(sizeof(struct bmi_struct));
        list[i]->height = t_height;
        list[i]->weight = t_weight;
        eval_bmi(*(list+i));
        i++;
    }
    fclose(fp);
    printf("We read data from %d people.\n", i);
    return i;
}

void eval_bmi(struct bmi_struct* p){
	p->bmi = (float) p->weight / ( (p->height * 0.01) * (p->height * 0.01));
    if (p->bmi < 18.5) p->bmi_index = 1;
    else if (p->bmi < 23) p->bmi_index = 2;
    else if (p->bmi < 25) p->bmi_index = 3;
    else p->bmi_index = 4;
}