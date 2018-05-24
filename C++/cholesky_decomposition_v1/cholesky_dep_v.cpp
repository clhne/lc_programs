#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/* Cholesky-decomposition matrix-inversion code, adapated from
   http://jean-pierre.moreau.pagesperso-orange.fr/Cplus/choles_cpp.txt */

static int choldc1(double * a, double * p, int n) {
    int i,j,k;
    double sum;

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            sum = a[i*n+j];
            for (k = i - 1; k >= 0; k--) {
                sum -= a[i*n+k] * a[j*n+k];
            }
            if (i == j) {
                if (sum <= 0) {
                    return 1; /* error */
                }
                p[i] = sqrt(sum);
            }
            else {
                a[j*n+i] = sum / p[i];
            }
        }
    }

    return 0; /* success */
}

static int choldcsl(double * A, double * a, double * p, int n) 
{
    int i,j,k; double sum;
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            a[i*n+j] = A[i*n+j];
    if (choldc1(a, p, n)) return 1;
    for (i = 0; i < n; i++) {
        a[i*n+i] = 1 / p[i];
        for (j = i + 1; j < n; j++) {
            sum = 0;
            for (k = i; k < j; k++) {
                sum -= a[j*n+k] * a[k*n+i];
            }
            a[j*n+i] = sum / p[j];
        }
    }

    return 0; /* success */
}


static int cholsl(double * A, double * a, double * p, int n) 
{
    int i,j,k;
    if (choldcsl(A,a,p,n)) return 1;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            a[i*n+j] = 0.0;
        }
    }
    for (i = 0; i < n; i++) {
        a[i*n+i] *= a[i*n+i];
        for (k = i + 1; k < n; k++) {
            a[i*n+i] += a[k*n+i] * a[k*n+i];
        }
        for (j = i + 1; j < n; j++) {
            for (k = j; k < n; k++) {
                a[i*n+j] += a[k*n+i] * a[k*n+j];
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            a[i*n+j] = a[j*n+i];
        }
    }

    return 0; /* success */
}
int main()
{
	double A[9] = {
		7, 2, 3,
		2, 4, 1,
		3, 1, 10
	};
	double B[4] = {
		7, 2,
		2, 4
	};
	double a[9] = {0}, p[9] = {0};
	double B_a[4] = {0}, B_p[4] = {0};
	int n = 3, B_n = 2, i, j;
	cholsl(A, a, p, n);
	cholsl(B, B_a, B_p, B_n);
	//A
	for(i = 0; i < n ; i++){
		for(j = 0; j < n; j++){
			printf("A[%d] = %10.6f   ", j + i * n, A[j + i * n]);
		}
		printf("\n");
	}
	printf("\n");
	//a = inverse(A)
	for(i = 0; i < n ; i++){
		for(j = 0; j < n; j++){
			printf("a[%d] = %10.6f   ", j + i * n, a[j + i * n]);
		}
		printf("\n");
	}
	printf("\n");
	//B
	for(i = 0; i < B_n ; i++){
		for(j = 0; j < B_n; j++){
			printf("B[%d] = %10.6f   ", j + i * B_n, B[j + i * B_n]);
		}
		printf("\n");
	}
	printf("\n");
	//B_a = inverse(B)
	for(i = 0; i < B_n ; i++){
		for(j = 0; j < B_n; j++){
			printf("B_a[%d] = %10.6f   ", j + i * B_n, B_a[j + i * B_n]);
		}
		printf("\n");
	}
	return 0;
}