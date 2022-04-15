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
    char names_cp[13][100]={""}; //copied names
    char input[100]; //input character
    int num[13] = {0}; //number information
    int count = 0; //count the number of matching
    int i; // variable for loop
    int j = 0; // variable for assemble
    
    printf("Input >> ");
    scanf("%s", input);

    if (strlen(input) < 3){
        printf("3글자 이상 입력해주세요.\n");
    }
    else{
        for ( i = 0; i < 13; i++){
            strncpy(names_cp[i], names[i], strlen(input));
        }
        
        for ( i = 0; i < 13; i++){
            if (strcmp(input, names_cp[i]) == 0){
                num[j] = i;
                count ++;
                j ++;
            }
            
        }
        j = 0;
        printf("Matching : \n");
        for ( i = 0; i < count; i++){
            printf("[%s]\n", names[num[j]]);
            j++;
        }
        printf("%d major found\n", count);
    }
    return 0;

}