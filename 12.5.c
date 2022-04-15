#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readtext(char * p[]);

int main(){
    char* pstr[20]; // Pointer array for up to 20 sentences to be stored
    char* longest;  // Pointer to the longest sentence
    char* shortest;	// Pointer to the shortest 
    int id_longest = 0, id_shortest = 0;        // index number for the longest and shorest sentence
    int i;

    int lines = readtext(pstr);
    printf("%d lines read.\n", lines);
    
    longest = pstr[0];
    shortest = pstr[0];
    
    for ( i = 1; i < lines; i++){
        if(strlen(pstr[i]) > strlen(longest)){
            longest = pstr[i];
            id_longest = i + 1;
        }
        if(strlen(pstr[i]) < strlen(shortest)){
            shortest = pstr[i];
            id_shortest = i + 1;
        }
    }   
    printf("Longest #%d - %s\n", id_longest, longest);
    printf("Shortest #%d - %s", id_shortest, shortest);
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