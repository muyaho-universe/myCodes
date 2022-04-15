#include <stdio.h>
#include <math.h>

#define num 5

int main(){
    int number[num];        // 5 numbers entered
    double pow_value[num][num] = {};  // Values ​​of a^b that can be made with a and b
    double max = 4, min = pow(9, 9);         // max and min
    int max_a, max_b;     // values ​​of a and b for the largest
    int min_a, min_b;     // values ​​of a and b for the smallest
    int i, j;             // variable for loop

    printf("Enter 5 numbers between 2 and 9. ");
    scanf("%d %d %d %d %d", &number[0], &number[1], &number[2], &number[3], &number[4]);

    for ( i = 0; i < num; i++){
        for ( j = 0; j < num; j++){
            if(i == j) continue; 
            
            else{
                pow_value[i][j] = pow(number[i],number[j]);
            }
            
            
            
        }
    }
    
    for ( i = 0; i < num; i++){
        for ( j = 0; j < num; j++){
            if(i == j)continue;
            
            if (pow_value[i][j]>= max){
                max = pow_value[i][j];
                max_a = number[i];
                max_b = number[j];
            }
            if (pow_value[i][j] <= min){
                min = pow_value[i][j];
                min_a = number[i];
                min_b = number[j];
            }
        }
    }
    printf("\nIf you make a square number with the %d numbers you entered,\n", num);
    printf("the largest number is %d^%d (= %.0f), \n", max_a, max_b, max);
    printf("and the smallest number is %d^%d (= %.0f).\n", min_a, min_b, min);
    return 0;
    
}