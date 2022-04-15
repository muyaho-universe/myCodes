#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int i = 1;
struct st_point{
    float x; // x-coordinate value
    float y; // y coordinate value
};
struct st_point*  get_point();  
// After getting x and y from user input, return a structure pointer to st_point which must allocate the memory space dynamically to hold x and y. 

float calc_distance (struct st_point* p1, struct st_point* p2); 
// Function of the distance of the two points
// Parameter: two structure pointers. 

int main(){
    struct st_point* point1; //pointer for the first point
    struct st_point* point2; // Pointer for the second point
    point1 = get_point();
    point2 = get_point();

    printf("\nThe distance between the two points is %.1f.",calc_distance (point1, point2));
    free(point1);
    free(point2);
    return 0;
}

struct st_point*  get_point(){
    struct st_point* p = (struct st_point*)malloc(sizeof(struct st_point));
    printf("Point %d: x value? ", i);
    scanf("%f", &p->x);
    printf("Point %d: y value? ", i);
    scanf("%f", &p->y);
    i++;
    return p;
}

float calc_distance (struct st_point* p1, struct st_point* p2){
    float result;
    result = sqrt(pow((p1->x)-(p2->x),2) + pow((p1->y)-(p2->y),2));
    return result;
}