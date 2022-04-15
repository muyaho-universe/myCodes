///////////////////////////////////////////
// You don't need to modify until line 70, 
// if you want, however, you can. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record{		// management record
	char name[20];	// name				
	char fm;		   // gender ('F' female, 'M' male)				
	int class_year;		// admission year (4 digits)
	int room;		// room number
	int penalty;		// penalty 
};

int load_members(struct Record* p[]);		// load records
void list_members(struct Record* p[], int n);	// print records
void edit_room(struct Record* p[], int n);		// change room for one student
void make_penalty(struct Record* p[], int n);	// penalize a student
void find_members(struct Record* p[], int n);	// search for a student. 
void save_report(struct Record* p[], int n);	// save a report. 

int main(){
	struct Record* members[100]; 	// structure pointers for at most 100 students. 
	int count;	// number of currently enrolled students
	int menu;	// menu number. 

	count = load_members(members);	// load all the students. 
	while(1) {
		// printing menu.
		printf("\n[1]List [2]Room change [3]Penalty [4]Search [5]Save [0]Quit >> ");
		scanf("%d", &menu);	

		if(menu==1)			  list_members(members, count);	
		else if(menu==2)	edit_room(members, count);	
		else if(menu==3)	make_penalty(members, count); 
		else if(menu==4)	find_members(members, count);	
		else if(menu==5)	save_report(members, count);	
		else 	break;
	}
}

int load_members(struct Record* p[]){
	FILE *file;
	int n=0;

	file = fopen("members.txt","rt");
	while(!feof(file)){
		p[n]=(struct Record*)malloc(sizeof(struct Record));
		fscanf(file,"%s %c %d %d %d",p[n]->name,&(p[n]->fm),&(p[n]->class_year),&(p[n]->room),&(p[n]->penalty));
		n++;
	}
	fclose(file);
	printf("%d students are loaded.\n",n);

	return n;
}

void list_members(struct Record * p[], int n){
	int i;
	printf("\nTotal list.\n");
	printf("NO Name Gender ClassYear RoomNo Penalty\n");
	
	for(i=0; i<n; i++){
		printf("%d %s [%c] %d %d %d\n", (i+1), p[i]->name, p[i]->fm, p[i]->class_year, p[i]->room, p[i]->penalty);
	}
}

// You don't need to edit upto here. 
//////////////////////////////////////////

void edit_room(struct Record* p[], int n){
// # 15-1 

	char name[20];
	struct Record* rp; // structure pointer to edit. 
	int i, found=0, newroom;
    int count = 0;

	printf("Student name to change the room? >> ");
	scanf("%s", name);
	for(i=0;i<n;i++){
		if(strcmp(p[i]->name,name)==0){
			found=1;
			rp=p[i];
			break;
		}
	}
	if(found==1){
        printf("Name Gender ClassYear RoomNo Penalty\n");
		printf("%s [%c] %d %d %d\n", rp->name, rp->fm, rp->class_year, rp->room, rp->penalty);
        while (1){
            count = 0;
            printf("New room number >> ");
		    scanf("%d", &newroom);
            if (newroom < 100 || (newroom > 115 && newroom < 201) || newroom > 215){
                printf("Room Error!\n");
                continue;
            }
            if (rp->fm == 'M'){    
                if (newroom / 100 == 1){
                    printf("Floor Error!\n");
                    continue;
                }
                else{
                    for ( i = 0; i < n; i++){
                        if (newroom == p[i]->room) count++; 
                    }
                    if (count > 2){
                        printf("Exceeded Occupancy Error!\n");
                        continue;
                    }
                    else break;
                }
            }
            else{
                if (newroom / 100 == 2){
                    printf("Floor Error!\n");
                    continue;
                }
                else{
                    for ( i = 0; i < n; i++){
                        if (newroom == p[i]->room) count++; 
                    }
                    if (count > 2){
                        printf("Exceeded Occupancy Error!\n");
                        continue;
                    }
                    else break;
                }
            }             
        }
		rp->room = newroom;
		printf("Room Changed!\n");
	}
	else{
		printf("No student with the name.\n");
	}
}

void make_penalty(struct Record* p[], int n){
    // 15-2
    char name[20];
	struct Record* rp; // structure pointer to edit. 
	int i, found=0, go = 0;
    
    printf("Student name to give penalty? >> ");
	scanf("%s", name);
	for(i=0;i<n;i++){
		if(strcmp(p[i]->name,name)==0){
			found=1;
			rp=p[i];
			break;
		}
	}
    if(found==1){
        printf("Name Gender ClassYear RoomNo Penalty\n");
		printf("%s [%c] %d %d %d\n", rp->name, rp->fm, rp->class_year, rp->room, rp->penalty);
        printf("Do you want to impose penalty? (YES 1, NO 0) >> ");
        scanf("%d", &go);
        if (go) {
            rp->penalty ++;
            printf("%s's penalty point is now %d in total. \n", name,rp->penalty);
        }
        else{
            printf("%s's penalty point is still %d in total. \n", name,rp->penalty);
        }
    }
    else{
        printf("No student with the name.\n");
    }
}

void find_members(struct Record * p[], int n){
  // # 15-3
    int i, count=0;
	char name[20];
    int index[100] = {0};

	while(1){
		printf("Enter at least 2 letters to search for. >> ");
		scanf("%s", name);
		if(strlen(name) > 1) break;
	}
    for ( i = 0; i < n; i++){
        char *ptr = strstr(p[i]->name, name); 
        if (ptr != NULL){             // 검색된 문자열이 없을 때까지 반복
            index[count] = i;
            count++;
        }
    }
    printf("No Name Gender ClassYear RoomNo Penalty\n");
	
	for(i=0; i<n; i++){
        for (int j = 0; j < count; j++){
            if (!strcmp(p[i]->name, p[index[j]]->name)){
                printf("%d %s [%c] %d %d %d\n", (i+1), p[i]->name, p[i]->fm, p[i]->class_year, p[i]->room, p[i]->penalty);
            }
        }
	}
	printf("%d student(s) found\n", count);
}

void save_report(struct Record* p[], int n){
  	// # 15-4
	int count_m = 0, count_f = 0, count_v = 0, count_s = 0, count_d = 0, count_15 = 0, count_16 = 0, count_17 = 0, count_18 = 0;
	int rms[31] = {0}, vacancy[30], single[30], duo[30], penal[100];
	char pen[100][20] = {""};
	int num = 0, v = 0, s = 0, d = 0, num_p = 0, rm, temp;
	int i, j;
	
	for ( i = 0; i < n; i++){
		num = 0;
		if (p[i]->fm == 'M') count_m ++;
		else count_f ++;					//1. Number of resident students		

		if (p[i]->room>100 && p[i]->room < 200) rm = (p[i]->room) -100;
		else rm = (p[i]->room) - 200 + 15;
		rms[rm] ++;

		if (p[i]->class_year == 2015) count_15 ++;
		else if (p[i]->class_year == 2016) count_16 ++;
		else if (p[i]->class_year == 2017) count_17 ++;
		else count_18++;										//3. Status by student class year

		if (p[i]->penalty >= 7) {
		 	strcpy( pen[num_p], p[i]->name);
			penal[num_p] = p[i]->penalty;					//4. High penalty points (7 points or more)
			num_p ++;
		}
	}

	for ( i = 1; i < 31; i++){
		if(i<=15){
			if (rms[i] == 0){
				vacancy[v] = (i + 100);
				v++;
			} 
			else if (rms[i] == 1){
				single[s] = (i + 100);
				s++;
			}
			else {
				duo[d] = (i + 100);
				d++;
			}
		}
		else{
			if (rms[i] == 0){
				vacancy[v] = (i + 200 - 15);
				v++;
			}
			else if (rms[i] == 1) {
				single[s] = (i + 200 - 15);
				s++;
			}
			else {
				duo[d] = (i + 200 - 15);
				d++;
			}
		}
	}

	FILE* file1;
	file1 = fopen("report.txt","wt");
	
	fprintf(file1,"David Hall Status Report\n");
	fprintf(file1,"1. Number of resident students: %d ", n);
	fprintf(file1,"(%d male, %d female)\n", count_m, count_f);

	fprintf(file1,"2. Room Status\n");
	fprintf(file1,"  1) Vacancy:");
	for ( i = 0; i < v; i++) fprintf(file1,"  %d", *(vacancy + i));
	fprintf(file1,"\n  2) Single room:");
	for ( i = 0; i < s; i++) fprintf(file1,"  %d", *(single + i));
	fprintf(file1,"\n  3) Double room:");
	for ( i = 0; i < d; i++) fprintf(file1,"  %d", *(duo + i));


	fprintf(file1,"\n3. Status by student class year\n");
	fprintf(file1,"  1) Class of 2015: %d students\n", count_15);
	fprintf(file1,"  2) Class of 2016: %d students\n", count_16);
	fprintf(file1,"  3) Class of 2017: %d students\n", count_17);
	fprintf(file1,"  4) Class of 2018: %d students\n", count_18);


	fprintf(file1," 4. High penalty points (7 points or more): %d students\n", num_p);
	for ( i = 0; i < num_p; i++) fprintf(file1,"%s(%d) ", *(pen+i), *(penal + i));

	fprintf(file1,"\n5. Student list\n");
	fprintf(file1,"NO Name Gender ClassYear RoomNo Penalty\n");
	for ( i = 0; i < n; i++) fprintf(file1,"%d %s [%c] %d %d %d\n", (i+1), p[i]->name, p[i]->fm, p[i]->class_year, p[i]->room, p[i]->penalty);

	fclose(file1);
	printf("Report saved!\n");
}	
