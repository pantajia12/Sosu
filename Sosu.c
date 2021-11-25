#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <malloc.h>

int main() {
   int num;
   scanf("%d", &num);
   clock_t start = clock();
   bool* Sosu_index = (bool*)calloc(num, sizeof(bool));

   register int i, j;
   
      
   for(i=2;i<=num;i++) {
      if(Sosu_index[i] == false) {
         Sosu_index[i] = true;
         printf("%d ", i);
         
         for(j=i;j<=num;j+=i) {
               Sosu_index[j] = true;
         }
      }       
   }

   clock_t end = clock();
   
   printf("Time: %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
   free(Sosu_index);
    return 0;
}