#include <stdio.h>
#include <string.h>

#define MAX_N 20
#define SUB_N 3

int main(){
    char * pname[SUB_N]={"C", "Java", "Python"};
    char name[MAX_N][30]; // names (upto 20)
    int score[SUB_N][MAX_N]; // scores (upto 20)
    int sum[MAX_N]; // total score (upto 20)
    float avg[MAX_N]; // score average (upto 20)
    char check[100];    //checking if there is null value
    int i, j;       //varaiable for loop
    char file_name[100];    //inputted file name

    int sum_class;
    float avg_class;
    
    int top_name = 0;
    int top_score;
    int count = 0;
    
    printf("Enter the file name: ");
    scanf("%s", file_name);

    FILE * fp;
    fp = fopen(file_name, "r");
 
    for ( i = 0; i < 20; i++){
        fscanf(fp, "%s %d %d %d", name[i], &score[0][i], &score[1][i], &score[2][i]);
        if(!fgets(check, 100, fp)) break;
        count ++;
        
    }
    printf("%d records read.\n", count);
    
    for ( i = 0; i < count; i++){
        sum[i] = score[0][i] + score[1][i] + score[2][i];
        avg[i] = (float) sum[i] / SUB_N;
        printf("%-8s%d  %d  %d  %d  %.1f\n", name[i], score[0][i], score[1][i], score[2][i], sum[i], avg[i]);
    }

    for ( i = 0; i < SUB_N; i++){
        sum_class = 0;
        top_score = score[i][0];
        for ( j = 0; j < count; j++){
            sum_class += score[i][j];
            if (score[i][j] > top_score){
                top_score = score[i][j];
                top_name = j;
            }
        }
        avg_class = (float) sum_class / count;
        printf("%s - average : %.1f, Top : %s (%d)\n", * pname[i], avg_class, name[top_name], top_score);
    }
    
    fclose(fp);
    return 0;
}