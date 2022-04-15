#include <stdio.h>
#include <string.h>

#define MAX_N 20
#define SUB_N 3

struct st_score{
    char name[10]; // 
    int scores[3]; // Score (C, Java, Python)
    int sum; // total score
    float avg; //  average
};

int main(){
    char * pname[SUB_N]={"C", "Java", "Python"};
    struct st_score datas[MAX_N];
    
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
        fscanf(fp, "%s %d %d %d", &datas[i].name, &datas[i].scores[0], &datas[i].scores[1], &datas[i].scores[2]);
        if(!fgets(check, 100, fp)) break;
        count ++;
    }

    printf("%d records read.\n", count);
    
    for ( i = 0; i < count; i++){
        datas[i].sum = datas[i].scores[0] + datas[i].scores[1] + &datas[i].scores[2];
        datas[i].avg = (float) datas[i].sum / SUB_N;
        printf("%-8s%d  %d  %d  %d  %.1f\n", datas[i].name, datas[i].scores[0], datas[i].scores[1], datas[i].scores[1], datas[i].sum, datas[i].avg);
    }
 
    for ( i = 0; i < SUB_N; i++){
        sum_class = 0;
        top_score = datas[0].scores[i];
        for ( j = 0; j < count; j++){
            sum_class +=  datas[j].scores[i];
            if (datas[j].scores[i] > top_score){
                top_score = datas[j].scores[i];
                top_name = j;
            }
        }
        avg_class = (float) sum_class / count;
        printf("%s - average : %.1f, Top : %s (%d)\n", * (pname+i), avg_class, datas[top_name].name, top_score);
    }
    
    fclose(fp);
    return 0;
}