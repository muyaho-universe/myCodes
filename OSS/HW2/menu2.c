#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int NUM = 1;

typedef struct{
    int num;
    char name[20];
    char type;
    int price;
} Pizza;
 
int addPizza(Pizza *s, int Num);
void readPizza(Pizza* s, int count);
int updatePizza(Pizza *s);
int deletePizza(Pizza *s, int i);

int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n");
    printf("1. �޴���ȸ\n");
    printf("2. �޴��߰�\n");
    printf("3. �޴�����\n");
    printf("4. �޴�����\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    while (getchar()!='\n');
    return menu;
}

int main(void){
    Pizza s[100];
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
            
            readPizza(s, count);
        }
        else if (menu == 2){
            isAdd = addPizza(&s[count], NUM);
            count++;
            NUM++;
        }
        else if (menu == 3){
            readPizza(s, count);
            printf("\n��ȣ��(���:0)?");
            scanf("%d", &selectedNum);
            while (getchar()!='\n');
            if (selectedNum == 0) continue;
            isUpdated = updatePizza(&s[selectedNum-1]);
            if (isUpdated == 1)
                printf("=> ��������!\n");
        }
        else if (menu == 4){
            readPizza(s, count);
            printf("\n��ȣ��(���:0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            printf("������ �����Ͻðڽ��ϱ�?(���� :1)");
            scanf("%d", &go);
            if (go != 1) continue;
            for (int i = selectedNum; i < count; i++)
            {
                deletePizza(s, i);
            }
            
            printf("=> ������!\n");
            count--;
        }
        
    }
    printf("�����!\n");
    return 0;
}

void readPizza(Pizza *s, int count){
    printf("*****************\n");
    
    for (int i = 0; i < count; i++)
    {
        printf("%d %d %c %5s", s[i].num, s[i].price, s[i].type,s[i].name);
    }
}

int addPizza(Pizza *s, int Num){

    s->num = Num;
    printf("�޴�����?");
    fgets(s->name, 20, stdin);
    s->name[strlen(s->name)] = '\0';
    // while (getchar()!='\n');        // ���� ���� ����
    printf("�޴�����(P/S/R)?");
    scanf("%c", &s->type);
    printf("������?");
    scanf("%d", &s->price);
    return 1;
}

int updatePizza(Pizza *s){
    char t[20];
    printf("�� �޴�����?");
    fgets(t, 20, stdin);
    //while (getchar()!='\n');        // ���� ���� ����
    t[strlen(t)] = '\0';
    strcpy(s->name, t);
    printf("�� �޴�����(P/S/R)?");
    scanf("%c", &s->type);
    printf("�� ������?");
    scanf("%d", &s->price);
    return 1;
}

int deletePizza(Pizza *s, int i){
    if (i == NUM) return 1;
    strcpy(s[i-1].name,s[i].name);
    s[i-1].num = s[i].num;
    s[i-1].type = s[i].type;
    s[i-1].price = s[i].price;
}