#include <stdio.h>
#include <string.h>

int main(){
    char input[1000];
    char output[1000];
    int i;

    scanf("%s", input);

    for ( i = 0; i < strlen(input); i++){
        if (input[i] == 'A' || input[i] == 'B' || input[i] == 'C'){
            output[i] = input[i] + 23;
        }
        else output[i] = input[i] - 3;
    }
    output[strlen(input)] = '\0';
    printf("%s", output);
    return 0;
}