#include <stdio.h>

int main(){
    int a, b, c, i, avg;
    int count = 0;
    i = 1;
    a = 1;
    b = 100;



    while (i == 1) {
        avg = (a+b) / 2;
        printf("How about %d? (try more : 1, try less : 2, right : 0) ", avg);
        scanf("%d", &c);
        
        if (c == 1) {
            a = avg + 1;
            count ++;
        }
        else if (c == 2) {
            b = avg - 1;
            count ++;
        }
        else{
            i = 0;
            count ++;
        }
        

    }
    printf("%d tried.", count);
    return 0;

}