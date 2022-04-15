#include <stdio.h>
#include "score.h"

int main(void){
    struct Score* s[20];
    int count = 0, menu;
    int isUpdated, isAdd, isDel;
    int selectedNum;
    int go;
    char filename[100]="score.txt";
    int NUM = 1;
    

    count = load_score(s, filename);
    if (count != 0)
    {
        NUM = count + 1;
    }
    
    while (1){
        if (count ==20) break;

        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            readScore(s, count);
        }
        else if (menu == 2){
            s[count] = get_score(NUM);
            count++;
            NUM++;
        }
        else if (menu == 3){
            readScore(s, count);
            printf("\n번호는 (취소 :0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            s[selectedNum-1] = updateScore(selectedNum);
            printf("=> 수정됨!\n");
        }
        else if (menu == 4){
            readScore(s, count);
            printf("\n번호는 (취소 :0)?");
            scanf("%d", &selectedNum);
            if (selectedNum == 0) continue;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &go);
            if (go != 1) continue;
            for (int i = selectedNum; i < count; i++)
            {
                deleteScore(s, i, NUM);
            }
            count--;
            printf("=> 삭제됨!\n");
        }
        else if(menu == 5){
            save_score(s, filename, count);
            
        }
        else if (menu == 6){
            searchData(s, count);
        }
        
    }
    printf("종료됨!\n");
    return 0;
}