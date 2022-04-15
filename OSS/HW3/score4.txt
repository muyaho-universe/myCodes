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
void searchData(struct Score *s[], int count);
int load_score(struct Score* p[], char* filename);
void save_score(struct Score* list[], char* filename, int count);

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int main(void){
    struct Score* s[20];
    int count = 0, menu;
    int isUpdated, isAdd, isDel;
    int selectedNum;
    int go;
    char filename[100]="score.txt";
    

    count = load_score(s, filename);
    if (count != 0)
    {
        NUM = count + 1;
    }
    
    while (1){
        if (count ==20) break;

        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            readScore(s, count);
        }
        else if (menu == 2){
            s[count] = get_score();
            count++;
        }
        else if (menu == 3){
            readScore(s, count);
            printf("\n번호는 (취소 :0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            s[selectedNum-1] = updateScore(selectedNum);
            printf("=> 수정됨!\n");
        }
        else if (menu == 4){
            readScore(s, count);
            printf("\n번호는 (취소 :0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &go);
            if (go != 1) continue;
            for (int i = selectedNum; i < count; i++)
            {
                deleteScore(s, i);
            }
            count--;
            printf("=> 삭제됨!\n");
        }
        else if(menu == 5){
            save_score(s, filename, count);
            
        }
        else if (menu == 6){
            searchData(s, count);
        }
        
    }
    printf("종료됨!\n");
    return 0;
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
    printf("이름은?");
    scanf("%s", temp);
    printf("국어는?");
    scanf("%d", &p->score[0]);
    printf("영어는?");
    scanf("%d", &p->score[1]);
    printf("수학은?");
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
    printf("이름은?");
    scanf("%s", p->name);
    printf("국어는?");
    scanf("%d", &p->score[0]);
    printf("영어는?");
    scanf("%d", &p->score[1]);
    printf("수학은?");
    scanf("%d", &p->score[2]);

    p->sum = p->score[0] + p->score[1] + p->score[2];
    p->avg = p->sum / 3.0;
    printf("=> 추가됨!\n");
    return p;
}

void searchData(struct Score *s[], int count){
    char data[20];
    int go = 0;
    printf("검색할 이름은? ");
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
        printf("=> 로딩 성공!\n");
        fclose(fp);
    }
    else{
        printf("\n=> 파일 없음\n");
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
    printf("저장됨!\n");
}