#include <stdio.h>
#include <string.h>

int main(){
    char firstname[30];
    char lastname[30];
    char age_group[4][30] = {"[Youth]","[Junior]","[Senior]","[Silver]"}; 
    char out_put[100] = {};
    int birthyear;
    int age; // age
    int i = 0; //variable for information

    printf("Firstname? ");
    scanf("%s", firstname);

    printf("Lastname? ");
    scanf("%s", lastname);

    printf("Birthyear? ");
    scanf("%d", &birthyear);
    
    age = 2021 - birthyear + 1;

    if (age < 20 ){
        i = 0;
    }
    else if(age < 40){
        i = 1;
    }
    else if(age < 65){
        i = 2;
    }
    else{
        i = 3;
    }

    strcat(out_put, age_group[i]);
    out_put[strlen(out_put)] = '\0';
    strcat(out_put, " ");
    out_put[strlen(out_put)] = '\0';
    strcat(out_put, firstname);
    out_put[strlen(out_put)] = '\0';
    strcat(out_put, " ");
    out_put[strlen(out_put)] = '\0';
    strcat(out_put, lastname);
    out_put[strlen(out_put)] = '\0';
    
    printf("결과 : %s", out_put);
    
    return 0;
}