#include <stdio.h>

void PrintCharWithBlank(int blanks, int size, char ch);
// 파라미터: blanks : 빈칸의 개수, size : 출력할 문자의 개수,ch : 출력할 문자
// 리턴값 : 없음
// 수행내용 : blanks 숫자만큼 빈칸 출력, size 개수만큼 ch 문자 출력 후 개행

int main(void) {
    char ch;
    int height, blank;

    printf("사용할 문자? ");
    scanf("%c", &ch);
    printf("높이와 여백의 크기? ");
    scanf("%d %d", &height, &blank);
    PrintCharWithBlank(blank, height, ch);
    return 0;
}

void PrintCharWithBlank(int blanks, int size, char ch){
    if(size < 1 || blanks < 1) printf("잘못 입력하셨습니다.");
    else{
        for (int i = 1; i <= size; i++){
            for (int j = 0; j < blanks; j++){
                printf(" ");
            }
            for (int j = 1; j <= size - i; j++){
                printf(" ");
            }
            for (int j = 1; j <= i; j++){
                printf("%c", ch);
            }
            printf("\n");
        }
    }
}