#include <stdio.h>
#include <string.h>


int main(){
    char names[13][100]={
        "Global Leadership School",
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
        "Creative Convergence Education"};
    int size[13] = {0}; // numbers of
    int long_index = 0; //indext for longest string
    int short_index = 0; //indext for shortest string
    int max = 0; //for longest string
    int min = 100; //for shortest string
    int i, j; //variable for loop

    for ( i = 0; i < 13; i++){
        size[i] = strlen(names[i]);
        if ( size[i] >= max){
            long_index = i;
            max = size[i];
        }
        if (size[i] <= min){
            short_index = i;
            min = size[i];
        }
    }

    printf("가장 긴 학부 이름은 %s\n가장 짧은 학부 이름은 %s 입니다.", names[long_index], names[short_index]);
    return 0;
    
}