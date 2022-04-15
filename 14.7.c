#include <stdio.h>
#include <string.h>

int ind = 0;
int k = 1;

void r_print(char* pch);
// pch: pointer to the beginning of the string

int main(void) {
	char str[80];

	printf("Enter a string >> ");
	fgets(str, 80, stdin);
	str[strlen(str)-1]='\0';
	
    r_print(str);
	printf("\n");
	
    return 0;
}

void r_print(char* pch){
    for ( int i = 0; i < strlen(pch); i++){
        if (*(pch+i)>='a' && *(pch+i)<='z'){
            *(pch+i) += 32;
        }
        
    }
    
    if (strlen(pch) > 2){

    }
    
}
    // Hint: 
    // check the length of pch. 
    // if the length > 2
    // call r_print for the string after the current two characters.  
    // print the current two characters. 
    // else (when the length is 1 or 2)	