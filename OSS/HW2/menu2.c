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
            printf("\n번호는(취소:0)?");
            scanf("%d", &selectedNum);
            while (getchar()!='\n');
            if (selectedNum == 0) continue;
            isUpdated = updatePizza(&s[selectedNum-1]);
            if (isUpdated == 1)
                printf("=> 수정성공!\n");
        }
        else if (menu == 4){
            readPizza(s, count);
            printf("\n번호는(취소:0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &go);
            if (go != 1) continue;
            for (int i = selectedNum; i < count; i++)
            {
                deletePizza(s, i);
            }
            
            printf("=> 삭제됨!\n");
            count--;
        }
        
    }
    printf("종료됨!\n");
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
    printf("메뉴명은?");
    fgets(s->name, 20, stdin);
    s->name[strlen(s->name)] = '\0';
    // while (getchar()!='\n');        // 개행 문자 제거
    printf("메뉴종류(P/S/R)?");
    scanf("%c", &s->type);
    printf("가격은?");
    scanf("%d", &s->price);
    return 1;
}

int updatePizza(Pizza *s){
    char t[20];
    printf("새 메뉴명은?");
    fgets(t, 20, stdin);
    //while (getchar()!='\n');        // 개행 문자 제거
    t[strlen(t)] = '\0';
    strcpy(s->name, t);
    printf("새 메뉴종류(P/S/R)?");
    scanf("%c", &s->type);
    printf("새 가격은?");
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