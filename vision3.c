#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int maxProduct(int* nums, int numsSize);

int main(){
    int numsize = 2*10*10*10*10;

    scanf("%d", &numsize);

    int ary[numsize];
    srand(time(0));
    for (int i = 0; i < numsize; i++)
    {
        ary[i] = rand()% 11;
        if (rand()%2) ary[i] *= -1;
    }
    
    int max;
    max = maxProduct(ary, numsize);
    printf("%d", max);
    return 0;   
}

int maxProduct(int* nums, int numsSize){
    int temp, max;
    max = nums[0] * nums[0+1];
    for (int i = 0; i < numsSize; i++) {
        temp = nums[i] * nums[i+1];
        if (max < temp) max = temp;
    }
    return max;
}