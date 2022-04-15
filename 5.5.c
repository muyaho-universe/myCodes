/*This code is for calculating the day count of the year
    Daeseok Kim 21800059 Oct 2nd, 2021 */

#include <stdio.h>

int main(){
    int monthdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //Jan ~ Dec days
    int month, day; // month, day
    int day_count = 0; //day_count
    int i; //variable for loop

    printf("Month? ");
    scanf("%d", &month);
    printf("Day? ");
    scanf("%d", &day);

    if (month < 13 && month > 0) {
        if (day > monthdays[month - 1]){
            printf("잘못 입력하셨습니다.");
        }
        else{
            for ( i = 0; i < month - 1; i++){
                day_count += monthdays[i];
            }
            day_count += day;
            printf("이 날짜는 1년 중 %d번째 날에 해당", day_count);
        }
        
    }
    else{
        printf("잘못 입력하셨습니다.");
    }
    return 0;
}