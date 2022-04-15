#include <stdio.h>
#include <string.h>

int main(void) {
    FILE * fp;
    int count = 0;
    char line[100];
    char lonegest[100];
    char shortest[100];
    int lng = 0, sht = 100;
    int i;

    fp = fopen("name.txt", "r");

    while (!feof(fp)){
        if(!fgets(line, 100, fp)) break;
        count ++;

        if (strlen(line) > lng){
            for ( i = 0; i < strlen(line); i++){
                * (lonegest +i) = * (line + i);
                lng = strlen(line);
            }
            * (lonegest + strlen(line)) = '\0';
        } 
        if (strlen(line) < sht) {
            for ( i = 0; i < strlen(line); i++){
                * (shortest + i) = * (line + i);
                sht = strlen(line);
            }
            * (shortest + strlen(line)) = '\0';
        }
    }

    printf("Count : %d\nLongest name : %sShortest name : %s", count, lonegest, shortest);

    fclose(fp);
    return 0;
}