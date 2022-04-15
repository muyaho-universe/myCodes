#include <stdio.h>



int main(){
    int num;
    int location = 0;
    int i, j;
    int index = 0;

    printf("numbers of docs? ");
    scanf("%d", &num);

    int priority[num];

    printf("input the priorities: ");
    for ( i = 0; i < num; i++){
        scanf("%d",priority[i]);
    }
    printf("location of docs? ");
    scanf("%d", &location);
}