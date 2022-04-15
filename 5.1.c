/*This code is showing the number of family member
    Daeseok Kim Oct 1st, 2021 */

#include <stdio.h>

int main(){
    
    int birth_year; // Year of birth
    int year[100]; // array for date of birth (up to 100)
    int count_person = 0; // Number of people entered
    int count_baby = 0; // Number of infants
    int count_child = 0; // Number of children
    int count_youth = 0; // Number of adolescents
    int count_young = 0; // Number of youth
    int count_adult = 0; // Number of middle age
    int count_old = 0; // Number of old age
    int i; //variable for loop
    int this_year = 2021; //this year

    for(i = 0; i < 100; i++){
        printf("Enter the year of birth of person %d. ", i +1);
        scanf("%d", &birth_year);
        year[i] = this_year - birth_year + 1;

        if(birth_year > 2021){ 
            break;
        }
        if(year[i] < 7){
            count_baby ++;
            count_person ++;
        }
        else if (year[i] < 13) {
            count_child ++;
            count_person ++;
        }
        else if (year[i] < 20) {
            count_youth ++;
            count_person ++;
        }
        else if (year[i] < 30) {
            count_young ++;
            count_person ++;
        }
        else if (year[i] < 60) {
            count_adult ++;
            count_person ++;
        }
        else if(year[i] >= 60){
            count_old ++;
            count_person ++;
        }
        
        
        
    }
    for(i = 0; i < count_person; i ++){
      printf("The person %d is %d years old.\n", i + 1, year[i]);
    }
    printf("There are %d infant, %d child, %d adolescent, %d youth, %d middle age, and %d old age.\n", count_baby, count_child, count_youth, count_young, count_adult, count_old);
  
    return 0;
}