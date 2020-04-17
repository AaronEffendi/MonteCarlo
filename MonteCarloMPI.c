#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<time.h>
#include <mpi.h>
#define SEED 35791246
float f (float x){
 //2x^2 + 4x + 5
 return ((2 * x * x ) + (4 * x) + 5);
}
int main(int argc, char *argv[]){
 int count = 0, i, iter;
 int rank, size, sisa, Niter;
 double xmin, xmax;
 double x, y, yhasil, xcoord;
 MPI_Init(&argc,&argv);
 MPI_Comm_size(MPI_COMM_WORLD,&size);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 iter=atoi(argv[1]);
 int n1 = (int)( (double)iter * (double)(rank)/size);
 int n2 = (int)( (double)iter * (double)(rank+1.0)/size);
 srand(SEED + rank);
 y = 0;
 xmin = 0;
 xmax = 5;
 for (i = n1; i < n2; i++){
 x = (double)rand()/RAND_MAX;
 xcoord = ((xmax - xmin) * x) + xmin;
 y = y + f(xcoord);
 }
 MPI_Reduce(&y, &yhasil, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
 if(rank == 0){
 double result;
 result = (xmax - xmin) * yhasil / iter;
 printf("Estimated value for area of curve %f in %d iteration", result, iter);
 }
 MPI_Finalize();
}
