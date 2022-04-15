#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int com_finger; // Computer generated rock (1), paper (2), and scissors (3)
    int my_finger; // rock (1), paper (2), and scissors (3) made by user
    int score[2][3]={}; // Number of results (Row 0: Computer wins, draws, loses, Row 1: User wins, draws, loses)
    int i, j; // variable for loop
    
    while (1){
        printf("Enter rock (1), paper (2), and scissors (3).");
        scanf("%d", &my_finger);

        srand(time(0));
        com_finger = rand()%3+1;

        if (my_finger == 0){
            break;
        }
        
        else if (my_finger == 1){ //User rock
            if (com_finger == 1){ //Computer rock
                printf("Computer: rock -> Draw!\n");
                score[0][1] ++;
                score[1][1] ++;
            }
            else if (com_finger == 2){ //Computer paper
                printf("Computer: paper -> Computer Wins!\n");
                score[0][0] ++;
                score[1][2] ++;
            }
            else{ //Computer scissors
                printf("Computer: scissors -> User Wins!\n");
                score[0][2] ++;
                score[1][0] ++;
            }

        }

        else if (my_finger == 2){ //user paper
            if (com_finger == 1){ //Computer rock
                printf("Computer: rock -> User Wins!\n");
                score[0][2] ++;
                score[1][0] ++;
            }
            else if (com_finger == 2){  //Computer paper
                printf("Computer: paper -> Draw!\n");
                score[0][1] ++;
                score[1][1] ++;
            }
            else{ //Computer scissors
                printf("Computer: scissors -> Computer Wins!\n");
                score[0][0] ++;
                score[1][2] ++;
            }

        }

        else if (my_finger == 3){ //user scissors
            if (com_finger == 1){ //Computer rock
                printf("Computer: rock -> Computer Wins!\n");
                score[0][0] ++;
                score[1][2] ++;
            }
            else if (com_finger == 2){ //Computer paper
                printf("Computer: paper -> User Wins!\n");
                score[0][2] ++;
                score[1][0] ++;
            }
            else{ //Computer scissors
                printf("Computer: scissors -> Draw!\n");
                score[0][1] ++;
                score[1][1] ++;
            }
        }
    }
    
    printf("\nComputer: %d wins, %d losses, %d draws\n", score[0][0], score[0][2],  score[0][1]);
    printf("User: %d wins, %d losses, %d draws", score[1][0], score[1][2],  score[1][1]);

    return 0;



}