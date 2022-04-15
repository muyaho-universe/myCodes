//21800059 김대석 나대영교수님 c프로그래밍 01분반 과제 5-3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define S_NUM 0
#define E_NUM 10               //배열의 시작과 끝 숫자

void menu();                        //메뉴 출력용 함수
void print_array(int [], int);     // 배열 출력 함수
void frequency(int [], int);
void input_data(int *, int *, int); //데이터 생성 함수
void idx(int*, int*, int);         //원하는 숫자의 인덱스
void print_frq(int*);               //빈도수 출력을 위한 함수

float dev(int *,int);               //표준편차 함수
int fun5(int*);                     //최빈수 함수

int main(){
    int size = 0;           //input size
    int no;                 //menu number
    int f=0;                  //최빈수 숫자
    float stdev;            //표준편차

    while (1){
        printf("input number of data:");
        scanf("%d", &size);
        if (size<=0) printf("Please input greater than 0\n");
        else break;
    }
    int ary[size];
    int ar_index[size]; //인덱스 번호를 담기 위한 배열
    int frq[11]={0};    //빈도수 체크를 위한 배열
    srand(time(0));     //랜덤값을 위한 srand 호출
    input_data(ary, frq, size);
    
    while (1){
        printf("\n");
        menu();                                                     //showing the menu

        while (1){
            printf("input menu:");
            scanf("%d", &no);
            if (no >= 1 && no <= 6) break;                          //getting number between 1 and 6
            else printf("Please input number between 1 and 6!\n");
        }
        printf("\n");
        if (no == 1) print_array(ary, size);
        else if (no == 2) print_frq(frq);
        else if (no == 3){
            stdev= dev(ary, size);
            printf("Standard deviation: %.2f\n", stdev);
        } 
        else if (no == 4) idx(ary, ar_index ,size);
        else if (no == 5) {
            f = fun5(frq);
            printf("Mode: %d, %d번 생성됨.\n", f, frq[f]);
        }
        else break;
    }
    printf("Good Bye\n");
    return 0;
}

void input_data(int *a, int *f, int s){
    int temp;
    for (int i = 0; i < s; i++){
        temp = rand()%(E_NUM - S_NUM + 1) + S_NUM;
        *(a + i) = temp;
        f[temp]++;
    }
}

void menu(){
    printf("************************************************\n");
    printf("** (1) 생성된 데이터의 내용 출력 (display)    **\n");
    printf("** (2) 각 숫의 빈도수 (frequency)를 출력      **\n");
    printf("** (3) 입력된 데이터의 표준편차 출력          **\n");
    printf("** (4) 입력 숫자를 DATA array에서 찾기        **\n");
    printf("** (5) 최빈수(mode) 찾기                      **\n");
    printf("** (6) 종료                                   **\n");
    printf("************************************************\n");
}

float dev(int *a,int s){
    float sum = 0.0, avg;
    float v = 0;                //variance
    float stdev;            //표준편차

    for (int i = 0; i < s; i++) sum += a[i];
    avg = (float) sum / s;

    for (int i = 0; i < s; i++) v += pow((a[i]-avg),2);
    v /= (float) (s - 1);

    stdev = sqrt(v);
    return stdev;
}

void print_array(int a[], int s){
    for (int i = 0; i < s; i++){
        printf("%2d ", a[i]);
        if ((i+1) % 10 == 0 ) printf("\n");
    }
}

void idx(int* a, int* ai, int s){
    int num;                    //4번에서 찾고 싶은 숫자
    int i, j = 0;               //variable for loop
    while (1){
        printf("input find number:");
        scanf("%d", &num);
        if (num >= 0 && num <= 10) break;
        else printf("Please input number between 0 and 10!\n");  
    }
    for ( i = 0; i < s; i++){
        if (*(a+i) == num){
            *(ai+j) = i;
            j++;
        }
    }
    for ( i = 0; i < j; i++){
        printf("data[%d] ", ai[i]+1);
    }
    printf("\n");
}

int fun5(int* f){
    int num = 0, max = 0;
    int i, j;

    for ( i = 0; i < 11; i++){
        if (f[i] > max){
            max = f[i];
            num = i;
        }
    }
    return num;
}

void print_frq(int* f){
    for (int i = 0; i < 11; i++) printf("%02d: %2d  ", i, f[i]);
    printf("\n");
}