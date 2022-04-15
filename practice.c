#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "product.h"

int NUM = 1;

struct Product
{
        int num; // ��ȣ
        char name[20]; //��ǰ��
        char description[100]; // ����
        char weight[10]; // �߷�
        int price;  // ����
        int type;   // ��۹��
        char isDel; // ���� ����
};

struct Product* get_product(int count){
        struct Product* p = (struct Product*)malloc(sizeof(struct Product));
        char temp_name[20];
        char temp_des[100];
        p->num = count+1;
        printf("��ǰ���� �����ּ��� :  ");
        fgets(temp_name, 20, stdin);
        temp_name[strlen(temp_name)-1] = '\0';
        strcpy(p->name, temp_name);
        printf("��ǰ ������ �����ּ��� : ");
        fgets(temp_des, 100, stdin);
        temp_des[strlen(temp_des)-1] = '\0';
        strcpy(p->description, temp_des);
        printf("��ǰ�� ���Ը� �����ּ��� : ");
        scanf("%s", p->weight);
        printf("��ǰ�� ������ �����ּ��� :  ");
        scanf("%d", &p->price);
        printf("��ǰ�� ��۹���� �����ּ��� : ");
        scanf("%d", &p->type);

        printf("=> ����Ϸ�!!\n");
        return p;

}       // ��ǰ�� �߰��ϴ� �Լ�
void readProduct(struct Product* p){
        printf("%d %d %s: %s %s %d\n", p->num, p->price, p->name, p->description, p->weight, p->type);
}       // �ϳ��� ��ǰ ��� �Լ�
int listProduct(struct Product* p[], int count){
        printf("*****************\n");
        for (int i = 0; i < count; i++)
        {
                readProduct(p[i]);
        }
        return 1;
} // ��ü ��ϵ� ��ǰ ����Ʈ ���
void searchProduct(struct Product *p[], int count, int type)
{
        char n_data[20], w_data[10];
        int t_data, go = 0;

        if(type == 1 )
        {
                printf("ã�� �����̸���? ");
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
                printf(" ã�� ���� ���Դ�?(�������� �Է�) ");
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
                printf("ã�� ������ ��� �����?(1:������� /2:�ù���) ");
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
                printf("�߸��� �˻�Ÿ���Դϴ�.\n");
        }
}       // ��ǰ�̸� �˻�
int load_product(struct Product* p[], char* filename){
        FILE * fp;
        printf("����ȣ~");
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
        printf("=> �ε�����!\n");
        fclose(fp);
        }
        else
        {
                printf("\n=> ������ �����ϴ�!\n");
        }

        return i;
}       // ��ǰ������ ����� ���� �б�/ type�� ���� �˻��� ������ �޶���
void save_product(struct Product* p[], char* filename, int count){
        FILE * fp;
         fp = fopen(filename, "w");
        for ( int i = 0; i < count; i++){
                fprintf(fp,"%d %d %s %s %s %d \n", i + 1, p[i]->price, p[i]->name, p[i]->description, p[i]->weight, p[i]->type);
        }
        fclose(fp);
        printf("����Ϸ�!\n");
}       // ���Ͽ� ��ǰ ���� ����
int selectMenu(){
    int menu;
    printf("\n*** Product Menu Select ***\n");
    printf("1. ��ǰ��ȸ\n");
    printf("2. ��ǰ�߰�\n");
    printf("3. ��������\n");
    printf("4. ��ǰ�˻�\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
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
                        printf("�˻�Ÿ����? ");
                        scanf("%d", &type);
                        while (getchar()!='\n');
                        searchProduct(p, count,type);
                }
                // else if (menu == 5)
                // {
                //         printf("��ȣ�� (��� :0)?");
                //         scanf("%d", &selectedNum);
                //         if (selectedNum == 0) continue;
                //         printf("������ �����Ͻðڽ��ϱ�?(���� :1) ");
                //         scanf("%d", &go);
                //         if (go != 1) continue;
                //         deleteProduct(p, selectedNum-1);
                // }
//                 else if (menu == 6)
//                 {
//                         printf("\n��ȣ�� (��� :0)?");
//                         scanf("%d", &selectedNum);
//                         while (getchar()!='\n');
//                         if (selectedNum == 0) continue;
//                         p[selectedNum-1] = updateProduct(selectedNum);
//                         printf("=> ������!\n");
// }
                else
                {
                        printf("���� �޴��Դϴ�.\n");
                }

        }
        printf("�����!\n");

        return 0;


    
}                                                