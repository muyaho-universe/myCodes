#include <stdio.h>
#include <math.h>

struct point{ 
  float x; // x-coordinate value
  float y; // y coordinate value
}; 

float calcDistance(struct point* p1, struct point* p2); // Function to find the distance between two points

int main(){
    struct point p1, p2;

    printf("Point 1: x value? ");
    scanf("%f", &p1.x);
    printf("Point 1: y value? ");
    scanf("%f", &p1.y);
    printf("Point 2: x value? ");
    scanf("%f", &p2.x);
    printf("Point 2: y value? ");
    scanf("%f", &p2.y);

    printf("\nThe distance between the two points is %.1f.",calcDistance(&p1, &p2));

    return 0;

}

float calcDistance(struct point* p1, struct point* p2){
    float result;
    result = sqrt(pow((p1->x)-(p2->x),2) + pow((p1->y)-(p2->y),2));
    return result;
}