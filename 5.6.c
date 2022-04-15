/*This code is for 
    Daeseok Kim 21800059 Oct 2nd, 2021 */

#include <stdio.h>

int main(){
    int jumsu[5][3]; //2D array storing the scores of 5 students in 3 subjects
    int sum_student[5] ={0}; // total score per student
    float average_student[5] ={0.0}; // average per student
    char grade[5]; // grade by student
    int sum_class[3] ={0}; //Total score for each subject
    float average_class[3] = {0.0}; // Average by subject
    int i, j; //variable for loop

    for ( i = 0; i < 5; i++){
        printf("Student %d: Korean, English, and math scores? ", i + 1);
        scanf("%d %d %d", &jumsu[i][0], &jumsu[i][1], &jumsu[i][2]);    
        sum_class[0] += jumsu[i][0]; //국어 점수의 학급 전체 합
        sum_class[1] += jumsu[i][1]; //영어 점수의 학급 전체 합
        sum_class[2] += jumsu[i][2]; //수학 점수의 학급 전체 합
    }
    
    average_class[0] =  sum_class[0] / 5.0; //국어 점수의 학급 전체 평균
    average_class[1] =  sum_class[1] / 5.0; //영어 점수의 학급 전체 평균
    average_class[2] =  sum_class[2] / 5.0; //국어 점수의 학급 전체 평균
    printf("\n");
    printf("1) Total and average scores for each subject\n");
    printf("As for Korean, the total and average scores are %d and %.1f.\n", sum_class[0], average_class[0]);
    printf("As for English, the total and average scores are %d and %.1f.\n", sum_class[1], average_class[1]);
    printf("As for Math, the total and average scores are %d and  %.1f.\n", sum_class[2], average_class[2]);

    printf("2) The total and average scores, and grade for each student\n");
    for ( i = 0; i < 5; i++){
        for ( j = 0; j < 3; j++){
            sum_student[i] += jumsu[i][j]; 
        }
        average_student[i] = sum_student[i] / 3.0;
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

        printf("Student %d: total %d and average %.1f (Grade %c)\n", i + 1, sum_student[i], average_student[i], grade[i]);
    }
    


    return 0;
}