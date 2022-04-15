#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int NUM = 1;

struct Menu{
    int num;
    int count[3];
    char name[20];
    char grade;
    char address[100];
    int price;
    char isDelete;
};

struct Menu*  addOrder();

void readOrder(struct Menu *s[], int count);
// struct Menu* updateOrder(int selectNum);
void deleteOrder(struct Menu *s[], int i);
void findname(struct Menu *s[], int count);
void saveData(struct Menu* s[], char* filename, int count);
void readOrder(struct Menu *s[], int count);

int selectMenu(){
    int menu;
    printf("\n*** ���ִ� �ѽ� ��� ***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("5. ����\n");
    printf("6. �����ڰ˻�\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}

int main(void){
    struct Menu* s[20];
    int count = 0, menu;
    int isUpdated, isAdd, isDel;
    int selectedNum;
    int go;
    char filename[20] ="orders.txt ";
 
    while (1){
        if (NUM ==20) break;
        
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            readOrder(s, count);
        }
        else if (menu == 2){
            s[count] = addOrder();
            NUM++;
            count++;
        }
        else if (menu == 3){
            
            // readOrder(s, count);
            // printf("\n��ȣ�� (��� :0)?");
            // scanf("%d", &selectedNum);
            // if (selectedNum == 0) continue;
            // s[selectedNum-1] = updateMenu(selectedNum);
            // printf("=> ������!\n");
        }
        else if (menu == 4){
            readOrder(s, count);
            printf("��ȣ�� (��� :0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            printf("������ �����Ͻðڽ��ϱ�?(���� :1) ");
            scanf("%d", &go);
            if (go != 1) continue;
            deleteOrder(s, selectedNum-1);
            
            printf("=> ������!\n");
        }
        else if(menu == 5){
            saveData(s, filename, count);
            printf("=> �����!\n");
        }
        else if (menu == 6){
            findname(s, count);
        }

    }
    printf("�����!\n");
    return 0;
}

void readOrder(struct Menu *s[], int count){
    int total = 0;
    printf("No  �޴����� ������ ��� ���� �ּ�\n");
    printf("================================\n");
    for (int i = 0; i < count; i++)
    {
        if (s[i]->isDelete == 'Y')
        {
            continue;
        }
        else{
            total++;
            printf("%d %d-%d-%d %s %c %d %s\n", s[i]->num, s[i]->count[0], s[i]->count[1], s[i]->count[2], s[i]->name, s[i]->grade, s[i]->price, s[i]->address);
        }   
    }
    printf("\n�� %d���� �ֹ��� �ֽ��ϴ�.\n", total);
}


// struct Score* updateOrder(int selectNum){
    
//     struct Score* p = (struct Score*)malloc(sizeof(struct Score));
//     p->num = selectNum ;
//     char temp[20];
//     printf("�̸���?");
//     scanf("%s", temp);
//     printf("�����?");
//     scanf("%d", &p->score[0]);
//     printf("�����?");
//     scanf("%d", &p->score[1]);
//     printf("������?");
//     scanf("%d", &p->score[2]);

//     strcpy(p->name,temp);
//     p->sum = p->score[0] + p->score[1] + p->score[2];
//     p->avg = p->sum / 3.0;

//     return p;
// }

void deleteOrder(struct Menu *s[], int i){
    s[i]->isDelete = 'Y';
}

struct Menu*  addOrder(){
    printf("**** �޴��� *****\n1. �����   8,000��\n2. ��ġ� 7,000��\n3. ��ġ���� 9,000��\n*********\n");
    struct Menu* p = (struct Menu*)malloc(sizeof(struct Menu));

    p->num = NUM ;
    printf("�޴��� ���� ? ");
    
    scanf("%d %d %d", &p->count[0], &p->count[1], &p->count[2]);
    printf("�����ڴ�? ");
    scanf("%s", p->name);
    while (getchar()!='\n'); 
    printf("������ �����(B,S,G) ? ");
    scanf("%c", &p->grade);
    while (getchar()!='\n'); 
    printf("��� �ּҴ� ? ");
    fgets(p->address, 100, stdin);
    p->address[strlen(p->address)-1] = '\0';
    p->price = 8000 * p->count[0] + 7000 * p->count[1] + 9000 * p->count[2];
    printf("�� �ֹ��� ���� ���� %d �Դϴ�.\n", p->price);
    p->isDelete = 'N';
   

    return p;
}

void findname(struct Menu *s[], int count){
    char data[100];
    int total = 0;
    printf("�˻��� �̸���? ");
    scanf("%s", data);
    while (getchar()!='\n'); 
    printf("No  �޴����� ������ ��� ���� �ּ�\n");
    printf("================================\n");
    for (int i = 0; i < count; i++)
    {
        if (strstr(s[i]->name, data) != NULL)
        {
            printf("%d %d %c %5s\n", s[i]->num, s[i]->price, s[i]->grade,s[i]->name);
            total++;
        }
        
    }
    printf("�� %d���� �ֹ��� �ֽ��ϴ�.\n", total);
    if (total == 0) printf("=> �˻��� ������ ����!\n");
    
}

// int loadData(struct Menu* p[], char* filename){
//     FILE * fp;
//     int i = 0;
//     if(fp = fopen(filename, "r"))
//     {
//         while (!feof(fp)){
//             int t_num;
//             int t_kor, t_eng, t_math;     //temporary variable for reading from file
//             char t_name[20];
//             int t = fscanf(fp,"%d %s %d %d %d", &t_num, t_name, &t_kor, &t_eng, &t_math);
//             if (t <= 0) break;
//             p[i] = (struct Menu*) malloc(sizeof(struct Menu));
//             strcpy(p[i]->name, t_name);
//             p[i]->num = t_num;
//             p[i]->score[0] = t_kor;
//             p[i]->score[1] = t_eng;
//             p[i]->score[2] = t_math;
//             p[i]->sum = t_kor + t_eng + t_math;
//             p[i]->avg = p[i]->sum / 3.0;
//             i++;
//         }
//         printf("=> �ε� ����!\n");
//         fclose(fp);
//     }
//     else{
//         printf("\n=> ���� ����\n");
//     }
    
//     return i;
// }

void saveData(struct Menu* s[], char* filename, int count){
    FILE * fp;
    fp = fopen(filename, "w");
    int t = 0;
    for ( int i = 0; i < count; i++){
        if (s[i]->isDelete == 'Y') continue;
        else{
            fprintf(fp,"%d %d-%d-%d %s %c %d %s\n", t + 1, s[i]->count[0], s[i]->count[1], s[i]->count[2], s[i]->name, s[i]->grade, s[i]->price, s[i]->address);
            t++;
        }
    
    }
    fclose(fp);
    printf("�����!\n");
}