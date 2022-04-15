#include <stdio.h>

int main() {

    int birth_year; //태어난 년도
    int age; //나이

    printf("Birth year? ");
    scanf("%d",&birth_year);

    age = 2021 - birth_year + 1;

    if (age<7)
    {
        printf("유아입니다.");
    }
    
    else if (age < 13)
    {
        printf("어린이입니다.");
    }
    
    else if (age < 20)
    {
        printf("청소년입니다.");
    }
    
    else if (age < 30)
    {
        printf("청년입니다.");
    }

    else if (age < 60)
    {
        printf("중년입니다.");
    }

    else{
        printf("노년입니다.");
    }

    return 0;
}