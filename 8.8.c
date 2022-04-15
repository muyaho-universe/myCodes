#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define student 5
#define class 3
#define Maxscore 100
#define Minscore 50

int classsum(int s[student][class], int classnum);
// 파라미터 : 점수배열(s)과 과목번호(0,1,2) 
// 리턴값 : 해당 과목의 총점
int studentsum(int s[student][class], int classnum);
// 파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
// 리턴값 : 해당 학생의 총점
char studentgrade(int s[student][class], int classnum);
// 파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
// 리턴값 : 해당 학생의 등급 ('A','B','C','D','F')

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
        sum_class[i] = classsum(scores, i);
        average_class[i] = (float) sum_class[i] / student;
        printf("%s: %d and %.1f.\n", classname[i], sum_class[i], average_class[i]);
    }
    
    printf("2) The total and average scores for each student, and grade\n");
    for ( i = 0; i < student; i++){
        sum_student[i] = studentsum(scores, i);
        average_student[i] = (float) sum_student[i] / class;
        grade[i] = studentgrade(scores, i);
        printf("Student %d: %d and %.1f (Grade %c)\n", i + 1, sum_student[i], average_student[i], grade[i]);
    }
    return 0;
}

int classsum(int s[student][class], int classnum){
	int sum_class = 0;
    for ( int i = 0; i < student; i++){
        sum_class += s[i][classnum];
    }
    return sum_class;
}
int studentsum(int s[student][class], int stunum){
    int sum_student = 0;
    for (int i = 0; i < class; i++){
        sum_student += s[stunum][i];
    }
	return sum_student;
}
char studentgrade(int s[student][class], int stunum){
	int sum_student = 0;
    for (int i = 0; i < class; i++){
        sum_student += s[stunum][i];
    }
    float avg_student = (float) sum_student / class;
    char grd;
    if (avg_student >= 90){
        grd = 'A';
    }
    else if (avg_student >= 80){
        grd = 'B';
    }
    else if (avg_student >= 70){
        grd = 'C';
    }
    else if (avg_student >= 60){
        grd = 'D';
    }
    else{
        grd = 'F';
    }
    return grd;
}