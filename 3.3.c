#include <stdio.h>

int main() {
    int width, height; //
    int count1 = 0; // "정사각형"의 개수
    int count2 = 0; // "가로형 직사각형"의 개수
    int count3 = 0; // "세로형 직사각형"의 개수
    int i=0;

    while (i == 0){
        printf("직사각형의 가로 크기와 세로 크기를 입력하시오. : ");
        scanf("%d %d", &width, &height);
        if (width > 0 && height > 0) {
            if (width > height) {
                count2 ++;
            }
            else if (width < height) {
                count3 ++;
            }
            else{
                count1 ++;
            }
            
        }
        else{
            i = 1;
        }

    }
    printf("\"정사각형\"의 개수는 %d 입니다.\n", count1);
    printf("\"가로형 직사각형\"의 개수는 %d 입니다.\n", count2);
    printf("\"세로형 직사각형\"의 개수는 %d 입니다.\n", count3);


    return 0;

}