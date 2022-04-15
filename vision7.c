#include <stdio.h>
#include <string.h>
#include <time.h>

void bubble_sort(char arr[], int count);

void guesspassword(char arr[], int L, int C);

int main(){
    int i, j = 0;
    char c_ary1[21];
    char c_ary2[5] = {'a', 'e', 'i', 'o', 'u'};
    int L, C;

    for ( i = 0; i < 26; i++){
        if (i + 97 == 'a' || i + 97 == 'e' || i + 97 == 'i' || i + 97 == 'o' || i + 97 == 'u') continue;
        else {
            c_ary1[j] = i + 97;
            j++;
        }
    }

    printf("L과 C입력: ");
    scanf("%d %d", &L, &C);
    while (getchar()!='\n');        // 개행 문자 제거
    char str[C+C];
    char tempstr[C];

    printf("%d개의 문자 입력: ", C);
    fgets(str, C+C, stdin);
    
    j = 0;
    
    for ( i = 0; i < 2*C; i++){
        if (str[i] == ' ') continue;
        else if (str[i] == '\0') break;
        else {
            tempstr[j] = str[i];
            j++;
        }
    }
    
    bubble_sort(tempstr, C);

    printf("sort: %s", tempstr);

    guesspassword(tempstr, L, C);

    
    return 0;
}

void bubble_sort(char arr[], int count)    // 매개변수로 정렬할 배열과 요소의 개수를 받음
{
    int temp;

    for (int i = 0; i < count; i++)    // 요소의 개수만큼 반복
    {
        for (int j = 0; j < count - 1; j++)   // 요소의 개수 - 1만큼 반복
        {
            if (arr[j] > arr[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
            {                                 // 큰 값을
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;            // 다음 요소로 보냄
            }
        }
    }
}

void guesspassword(char arr[], int L, int C){
    int ja, mo;
    int index_mo[C-2], index_ja[C-1];
    char guess[L];
    int i, j = 0, k = 0;
    for( i = 0; i < C; i++){
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
            mo++;
            index_mo[j] = i;
            j++;
        }
        else {
            ja ++;
            index_ja[k] = i;
            k++;
        }
    }

    i = 0;
    j = 0;
    k = 1;
    while (1){
        guess[0] = index_mo[j];
        guess[1] = index_ja[k];
        guess[2] = index_ja[k-1];

        for ( i = 0; i < L-3; i++){
            if (arr[i] != index_mo[j] && arr[i] != index_mo[k] && arr[i] != index_mo[k-1]){
                guess[i+3] = arr[i];
            }
        }
        
        bubble_sort(guess, L);
        printf("result: %s\n", guess);
        j++;
        k++;
        
    }
    


}