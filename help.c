#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void input_array(int[],int);
void output_array(int [], int);
//배열 출력
bool sort(int [], int);

int main(void){
   int size;
   int temp; 
   int i;

   srand(time(0));
   printf("input number: ");
   scanf("%d", &size);
   int ary[size];

   input_array(ary, size);

   output_array(ary, size);
   
   if(sort(ary, size)) printf("Called swap function");
   
   printf("==============sorted array====================");

   output_array(ary, size);

   min max

   return 0;
}

void input_array(int a[], int s){
   int i;
   // 1 = 10*몫 + 나머지;
   //n 0~(n-1) 
   //n % 10 =>자연수 10%10 몫? 0 나머지? 1? 정수-1 0 1와 실수: 0.0 자연수: 1234576
   for( i = 0; i<s; i++) a[i] = rand()%(끝값 - 시작값 +1) +시작값;
}

void output_array(int a[], int s){
   printf("Array: \n");
   for (int i = 0; i < s; i++){
      printf("%d ",a[i]);
   }
}

bool sort(int a[], int s){
   bool k = false; //key
   for (int i = 0; i < s; i++){
      for (int j = 0; j < i; j++){
         if (a[j] > a[i]){
            swap((a+j), (a+i));     //*(a+i) == a[i] a[j], a[i]
            k = true;
         }
      }
   }
   return k;
   if (k) return true;
   else return false;
}

void swap(int* i,int* j){
   int temp;

   temp=i;
   i=j;
   j=temp;
}