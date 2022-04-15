#include <stdio.h>

struct jumsu_struct{
    int kor, eng, math;
    int sum;
    float avg;
    char grade;
};

void sumClass(struct jumsu_struct p[], int* sum, float* avg, int i);
// Parameter: array of structures, sum pointer, avg pointer, and sub_i (type of subject: 0,1,2)
// Return value: none
// Execution: Receive a structure array and calculate the total score and average for the subject

void evalStudent(struct jumsu_struct* p);
// Parameter: pointer to structure
// Return value: none
// Execution: Receive the student's score structure pointer, calculate and store the total score, average, and grade

int main(void) {
    struct jumsu_struct p[5];
    FILE* data;
    int i = 0;
    int count=0;

    data = fopen("data.txt", "r");
    while(!feof(data)){
        fscanf(data, "%d %d %d", &p[i].kor, &p[i].eng, &p[i].math);
        evalStudent(p+i);
        i++;
        count ++;
    }
    int sum;
    float avg;
    for( i=0; i<3; i++){
        sumClass(p, &sum, &avg, i);
    }

    printf("%d student scores were generated.\n",count);

    for( i=0;i<count;i++){
        printf("Student %d: ",i+1); 
        for( int j=0;j<3;j++){
            if (j == 0) printf("Korean %d", p[i].kor); 
            else if (j == 1) printf("English %d", p[i].eng); 
            else printf("Mathematics %d", p[i].math); 
            if(j<2) printf(", ");
            else printf("\n");
        }
    }

    printf("1) Total and average scores for each subject\n"); 
    for( i = 0; i < 3; i++){
        sumClass(p, &sum, &avg, i);
        if( i == 0 ) printf("Korean: %d and %.1f.\n", sum, avg );
        else if( i == 1 ) printf("English: %d and %.1f.\n", sum, avg );
        else printf("Math: %d and %.1f.\n", sum, avg );
    }

    printf("2) The total and average scores for each student, and grade\n"); 
    for( i=0;i<count;i++){
        printf("Student %d: %d and %.1f (Grade %c)\n",i+1,p[i].sum,p[i].avg,p[i].grade); 
    }
    
    return 0;
}

void evalStudent(struct jumsu_struct* p){
    p->sum = p->kor + p->eng + p->math;
    p->avg = p->sum / 3.0;
    if (p->avg  >= 90) p->grade = 'A';
    else if (p->avg  >= 80) p->grade = 'B';
    else if (p->avg  >= 70) p->grade = 'C';
    else if (p->avg  >= 60) p->grade = 'D';
    else p->grade = 'F';
}

void sumClass(struct jumsu_struct p[], int* sum, float* avg, int i){
    * sum = 0;
    for (int j = 0; j < 5; j++) {
        if(i == 0) *sum += p[j].kor;
        else if (i == 1) *sum += p[j].eng;
        else *sum += p[j].math;
    }

    *avg = *sum / 5,0;
}