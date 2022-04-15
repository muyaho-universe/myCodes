#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define start 1
#define end 45
#define num 6

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

    for ( i = 0; i < num; i++){
        for ( j = 0; j < num; j++){
            if ( lotto_com[i] == lotto_user[j]){
                match_count++;
            }
        }
    }
    printf("There are %d matching lottery numbers.", match_count);
    return 0;
    
    
}