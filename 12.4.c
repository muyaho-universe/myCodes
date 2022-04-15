#include <stdio.h>
#include <stdlib.h>

struct jumsu_struct{
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};

struct jumsu_struct* get_score();
// Execution: allocate memory space for the structure and save Korean, English and Math in it. 
// Return: the structure pointer. 

void eval_score(struct jumsu_struct* p);
// Parameters: Structure Pointer
// Return value: None
// Execution: Calcuate the total and average scores, and grade and save them in the structure.

// Do not modify the main function!! 
int main(){
	struct jumsu_struct* score = get_score();
	eval_score(score);
	printf("The total and average scores are %d and %.1f (Grade %c).\n",score->sum, score->avg, score->grade);
    free(score);
	return 0;
}

struct jumsu_struct* get_score(){
    struct jumsu_struct* p = (struct jumsu_struct*)malloc(sizeof(struct jumsu_struct));
    printf("Korean? ");
    scanf("%d", &p->kor);
    printf("English? ");
    scanf("%d", &p->eng);
    printf("Math? ");
    scanf("%d", &p->mat);
    return p;
}

void eval_score(struct jumsu_struct* p){
    p->sum = p->kor + p->eng + p->mat;
    p->avg = p->sum/3.0;
    if (p->avg  >= 90) p->grade = 'A';
    else if (p->avg  >= 80) p->grade = 'B';
    else if (p->avg  >= 70) p->grade = 'C';
    else if (p->avg  >= 60) p->grade = 'D';
    else p->grade = 'F';
}