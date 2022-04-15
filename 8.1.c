#include <stdio.h>

#define this_year 2021
int birthday(int b);
// 파라미터 : 태어난 년도 (b)
// 리턴값:연령대에따른번호-유아0,어린이1,청소년2,청년3,중년4, 노년5
// 수행내용 : 태어난 년도를 통해 연령대를 계산하고, 연령대에 따른 번호 리턴
 
int main(void){
    int birth_year;     // 입력받은 태어난 년도
    int year[100]={};      // 각 사람들의 생년 (최대 100명)  
    int count_person = 0;   // 입력된 인원 수
    int count[6]={};       // 6가지 연령대별 숫자
    int i = 0;              // variable for loop

    while (1){
        printf("%d번째 사람의 태어난 년도를 입력하시오. ", i + 1);
        scanf("%d", &birth_year);
        if (birth_year > 2020){
            break;
        }
        year[i] =this_year - birth_year + 1;
        count[birthday(birth_year)]++;
        count_person ++;
        i++;
    }

    for ( i = 0; i < count_person; i++){
        printf("%d번째 사람의 나이는 %d입니다.\n", i + 1, year[i]);
    }
    
    for ( i = 0; i < 6; i++){
        if (i == 0){
            printf("유아는 %d명입니다.\n", count[i]);
        }
        if (i == 1){
            printf("어린이는 %d명 입니다.\n", count[i]);
        }
        if (i == 2){
            printf("청소년은 %d명 입니다.\n", count[i]);
        }
        if (i == 3){
            printf("청년은 %d명 입니다.\n", count[i]);
        }
        if (i == 4){
            printf("중년은 %d명 입니다.\n", count[i]);
        }
        if (i == 5){
            printf("노년은 %d명 입니다.\n", count[i]);
        }
    }
    


    return 0;
}

int birthday(int b){
    int age = this_year - b + 1;
    if (age < 7){
        return 0; //toddler
    }
    else if(age < 13){
        return 1; //child
    }
    else if (age < 20){
        return 2; //청소년
    }
    else if (age < 30){
        return 3; //청년
    }
    else if (age < 60){
        return 4; //중년
    }
    else{
        return 5; //노년
    }
}