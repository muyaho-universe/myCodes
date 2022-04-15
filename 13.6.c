#include <stdio.h>
#include <stdlib.h>
#define SUB_N 3

struct score_struct{
    int kor, eng, math;
    int sum;
    float avg;
    char grade;
};

int load_score(struct score_struct* p[], char* filename);
// Parameter: Array of pointers to structures to store the score list, data file name
// Return value: the number of students. 
// Execution: Creates a score structure through dynamic memory allocation while reading a file, receives and saves Korean, English, and math scores, and returns the number of created score lists

void eval_score(struct score_struct* p);
// Parameter: Pointer to the student's score structure
// Return value: none
// Execution: Receive a structure pointer, calculate and store the total score, average, and grade for each student

void eval_class(struct score_struct* p[], int sum[], float avg[]);
// Parameters: Score array (structure pointer array), total score array for each subject, average array for each subject
// Return value: none
// Execution: Receive an array of scores, calculate and store the total score and average for each of the three subjects.

int main(){
    struct score_struct* scores[10]; 	// at most 10 students. 
    int count; 
    int classsum[SUB_N]; 			
    float classavg[SUB_N]; 			
    char* classname[SUB_N]={"Korean","English","Math"};
    char filename[100]="data.txt"; 
    int i; 

    count = load_score(scores, filename);
    printf("%d student scores from the file\n", count);

    for(i=0; i<count; i++)
        eval_score(scores[i]);

    eval_class(scores, classsum, classavg);

    printf("1) Total and average scores for each subject\n");
    for(i=0; i<SUB_N; i++)
        printf("%s: %d and %.1f\n", classname[i], classsum[i], classavg[i]);

    printf("2) The total and average scores for each student, and grade\n");
    for(i=0; i<count; i++)
        printf("Student %d: %d and %.1f (Grade %c)\n", i+1, scores[i]->sum, scores[i]->avg, scores[i]->grade);

    return 0;
}

int load_score(struct score_struct* p[], char* filename){
    FILE * fp;
    fp = fopen(filename, "r");
    int i = 0;
    while (!feof(fp)){
        int t_kor, t_eng, t_math;     //temporary variable for reading from file
        int t = fscanf(fp,"%d %d %d", &t_kor, &t_eng, &t_math);
        if (t <= 0) break;
        p[i] = (struct score_struct*) malloc(sizeof(struct score_struct));
        p[i]->kor = t_kor;
        p[i]->eng = t_eng;
        p[i]->math = t_math;
        i++;
    }
    fclose(fp);
    return i;
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

void eval_class(struct score_struct* p[], int sum[], float avg[]){
    int i;
    for ( i = 0; i < SUB_N; i++){
        sum[i] = 0;
        avg[i] = 0.0;
    }
    
    i=0;
    while(1){
        if(p[i]->kor < 0 ||p[i]->kor > 100) break;      //score is from 0 to 100, so if some score is over 100 or under 0, it means it's dummy
        sum[0] += p[i]->kor;
        i++;
    }
    avg[0] = (float) sum[0] / i;
    i = 0;

    while(1){
        if(p[i]->eng < 0 ||p[i]->eng > 100) break;      //score is from 0 to 100, so if some score is over 100 or under 0, it means it's dummy
        sum[1] += p[i]->eng;
        i++;
    }
    avg[1] = (float) sum[1] / i;
    i = 0;

    while(1){
        if(p[i]->eng < 0 ||p[i]->eng > 100) break;      //score is from 0 to 100, so if some score is over 100 or under 0, it means it's dummy
        sum[2] += p[i]->math;
        i++;
    }
    avg[2] = (float) sum[2] / i;
}