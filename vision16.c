#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10000

void push(int ary[], int num, int TOP);
int pop(int ary[], int TOP);
void size(int ary[], int TOP);
void top(int ary[], int TOP);
void empty(int ary[], int TOP);

int main(){
    int TOP = 0;
    int ary[SIZE];
    int count;
    char input[20];
    char con[20];
    int i, j, k;
    int convert;
    int result;

    printf("count? ");
    scanf("%d", &count);
    
    while (getchar()!='\n');        // 개행 문자 제거
    for ( i = 0; i < count; i++){

        printf("What to do? ");
        fgets(input, 20, stdin);
        input[strlen(input)-1]='\0';
        printf("input: %s\n", input);

        if (input[0] == 'p' && input[1] == 'u' && input[2] == 's' && input[3] == 'h'){
            k = 0;
            for (j = 5; j < strlen(input); j++){
              con[k] = input[j];
              k++;
            }
            con[strlen(con)] = '\0';
            convert = atoi(con);
            
            push(ary, convert, TOP);
            TOP ++;
        }
        else if (strcmp(input,"pop") == 0){
            result = pop(ary, TOP);
            TOP --;
            printf("pop: %d\n", result);
        }
        else if (strcmp(input,"size") == 0){
            size(ary, TOP);
        }
        else if (strcmp(input,"top") == 0){
            top(ary, TOP);
        }
        else if (strcmp(input,"empty") == 0){
            empty(ary, TOP);
        }
        else continue;
    }
    for(i=0; i < TOP; i++) printf("%d\n",ary[i]);
    return 0;
}

void push(int* ary, int num, int TOP){
    *(ary+TOP) = num;
    printf("push done!\n");
}

int pop(int ary[], int TOP){
    if (TOP == 0) return -1;
    else{

        int result = ary[TOP-1];
        ary[TOP-1] = '\0';
        return result;
    }
}

void size(int ary[], int TOP){
  printf("size: %d\n", TOP);
}

void top(int ary[], int TOP){
  if(TOP == 0) printf("top: -1\n");
  else printf("top: %d\n", ary[TOP-1]);
}

void empty(int ary[], int TOP){
  if(TOP == 0) printf("empty: 1\n");
  else printf("empty: 0\n");
}