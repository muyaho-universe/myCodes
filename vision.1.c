#include <stdio.h>

int main(){
    int num1, num2;
    int count = 0;
    int k = 1;

    scanf("%d %d", &num1, &num2);
    for (int i = 1; i <= num1; i++){
        if (num1 % i == 0){
            count++;
            if (count == num2){
                printf("%d", i);
                k = 0;
                break;
            }
        }
    }
    
    if (k) printf("0");
    return 0;
}