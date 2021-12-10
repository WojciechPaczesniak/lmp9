#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

	int i, j;
        int n = mat->r; /* stopien macierzy */
        double suma = 0.0;

        if( (mat->c != n) || (x->r != n) || (x->c != 1) ||
                        (b->r != n) || (b->c != 1) ) {
                fprintf( stderr, "Błędny rozmiar macierzy
                                w podstawieniu wstecznym\n" );
                return 2;
        }

        x->data[n-1][0] = b->data[n-1][0] / mat->data[n-1][n-1];
        for( i = n-2; i >= 0; i-- ) {
                suma = 0.0;
                for( j = i+1; j < n; j++ )
                        suma += mat->data[i][j] * x->data[j][0];
                if( mat->data[i][i] == 0.0 ) {
                /* dzielenie przez 0 */
                        fprintf( stderr, "Błąd w podstawieniu wstecznym:
                                        próba dzielenie przez 0\n" );
                        return 1;
                }
                x->data[i][0] = ( b->data[i][0] - suma ) / mat->data[i][i];
        }

	return 0;

}


