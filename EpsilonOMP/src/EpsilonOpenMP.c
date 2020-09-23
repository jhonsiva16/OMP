
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, char *argv[]) {
  int k;

  double EPSILON = 2.718281828459045235360;
  printf("\n Fuera de la región paralela, se utilizan 4 threads");
  printf("\n \n Ingresa un valor para k : ");
  scanf("%d",&k);

  omp_set_num_threads(4);

   double et = 0.0;


#pragma omp parallel reduction(+:et)
{
   int id = omp_get_thread_num();
   int nt = omp_get_num_threads();
   double e=0;
   double fact = 1;
   for (int i=id; i<k; i+=nt){
	   for (int j = 1; j <= i; j++){
		   fact *= j;
	   }

	   float frac = 1.0 / fact;
	   	e += frac;  //e=e+1.0/fact
	   }
   et = e;
   //printf("El valor de épsilon es: %.10f",et);
}
printf("El valor de épsilon es: %.30f \n",et);
printf("Con un error de %.60f \f",fabs(et - EPSILON));

return 0;
}
