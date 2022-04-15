#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUB_N 3
#define STU_N 5

void evalClass(int j[STU_N][SUB_N], int i, int* s, float* a);
// Parameters: score array (scores) and course number (i=0,1,2), pointer variable to store total score (s), pointer variable to store average (a)
// Return value: none
// Execution: Receives the score array and course number, calculates and stores the total score and average

void evalStudent(int j[STU_N][SUB_N], int i, int* s, float* a, char* g);
// Parameters: score array (scores) and student number (i=0,1,2,3,4), pointer variable to store total score (s), pointer variable to store average (a), pointer variable to store grade (g= 'A','B','C','D','F')
// Return value: none
// Execution: Receives the score arrangement and course number, calculates and stores the total score, average, and grade

int main(void) {
    int score[STU_N][SUB_N]; // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
    char *classname[SUB_N]={"Korean","English","Math"};
    int sum = 0;    // total sum
    float avg = 0;  // average
    char grade;     // grade
    int i, j;       // for loops

    FILE* fp;
    fp = fopen("data.txt", "r");
    for ( i = 0; i < STU_N; i++){
        for ( j = 0; j < SUB_N; j++){
            fscanf(fp, "%d", &score[i][j]);
        }
    }
    

    for(i=0;i<5;i++){
        printf("Student %d: ",i+1); 
        for(j=0;j<3;j++){
            printf("%s %d", classname[j], score[i][j]); 
            if(j<2) printf(", ");
            else printf("\n");
        }
    }
    printf("1) Total and average scores for each subject\n"); 
    for(i=0;i<3;i++){
        evalClass(score, i, &sum, &avg);
        printf("%s: %d and %.1f\n",classname[i],sum,avg); 
    }
    printf("2) The total and average scores, and grade for each student\n"); 
    for(i=0;i<5;i++){
        evalStudent(score, i, &sum, &avg, &grade);
        printf("Student %d: %d and %.1f(grade %c)\n",i+1,sum,avg,grade); 
    }
    fclose(fp);
    return 0; 
}

void evalClass(int j[STU_N][SUB_N], int i, int* s, float* a){
    int k; // variable for loop
    * s = 0;
    for ( k = 0; k < STU_N; k++){
        * s += j[k][i];
    }
    * a = * s / 5.0;
}

void evalStudent(int j[STU_N][SUB_N], int i, int* s, float* a, char* g){
    int k; // variable for loop
    * s = 0;
    for ( k = 0; k < SUB_N; k++){
        * s += j[i][k];
    }
    * a = * s / 3.0;
    if (*a >= 90) * g = 'A'; 
    else if (*a >= 80) * g = 'B';
    else if (*a >= 70) * g = 'C';
    else if (*a >= 60) * g = 'D';
    else * g = 'F';
}