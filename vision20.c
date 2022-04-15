#include <stdio.h>

int jomang();

int main(){
    int num1, ground = 1000, height= 255;
    int i, j, k;
    int apart[ground][height] = {0};
    for ( i = 0; i < 10; i++){
        apart[ground][height] = {0};
        scanf("%d", &num1);
        for ( j = 0; j < num1; j++){
            scanf("%d", &height);
            for ( k = 0; k < height; k++){
                apart[j][k] = 1;
            }
        }
    }
    

}