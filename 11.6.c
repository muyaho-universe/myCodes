#include <stdio.h>

struct user_struct{ 
    char userid[20]; 
    char userpw[20]; 
};

int main(void) {
    struct user_struct us[10];
    int i;

    FILE * fp;
    fp = fopen("user.txt", "w");

    for ( i = 0; i < 10; i++){
        printf("%d", i+1);
        if(i == 0) printf("st ");
        else if(i == 1) printf("nd ");
        else if(i == 2) printf("rd ");
        else printf("th ");
        printf("user ID Password? ");
        scanf("%s %s", us[i].userid, us[i].userpw);

        fprintf("%s %s\n", us[i].userid, us[i].userpw);
    }
    printf("\nRegistered users\nNo ID   Password\n");
    for ( i = 0; i < 10; i++){
        printf("%-2d %s %s\n", i+1, us[i].userid, us[i].userpw);
    }
    printf("\nSaved in user.txt");
    
    fclose(fp);


	return 0;
}
