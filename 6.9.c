#include <stdio.h>
#include <string.h>

int main(){
    char input[100] = {" "}; //inputed sentence
    char reverse[100] = {" "}; //reverse for the inputed sentence
    char comp[100] = {" "}; //for comparing
    int i, j; //variable for loop

    printf("Sentence > ");
    fgets(input, 100, stdin);
    j = 0;
    for ( i = 0; i < strlen(input); i++){
        if(input[i] >= 97 && input[i] <= 122 ){
            comp[j] = input[i];
            j++;
        }
        else{
            continue;
        }
    }
    comp[strlen(comp)] = '\0';
    
    j = 0;
    for ( i = strlen(input) - 1; i >= 0 ; i--){
        if(input[i] >= 97 && input[i] <= 122 ){
            reverse[j] = input[i];
            j++;
        }
        else{
            continue;
        }
    }
    reverse[strlen(reverse)] = '\0';

    // printf("%s\n", comp);
    // printf("%s\n", reverse);
    if (strcmp(comp, reverse) == 0){
        printf("Palindrome!\n");
    }
    else{
        printf("Not Palindrome!\n");
    }
    return 0;

}