#include <stdio.h>
#include <string.h>

int numDistinct(char * s, char * t);

int main() {
    char s[1000];
    char t[1000];
    int result;

    scanf("%s %s", s, t);
    result = numDistinct(s, t);
    printf("%d", result);
    return 0;
}

int numDistinct(char * s, char * t){
    int i;
    int count = 0;
    int index = 0;

    for ( i = 0; i < strlen(s); i++){
        if (s[i] == t[index]){
            index++;
            if (index == strlen(t)){
                count ++;
            }
        }
    }

    return count;
}