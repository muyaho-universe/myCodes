#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int go = 1;
    int i = 0;
    char ch[21];
    char l_ch[20];
    char s_ch[20];

    while (1){
        printf("Enter word:");
        scanf("%s", ch);
        while (getchar()!='\n');  
        if (strlen(ch) > 20){
            printf("Too long word\n");
            continue;
        }
        else if(strlen(ch) <= 2) {
            break;
            go = 0;
        }
        else{
            strcpy(l_ch, ch);
            strcpy(s_ch, ch);
            break;
        }
    }
    
    while (go){
        printf("Enter word:");
        scanf("%s", ch);
        while (getchar()!='\n');  
        if (strlen(ch) > 20){
            printf("Too long word\n");
            continue;
        }
        else if(strlen(ch) <= 2) {
            break;
        }
        
        else{
          while(1){
            if (ch[i]<s_ch[i]){
              strcpy(s_ch, ch);
              break;
            } 
            else if(ch[i]==s_ch[i]) i ++;
            
            else if (ch[0]>l_ch[0]){
              strcpy(l_ch, ch);
            } 
            else if(ch[i]==l_ch[i]) i ++;
            else break;
          }
          i = 0;
            
        }
        
    }
    
    printf("Smallest word: %s\n", s_ch);
    printf("Largest word: %s\n", l_ch);
    return 0;
}