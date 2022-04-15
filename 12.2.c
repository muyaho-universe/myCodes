#include <stdio.h>
#include <stdlib.h>

struct rectangle{ 
    int x1, y1; 		// upper-left point 
    int x2, y2; 		// lower-right point
}; 

struct rectangle * get_points (); // Return: the pointer to the structure

int check_overlap(struct rectangle* r1, struct rectangle* r2); // If overlapped, return 1, otherwise return 0.

// Don't modify the main function! 
int main(){
    struct rectangle* rect1;  	// for the 1st rectangle
    struct rectangle* rect2;  	// for the 2nd rectangle
    printf("Rectangle #1\n");
    rect1 = get_points();
    printf("Rectangle #2\n");
    rect2 = get_points();

    if (check_overlap(rect1, rect2)) printf("They overlap.\n");
    else printf("They do not overlap.\n");
    free(rect1);
    free(rect2);
    return 0;
}

struct rectangle* get_points(){
    struct rectangle* p = (struct rectangle*)malloc(sizeof(struct rectangle));
    printf("upper-left point (x, y)? ");
    scanf("%d %d", &(p->x1), &(p->y1));
    printf("lower-right point (x, y)? ");
    scanf("%d %d", &(p->x2), &(p->y2));
    return p;
}

int check_overlap(struct rectangle* r1, struct rectangle* r2){
    int i1, j1, i2, j2;
    int v = 0;
    for ( i1 = r1->x1; i1 < r1->x2; i1++){
        for ( j1 = r1->y1; j1 > r1->y2; j1--){
            for ( i2 = r2->x1; i2 < r2->x2; i2++){
                for ( j2 = r2->y1; j2 > r2->y2; j2--){
                    if(i1 == i2 && j1 == j2) {
                        v = 1;
                        break;
                    }
                }
            }
        }
    }
    if (v) return 1;
    else return 0;
}
