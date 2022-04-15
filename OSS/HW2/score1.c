#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];
    int score[3];
} Score;
 
int addScore(Score *s);
void readScore(Score s);
int updateScore(Score *s);
int deleteScore(Score *s);

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int main(void){
    Score s;
    int count = 0, menu;
    
    int isUpdated, isAdd, isDel;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            printf("Name Kor Eng Math Sum Avg \n");
            readScore(s);
        }
        else if (menu == 2){
            isAdd = addScore(&s);
        }
        else if (menu == 3){
            isUpdated = updateScore(&s);
            if (isUpdated == 1)
                printf("=> 수정성공!\n");
        }
        else if (menu == 4){
            isDel = deleteScore(&s);
            if (isDel == 1)
                printf("=> 삭제됨!\n");
        }
        count++;
    }
    printf("종료됨!\n");
    return 0;
}

void readScore(Score s){
    int sum = 0;
    if(s.score[0] != -1){
      for (int i = 0; i < 3; i++)
        {
            sum += s.score[i];
        }
        float avg = sum /3.0;
        printf("%5s %4d %4d %4d %5d %5.1f\n", s.name, s.score[0], s.score[1], s.score[2], sum, avg);
    }
    else{
        printf("\n");
    }
    
}

int addScore(Score *s){
    printf("이름은?");
    scanf("%s", s->name);
    printf("국어는?");
    scanf("%d", &s->score[0]);
    printf("영어는?");
    scanf("%d", &s->score[1]);
    printf("수학은?");
    scanf("%d", &s->score[2]);
    return 1;
}

int updateScore(Score *s){
    printf("이름은?");
    scanf("%s", s->name);
    printf("국어는?");
    scanf("%d", &s->score[0]);
    printf("영어는?");
    scanf("%d", &s->score[1]);
    printf("수학은?");
    scanf("%d", &s->score[2]);
    return 1;
}

int deleteScore(Score *s){
    strcpy(s->name,"");
    for (int i = 0; i < 3; i++)
    {
        s->score[i] = -1;
    }
    return 1;
}