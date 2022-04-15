#include <stdio.h>
void markarea(int p[5][5], int z[5][5], int xpos, int ypos, int area, int value);
// Execution: Starting from the xpos and ypos of the original matrix (p), search in all directions, and for the column that matches the value, put the area number (area) in the same position column of the area matrix (z).

void printmat(int p[5][5]);

int main(void) {
    int picture[5][5]={0}; // original pattern
    int zone[5][5] = {0}; // area pattern
    int row=5, col=5;  
    int area=0;  // area number
    FILE *fp;
    
    fp = fopen("picture.txt", "rt");
    for(int i= 0; i < row; i++){
        for(int j= 0; j < col; j++)
            fscanf(fp, "%d", &picture[i][j]);
    }
    fclose(fp);

    printmat(picture);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(picture[i][j] != 0 && zone[i][j]==0){ // original pattern is not 0, and not checked yet.
                area++; // new area 
                int value=picture[i][j]; // pattern value
                markarea(picture, zone, i, j, area, value); // Mark all the areas with the same pattern 
            }
        }
    }
    
    printf("\n%d areas found.\n\n", area);
    printmat(zone);
} 

void printmat(int p[5][5]){
    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

void markarea(int p[5][5], int z[5][5], int xpos, int ypos, int area, int value){
    z[xpos][ypos] = area;
    if (p[xpos+1][ypos] == value) return markarea(p, z, xpos+1, ypos, area, value);
    if (p[xpos][ypos+1] == value) return markarea(p, z, xpos, ypos+1, area, value);
    if (xpos > 0 && p[xpos-1][ypos] == value) return markarea(p, z, xpos-1, ypos, area, value);
    if (ypos > 0 && p[xpos][ypos-1] == value) return markarea(p, z, xpos, ypos-1, area, value);
    else return;
}