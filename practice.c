#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "product.h"

int NUM = 1;

struct Product
{
        int num; // 번호
        char name[20]; //제품명
        char description[100]; // 설명
        char weight[10]; // 중량
        int price;  // 가격
        int type;   // 배송방법
        char isDel; // 삭제 여부
};

struct Product* get_product(int count){
        struct Product* p = (struct Product*)malloc(sizeof(struct Product));
        char temp_name[20];
        char temp_des[100];
        p->num = count+1;
        printf("제품명을 적어주세요 :  ");
        fgets(temp_name, 20, stdin);
        temp_name[strlen(temp_name)-1] = '\0';
        strcpy(p->name, temp_name);
        printf("제품 설명을 적어주세요 : ");
        fgets(temp_des, 100, stdin);
        temp_des[strlen(temp_des)-1] = '\0';
        strcpy(p->description, temp_des);
        printf("제품의 무게를 적어주세요 : ");
        scanf("%s", p->weight);
        printf("제품의 가격을 적어주세요 :  ");
        scanf("%d", &p->price);
        printf("제품의 배송방법을 적어주세요 : ");
        scanf("%d", &p->type);

        printf("=> 저장완료!!\n");
        return p;

}       // 제품을 추가하는 함수
void readProduct(struct Product* p){
        printf("%d %d %s: %s %s %d\n", p->num, p->price, p->name, p->description, p->weight, p->type);
}       // 하나의 제품 출력 함수
int listProduct(struct Product* p[], int count){
        printf("*****************\n");
        for (int i = 0; i < count; i++)
        {
                readProduct(p[i]);
        }
        return 1;
} // 전체 등록된 제품 리스트 출력
void searchProduct(struct Product *p[], int count, int type)
{
        char n_data[20], w_data[10];
        int t_data, go = 0;

        if(type == 1 )
        {
                printf("찾는 물건이름은? ");
                fgets(n_data, 20, stdin);
                n_data[strlen(n_data)-1] = '\0';

                printf("*****************\n");
                for (int i = 0; i < count; i++)
                {
                        if (strstr(p[i]->name, n_data) != NULL)
                        {
                                printf("%d %d %s: %s %s %d\n", p[i]->num, p[i]->price, p[i]->name,p[i]->description, p[i]->weight, p[i]->type);
                        }
                }
        }

        else if(type == 2)
        {
                printf(" 찾는 물건 무게는?(단위까지 입력) ");
                fgets(w_data, 10, stdin);
                w_data[strlen(w_data)-1] = '\0';
                printf("*****************\n");
                for (int i = 0; i < count; i++)
                {
                        if (strstr(p[i]->weight, w_data) != NULL)
                        {
                                readProduct(p[i]);
                        }
                }

        }

        else if(type == 3)
        {
                printf("찾는 물건의 배송 방법은?(1:새벽배송 /2:택배배송) ");
                scanf("%d", &t_data);
                printf("*****************\n");
                for (int i = 0; i < count; i++)
                {
                        if (p[i]->type == t_data)
                        {
                                readProduct(p[i]);
                        }
                }
        }

        else
        {
                printf("잘못된 검색타입입니다.\n");
        }
}       // 제품이름 검색
int load_product(struct Product* p[], char* filename){
        FILE * fp;
        printf("무야호~");
        int i = 0;
        if(fp = fopen(filename, "r"))
        {
                while (!feof(fp)){
                int t_price, t_num;     //temporary variable for reading from file
                char t_name[20], t_des[100],t_weight[10] ;
                int t_type;
                int t = fscanf(fp,"%d %d %[^\n]s %[^\n]s %[^\n]s %d",  &t_num, &t_price, t_name, t_des,t_weight, &t_type);
                if (t <= 0) break;
                p[i] = (struct Product*) malloc(sizeof(struct Product));
                strcpy(p[i]->name, t_name);
	                    strcpy(p[i]->description, t_des);
                strcpy(p[i]->weight, t_weight);
                p[i]->num = t_num;
                p[i]->price = t_price;
                p[i]->type = t_type;
                i++;
                }
        printf("=> 로딩성공!\n");
        fclose(fp);
        }
        else
        {
                printf("\n=> 파일이 없습니다!\n");
        }

        return i;
}       // 제품정보가 저장된 파일 읽기/ type에 따라 검색의 내용이 달라짐
void save_product(struct Product* p[], char* filename, int count){
        FILE * fp;
         fp = fopen(filename, "w");
        for ( int i = 0; i < count; i++){
                fprintf(fp,"%d %d %s %s %s %d \n", i + 1, p[i]->price, p[i]->name, p[i]->description, p[i]->weight, p[i]->type);
        }
        fclose(fp);
        printf("저장완료!\n");
}       // 파일에 제품 정보 저장
int selectMenu(){
    int menu;
    printf("\n*** Product Menu Select ***\n");
    printf("1. 제품조회\n");
    printf("2. 제품추가\n");
    printf("3. 파일저장\n");
    printf("4. 제품검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    while (getchar()!='\n');
    return menu;
}

int main(){
     struct Product* p[20];
        int count = 0, menu, type;
        int isLoaded, isAdd, isDel;
        int selectedNum;
        int go;
        char filename[100]="product.txt";

        count = load_product(p, filename);
        if (count != 0)
        {
                NUM = count + 1;
        }

        while(1)
        {
                if (count ==20) break;

                menu = selectMenu();
                if (menu == 0) break;
                else if (menu == 1)
                {
                        isLoaded = listProduct(p, count);
                }
                else if (menu == 2)
                {
                        p[count] = get_product(count);
                        NUM++;
                        count++;
                }
                else if (menu == 3)
                {
                        save_product(p, filename, count);
                }
                else if (menu == 4)
                {
                        printf("검색타입은? ");
                        scanf("%d", &type);
                        while (getchar()!='\n');
                        searchProduct(p, count,type);
                }
                // else if (menu == 5)
                // {
                //         printf("번호는 (취소 :0)?");
                //         scanf("%d", &selectedNum);
                //         if (selectedNum == 0) continue;
                //         printf("정말로 삭제하시겠습니까?(삭제 :1) ");
                //         scanf("%d", &go);
                //         if (go != 1) continue;
                //         deleteProduct(p, selectedNum-1);
                // }
//                 else if (menu == 6)
//                 {
//                         printf("\n번호는 (취소 :0)?");
//                         scanf("%d", &selectedNum);
//                         while (getchar()!='\n');
//                         if (selectedNum == 0) continue;
//                         p[selectedNum-1] = updateProduct(selectedNum);
//                         printf("=> 수정됨!\n");
// }
                else
                {
                        printf("없는 메뉴입니다.\n");
                }

        }
        printf("종료됨!\n");

        return 0;


    
}                                                