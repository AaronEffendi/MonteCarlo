#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SEED 35791246

double f(float x) {
    return ((2 * x * x) + (4 * x) + 5);
}

int main(int argc, char* argv)
{
    int xmax, xmin;
    int niter = 0;
    double x, y;
    int i;
    double xcoord, ycoord;
    double hasil;

    printf("Enter the number of iterations used to estimate: ");
    scanf("%d", &niter);

    /* initialize random numbers */
    srand(SEED);
    xmin = 0;
    xmax = 5;
    y = 0;
    for (i = 0; i < niter; i++) {
        x = (double)rand() / RAND_MAX;
        xcoord = ((xmax - xmin) * x) + xmin;
        y = y + f(xcoord);
    }
    hasil = (xmax - xmin) * y / niter;
    printf("Jumlah sampling = %d , Estimasi nilai = %f\n", niter, hasil);
    return 0;
}
