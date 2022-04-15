#include <stdio.h>

struct rectangle{
   int x1, y1; // upper-left point 
   int x2, y2; // lower-right point
};

int check_overlap(struct rectangle r1, struct rectangle r2); // If overlapped, return 1, otherwise return 0.

int main(){
    struct rectangle nemo1;
    struct rectangle nemo2;
    int check;

    printf("Rectangle 1: upper-left point (x, y)? ");
    scanf("%d %d", &nemo1.x1, &nemo1.y1);
    printf("Rectangle 1: lower-right point (x, y)? ");
    scanf("%d %d", &nemo1.x2, &nemo1.y2);

    printf("Rectangle 2: upper-left point (x, y)? ");
    scanf("%d %d", &nemo2.x1, &nemo2.y1);
    printf("Rectangle 2: lower-right point (x, y)? ");
    scanf("%d %d", &nemo2.x2, &nemo2.y2);    

    check = check_overlap(nemo1, nemo2);
    if(check) printf("They overlap.");
    else printf("They do not overlap.");

    return 0;
}

int check_overlap(struct rectangle r1, struct rectangle r2){
    int i1, j1, i2, j2;
    int v = 0;
    
    for ( i1 = r1.x1; i1 < r1.x2; i1++){
        for ( j1 = r1.y1; j1 > r1.y2; j1--){
            for ( i2 = r2.x1; i2 < r2.x2; i2++){
                for ( j2 = r2.y1; j2 > r2.y2; j2--){
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