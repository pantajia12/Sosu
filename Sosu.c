#include <stdio.h>
#include <time.h>

int main() {
   int num = 0;
   scanf("%d", &num);//259051 까지 검색가능 
   
   int Sosu[num];
   int Sosu_index[num] = {0};
   
   int i;//왜 register int가 int보다 느릴까 
   clock_t start = clock();
   
   for(i=0;i<=num;i++) {
      Sosu[i] = i;
      Sosu_index[i] = 2;
   }
   
   for(i=2;i<=num;i++) {
      if(Sosu_index[i] == 2) {
         Sosu_index[i] = 1;
         int a = i;
         while(a <= num) {
            a += i;
            if(a <= num)
               Sosu_index[a] = 0;
         }
      }
   }
   Sosu_index[0] = 0;
   Sosu_index[1] = 0;
      
   for(i=0;i<=num;i++) {
      if(Sosu_index[i] == 1)
         printf("%d\n", Sosu[i]);
   }
   clock_t end = clock();
   

   printf("Time: %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
    return 0;
}