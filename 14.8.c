#include <stdio.h>
#include <string.h>

int i = 0;
int count =0;

int r_strlen(char* str);
// Parameter: the starting pointer of the string to be counted
// Return value: the number of non-whitespace characters from this pointer to the end of the string

int main(){
    char line[100];
	  printf("Enter a string > ");
    fgets(line, 100, stdin);
    printf("length : %d\n", r_strlen(line));

    return 0;
}


int r_strlen(char* str){
    i ++;
    if(i - 1 == strlen(str)) return count-1;
    else{
        if(*(str+i -1) != ' ') count ++;
        return r_strlen(str);
    }
}

// The number of characters in a string is calculated by counting the number of characters in the string starting immediately after the current character and adding 1

// Types of white space: ' ', '\n', '\t' Only check 3 things