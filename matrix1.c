#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// compile like:  gcc -Wall -O2 -DNROWS=10000 matrix1.c -o matrix1


#define NCOLS 100 // παραμένει σταθερό
#define NROWS  100000
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


  table = (double *)malloc(NCOLS*NROWS*sizeof(double)); // δυναμική δεσμευση μνήμης
  if (table==NULL) {
    printf("alloc error!\n");
    exit(1);
  }

 

  for(i=0; i<NCOLS*NROWS; i++){
  	table[i]=1.0;
  }

  get_walltime(&ts);
  

  // προσπελαση κατα γραμμη

  for (i=0;i<NROWS;i++){
  	for(j=0;j<NCOLS;j++){
  		sum+=table[i][j];
 	 }
  }
  get_walltime(&te);

  printf("Accesses = %f\n", sum);

//To Maccess ειναι τα  Memory_accesses per second
  Maccess=((double)NROWS*NCOLS)/((te-ts)*1e6);

  printf("Maccesses/sec = %f\n" ,Maccess);

  free(table);

  return 0;
}
