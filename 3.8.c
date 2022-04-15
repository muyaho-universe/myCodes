#include <stdio.h>

int main(void) {
  int dan; // Number of multiplication tables to be printed
  int i; // variable for iteration
  int k = 0; // key

  while (k == 0){
    printf("Enter a number for multiplication table (2~9). ");
    scanf("%d", &dan);

    if(dan < 2 || dan > 9){
      printf("Incorrect input.\n");
    }
    else{
      for(i = 1; i <= 9; i++){
        printf("%d x %d = %d\n", dan, i, dan*i);       
      }
      k = 1; // end of loop
    }
  }
  return 0;
}