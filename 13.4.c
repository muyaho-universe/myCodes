#include <stdio.h>
#include <stdlib.h>

struct st_point{ 
    float x; 		 
    float y; 		
}; 

int load_points(struct st_point* list[], char* filename);
// Parameters: array of points to be saved (structure pointer array), file name to read
// Return value: the number of read points
// Execution: Read points from a file after dynamic memory allocation, and return the number of points.

int get_position(struct st_point* p);
// Return value: quadrant position (0: on axis, 1:1st quadrant, 2:2nd quadrant, 3:3rd quadrant, 4:4th quadrant)
// Execution: Returns the location number (0~4) by identifying the location of the received point

int main(){
    struct st_point* mypoint[50];  
    char* ordinals[4]={"st", "nd", "rd", "th"}; 
    int size; 
    int count[5]={0}; 
    int i, pos; 
    char filename[100] = "point.txt"; 

    size = load_points(mypoint, filename);
    for(i=0; i<size; i++){
        pos = get_position(mypoint[i]);
        count[pos]++;
    }
    printf("%d points form %s\n", size, filename);
        
    printf("On axes: %d points\n", count[0]);
    for(i=1; i<=4; i++)
        printf("In the %d%s quadrant: %d points\n", i, ordinals[i-1], count[i]);
        
    return 0;
}

int load_points(struct st_point* list[], char* filename){
    FILE * fp;
    fp = fopen(filename, "r");
    int i = 0;
    while (!feof(fp)){
        int t_x, t_y;     //temporary variable for reading from file
        int t = fscanf(fp,"%f %f", &t_x, &t_y);
        if (t <= 0) break;
        list[i] = (struct st_point*) malloc(sizeof(struct st_point));
        list[i]->x = t_x;
        list[i]->y = t_y;
        eval_bmi(*(list+i));
        i++;
    }
    fclose(fp);
    return i;
}

int get_position(struct st_point* p){
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