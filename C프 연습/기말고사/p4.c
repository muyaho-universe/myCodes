#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct BASIC{ 
    int type;
    char size[20];
    int length;
};

struct SP_DATA{ 
    float area, lines;
};

struct FIG_DATA{ 
    struct BASIC basic;
    struct SP_DATA sp_data;       // stinfo->stu->name;
};

int load_data(struct FIG_DATA* p[], char* filename);

int main(){
    struct FIG_DATA* shapes[10]; 	// at most 10 numbers. 
    int count = load_num(shapes, "p4data.txt");
    printf("-----input data--------------\n");
    for (int i = 0; i < count; i++)
    {
        if(shapes[i]->basic->type == 0) strcpy(shapes[i]->basic->size, "원");
        if(shapes[i]->basic->type == 3) strcpy(shapes[i]->basic->size, "삼각형");
        if(shapes[i]->basic->type == 4) strcpy(shapes[i]->basic->size, "사각형");
        if(shapes[i]->basic->type == 5) strcpy(shapes[i]->basic->size, "오각형");

        printf("%s %d\n", shapes[i]->basic->size, shapes[i]->basic->length);
    }
    
    printf("------------calc area size------------\n");
    printf("도형 |한변길이| 넓이 | 둘레 | \n");
    for (int i = 0; i < count; i++)
    {
        if(shapes[i]->type == 0) {
            printf("%s %d %.2f %.0f\n", shapes[i]->size, shapes[i]->length)
        }
        if(shapes[i]->type == 3) strcpy(shapes[i]->size, "삼각형");
        if(shapes[i]->type == 4) strcpy(shapes[i]->size, "사각형");
        if(shapes[i]->type == 5) strcpy(shapes[i]->size, "오각형");
    }
    
}

int load_data(struct BASIC* p[], char* filename){
    FILE * fp;
    fp = fopen(filename, "r");
    int i = 0;
    while (!feof(fp)){
        int t_t;
        int t_length;     //temporary variable for reading from file
        int t = fscanf(fp,"%d %d", &t_t, &t_length);
        if (t <= 0) break;
        p[i] = (struct BASIC*) malloc(sizeof(struct BASIC));
        p[i]->type = t_t;
        p[i]->length = t_length;
        i++;
    }
    fclose(fp);
    return i;
}