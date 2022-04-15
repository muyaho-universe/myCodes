#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int NUM = 1;

struct Score{
    int num;
    char name[20];
    int score[3];
    int sum;
    float avg;
};

struct Score* get_score();

void readScore(struct Score *s[], int count);
struct Score* updateScore(int selectNum);
void deleteScore(struct Score *s[], int i);

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
    struct Score* s[20];
    int count = 0, menu;
    int isUpdated, isAdd, isDel;
    int selectedNum;
    int go;
 
    while (1){
        if (count ==20) break;
        
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            printf("No Name Kor Eng Math Sum Avg \n");
            printf("================================\n");
            readScore(s, count);
        }
        else if (menu == 2){
            s[count] = get_score();
            NUM++;
            count++;
        }
        else if (menu == 3){
            printf("No Name Kor Eng Math Sum Avg \n");
            printf("================================\n");
            readScore(s, count);
            printf("\n��ȣ�� (��� :0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            s[selectedNum-1] = updateScore(selectedNum);
            printf("=> ������!\n");
        }
        else if (menu == 4){
            printf("No Name Kor Eng Math Sum Avg \n");
            printf("================================\n");
            readScore(s, count);
            printf("\n��ȣ�� (��� :0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            printf("������ �����Ͻðڽ��ϱ�?(���� :1)");
            scanf("%d", &go);
            if (go != 1) continue;
            for (int i = selectedNum; i < count; i++)
            {
                deleteScore(s, i);
            }
            count--;
            printf("=> ������!\n");
            }
    }
    printf("�����!\n");
    return 0;
}

void readScore(struct Score *s[], int count){
    for (int i = 0; i < count; i++)
    {
        if(s[i]->score[0] != -1){
            printf("%d %5s %4d %4d %4d %5d %5.1f\n", s[i]->num, s[i]->name, s[i]->score[0], s[i]->score[1], s[i]->score[2], s[i]->sum, s[i]->avg);
        }
        else{
            continue;
        }
    }
}


struct Score* updateScore(int selectNum){
    
    struct Score* p = (struct Score*)malloc(sizeof(struct Score));
    p->num = selectNum ;
    char temp[20];
    printf("�̸���?");
    scanf("%s", temp);
    printf("�����?");
    scanf("%d", &p->score[0]);
    printf("�����?");
    scanf("%d", &p->score[1]);
    printf("������?");
    scanf("%d", &p->score[2]);

    strcpy(p->name,temp);
    p->sum = p->score[0] + p->score[1] + p->score[2];
    p->avg = p->sum / 3.0;

    return p;
}

void deleteScore(struct Score *s[], int i){
    if (i == NUM) return;
    strcpy(s[i-1]->name,s[i]->name);
    s[i-1]->num = s[i]->num; 
    for (int j = 0; j < 3; j++)
    {
        s[i-1]->score[j] = s[i]->score[j];
    }
    s[i-1]->sum = s[i]->sum;
    s[i-1]->avg = s[i]->avg; 
}

struct Score* get_score(){
    
    struct Score* p = (struct Score*)malloc(sizeof(struct Score));

    p->num = NUM ;
    printf("�̸���?");
    scanf("%s", p->name);
    printf("�����?");
    scanf("%d", &p->score[0]);
    printf("�����?");
    scanf("%d", &p->score[1]);
    printf("������?");
    scanf("%d", &p->score[2]);

    p->sum = p->score[0] + p->score[1] + p->score[2];
    p->avg = p->sum / 3.0;

    return p;
}