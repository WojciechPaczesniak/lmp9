#include "selekcja.h"
#include "backsubst.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* tworzy macierz rozszerzona A|B */
Matrix * utworz_macierz_rozszerzona( Matrix *A, Matrix *B ) {
	int i, j;
	Matrix * mat = NULL;
	mat = createMatrix( A->r, (A->c)+1 );
	
	for( i = 0; i < A->r; i++ )
		for( j = 0; j < A->c; j++)
			mat->data[i][j] = A->data[i][j];
	for( i = 0; i < B->r; i++ )
		mat->data[i][(mat->c)-1] = B->data[i][0];
	return mat;
}

/* rozdziela macierz rozszerzona A|B do A i B */
Matrix * rozdziel_macierz_rozszerzona( Matrix *mat, Matrix *A, Matrix *B ) {
	int i, j;

	for( i = 0; i < mat->r; i++ )
		for( j = 0; j < mat->c-1; j++ )
			A->data[i][j] = mat->data[i][j];
	for( i = 0; i < mat->r; i++ )
		B->data[i][0] = mat->data[ i ][ mat->c-1 ];
	
	freeMatrix(mat);
}

/* wybiera element glowny macierzy mat w kolumnie o numerze nr_k (numerujac od 0 ),
 * nastepnie zamienia wiersze miejscami, zwraca otrzymana macierz */
Matrix * wybor_elementu_glownego( Matrix * mat, int nr_k) {
	int i;
	double pom;
	int nr_w = 0+nr_k; /* numer wiersza, w ktorym w
			 nr_k kolumnie wystepuje max element */
	int max_w = nr_w;
	int max_el = mat->data[nr_w][nr_k]; /* wartosc max elementu w 1. kolumnie */

	/* wybor elementu glownego w 1. kolumnie */
	for( i = nr_w+1; i < mat->r; i++ )
		if( fabs( mat->data[i][nr_k] ) > fabs( max_el ) ) {
			max_el = mat->data[i][nr_k];
			max_w = i;
		}

	/* zamiana wierszy */
	for( i = 0; i < mat->c; i++ ) {
		pom = mat->data[nr_w][i];
		mat->data[nr_w][i] = mat->data[max_w][i];
		mat->data[max_w][i] = pom;
	}
	return mat;
}

/* rozwiazuje rownanie A*X=B, wykorzystujac selekcje elementu diagonalnego, zwraca X */
Matrix * selekcja( Matrix *A, Matrix *B, Matrix *X) {
	int i;
	
	Matrix *mat = NULL;
	
	printf("\nMacierz rozszerzona: \n");
	printToScreen(mat);

	for( i =0; i < (A->r)-1; i++ ) {
		mat = utworz_macierz_rozszerzona( A, B );

		mat = wybor_elementu_glownego( mat, i );
		printf("\nWybor elementu glownego - kolumna %d:\n", i);
		printToScreen(mat);

		rozdziel_macierz_rozszerzona( mat, A, B );
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

