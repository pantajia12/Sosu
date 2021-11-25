#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <memory.h>
#include <math.h>

int main() {
   int num;
   scanf("%d", &num);
   
   int* Sosu_index = (int*)calloc(num, sizeof(int));

   register int i, j;
   clock_t start = clock();
      
   for(i=2;i<=num;i++) {
      if(Sosu_index[i] == 0) {
         Sosu_index[i] = 1;
         printf("%d\n", i);
         
         for(j=i;j<=num;j+=i) {
            if(j <= num)
               Sosu_index[j] = 2;
         }
      }      
   }

   clock_t end = clock();
   

   printf("Time: %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
   free(Sosu_index);
    return 0;
}