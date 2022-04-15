#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st_menu{ 
    int no; 				// menu number
    char name[20]; 		    // menu name 
    char made_in[20]; 	    // origin 
    int price; 				// price
};

struct st_menu* get_menu();
// What to do: After allocating the menu information structure to dynamic memory, input menu information, store it into the structure, and return the address value

int main(){
    struct st_menu *menu;

    menu = get_menu();
    
    printf("Menu number, name, country of origin, price are as follows.\n  %3d %s %s %d", menu->no, menu->name,  menu->made_in,  menu->price);
    free(menu);
    
    return 0;
}

struct st_menu* get_menu(){
    struct st_menu* p = (struct st_menu*)malloc(sizeof (struct st_menu));
    printf("Enter the menu number, name, country of origin, and price.");
    scanf("%d %s %s %d", &p->no, p->name, p->made_in, &p->price);
    return p;
}