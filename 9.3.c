#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUB_N 3
#define STU_N 5

void evalClass(int j[STU_N][SUB_N], int i, int* s, float* a);
// 파라미터 : 점수배열(j)과 과목번호(i=0,1,2), 총점을 저장할 포인터변수(s), 평균을 저장할 포인터변수(a)
// 리턴값 : 없음
// 수행내용 : 점수배열과 과목번호를 받아서, 총점과 평균을 계산해 저장함

void evalStudent(int j[STU_N][SUB_N], int i, int* s, float* a, char* g);
// 파라미터 : 점수배열(j)과 학생번호(i=0,1,2,3,4),총점을 저장할 포인터변수(s), 평균을 저장할 포인터변수(a), 등급을 저장할 포인터변수(g='A','B','C','D','F')
// 리턴값 : 없음
// 수행내용 : 점수배열과 과목번호를 받아서, 총점과 평균, 등급을 계산해 저장함

int main(void) {
  int scores[STU_N][SUB_N];        // scores 
  char *classname[SUB_N]={"Korean","English","Math"};
  int sum;                // total sum
  float avg;              // average
  char grade;             // grade
  int i, j;               // for loops

  srand(time(0)); 
  for(i=0; i<STU_N; i++)
    for(j=0; j<SUB_N; j++)
      scores[i][j] = rand()%50 + 51;

  printf("%d students scores are generated\n", STU_N); 
  for(i=0; i<STU_N; i++){
    printf("Student %d: ",i+1); 
    for(j=0; j<SUB_N; j++){
      printf("%s %d", classname[j], scores[i][j]); 
      if(j<2) printf(", ");
      else printf("\n");
    } 
  }

  printf("1) Total and average scores for each subject\n"); 
  for(i=0; i<SUB_N; i++){
    evalClass(scores, i, &sum, &avg);
    printf("%s: %d and %.1f\n", classname[i], sum, avg);
  }

  printf("2) The total and average scores, and grade for each student\n"); 
  for(i=0; i<STU_N; i++){
    evalStudent(scores, i, &sum, &avg, &grade);
    printf("Student %d: %d and %.1f(grade %c)\n",i+1, sum, avg, grade); 
  }
  
  return 0; 
}

void evalClass(int s[STU_N][SUB_N], int i, int* s1, float* a){
    *s1 = 0;
    for (int j = 0; j < STU_N; j++)
        *s1 += s[j][i];
    *a = *s1 / (float) STU_N;
}

void evalStudent(int s[STU_N][SUB_N], int i, int* s2, float* a, char* g){
    *s2 = 0;
    for (int j = 0; j < SUB_N; j++)
        *s2 += s[i][j];
    *a = (float) *s2 / SUB_N;

    if (*a >= 90) *g = 'A';

    else if (*a >= 80) *g = 'B';
        
    else if (*a >= 70) *g = 'C';
        
    else if (*a >= 60) *g = 'D';
    
    else *g = 'F';
}