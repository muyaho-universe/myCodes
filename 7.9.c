#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define student 5
#define class 3
#define Maxscore 100
#define Minscore 50
int main(void){
    int scores[student][class];            // 2D array storing the scores of 5 students in 3 subjects 
    char classname[class][20]={"Korean","English","Mathematics"};
    int sum_student[student] = {};         // total score for each student
    float average_student[student] = {};   // average by student
    char grade[student];              // grade by student
    int sum_class[class] = {};           // total score for each subject
    float average_class[class] ={};     // average by subject
    int i, j; // variable for loop

    srand(time(0));
    for ( i = 0; i < student; i++){
        for ( j = 0; j < class; j++){
            scores[i][j] = rand()%(Maxscore - Minscore + 1)+Minscore;
        }
    }
    printf("5 student scores were generated.\n");
    for ( i = 0; i < student; i++){
        printf("Student %d: ", i+1);
        for ( j = 0; j < class; j++){
            printf("%s %d",classname[j], scores[i][j]);
            if (j != class - 1){
                printf(", ");
            }
            else{
                printf("\n");
            } 
        }
    }

    printf("1) Total and average scores for each subject\n");

    for ( i = 0; i < class; i++){
        for ( j = 0; j < student; j++){
            sum_class[i] += scores[j][i];
        }
        average_class[i] = (float) sum_class[i] / student;
        printf("%s: %d and %.1f.\n", classname[i], sum_class[i], average_class[i]);
    }

    printf("2) The total and average scores for each student, and grade\n");

    for ( i = 0; i < student; i++){
        for ( j = 0; j < class; j++){
            sum_student[i] += scores[i][j];
        }
        average_student[i] = (float) sum_student[i] / class;
        if (average_student[i] >= 90){
            grade[i] = 'A';
        }
        else if (average_student[i] >= 80){
            grade[i] = 'B';
        }
        else if (average_student[i] >= 70){
            grade[i] = 'C';
        }
        else if (average_student[i] >= 60){
            grade[i] = 'D';
        }
        else{
            grade[i] = 'F';
        }
        printf("Student %d: %d and %.1f (Grade %c)\n", i + 1, sum_student[i], average_student[i], grade[i]);
    }
    return 0;
}