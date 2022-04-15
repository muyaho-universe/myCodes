#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define USER_N 10

struct user_struct{
    char userid[20];
    char userpw[20];
};

struct user_struct* get_user(); 

void save_user(struct  user_struct* userlist[], int size, char* filename);
// Parameters: user list, number of users, file name to save

int main(void) {
    struct user_struct* userlist[USER_N]; 
    char filename[100] = "user.txt";
    int i; 

    for(i=0; i<USER_N; i++){
        printf("#%d User\n", i+1);
        userlist[i] = get_user();
    }
    
    save_user(userlist, USER_N, filename);

    printf("Saved in %s\n", filename); 

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
    return p;
}

void save_user(struct  user_struct* userlist[], int size, char* filename){
    FILE * fp;
    fp = fopen(filename, "w");
    for ( int i = 0; i < size; i++){
        fprintf(fp,"%s %s\n", userlist[i]->userid, userlist[i]->userpw);
    }
    fclose(fp);
}