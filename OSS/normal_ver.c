// 21800059 김대석 오픈소스소프트웨어 실습 장소연 교수님 02분반 과제코드

#include <stdio.h>

int main(){
    int first_1, first_2, first_3;
    int second_1, second_2, second_3;
    int third_1, third_2, third_3;
    int fourth_1, fourth_2, fourth_3;
    int fifth_1, fifth_2, fifth_3;

    int sum = 0;
    float avg;
    char grade;

    int i;

    printf("1번 학생 : ");
    scanf("%d %d %d", &first_1, &first_2, &first_3);

    printf("2번 학생 : ");
    scanf("%d %d %d", &second_1, &second_2, &second_3);

    printf("3번 학생 : ");
    scanf("%d %d %d", &third_1, &third_2, &third_3);

    printf("4번 학생 : ");
    scanf("%d %d %d", &fourth_1, &fourth_2, &fourth_3);

    printf("5번 학생 : ");
    scanf("%d %d %d", &fifth_1, &fifth_2, &fifth_3);

    sum = first_1 + first_2 + first_3;
    avg = sum / 3.0;
    if(avg>= 90) grade = 'A';
    else if(avg>= 80) grade = 'B';
    else if(avg>= 70) grade = 'C';
    else if(avg>= 60) grade = 'D';
    else grade = 'F';
    printf("1번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", sum, avg, grade);
    sum = 0;

    sum = second_1 + second_2 + second_3;
    avg = sum / 3.0;
    if(avg>= 90) grade = 'A';
    else if(avg>= 80) grade = 'B';
    else if(avg>= 70) grade = 'C';
    else if(avg>= 60) grade = 'D';
    else grade = 'F';
    printf("2번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", sum, avg, grade);
    sum = 0;

    sum = third_1 + third_2 + third_3;
    avg = sum / 3.0;
    if(avg>= 90) grade = 'A';
    else if(avg>= 80) grade = 'B';
    else if(avg>= 70) grade = 'C';
    else if(avg>= 60) grade = 'D';
    else grade = 'F';
    printf("3번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", sum, avg, grade);
    sum = 0;

    sum = fourth_1 + fourth_2 + fourth_3;
    avg = sum / 3.0;
    if(avg>= 90) grade = 'A';
    else if(avg>= 80) grade = 'B';
    else if(avg>= 70) grade = 'C';
    else if(avg>= 60) grade = 'D';
    else grade = 'F';
    printf("4번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", sum, avg, grade);
    sum = 0;

    sum = fifth_1 + fifth_2 + fifth_3;
    avg = sum / 3.0;
    if(avg>= 90) grade = 'A';
    else if(avg>= 80) grade = 'B';
    else if(avg>= 70) grade = 'C';
    else if(avg>= 60) grade = 'D';
    else grade = 'F';
    printf("5번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", sum, avg, grade);
    sum = 0;

    return 0;
}