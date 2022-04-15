#include <stdio.h>
#include <string.h>

int i, count = 0;

int r_spaces(char* str);
// Parameter: the starting pointer of the string to be counted
// Return value: the number of whitespace characters from this pointer to the end of the string

int main(void) {
    char line[100];
	printf("Enter a string > ");
	fgets(line, 100, stdin);
	printf("spaces : %d\n", r_spaces(line));
	return 0;
}

int r_spaces(char* str){
    i ++;
    if(i - 1 == strlen(str)) return count-1;
    else{
        if(*(str+i -1) == ' ' || *(str+i -1) == '\t') count ++;
        return r_strlen(str);
    }
}
// The number of characters in a string is calculated by counting the number of characters in the string starting immediately after the current character and adding 1