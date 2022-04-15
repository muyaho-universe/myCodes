#include <stdio.h>

struct user_struct{
  char userid[20];
  char userpw[20];
};


int main(){
    struct user_struct us[10];
    int i;

    FILE * fp;
    fp = fopen("user.txt", "r");

    printf("Registered users\nNo ID   Password\n");
    
    for ( i = 0; i < 10; i++){
        fscanf(fp, "%s %s", us[i].userid, us[i].userpw);
    }

    for ( i = 0; i < 10; i++){
        if(i==9) printf("%-2d %s %s", i+1 ,us[i].userid, us[i].userpw);
        else printf("%-2d %s %s\n", i+1 ,us[i].userid, us[i].userpw);
    }
    fclose(fp);
	
	return 0;

}