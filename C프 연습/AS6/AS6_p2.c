//21800059 김대석 나대영교수님 c프로그래밍 01분반 과제 6-2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define STR_N 0
#define END_N 19            //랜덤을 위한 시작값과 끝값

void hangman(char * w[], char* t, char c, int index);
// Parameter: 컴퓨터가 단어 유추를 선택할 포인트 배열 w, 화면에 '-'를 출력하기 위한 포인트 배열 t, 사용자가 입력한 문자 c,컴퓨터가 선택한 랜덤 값 index
// Return value: none
// Execution: 있으면 있다 말해주기

bool IsAnswer(char * w[], char *a, int index);
// Parameter: 컴퓨터가 단어 유추를 선택할 포인터 배열 w, 사용자가 입력한 정답 포인터 a, 컴퓨터가 선택한 랜덤 값 index
// Return value: 정답: True, 오답: False
// Execution: 있으면 있다 말해주기

int main(){
    char * words[] = {"school", "home", "sweet", "gwacheon", "seoul", "jonggang", "covid", "sadness", "katusa", "carroll", "gimalgosa", "seattle", "washington", "ssgdenette", "babykatusa", "pohangmission", "usfk", "jipgalae", "tinybubble", "hihihee"};
    // 20개의 영어 단어
    char guess;        //사용자가 입력하는 단어를 받기 위한 문자형 변수
    char answer[100];    // 정답입력을 받기위한 string
    char con;           // 계속 할 것인지 여부를 묻는 문자형 변수 continue
    int index;          // 랜덤한 index 번호
    int chance;         // 10번의 기회
    int i;              // 반복문을 위한 변수 
    bool go =true;      

    srand(time(0));     // 랜덤을 위한 srand함수 호출

    while (1){
        index = rand()%(END_N - STR_N + 1) + STR_N;     // 0부터 19사이 랜덤한 값을 index 변수에 집어넣기
        char temp[strlen(words[index])];                                    // 글자수만큼 -을 표시하기 위한 문자열
        for ( i = 0; i < strlen(words[index]); i++){
            temp[i] ='_';
        }
        temp[strlen(words[index])] = '\0';
        // printf("picked word: %s\n\n", words[index]);            // 잘돌아가는지 확인하기 위해 쓴 printf함수
        chance = 10;                                          // 10번의 기회
         go = true;
        while (1){
            if (!go) break;                                    // 정답을 맞춰서 그 전 루프에서 탈출한 것임으로 이 루프 역시 종료시킴
            go = true;                                        // go 초기화
            printf("The word looks like this:%s\n", temp);
            for ( i = 0; i < strlen(words[index]); i++){
                temp[i] ='_';
            }                                               // 지난번 결과를 보여준뒤 다시 '_'로 초기화

            if (chance == 0){
                printf("You lost!!!\n");
                break;
            }
            
            while (1){
                printf("You have %d guess left.\n", chance);    //틀렸을 경우에도 기회를 표시해 줘야함
                printf("your guess: ");
                scanf("%c", &guess);                        //한글자만 가져가기 위한 scanf 사용
                while (getchar()!='\n');                    // 개행 문자 제거
                if (guess >= 'A' && guess <= 'Z') {         //대문자일 경우 아스키코드를 사용하여 소문자로 전환
                    guess+=32;
                    break;
                }
                else if (guess >= 'a' && guess <= 'z') break;  // 제대로 입력 받았기 때문에 반복문에서 빠져 나온다
                else if (guess == '0'){ //정답을 맞추겠다고 선언한 경우           
                    printf("\ninput answer:");
                    scanf("%s", answer);            // 정답을 입력받음
                    while (getchar()!='\n');        // 개행 문자 제거
                    answer[strlen(answer)] = '\0';  //answer가 문자열임을 알려줌

                    if(IsAnswer(words, answer, index)){       // IsAnswer 함수를 호출하여 정답이면 TRUE를 오답이면 FALSE를 리턴
                        printf("%s is correct\n", answer);
                        printf("You win!!\n");
                        go = false;                            // 밑에 hangman 함수를 실행시킬지 말지(go/ no go) 결정
                        break;                                  // 무한 루프에서 탈출
                    }
                    else printf("incorrect!\n\n");                // false 리턴시 출력되는 문장
                }
                else {
                    printf("\n");
                    continue;                                  // 알파벳이나 0 외 다른 문자가 들어오면 다시 입력받기 위한
                }
            }

            if(go){
                hangman(words, temp, guess, index);
                printf("\n");
                chance --;
            }
        }
        printf("\nDo you want another game(y/n)");        //게임을 계속할지 묻는다
        scanf("%c", &con);
        while (getchar()!='\n');                    // 개행 문자 제거
        if (con == 'y' || con == 'Y') continue;        //계속함
        else break; // 싫다고 하면 그만함

    }

    return 0;
}

bool IsAnswer(char * w[], char *a, int index){
    if (!strcmp(w[index], a)) return true;          //두 문자열을 비교해서 같으면 0이 리턴되는 strcmp 함수
    else return false;
}

void hangman(char * w[], char* t, char c, int index){       // 문자열 안에 찾는 문자가 있는지 묻는 함수
    char temp;                                              // c와 비교를 위한 단일 문자 temp
    for (int i = 0; i < strlen(w[index]); i++){
        temp = *(w[index]+i);                               // temp는 반복문을 통해 word[index]+i의 문자가 입력된다.
        if(temp == c ){                                     // temp와 c 같을 경우
          t[i] = c;                                         // '_'를 출력하는 포인터의 i 번째 칸에 c를 집어 넣는다.
        }
    }
}