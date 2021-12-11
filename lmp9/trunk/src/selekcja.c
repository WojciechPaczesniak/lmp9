#include "selekcja.h"
#include "backsubst.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* wybiera element glowny macierzy A w kolumnie o numerze nr_k (numerujac od 0 ),
 * nastepnie zamienia wiersze miejscami */
void wybor_elementu_glownego( Matrix * A, Matrix * B, int nr_k) {
	int i;
	double pom;
	int nr_w = 0+nr_k; /* numer wiersza, w ktorym w
			 nr_k kolumnie wystepuje max element */
	int max_w = nr_w;
	int max_el = A->data[nr_w][nr_k]; /* wartosc max elementu w 1. kolumnie */

	/* wybor elementu glownego w 1. kolumnie */
	for( i = nr_w+1; i < A->r; i++ )
		if( fabs( A->data[i][nr_k] ) > fabs( max_el ) ) {
			max_el = A->data[i][nr_k];
			max_w = i;
		}

	/* zamiana wierszy */
	for( i = 0; i < A->c; i++ ) {
		pom = A->data[nr_w][i];
		A->data[nr_w][i] = A->data[max_w][i];
		A->data[max_w][i] = pom;
	}
	pom = B->data[nr_w][0];
	B->data[nr_w][0] = B->data[max_w][0];
	B->data[max_w][0] = pom;
}

/* rozwiazuje rownanie A*X=B, wykorzystujac selekcje elementu diagonalnego, zwraca X */
Matrix * selekcja( Matrix *A, Matrix *B, Matrix *X) {
	int i;
	
	for( i =0; i < (A->r)-1; i++ ) {
		wybor_elementu_glownego( A, B, i );
		printf("\nWybor elementu glownego - kolumna %d:\n", i);
		printToScreen(A);
		printToScreen(B);

		/*mat = schodkowanie; funkcja do zrobienia */
	}
	/*
	printf("\nA:\n");
	printToScreen(A);
	printf("\nB\n");
	printToScreen(B);
	*/

	backsubst(X, A, B);
	printf("\nX:\n");
	printToScreen(X);

	return X;
}

