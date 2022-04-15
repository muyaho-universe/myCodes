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
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
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
                printf("=> 수정성공!\n");
        }
        else if (menu == 4){
            isDel = deletePizza(&s);
            if (isDel == 1)
                printf("=> 삭제됨!\n");
        }
    }
    printf("종료됨!\n");
    return 0;
}

int addPizza(Pizza *s){
    printf("메뉴명은?");
    fgets(s->name, 20, stdin);
    
    // while (getchar()!='\n');        // 개행 문자 제거
    printf("메뉴종류(P/S/R)?");
    scanf("%c", &s->type);
    printf("가격은?");
    scanf("%d", &s->price);
    return 1;

}

void readPizza(Pizza s){
    printf("*****************\n");
    printf("1	 %d	%c %s\n", s.price, s.type, s.name);
}

int updatePizza(Pizza *s){
    printf("새 메뉴명은?");
    fgets(s->name, 20, stdin);
    // while (getchar()!='\n');        // 개행 문자 제거
    printf("새 메뉴종류(P/S/R)?");
    scanf("%c", &s->type);
    printf("새 가격은?");
    scanf("%d", &s->price);
    return 1;
}

int deletePizza(Pizza *s){
    strcpy(s->name,"");
    s->type = ' ';
    s->price = -1;
    return 1;
}