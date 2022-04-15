#include <stdio.h>
#include <string.h>

int main(){
    char names[13][100]={"Global Leadership School",
    "International Studies, Languages and Literature",
    "Management and Economics",
    "Law",
    "Counseling Psychology and Social Welfare",
    "Communication Arts",
    "Spatial Environment System Engineering",
    "Mechanical and Control Engineering",
    "Contents Convergence Design",
    "Life Science",
    "Computer Science and Electrical Engineering",
    "Global Entrepreneurship and ICT",
    "Creative Convergence Education"
    };
    char input[100] = {" "};
    int num[13] = {0}; //number information
    int count = 0; //count
    int i, j, k; //variable for loop
    int a = 0; // variable for number

    printf("Input >> ");
    scanf("%s", input);
    
    for ( i = 0; i < 13; i++){
        k = 0;
        for ( j = 0; j < strlen(names[i]); j++){
            if ( input[k] == names[i][j]){
                k ++;
                if (k == strlen(input)){
                    num[a] = i;
                    a ++;
                    count ++;
                    break;
                }
            }
            else{
                k = 0;
            }   
        }    
    }
    printf("Matching : \n");
    for ( i = 0; i < count; i++){
        printf("[%s]\n", names[num[i]]);
    }
    
    printf("%d major found\n", count);
    
    
    return 0;
}