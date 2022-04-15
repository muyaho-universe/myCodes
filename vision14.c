#include <stdio.h>

int main() {
    int n = 2;
    int i, j, k = 0, a = 0;
    printf("N? ");
    scanf("%d", &n);

    int snail[n][n];
    snail[n][n] = 0;
    for ( i = 0; i < n; i++){
        for ( j = 0; j < n; j++){
            snail[i][j] = 0;;
        }
    }
    for ( i = 0; i < n; i++){
        for ( j = 0; j < n; j++){
            if (i == 0) snail[i][j] = j + 1;
            if (i > 0 && i < n - 1 && j == 0) {
              snail[i][0] = 4*n - 4 - a;
              a++;
            }
            if (i == 1 && j != 0 && i != n-1) snail[i][j] = snail[1][0] + j;
            if (i == n-1) snail[i][j] = 3*n-2 - j;
            if(j == n-1) {
                snail[i][j] = n + k;
                k++;
            }
        }
        
    }
    for ( i = 0; i < n; i++){
        for ( j = 0; j < n; j++){
            printf("%2d ", snail[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}