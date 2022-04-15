#include <stdio.h>
#include <stdlib.h>

struct score_struct{
    int kor, eng, math;
    int sum;
    float avg;
    char grade;
};

struct score_struct* get_score();
// Execution: Get and store Korean, English, and math scores in a dynamically allocated structure and return a pointer to this structure.

void eval_score(struct score_struct* p);
// Parameter: pointer to structure
// Return value: none
// Execution: Receive a structure pointer, calculate and store the total score, average, and grade for each student

int main(){
    struct score_struct* scores[5]; 
    int i; 

    for(i=0; i<5; i++){
        printf("Student %d: Korean, English, Math: ", i+1);
        scores[i] = get_score();
        eval_score(scores[i]);
    }

    for(i=0; i<5; i++){
        printf("Student %d: Total %d, Average %.1f (Grade %c)\n", i+1, scores[i]->sum, scores[i]->avg, scores[i]->grade);
    }
    
    return 0;
}

struct score_struct* get_score(){
    struct score_struct* p = (struct score_struct*)malloc(sizeof(struct score_struct));
    scanf("%d %d %d", &p->kor, &p->eng, &p->math);
    return p;
}

void eval_score(struct score_struct* p){
    p->sum = p->kor + p->eng + p->math;
    p->avg = p->sum/3.0;
    if (p->avg  >= 90) p->grade = 'A';
    else if (p->avg  >= 80) p->grade = 'B';
    else if (p->avg  >= 70) p->grade = 'C';
    else if (p->avg  >= 60) p->grade = 'D';
    else p->grade = 'F';
}