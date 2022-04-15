// 21800059 김대석 오픈소스소프트웨어 실습 장소연 교수님 02분반 과제코드

#include <stdio.h>

int main(){
    int score[5][3];
    int sum[5] = {0};
    float avg[5];
    char grade[5] = {'A', 'B', 'C', 'D', 'F'};
    int index[5];
    int i;

    for ( i = 0; i < 5; i++){
        printf("%d번 학생 : ", i + 1);
        scanf("%d %d %d", &score[i][0], &score[i][1], &score[i][2]);
        sum[i] = score[i][0] + score[i][1] + score[i][2];
        avg[i] = sum[i] / 3.0;
        if(avg[i]>= 90) index[i] = 0;
        else if(avg[i]>= 80) index[i] = 1;
        else if(avg[i]>= 70) index[i] = 2;
        else if(avg[i]>= 60) index[i] = 3;
        else index[i] = 4;
        
    }

    for ( i = 0; i < 5; i++)
        printf("%d번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", i+1, sum[i], avg[i], grade[index[i]]);
    
    return 0;
}