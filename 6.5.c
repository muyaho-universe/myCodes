#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char birthday[100]={'0'}; //entered birthday
    int sum = 0; //sum
    int num; //num
    int year, month, day; // entered year, month and day
    int i; //variable for loop

    printf("Enter your birthdate >> ");
    scanf("%s", birthday);
    birthday[strlen(birthday)] = '\0';
    
    num = atoi(birthday);
    
    year = num / 10000;
    num = num % 10000; 

    month = num / 100;
    num = num % 100;

    day = num;

    for (i = 1000; i >= 1; i /= 10){
        sum += year / i;
        year %= i;
    }g
    sum += month + day;
    
    printf("Your birthdate number is %d.", sum);

    return 0;
    
}