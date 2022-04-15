#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* findLongestWord(char* str);
// Parameter: whole sentence (str)
// Return value: the sentence starting with the longest word
// What to do: The string at the beginning of the longest word in the sentence

int main(void) {
    char line[100];     // input sentence 
    int i;
    int blank = 0;
    int length;
    int brk;
    printf("Enter text: ");
    fgets(line, 100, stdin); 

    line[strlen(line)-1]='\0';
    printf("Results: The longest word in \'%s\' is ", line);

    findLongestWord(line);
    for ( i = 1; i < strlen(line); i++){
        if (*(line + i) == ' '){
            blank = i;
            brk = 1;
            break;
        }
        else {
            blank = i;
            brk = 0;
        }
    }
    if(brk) line[blank] = '\0';
    else line[blank+1] = '\0';
    
    length = strlen(line);
    printf("\'%s\', with a length of %d.", line, length);
    return 0;
}

char *findLongestWord(char* str){
    int i, j;
    int lct = 0;
    int longest = 1;
    int blank = 0;
    
    for (i = 0; i < strlen(str); i++){
        if (*(str + i) == ' ' || *(str + i) == '\0'){
            if (longest < i - blank - 1){
                longest = i - blank - 1;
                lct = i - longest;
            }
            blank = i;
        }
    }

    for ( i = 0; i < strlen(str) - lct; i++){
        str[i] = str[lct + i];
    }
    str[strlen(str) - lct] = '\0';
    return *str;
}
