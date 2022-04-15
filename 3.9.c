#include <stdio.h>

int main(void) {
  int num1, num2; // two numbers entered
  int i; // variable for iteration
  int j = 1;
  int k = 1;
  i = 0;

  printf("Enter 2 numbers ");
  scanf("%d %d", &num1, &num2);
  printf("\n");

  for(i = 1; i <= 100; i++){
      if(num1 * k >= num2 * j){ 
        if(num2 * j > 101) break;
      }
      else{
        if(num1 * k > 101) break;
      }    
      if(num1 * k >= num2 * j){
        if((num2 * j) % num1 != 0){
        printf("%d\n",num2*j);
        }
        j++;
      }
      else{
        if((num1 * k) % num2 != 0){
          printf("%d\n",num1*k);
                    
        }
        k++;
        
      }

  
  }
  return 0;
}
