#include <stdio.h>
#include <string.h>

int main(){
    char username[5][20]={"kim", "lee", "park", "hong", "choi"}; 
    char password[5][20]={"1111", "1234", "3456", "3535", "7777"};
    char ent_name[20]={}; //entered name
    char ent_password[20]={}; //entered password
    int correct = 0; //looking for correct number
    int i, j; //variable for loop

    printf("아이디를 입력하시오. ");
    scanf("%s", ent_name);
    ent_name[strlen(ent_name)] = '\0';

    printf("비밀번호를 입력하시오. ");
    scanf("%s", ent_password);
    ent_password[strlen(ent_password)] = '\0';

    for ( i = 0; i < 5; i++){
        if (strcmp(ent_name, username[i]) == 0){
            
            if (strcmp(ent_password, password[i]) == 0){
                correct = 1;
                break;
            }
            else{
                correct = 2;
                break;
            }
        }
        else{
            correct = 3;
        }   
    }

    if (correct == 1){
        printf("로그인 성공");
    }
    else if (correct == 2){
        printf("아이디는 맞는데 비번이 틀림");
    }
    else{
        printf("그런 아이디가 없음");
    }
    return 0;
}