#include <stdio.h>

int main(){
    int family; //number of families
    int children, adult, senior; //Number of children, adults, and seniors per family
    int all_children=0, all_adult=0, all_senior=0; //Sum of total children, adults, and seniors
    int i, j; //variable for the loop

    printf("What is the total number of families? ");
    scanf("%d", &family);
    if(family == 0 ){
      printf("The numbers for all families are as follows:\n");
    }
    else{
      for (i = 1; i <= family; i++){
          printf("What is the number of children, adults, and seniors in family #%d? ", i); //gain number for each members
          scanf("%d %d %d", &children, &adult, &senior);
          j=1;
          while (j <= children){ //print @ by the number of children
            printf("@");
            j++;
            all_children ++;
          }
          if(children > 0){
            printf(" ");
          }
          j=1;
          while (j <= adult){ //print # by the number of adult
            printf("#");
            j++;
            all_adult ++;
          }
          if(adult > 0){
            printf(" ");
          }
        
          j=1;
          while (j <= senior){ //print $ by the number of senior
            printf("$");
            j++;
            all_senior ++;
          }
          printf("\n");
      }
      printf("The numbers for all families are as follows:\n");
      while (j <= all_children){
        printf("@");
        j++;
      }
      j = 1;
      if(all_children > 0){
          printf(" ");
      }

      j=1;
      while (j <= all_adult){
        printf("#");
        j++;
      }
      if(all_adult > 0){
          printf(" ");
      }
    
      j=1;
      while (j <= all_senior){
        printf("$");
        j++;
      }
    }
    return 0;
  }