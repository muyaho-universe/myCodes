//21800059 김대석 나대영교수님 c프로그래밍 01분반 과제 5-1
#include <stdio.h>
#include <time.h>

void split_time(long total_sec, int *hr, int *min, int *sec);
// total_sec 는 1970 년 1 월 1 일 이후 현재까지 흐른 시간을 전달하는 파라미터.
// hr, min, sec 는 현재 시간을 저장하는 변수
// hr:시간(0~23), min:분(0~59), sec:초(0~59) 데이터를 저장

int main(){
    long now;                   //현재 초를 저장하기 위한 변수
    int *hr, *min, *sec;        //현재 시간을 저장하는 포인트 변수
    now = time(0);

    split_time(now, hr, min, sec);

    printf("Current UTC: %d시 %d분 %02d초 입니다.\n", *hr, *min, *sec);
    return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec){
     int temp, temp_s, temp_m, temp_h; //현재시간 계산을 위한 변수들
    int date = total_sec / 86400;     //불필요한 값을 없애기 위한 변수
    total_sec -= 86400 * date;
    temp = total_sec;
    temp_s = temp % 60;
    temp_m = (temp % 3600 - temp_s) / 60;
    temp_h = temp /3600;
    *sec = temp_s;
    *min = temp_m;
    *hr = temp_h;       
}