#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define start 1
#define end 45
#define num 6

int matchLotto(int lotto1[num], int lotto2[num]);
// 파라미터 : 입력한 로또 배열과 프로그램의 로또 배열
// 리턴값 : 일치하는 로또번호 개수
// 수행내용 : 로또번호 배열을 파라미터로 받아 번호 몇개가 일치하는지 리턴

int main(){
    int lotto_com[num] = {};   // computer generated lottery numbers
    int lotto_user[num] = {};  // lottery number entered by user
    int i = 1, j;              // variable for loop
    int count = 0;          // The order of the lottery numbers currently being created (0, 1, 2, 3, 4, 5)
    int match_count = 0;    // Number of matching numbers (0-6)

    while (1){
        srand(time(0));
        lotto_com[0] = rand()%(end - start + 1)+start;
        while (i < num){
            lotto_com[i] = rand()%(end - start + 1)+start;
            for ( j = 0; j < i; j++){
                if (lotto_com[j] == lotto_com[i]){
                    i --;
                    break;
                }
            }
            i++;
        }
        if (i == num){
            break;
        }
    }
   
    while (1){
        printf("Enter the 1st number: ");
        scanf("%d", &lotto_user[0]);
        if (lotto_user[0] > 45 || lotto_user[0] < 1){
            printf("-> Wrong number!\n");
        }
        else{
            break;
        }
    }

    count = 1;
    i = 0;
    while (count < num){
        printf("Enter the %d", count + 1);
        if(count + 1 == 2) printf("nd");
        else if(count + 1 == 3) printf("rd");
        else printf("th");
        printf(" number: ");
        scanf("%d", &lotto_user[count]);

        if (lotto_user[count] > 45 || lotto_user[count] < 1){
            printf("-> Wrong number!\n");
        }

        else{
            for ( i = 0; i < count; i++){
               if ( lotto_user[i] == lotto_user[count]){
                    printf("-> Duplicated!\n");
                    count --;
                    break;
                }
               
            }
            count ++;   
        }
    }

    printf("\nThis week's lottery winning numbers are ");
    for ( i = 0; i < num; i++){
        if(i == num -1) printf("%d", lotto_com[i]);
        else printf("%d ", lotto_com[i]);
    }
    printf(".\n");
    printf("\n");
    printf("There are %d matching lottery numbers.", matchLotto(lotto_com, lotto_user));
    return 0;
}

int matchLotto(int lotto1[num], int lotto2[num]){
    int match_count = 0;
    for ( int i = 0; i < num; i++){
        for ( int j = 0; j < num; j++){
            if ( lotto1[i] == lotto2[j]){
                match_count++;
            }
        }
    }
    return match_count;
}