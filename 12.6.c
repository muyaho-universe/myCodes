#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readtext(char * p[]);
int count_vowels(char *str);
// Return : the number of vowels in str (vowles: a,e,i,o,u,A,E,I,O,U)

int main(){
    char* pstr[20]; // Pointer array for up to 20 sentences to be stored
    int i;
    int lines = readtext(pstr);

    printf("%d lines read.\n", lines);
    for ( i = 0; i < lines; i++){
        printf("#%d - %s [%d]\n", i + 1, pstr[i], count_vowels(pstr[i]));
    }
    free(pstr);
    return 0;
}

int readtext(char * p[]){
    FILE * fp;
    char temp[100];     //temporary string
    int count = 0;      //the number of reading sentence
    fp = fopen("data.txt", "r");
    while(!feof(fp)){
        if(!fgets(temp, 100, fp)) break;
        if (temp[strlen(temp)-1] == '\n') temp[strlen(temp)-1] = '\0';
        else temp[strlen(temp)] = '\0';        
        p[count] = (char*) malloc(sizeof(char)*strlen(temp)+1);
        strcpy(p[count], temp);
        count++;
    }
    fclose(fp);
    return count;
}

int count_vowels(char *str){
    int i;
    int count = 0;
    for ( i = 0; i < strlen(str); i++){
        if (*(str+i) == 'a'|| *(str+i) == 'e'|| *(str+i) == 'i'|| *(str+i) == 'o'|| *(str+i) == 'u'||*(str+i) == 'A'|| *(str+i) == 'E'||*(str+i) == 'I'||*(str+i) == 'O'||*(str+i) == 'U') count ++;
    }
    return count;
}