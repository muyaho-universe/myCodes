#include <stdio.h>
#include <string.h>

int main(void) {
    int countUp = 0; // the number of upper characters
    int countLow = 0; // the number of lower characters
    int countSpace = 0; // the number of spaces
    char line[100];
    int i;

    FILE * fp;
    fp = fopen("data.txt", "r");

    while (!feof(fp)){
        if(!fgets(line, 100, fp)) break;
        for ( i = 0; i < strlen(line); i++){
            if(*(line + i ) == ' ') countSpace++;
            else if(*(line + i ) >= 'a' && *(line + i ) <= 'z') countLow ++;
            else if(*(line + i ) >= 'A' && *(line + i ) <= 'Z') countUp ++;
        }
    }

    printf("Analysis result of data.txt : Uppercase: %d, Lowercase: %d, Blank: %d", countUp, countLow, countSpace);
    fclose(fp);
    return 0;
}