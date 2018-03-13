#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define NCOLS 100
#define NROWS 100000

void get_walltime(double *wct) {
  struct timeval tp;
  gettimeofday(&tp,NULL);
  *wct = (double)(tp.tv_sec+tp.tv_usec/1000000.0);
}

int main(int argc, char *argv[]) {
int i,j;
double sum = 0.0;
double *table;
double ts,te, Maccess;

  table = (double *)malloc(NCOLS*NROWS*sizeof(double));
  if (table==NULL) {
    printf("alloc error!\n");
    exit(1);
  }

  
  for(i=0; i<NROWS*NCOLS; i++){
  	table[i]=1.0;
  }

  get_walltime(&ts);
  
  // προσπελαση κατα στήλη

  for (i=0;i< NCOLS;i++){
  	for(j=0;j< NROWS;j++){
  		sum+=table[j*NCOLS+i];
 	 }
  }
  get_walltime(&te);

  printf("Accesses = %f\n", sum);

  //To Maccess ειναι τα  Memoty_accesses per second

   Maccess=((double)NROWS*NCOLS)/((te-ts)*1e6);

  printf("Maccesses/sec = %f\n" , Maccess);

  free(table);

  return 0;
}

