#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_num{ 
    char ch;
    int a, b, c;
};

int load_num(struct st_num* p[], char* filename);

int main(){
    struct st_num* nums[10]; 	// at most 10 numbers. 
    int count = load_num(nums, "data.txt");
    int cal[10] = {0}; 

    for (int i = 0; i < count; i++){
        switch (nums[i]->ch)
        {
        case '+':
            cal[i] = nums[i]->a + nums[i]->b +nums[i]->c;
            break;
        
        case '-':
            cal[i] = nums[i]->a - nums[i]->b -nums[i]->c;
            break;
        case '*':
            cal[i]= nums[i]->a * nums[i]->b *nums[i]->c;
            break;
        case '/':
            cal[i]= nums[i]->a / nums[i]->b /nums[i]->c;
            break;
        case '%':
            cal[i]= nums[i]->a % nums[i]->b %nums[i]->c;
            break;    
        }
        printf("%c %d %d %d     line number %d: %d\n", nums[i]->ch, nums[i]->a, nums[i]->b, nums[i]->c, i, cal[i]);

    }
    return 0;
}


int load_num(struct st_num* p[], char* filename){
    FILE * fp;
    fp = fopen(filename, "r");
    int i = 0;
    while (!feof(fp)){
        char t_ch;
        int t_a, t_b, t_c;     //temporary variable for reading from file
        int t = fscanf(fp,"%c%d %d %d", &t_ch,&t_a, &t_b, &t_c);      
        if (t <= 0) break;
        p[i] = (struct st_num*) malloc(sizeof(struct st_num));
        p[i]->ch = t_ch;
        p[i]->a = t_a;
        p[i]->b = t_b;
        p[i]->c = t_c;
        i++;
    }
    fclose(fp);
    return i;
}