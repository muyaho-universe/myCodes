#include <stdio.h>

int main(){
    int birth_year; //태어난 년
    int age; //나이
    
    printf("Birth year? ");
    scanf("%d", &birth_year);

    age = 2021 - birth_year + 1;

    if (age < 20){
        printf("미성년자입니다.");
    }
    else {
        printf("미성년자가 아닙니다.");
    }

    return 0;
}