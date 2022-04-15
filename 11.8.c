#include <stdio.h>
#include <string.h>

struct person_struct{
   char name[20];
  char address[80];
  int age;
};

int main(void) {
  struct person_struct p1, p2, p3;

  FILE * fp;
  fp = fopen("user.txt", "w");

  printf("Please enter the first person's information.\n");
  printf("Name? ");
  fgets(p1.name, 20, stdin);
  printf("Address? ");
  fgets(p1.address, 20, stdin);
  printf("Age? ");
  scanf("%d", &p1.age);
  while (getchar() != '\n');
  p1.name[strlen(p1.name)-1] = '\0';
  p1.address[strlen(p1.address)-1] = '\0';

  printf("Please enter the second person's information.\n");
  printf("Name? ");
  fgets(p2.name, 20, stdin);
  printf("Address? ");
  fgets(p2.address, 20, stdin);
  printf("Age? ");
  scanf("%d", &p2.age);
  while (getchar() != '\n');
  p2.name[strlen(p2.name)-1] = '\0';
  p2.address[strlen(p2.address)-1] = '\0';


  printf("Please enter the third person's information.\n");
  printf("Name? ");
  fgets(p3.name, 20, stdin);
  printf("Address? ");
  fgets(p3.address, 20, stdin);
  printf("Age? ");
  scanf("%d", &p3.age);
  while (getchar() != '\n');
  p3.name[strlen(p3.name)-1] = '\0';
  p3.address[strlen(p3.address)-1] = '\0';

  printf("The first person: %s/ %s/ %d\n",p1.name, p1.address, p1.age);
  printf("The second person: %s/ %s/ %d\n",p2.name, p2.address, p2.age);
  printf("The third person: %s/ %s/ %d\n",p3.name, p3.address, p3.age);

  fprintf(fp,"%s %s %d\n", p1.name, p1.address, p1.age);
  fprintf(fp,"%s %s %d\n", p2.name, p2.address, p2.age);
  fprintf(fp,"%s %s %d\n", p3.name, p3.address, p3.age);
  
  fclose(fp);
  return 0;
}