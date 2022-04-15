#include <stdio.h>
#include <string.h>

int i = 1;

void r_print(char* pch, int position);
// pch: pointer to the beginning of the string
// position: index for the target character (1~)

int main(void) {
	char str[80];

	printf("Enter a string >> ");
	fgets(str, 80, stdin);
	str[strlen(str)-1]='\0';
	
    r_print(str, strlen(str));
	
    return 0;
}

void r_print(char* pch, int position){
    printf("%2d. %c\n", i,*(pch+position-1));
    i++;
    if (i-1 == strlen(pch)) return;
    else return r_print(pch, position-1);

}
// Hint: 
  // call r_print for the string after the current char.  
  // print the current char. 