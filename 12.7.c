#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user_struct{
    char userid[20];
    char userpw[20];
};
struct user_struct* get_user();

int main(){
    struct user_struct *stp = get_user();
    printf("\nUser ID: %s\n", stp->userid);
    printf("Password: %s", stp->userpw);
    free(stp);
    return 0;
}

struct user_struct* get_user(){
    int i;
    struct user_struct* p = (struct user_struct*)malloc(sizeof(struct user_struct));
    while (1){
        printf("User ID? ");
        scanf("%s", p->userid);
        if (strlen(p->userid) < 4) printf("-> need more than 4 characters\n");
        else break;
    }
    while (1){
        printf("Password? ");
        scanf("%s", p->userpw);
        if (strlen(p->userpw) < 4) printf("-> need more than 4 characters\n");
        else break;
    }
    for ( i = 2; i < strlen(p->userpw); i++){
        *(p->userpw +i) = '*';
    }
    *(p->userpw + strlen(p->userpw)) = '\0';
    return p;
}