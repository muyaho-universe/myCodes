#include <stdio.h>

int main() {
    int count_all; // 가족 인원수
    int count_young = 0; // 미성년자의 수
    int birth_year; //태어난 년도
    int age; //age
    int i; // 반복을 위한 변수

    printf("가족 인원수? ");
    scanf("%d", &count_all);
    
    for (i = 0; i < count_all; i++)
    {
        printf("Birth year? ");
        scanf("%d", &birth_year);
        age =  2021 - birth_year + 1;

        if (age < 20)
        {
            count_young = count_young + 1;   
        }
        age = 0 ;
    }

    printf("가족들 중 미성년자는 모두 %d명입니다.", count_young);    


    return 0;

}