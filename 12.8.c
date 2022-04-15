#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st_person{
    char name[20];
    char address[80];
    int age;
};

struct st_person* get_person(); // 메모리를 동적 할당하여 인적사항을 입력받아 저장한 후 포인터 리턴

int main(void) {
    char* ordinal[3] = {"first", "second", "third"}; 
    struct st_person* p[3];
    int i;
    
    for(i = 0; i < 3; i++){
        printf("Please enter the %s person's information.\n",ordinal[i]);
        p[i] = get_person();
    }
    for ( i = 0; i < 3; i++){
        printf("The %s person: : %s/ %s/ %d\n", ordinal[i], p[i]->name, p[i]->address, p[i]->age);
    }
    free(p);
    return 0;
}

struct st_person* get_person(){
    struct st_person* p = (struct st_person*)malloc(sizeof (struct st_person));
    printf("Name? ");
    scanf("%s", p->name);
    printf("Address? ");
    fgets(p->address, 80, stdin);
    p->address[strlen(p->address)-1] = '\0';
    printf("Age? ");
    scanf("%d", &p->age);
    return p;
}