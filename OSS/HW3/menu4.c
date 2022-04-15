#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int NUM = 1;

struct Pizza{
    int num;
    char name[20];
    char type;
    int price;
};

struct Pizza* get_pizza();

void readPizza(struct Pizza *s[], int count);
struct Pizza* updatePizza(int selectNum);
void deletePizza(struct Pizza *s[], int i);
int load_pizza(struct Pizza* p[], char* filename);
void save_pizza(struct Pizza* list[], char* filename, int count);
void searchData(struct Pizza *s[], int count);

int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("5. 파일저장\n");
    printf("6. 메뉴검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    while (getchar()!='\n');
    return menu;
}

int main(void){
    struct Pizza* s[20];
    int count = 0, menu;
    int isUpdated, isAdd, isDel;
    int selectedNum;
    int go;
    char filename[100]="menu.txt";
    
    count = load_pizza(s, filename);
    if (count != 0)
    {
        NUM = count + 1;
    }
    
 
    while (1){
        if (count ==20) break;
        
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            
            readPizza(s, count);
        }
        else if (menu == 2){
            s[count] = get_pizza();
            NUM++;
            count++;
        }
        else if (menu == 3){
            
            readPizza(s, count);
            printf("\n번호는 (취소 :0)?");
            scanf("%d", &selectedNum);
            while (getchar()!='\n');
            if (selectedNum == 0) continue;
            s[selectedNum-1] = updatePizza(selectedNum);
            printf("=> 수정됨!\n");
        }
        else if (menu == 4){
            
            readPizza(s, count);
            printf("\n번호는 (취소 :0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &go);
            while (getchar()!='\n');
            if (go != 1) continue;
            for (int i = selectedNum; i < count; i++)
            {
                deletePizza(s, i);
            }
            count--;
            printf("=> 삭제됨!\n");
        }
        else if(menu == 5){
            save_pizza(s, filename, count);
        }
        else if (menu == 6)
        {
           searchData(s, count);
        }
        
    }
    printf("종료됨!\n");
    return 0;
}

void readPizza(struct Pizza *s[], int count){
    printf("*****************\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d %d %c %5s\n", s[i]->num, s[i]->price, s[i]->type,s[i]->name);
    }
}


struct Pizza* updatePizza(int selectNum){
    
    struct Pizza* p = (struct Pizza*)malloc(sizeof(struct Pizza));
    p->num = selectNum ;
    char temp[20];
    printf("메뉴명은?");
    fgets(temp, 20, stdin);
    temp[strlen(temp)] = '\0';
    strcpy(p->name, temp);
    // while (getchar()!='\n');        // 개행 문자 제거
    printf("메뉴종류(P/S/R)?");
    scanf("%c", &p->type);
    printf("가격은?");
    scanf("%d", &p->price);
    return p;
}

void deletePizza(struct Pizza *s[], int i){
    if (i == NUM) return;
    strcpy(s[i-1]->name,s[i]->name);
    s[i-1]->num = s[i]->num; 
    s[i-1]->type = s[i]->type;
    s[i-1]->price = s[i]->price; 
}

struct Pizza* get_pizza(){
    
    struct Pizza* p = (struct Pizza*)malloc(sizeof(struct Pizza));

    p->num = NUM ;
    printf("메뉴명은?");
    fgets(p->name, 20, stdin);
    p->name[strlen(p->name)-1] = '\0';
    // while (getchar()!='\n');        // 개행 문자 제거
    printf("메뉴종류(P/S/R)?");
    scanf("%c", &p->type);
    printf("가격은?");
    scanf("%d", &p->price);
    return p;
}

int load_pizza(struct Pizza* p[], char* filename){
    FILE * fp;
    int i = 0;
    if(fp = fopen(filename, "r"))
    {
        while (!feof(fp)){
            int t_price, t_num;     //temporary variable for reading from file
            char t_name[20];
            char t_type;
            int t = fscanf(fp,"%d %d %c %[^\n]s",  &t_num, &t_price, &t_type, t_name);
            if (t <= 0) break;
            p[i] = (struct Pizza*) malloc(sizeof(struct Pizza));
            strcpy(p[i]->name, t_name);
            p[i]->num = t_num;
            p[i]->price = t_price;
            p[i]->type = t_type;
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

void save_pizza(struct Pizza* list[], char* filename, int count){
    FILE * fp;
    fp = fopen(filename, "w");
    for ( int i = 0; i < count; i++){
        fprintf(fp,"%d %d %c %s\n", i + 1, list[i]->price, list[i]->type, list[i]->name);
    }
    fclose(fp);
    printf("저장됨!\n");
}

void searchData(struct Pizza *s[], int count){
    char data[20];
    int go = 0;
    printf("검색할 이름은? ");
    scanf("%s", data);
    printf("*****************\n");
    for (int i = 0; i < count; i++)
    {
        if (strstr(s[i]->name, data) != NULL)
        {
            printf("%d %d %c %5s\n", s[i]->num, s[i]->price, s[i]->type,s[i]->name);
        }
        
    }
       
}