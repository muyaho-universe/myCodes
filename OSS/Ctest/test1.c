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
    printf("\n*** 맛있는 한식 배달 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 예약자검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
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
            // printf("\n번호는 (취소 :0)?");
            // scanf("%d", &selectedNum);
            // if (selectedNum == 0) continue;
            // s[selectedNum-1] = updateMenu(selectedNum);
            // printf("=> 수정됨!\n");
        }
        else if (menu == 4){
            readOrder(s, count);
            printf("번호는 (취소 :0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            printf("정말로 삭제하시겠습니까?(삭제 :1) ");
            scanf("%d", &go);
            if (go != 1) continue;
            deleteOrder(s, selectedNum-1);
            
            printf("=> 삭제됨!\n");
        }
        else if(menu == 5){
            saveData(s, filename, count);
            printf("=> 저장됨!\n");
        }
        else if (menu == 6){
            findname(s, count);
        }

    }
    printf("종료됨!\n");
    return 0;
}

void readOrder(struct Menu *s[], int count){
    int total = 0;
    printf("No  메뉴개수 예약자 등급 가격 주소\n");
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
    printf("\n총 %d개의 주문이 있습니다.\n", total);
}


// struct Score* updateOrder(int selectNum){
    
//     struct Score* p = (struct Score*)malloc(sizeof(struct Score));
//     p->num = selectNum ;
//     char temp[20];
//     printf("이름은?");
//     scanf("%s", temp);
//     printf("국어는?");
//     scanf("%d", &p->score[0]);
//     printf("영어는?");
//     scanf("%d", &p->score[1]);
//     printf("수학은?");
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
    printf("**** 메뉴판 *****\n1. 비빔밥   8,000원\n2. 김치찌개 7,000원\n3. 참치덮밥 9,000원\n*********\n");
    struct Menu* p = (struct Menu*)malloc(sizeof(struct Menu));

    p->num = NUM ;
    printf("메뉴별 개수 ? ");
    
    scanf("%d %d %d", &p->count[0], &p->count[1], &p->count[2]);
    printf("예약자는? ");
    scanf("%s", p->name);
    while (getchar()!='\n'); 
    printf("예약자 등급은(B,S,G) ? ");
    scanf("%c", &p->grade);
    while (getchar()!='\n'); 
    printf("배달 주소는 ? ");
    fgets(p->address, 100, stdin);
    p->address[strlen(p->address)-1] = '\0';
    p->price = 8000 * p->count[0] + 7000 * p->count[1] + 9000 * p->count[2];
    printf("총 주문한 음식 값은 %d 입니다.\n", p->price);
    p->isDelete = 'N';
   

    return p;
}

void findname(struct Menu *s[], int count){
    char data[100];
    int total = 0;
    printf("검색할 이름은? ");
    scanf("%s", data);
    while (getchar()!='\n'); 
    printf("No  메뉴개수 예약자 등급 가격 주소\n");
    printf("================================\n");
    for (int i = 0; i < count; i++)
    {
        if (strstr(s[i]->name, data) != NULL)
        {
            printf("%d %d %c %5s\n", s[i]->num, s[i]->price, s[i]->grade,s[i]->name);
            total++;
        }
        
    }
    printf("총 %d개의 주문이 있습니다.\n", total);
    if (total == 0) printf("=> 검색된 데이터 없음!\n");
    
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
//         printf("=> 로딩 성공!\n");
//         fclose(fp);
//     }
//     else{
//         printf("\n=> 파일 없음\n");
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
    printf("저장됨!\n");
}