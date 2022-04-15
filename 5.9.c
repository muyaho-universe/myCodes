#include <stdio.h> 

int main(void) {
  int i,j;
  int score;
  int count = 0;
  char names[5][20]={"James", "David", "Simon", "Peter", "Jason"}; // student names
  int sheet[5][10]; // answers from students
  int answer[10]={1,2,3,4,1,2,3,4,3,2}; // correct answer
  int grade[5]; // student grades
  char grade_name[5][20]={"James", "David", "Simon", "Peter", "Jason"}; //students names for each grade

  for(i=0;i<5;i++){
    printf("Enter %s's sheet >> ", names[i]); 
    for(j=0;j<10;j++)
      scanf("%d", &sheet[i][j]); //10 answers from ith student
  }
  
  for(i = 0; i < 5; i++){
    for(j = 0; j < 5; j++){
      if(sheet[i][j] == answer[j]){
        score++;
      }    
    }
    if(score >= 9){
      grade[i] = 1;
    }
    else if(count >= 7){
      grade[i] = 2;
    }
    else{
       grade[i] = 3;
    }
  }

  printf("\n");
  printf("Grade result\n");
  printf("1st: ");
  for(i = 0; i < 5; i++){
    if(grade[i] == 1){
      
      
    }
  }

  return 0; 
}