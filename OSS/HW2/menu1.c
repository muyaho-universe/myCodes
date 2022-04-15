#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];
    char type;
    int price;
} Pizza;
 
int addPizza(Pizza *s);
void readPizza(Pizza s);
int updatePizza(Pizza *s);
int deletePizza(Pizza *s);

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
    Pizza s;
    int count = 0, menu;

    int isUpdated, isAdd, isDel;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            readPizza(s);
        }
        else if (menu == 2){
            isAdd = addPizza(&s);
        }
        else if (menu == 3){
            isUpdated = updatePizza(&s);
            if (isUpdated == 1)
                printf("=> ��������!\n");
        }
        else if (menu == 4){
            isDel = deletePizza(&s);
            if (isDel == 1)
                printf("=> ������!\n");
        }
    }
    printf("�����!\n");
    return 0;
}

int addPizza(Pizza *s){
    printf("�޴�����?");
    fgets(s->name, 20, stdin);
    
    // while (getchar()!='\n');        // ���� ���� ����
    printf("�޴�����(P/S/R)?");
    scanf("%c", &s->type);
    printf("������?");
    scanf("%d", &s->price);
    return 1;

}

void readPizza(Pizza s){
    printf("*****************\n");
    printf("1	 %d	%c %s\n", s.price, s.type, s.name);
}

int updatePizza(Pizza *s){
    printf("�� �޴�����?");
    fgets(s->name, 20, stdin);
    // while (getchar()!='\n');        // ���� ���� ����
    printf("�� �޴�����(P/S/R)?");
    scanf("%c", &s->type);
    printf("�� ������?");
    scanf("%d", &s->price);
    return 1;
}

int deletePizza(Pizza *s){
    strcpy(s->name,"");
    s->type = ' ';
    s->price = -1;
    return 1;
}