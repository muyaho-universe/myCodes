#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int num;
    char name[20];
    int score[3];
} Score;
 
int addScore(Score *s, int Num);
void readScore(Score *s, int count);
int updateScore(Score *s);
int deleteScore(Score *s);

int selectMenu(){
    int menu;
    printf("\n*** �������� ***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}

int main(void){
    Score s[100];
    int count = 0, menu;
    int Num = 1;
    int isUpdated, isAdd, isDel;
    int selectedNum;
    int go;
 
    while (1){
        if (count == 20) break;
        
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            printf("No Name Kor Eng Math Sum Avg \n");
            printf("================================\n");
            readScore(s, Num);
        }
        else if (menu == 2){
            isAdd = addScore(&s[Num-1], Num);
            Num++;
            count++;
        }
        else if (menu == 3){
            printf("No Name Kor Eng Math Sum Avg \n");
            printf("================================\n");
            readScore(s, Num);
            printf("\n��ȣ�� (��� :0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            isUpdated = updateScore(&s[selectedNum-1]);
            if (isUpdated == 1)
                printf("=> ��������!\n");
        }
        else if (menu == 4){
            printf("No Name Kor Eng Math Sum Avg \n");
            printf("================================\n");
            readScore(s, Num);
            printf("\n��ȣ�� (��� :0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            printf("������ �����Ͻðڽ��ϱ�?(���� :1)");
            scanf("%d", &go);
            if (go != 1) continue;
            isDel = deleteScore(&s[selectedNum-1]);
            if (isDel == 1)
                printf("=> ������!\n");
            count--;
        }
        
    }
    printf("�����!\n");
    return 0;
}

void readScore(Score *s, int count){
    int sum = 0;
    for (int i = 0; i < count-1; i++)
    {
        sum = 0;
        if(s[i].score[0] != -1){
            for (int j = 0; j < 3; j++)
            {
                sum += s[i].score[j];
            }
            float avg = sum /3.0;
            printf("%d %5s %4d %4d %4d %5d %5.1f\n", s[i].num, s[i].name, s[i].score[0], s[i].score[1], s[i].score[2], sum, avg);
        }
        else{
            continue;
        }
    }
}

int addScore(Score *s, int Num){
    
    s->num = Num ;
    printf("�̸���?");
    scanf("%s", s->name);
    printf("�����?");
    scanf("%d", &s->score[0]);
    printf("�����?");
    scanf("%d", &s->score[1]);
    printf("������?");
    scanf("%d", &s->score[2]);
    return 1;
}

int updateScore(Score *s){
    char temp[20];
    printf("�̸���?");
    scanf("%s", temp);
    strcpy(s->name,temp);
    printf("�����?");
    scanf("%d", &s->score[0]);
    printf("�����?");
    scanf("%d", &s->score[1]);
    printf("������?");
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