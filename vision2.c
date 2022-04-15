#include <stdio.h>

int main(){
    int ary[100] = {0};
    int commands[50][3] = {0};
    int result[50] = {0};
    int count = 0;
    int i = 0, j, k = 0;
    int num;
    int temp[100], t;

    while (1){
        scanf("%d", &num);
        if (num == 0) break;
        while (getchar()!='\n');        // 개행 문자 제거

        ary[count] = num;
        count ++;
    }

    for ( i = 0; i < count; i++){
        for ( j = 0; j < 3; j++){
            scanf("%d", &num);
            while (getchar()!='\n');        // 개행 문자 제거
            commands[i][j] = num;
        }
    }

    for ( i = 0; i < count; i++){
        k = 0;
        for ( j = commands[i][0]; j <= commands[i][1]; j++){
            temp[k] = ary[j];
            k++;
        }
        for ( j = 0; i < commands[i][1]- commands[i][0] + 1; j++){
            for ( k = 1; k < j; k++){
                if(temp[k-1]>temp[k]){
                    t = temp[k-1];
                    temp[k-1] = temp[k];
                    temp[k] = t;
                    k = 1;
                }
            }
        }
        result[i] = temp[commands[i][2]];
    }

    for ( i = 0; i < count; i++) printf("%d ", result[i]);
    return 0;    
}