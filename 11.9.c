#include <stdio.h>

struct menu{
    int no; // menu number
    char name[20]; // menu name
    int price; // price
};

int main(){
    struct menu mymenu[5];
    int i;

    FILE * fp;
    fp = fopen("user.txt", "w");

    for ( i = 0; i < 5; i++){
        printf("Menu %d: number, name, and price? ", i + 1);
        scanf("%d %s %d", &mymenu[i].no, mymenu[i].name, &mymenu[i].price);
    }
    printf("Menu number, name and price for 1 person\n");
    for ( i = 0; i < 5; i++){
        printf("%4d %s %d\n", mymenu[i].no, mymenu[i].name, mymenu[i].price);
        fprintf(fp,"%4d %s %d\n", mymenu[i].no, mymenu[i].name, mymenu[i].price);
    }

    fclose(fp);
    return 0;
}