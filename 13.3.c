#include <stdio.h>
#include <stdlib.h>
struct st_point{ 
    float x; // x-coordinate value
    float y; // y-coordinate value 
}; 
struct st_point* get_point();
// After memory allocation, it receives the x,y values ​​of the structure, and returns the address

void save_points(struct st_point* list[], char* filename, int size);
// Parameters: array of points (array of structure pointers), file name to save, number of records
// Return value: none

int main(){
    struct st_point* mypoint[50]; // at most 50 points
    char* ordinals[3]={"st", "nd", "rd"}; 
    char filename[100] = "point.txt";  
    int size;

    printf("How many points do you want? ");
    scanf("%d", &size);

    for(int i=0;i<size;i++){
        if (i < 3) printf("%d%s point: x and y values? ", i+1, ordinals[i]);
        else printf("%dth point: x and y values? ", i+1);
        mypoint[i] = get_point();
    }

    save_points(mypoint, "point.txt", size);
    printf("Saved %d points.\n", size);

    for ( int i = 0; i < size; i++) free(mypoint[i]);
    
    return 0;
}

struct st_point* get_point(){
    struct st_point* p = (struct st_point*)malloc(sizeof(struct st_point));
    scanf("%f %f", &(p->x), &(p->y));
    return p;
}
void save_points(struct st_point* list[], char* filename, int size){
    FILE * fp;
    fp = fopen(filename, "w");
    int i ;
    for ( i = 0; i < size; i++){
        fprintf(fp,"%f %f\n", list[i]->x, list[i]->y);
    }
    printf("\n");
    fclose(fp);
}