#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "score.h"


int selectMenu(){
    int menu;
    printf("\n*** �������� ***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("5. ��������\n");
    printf("6. �̸��˻�\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}

struct Score* get_score(int count){
    struct Score* p = (struct Score*)malloc(sizeof(struct Score));

    p->num = count ;
    printf("�̸���?");
    scanf("%s", p->name);
    printf("�����??");
    scanf("%d", &p->score[0]);
    printf("�����??");
    scanf("%d", &p->score[1]);
    printf("������?");
    scanf("%d", &p->score[2]);
    p->sum = p->score[0] + p->score[1] + p->score[2];
    p->avg = p->sum / 3.0;
    printf("=> �߰���!\n");
    return p;
}

void readScore(struct Score *s[], int count){
    printf("No Name Kor Eng Math Sum Avg \n");
    printf("================================\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d %5s %4d %4d %4d %5d %5.1f\n", s[i]->num, s[i]->name, s[i]->score[0], s[i]->score[1], s[i]->score[2], s[i]->sum, s[i]->avg);
    }
}

struct Score* updateScore(int selectNum){
    struct Score* p = (struct Score*)malloc(sizeof(struct Score));
    p->num = selectNum ;
    char temp[20];
    printf("�̸���?");
    scanf("%s", temp);
    printf("�����??");
    scanf("%d", &p->score[0]);
    printf("�����??");
    scanf("%d", &p->score[1]);
    printf("������?");
    scanf("%d", &p->score[2]);

    strcpy(p->name,temp);
    p->sum = p->score[0] + p->score[1] + p->score[2];
    p->avg = p->sum / 3.0;

    return p;
}
void deleteScore(struct Score *s[], int i, int count){
    if (i == count) return;
    strcpy(s[i-1]->name,s[i]->name);
    s[i-1]->num = s[i]->num; 
    for (int j = 0; j < 3; j++)
    {
        s[i-1]->score[j] = s[i]->score[j];
    }
    s[i-1]->sum = s[i]->sum;
    s[i-1]->avg = s[i]->avg;
}
void searchData(struct Score *s[], int count){
    char data[20];
    int go = 0;
    printf("�˻��� �̸���? ");
    scanf("%s", data);
    printf("No Name Kor Eng Math Sum Avg \n");
    printf("================================\n");
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < strlen(s[i]->name); j++)
        {
            if (s[i]->name[j] == data[0])
            {
                for (int k = 1; k < strlen(data); k++)
                {
                    if (s[i]->name[j+k] != data[k])
                    {
                        go = 0;
                        break;
                    }
                    else go = 1;
                }                
            }
        }
        if (go == 1)
        {
            printf("%d %5s %4d %4d %4d %5d %5.1f\n", s[i]->num, s[i]->name, s[i]->score[0], s[i]->score[1], s[i]->score[2], s[i]->sum, s[i]->avg);
        }
        go = 0;   
    }
    
}
int load_score(struct Score* p[], char* filename){
    FILE * fp;
    int i = 0;
    if(fp = fopen(filename, "r"))
    {
        while (!feof(fp)){
            int t_num;
            int t_kor, t_eng, t_math;     //temporary variable for reading from file
            char t_name[20];
            int t = fscanf(fp,"%d %s %d %d %d", &t_num, t_name, &t_kor, &t_eng, &t_math);
            if (t <= 0) break;
            p[i] = (struct Score*) malloc(sizeof(struct Score));
            strcpy(p[i]->name, t_name);
            p[i]->num = t_num;
            p[i]->score[0] = t_kor;
            p[i]->score[1] = t_eng;
            p[i]->score[2] = t_math;
            p[i]->sum = t_kor + t_eng + t_math;
            p[i]->avg = p[i]->sum / 3.0;
            i++;
        }
        printf("=> �ε� ����!\n");
        fclose(fp);
    }
    else{
        printf("\n=> ���� ����\n");
    }
    
    return i;
}
void save_score(struct Score* list[], char* filename, int count){
    FILE * fp;
    fp = fopen(filename, "w");
    for ( int i = 0; i < count; i++){
        fprintf(fp,"%d %s %d %d %d\n", i + 1, list[i]->name, list[i]->score[0], list[i]->score[1], list[i]->score[2]);
    }
    fclose(fp);
    printf("�����?!\n");
}