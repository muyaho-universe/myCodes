#include <stdio.h>

int main(void) {
	char userid[10][20];
	char userpw[10][20];  
	int i;  //variable for loop

    FILE * fp;
    fp = fopen("user.txt", "r");

    printf("Registered users\nNo ID   Password\n");
    
    for ( i = 0; i < 10; i++){
        fscanf(fp, "%s %s", userid[i], userpw[i]);
    }

    for ( i = 0; i < 10; i++){
        if(i==9) printf("%-2d %s %s", i+1 ,userid[i], userpw[i]);
        else printf("%-2d %s %s\n", i+1 ,userid[i], userpw[i]);
    }
    fclose(fp);
	
	return 0;
}