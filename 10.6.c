#include <stdio.h>

int main(void) {
	char userid[10][20];
	char userpw[10][20];
    int i;  //variable for loop

    FILE * fp;
    fp = fopen("user.txt", "w");

    for ( i = 0; i < 10; i++){
        printf("%d", i+1);
        if(i == 0) printf("st ");
        else if(i == 1) printf("nd ");
        else if(i == 2) printf("rd ");
        else printf("th ");
        printf("ID Password? ");
        scanf("%s %s", userid[i], userpw[i]);

        fprintf(fp,"%s %s\n", userid[i], userpw[i]);
    }
    printf("\nRegistered users\nNo ID   Password\n");
    for ( i = 0; i < 10; i++){
        printf("%-2d %s %s\n", i+1, userid[i], userpw[i]);
    }
    printf("\nSaved in user.txt");
    
    fclose(fp);
	return 0;
}