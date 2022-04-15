#include <stdio.h>

#define MAX_N 1001

int matrix[MAX_N][MAX_N] = {0};
int visit[MAX_N] = {0};

void dfs(int v, int n);

int main(){
    int N, M, V;
    int point1, point2;

    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; i++){
        scanf("%d %d", &point1, &point2);
        matrix[point1][point2] = 1;
        matrix[point2][point1] = 1;
    }
    dfs(V, N);
    printf("\n");

    return 0;
}

void dfs(int v, int n){
    printf("%d ", v);
    visit[v] = 1;

    for(int i=1; i<=n; i++) {
        if(visit[i] == 1 || matrix[v][i] == 0)     
            continue;
        dfs(i, n);                //dfs에서 재귀를 사용
    }
}