// 21800059 김대석 오픈소스소프트웨어 실습 장소연 교수님 02분반 과제코드

#include <stdio.h>

struct score_struct{
    int first, second, third;
    int sum;
    float avg;
    char grade;
};

struct score_struct* get_score();


int main(){
    struct score_struct* scorelist[5];
    int i;

    for ( i = 0; i < 5; i++){
        printf("%d번 학생: ", i+1);
        scorelist[i] = get_score();
    }

    for ( i = 0; i < 5; i++){
        printf("%d번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", i + 1, scorelist[i]->sum, scorelist[i]->avg, scorelist[i]->grade);
    }
    
    return 0;
}

struct score_struct* get_score(){
    int i;
    struct score_struct* p = (struct score_struct*)malloc(sizeof(struct score_struct));

    scanf("%d %d %d", &p->first, &p->second, &p->third);

    p->sum = p->first + p->second + p->third;
    p->avg = p->sum / 3.0;
    if(p->avg>= 90) p->grade = 'A';
    else if(p->avg>= 80) p->grade = 'B';
    else if(p->avg>= 70) p->grade = 'C';
    else if(p->avg>= 60) p->grade = 'D';
    else p->grade = 'F';

    return p;
}