#include <stdio.h>
#include <string.h>

int main(){
    char str1[100] ={" "}; // first string
    char str2[100] ={" "}; // second string
    char alpha_1[100] = {" "}; // alphabet only for string one
    char alpha_2[100] = {" "}; // alphabet only for string two    
    int num1, num2; // numbers of alphabet
    int i, j = 0; //variable for loop

    printf("String 1 > ");
    fgets(str1, 100, stdin);
    printf("String 2 > ");
    fgets(str2, 100, stdin);

    for ( i = 0; i < strlen(str1); i++){
        if(str1[i] >= 97 && str1[i] <= 122){
            alpha_1[j] = str1[i];
            j++;
        }
        else{
            continue;
        }
    }
    alpha_1[strlen(alpha_1)] = '\0';

    j = 0;
    for ( i = 0; i < strlen(str2); i++){
        if(str2[i] >= 97 && str2[i] <= 122){
            alpha_2[j] = str2[i];
            j++;
        }
        else{
            continue;
        }
    }

    if (strlen(alpha_1) == strlen(alpha_2)){
        printf("Anagram!\n");
    }
    else{
        printf("Not anagram!\n");
    }
    return 0;
}