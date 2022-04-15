#include <stdio.h>

int wateringPlants(int* plants, int capacity);

int main (){
    int plants[1000] = {1,1,1,4,2,3};
    int capacity;

    int result;

    scanf("%d", &capacity);
    result = wateringPlants(plants, capacity);
    printf("%d", result);
    return 0;
}


int wateringPlants(int* plants, int capacity){
    int i = 0;
    int steps = -1;
    int water = capacity;
    int temp, index;
    
    while (plants[i] != 0){
        if (plants[i] == -1) {
            i++;
            steps++;
            continue;
        }
        else{
            if (water >= plants[i]){
                water -= plants[i];
                steps++;
                plants[i] = -1;
                i++;
            }
            else{
                steps += (i+1);
                i = 0;
                water = capacity;
            }
        }
    }
    
    return steps;
}