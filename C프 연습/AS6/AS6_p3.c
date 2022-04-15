//21800059 김대석 나대영교수님 c프로그래밍 01분반 과제 6-3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct STUDENT{
    char name[20];
    char idnum[10];
};

struct SCORE{
    int eng;
    int math;
    int sa;
    int prog;
};

struct STINFO{
    struct STUDENT stu;
    struct SCORE sco;       // stinfo->stu->name;
    int sum;
    float avg;              // 
};

int readFromFile(char* filename, struct STINFO * p[]);
 // data.txt 파일에서 데이터를 읽어들여 STINFO 구조체에 저장하고, 리턴은 읽은 라인의 수를 반환
 //  (예시 이미지의 경우 10 을 반환)

void sort(struct STINFO  * p[], int);
 // 전달받은 구조체의 정보를 이름순으로 정렬(오름차순) : bubble sort

struct STINFO *search(struct STINFO * p[], int, int);
 // 전달 받은 구조체에서 이름 또는 학번으로 학생 정보를 찾아주는 함수, 찾은 학생 정보의 메모리 주소 리턴
 // struct 형 리턴, 내용이 STINFO 리턴

void printstlist(struct STINFO * p[], int);
 //구조체에 있는 모든 학생의 정보를 출력하는 함수

bool svtofile(struct STINFO * p[], int count, char* filename);
 // 구조체에 있는 학생의 정보를 파일로 저장하는 함수, 크기 20 의 배열에 저장하기 위한 파일명을 입력 받을것, 파일 저장을 성공적으로 하였으면 true, 파일 저장을 실패하였으면 false 리턴

int main(){
    struct STINFO* info[50];      // at most 50
    struct STINFO* find_info;       //찾는 사람

    bool go = true;
    int menu;
    char sv_file[100];                  //저장할 이름을 받기 위한 문자열 배열
    char filename[100] = "data.txt";
    int count = readFromFile(filename, info);       //동적할당을 통해 파일 내 데이터 개수 받기

    printf("########################################################################################################\n");
    printf("##################                      학생 성적 프로그램 ver 1.0                           #############\n\n");
    while (1){
        printf("menu:\n");
        printf(" 1(sort), 2(search by name), 3(search by stnumber), 4(print list), 5(save to file), 6(end program): ");
        scanf("%d", &menu);
        if(menu == 1) sort(info, count);
        else if(menu == 2 || menu == 3) {
            find_info = search(info, count, menu);
            if (find_info == 0) printf("Can not find student information\n\n");     // 찾는 값이 없으면 0이 리턴
            else printf("%s %s %d %d %d %d %d %.2f\n\n", find_info->stu.idnum, find_info->stu.name, find_info->sco.eng, find_info->sco.math, find_info->sco.sa, find_info->sco.prog, find_info->sum, find_info->avg);
        }
        else if(menu == 4) printstlist(info, count);
        else if(menu == 5) {
            printf("Input file name to save:");
            scanf("%s", sv_file);   //이름 입력받기

            go = svtofile(info, count, sv_file);    // 함수 호출 및 bool값 입력받기
            if (go) printf("file saved\n\n");
            else printf("Error opening file for writing\n\n");
        }
        else break;
    }
    printf("Goodbye!!\n");
    for(int i=0; i < count; i++) free(info[i]);     // 동적할당 풀어주기
    return 0;
}

int readFromFile(char* filename, struct STINFO * p[]){
    FILE * fp;
    fp = fopen(filename, "r");              // 파일 열기
    int i = 0;
    while (!feof(fp)){
        char t_name[20], t_id[20];
        int t_eng, t_math, t_sa, t_prog;     //temporary variable for reading from file
        int t = fscanf(fp,"%s %s %d %d %d %d", t_name, t_id, &t_eng, &t_math, &t_sa, &t_prog);
        if (t <= 0) break;
        p[i] = (struct STINFO*) malloc(sizeof(struct STINFO));      // 구조체에 맞추어 동적할당하기
        strcpy(p[i]->stu.name, t_name);
        strcpy(p[i]->stu.idnum, t_id);
        p[i]->sco.eng = t_eng;
        p[i]->sco.math = t_math;
        p[i]->sco.sa = t_sa;
        p[i]->sco.prog = t_prog;
        p[i]->sum = t_eng + t_math + t_sa + t_prog;
        p[i]->avg = (float) (t_eng + t_math + t_sa + t_prog) / 4;
        i++;
    }
    fclose(fp);
    return i;
}

void printstlist(struct STINFO * p[], int cnt){
    for (int i = 0; i < cnt; i++){
        printf("%s %s %d %d %d %d %d %.2f\n", p[i]->stu.idnum, p[i]->stu.name, p[i]->sco.eng, p[i]->sco.math, p[i]->sco.sa, p[i]->sco.prog, p[i]->sum, p[i]->avg);
    }   // 출력하기
    printf("\n");
}

void sort(struct STINFO *p[], int count){
    struct  STINFO* t;
    for (int i = 0; i < count-1; i++){
        for (int j = i + 1; j < count; j++){
            if (strcmp(p[i]->stu.name, p[j]->stu.name)>0){  // 정렬하기, 비교했을 때 0보다 크면 위치 바꾸기
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        } 
    }
    printf("Sorted!!\n\n");
}

struct STINFO *search(struct STINFO * p[], int count, int menu){
    char n[20];
    char idnum[10];
    int go = 0;     // 어떤 값으로 갈지 말지
    int i;

    if (menu == 2){
        printf("input name:");
        scanf("%s", n); //이름찾기
        for (i = 0; i < count; i++){
            if(strcmp(p[i]->stu.name, n) == 0){
                go =1;
                break;
            }
        }

    }
    else{
        printf("input student number:");
        scanf("%s", idnum); //학번 찾기
        for (i = 0; i < count; i++){
            if(strcmp(p[i]->stu.idnum, idnum) == 0){
                go =1;
                break;
            }
        }
    }
    if(go) return p[i]; //있으면 그 값을 리턴
    else return 0;      // 없으면 0을 리턴
}

bool svtofile(struct STINFO * p[], int count, char* filename){
    if (filename[strlen(filename)-4] != '.' || filename[strlen(filename)-3] != 't' || filename[strlen(filename)-2] != 'x'|| filename[strlen(filename)-1] != 't'){ //.txt가 붙었는지 확인
        strcat(filename, ".txt");   // .txt 안붙어있으면 붙이기
    }
    FILE * fp;
    if (!(fp = fopen (filename, "w"))){     // open 실패시 false 리턴
        return false;
    }
    else{
        for (int i = 0; i < count; i++){        // filename.txt를 생성하고 집어 넣기
            fprintf(fp, "%s %s %d %d %d %d %d %.2f\n", p[i]->stu.idnum, p[i]->stu.name, p[i]->sco.eng, p[i]->sco.math, p[i]->sco.sa, p[i]->sco.prog, p[i]->sum, p[i]->avg);
        }
        return true;                // 했다고 리턴하기
    }
    fclose(fp);
}