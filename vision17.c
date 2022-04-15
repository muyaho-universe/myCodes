#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char * s);

int main() {
    char str[10*10*10*10];
    scanf("%s", str);
    if (isValid(str)) printf("true\n");
    else printf("false\n");
    return 0;
}

bool isValid(char * s){
    int top = strlen(s);
    bool tf = true;
    if (top % 2 == 1) return false;
    
    else {
        for (int i = top -1; i >= 0; i--){
            if ((s[i] == '}' && s[i-1] == '{')||(s[i] == ']' && s[i-1] == '[')|| (s[i] == ')' && s[i-1] == '(')) i--;
            else{
                tf = false;
                break;
            }
        }
        return tf;
    }
    
    
}