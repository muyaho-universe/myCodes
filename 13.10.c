#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define USER_N 10

struct user_struct{
    char userid[20];
    char userpw[20];
};

int load_user(struct user_struct* p[], char* filename);
// Parameter: Array of pointers to structures to store the user list, data file name
// Return value: the number of users. 
// Execution: Creates a user structure through dynamic memory allocation while reading a file, receives and saves user's id and password, and returns the number of created user lists

int check_user(struct user_struct* list[], int size, struct user_struct* temp);
// Parameters: All logins list, the number of lists, login information to check 
// Return value: Check result 1: Both ID and password are correct, 2: ID is correct but password is incorrect, 3: No matching ID

int main(void) {
    struct user_struct* userlist[100];
    struct user_struct* inputinfo;
    char filename[100] = "user.txt";
    int count = load_user(userlist, filename);
    int check;
    int id_length = 0;
    int pw_length = 0;
    int i = 0, j = 0; 

    printf("You have read the login information of %d people from %s.\n", count, filename);
    inputinfo = (struct user_struct*) malloc(sizeof(struct user_struct));
    memset(inputinfo, 0, sizeof(struct user_struct));
    while (1){
        id_length = 0;
        pw_length = 0;
        char tempstr[100];
        printf("Enter the ID and PW you want to log in. ");
        fgets(tempstr, 100, stdin);
        tempstr[strlen(tempstr)-1] = '\0';
        while(tempstr[i] != ' ') {
            id_length++;
            i++;
        }        
        pw_length = strlen(tempstr) - id_length - 1;
        
        memset(inputinfo, 0, sizeof(struct user_struct));
        strncpy(inputinfo->userid, tempstr, id_length);
        
        inputinfo->userid[id_length] = '\0';
        printf("k: %s\n", inputinfo->userid);
        strncpy(inputinfo->userpw, (tempstr+id_length+1), pw_length);
        inputinfo->userpw[pw_length] = '\0';

        check = check_user(userlist, count, inputinfo);
        if (check == 1) {
            printf("Login succeed!: Welcome %s", inputinfo->userid);
            break;
        }
        else if (check == 2) printf("Login failed!: The password is incorrect.\n");
        else if (check == 3) printf("Login failed!: ID does not exist.\n");
    }

    for ( i = 0; i < count; i++){
        free(*(userlist+i));
    }
    
    return 0;
}

int load_user(struct user_struct* p[], char* filename){
    FILE * fp;
    fp = fopen(filename, "r");
    int i = 0;
    while (!feof(fp)){
        char temp_id[100], temp_pw[100];
        int t = fscanf(fp,"%s %s", temp_id, temp_pw);
        if (t <= 0) break;
        temp_id[strlen(temp_id)] = '\0';
        temp_pw[strlen(temp_pw)] = '\0';
        p[i] = (struct user_struct*) malloc(sizeof(struct user_struct));
        strcpy(p[i]->userid, temp_id);
        strcpy(p[i]->userpw, temp_pw);
        i++;
    }
    fclose(fp);
    return i;
}

int check_user(struct user_struct* list[], int size, struct user_struct* temp){
    int i, j;
    int k = 0;
    for ( i = 0; i < size; i++){
        if(!strcmp(list[i]->userid, temp->userid)) k = 1;
        if (k){
            for ( j = 0; j < size; j++){
                if(strcmp(list[j]->userpw, temp->userpw) == 0) k =2;
            }
        }
    }

    if(k == 0) return 3;
    else if(k == 1) return 2;
    else return 1;
}