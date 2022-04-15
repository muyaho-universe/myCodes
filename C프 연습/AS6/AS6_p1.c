//21800059 김대석 나대영교수님 c프로그래밍 01분반 과제 6-1

#include <stdio.h>
#include <string.h>

#define CARDS 52                    //카드의 총 개수 각각 13 x 4 = 52
#define FACES 13                    // 각각의 숫자 1부터 왕까지

// card structure definition 
struct card { 
    const char *face; // define pointer face 
    const char *suit; // define pointer suit 
}; 
// new type name for struct card
typedef struct card Card; 

void fillDeck( Card * wDeck, const char * wFace[], const char * Suit[] );
// Parameter: structer pointer wDeck, constant character pointer array wFace and Suit
// Return value: none
// Execution: load the deck with Cards

void find_odds_reds( const Card * wDeck );
// Parameter: constant structer pointer wDeck, 
// Return value: none
// Execution: find evry both reds and odds numbers in the deck, and print it out


int main( void ){ 
    Card deck[ CARDS ]; // define array of Cards
    // initialize array of pointers
    const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    // initialize array of pointers
    const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};
    fillDeck( deck, face, suit ); // load the deck with Cards
    find_odds_reds( deck );       // 홀수이면서 빨간색인 카드를 찾는 함수 호출
    return 0;
} // find evry both reds and odds numbers in the deck
    
void fillDeck( Card * wDeck, const char * wFace[], const char * Suit[] ){ 
    int i, j, k; 
    for ( i = 0; i < CARDS; ++i ) { 
        j=i%FACES; k=i/FACES;
        wDeck[i].face = wFace[ j ];
        wDeck[i].suit = Suit[ k ];
    }
}

void find_odds_reds( const Card * wDeck ){ 
    int i, j;
    printf("The following cards are Red and odd in the same time\n");
    for ( i = 0; i < CARDS/2; i +=13) {                                 //처음 두 덱이 각각 Hearts와 Diamonds이므로 CARDS의 절반만 탐색하면 됐다.
        for ( j = 0; j < FACES; j+=2){                                  // 각각 FACES는 13까지 있으므로 2씩 늘어가면 된다.
            printf( "%5s of %-7s\n", wDeck[j].face, wDeck[i].suit);
        }
    }
}