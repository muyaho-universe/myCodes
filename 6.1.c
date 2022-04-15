#include <stdio.h>
#include <string.h>


int main(){
    char userid[30];
    char password[30];
    char password_cp[30];
    char name[30];
    int i = 1; //variabl for loop

    printf("User Id? ");
    scanf("%s", userid);
    printf("Password? ");
    scanf("%s", password);

    while(i){
        if(strlen(password) < 3){
            printf("-> Enter 3 or more characters\n");
            printf("Password? ");
            scanf("%s", password);
        }
        else{
            i = 0;
        }
    }
    printf("User Name? ");
    scanf("%s", name);

    printf("\n");

    strcpy(password_cp, password);
    for ( i = 2; i < strlen(password_cp); i++){
        password_cp[i] = '*';
    }
    password_cp[strlen(password_cp)] = '\0';

    printf("User Id: %s\n", userid);
    printf("Password: %s\n", password_cp);
    printf("User Name: %s\n", name);


    return 0;
}