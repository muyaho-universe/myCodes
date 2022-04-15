#include <stdio.h>
#include <stdlib.h>

struct st_point{ 
    float x; // x-coordinate value
    float y; // y coordinate value
}; 

int point = 1;
struct st_point* getPoint(); // After memory allocation, it receives the x,y values ​​of the structure, and returns the address of the structure.

int getPosition(struct st_point* p);
// Return value: quadrant position (0: on axis, 1:1st quadrant, 2:2nd quadrant, 3:3rd quadrant, 4:4th quadrant)
// Execution: Returns the location number (0~4) by identifying the location of th

int main(){
    struct st_point* mypoint[10];
    int pt[5] = {0};
    int area; 
    int i;

    for ( i = 0; i < 10; i++){
        mypoint[i] = getPoint();
    }
    for ( i = 0; i < 10; i++){
        area = getPosition(*(mypoint+i));
        if (area == 1) pt[1]+=1;
        else if (area == 2) pt[2]+=1;
        else if (area == 3) pt[3]+=1;
        else if (area == 4) pt[4]+=1;
        else pt[0]+=1;
        printf("%d", i + 1);
        if (i+1 == 1) printf("st");
        else if (i+1 == 2) printf("nd");
        else if (i+1 == 3) printf("rd");
        else printf("th");
        printf(" point: ");
        if(area == 0)  printf("located on the axis\n");
        else{
            printf("located in the ");
            if (area == 1) printf("1st quadrant\n");
            else if (area == 2) printf("2nd quadrant\n");
            else if (area == 3) printf("3rd quadrant\n");
            else printf("4th quadrant \n");
        }
       
    }
    printf("On axes: %d points\n", pt[0]);
    printf("In the 1st quadrant: %d points\n", pt[1]);
    printf("In the 2nd quadrant: %d points\n", pt[2]);
    printf("In the 3rd quadrant: %d points\n", pt[3]);
    printf("In the 4th quadrant: %d points\n", pt[4]);
    for ( i = 0; i < 10; i++) free(mypoint[i]);
    return 0;
}

struct st_point* getPoint(){
    struct st_point* p = (struct st_point*)malloc(sizeof(struct st_point));
    if (point == 1) printf("1st point: x and y values? ");
    else if (point == 2) printf("2nd point: x and y values? ");
    else if (point == 3) printf("3rd point: x and y values? ");
    else printf("%dth point: x and y values? ", point);
    scanf("%f %f", &(p->x), &(p->y));
    point ++;
    return p;
}

int getPosition(struct st_point* p){
    if (p->x == 0 || p->y == 0) return 0;
    else if(p->x > 0){
        if(p->y < 0) return 4;
        else return 1;
    }
    else{
        if (p->y>0) return 2;
        else return 3;
    }
}