#ifndef _SELEKCJA_H_
#define _SELEKCJA_H_	

#include "mat_io.h"

Matrix * utworz_macierz_rozszerzona( Matrix *A, Matrix *B );

Matrix * rozdziel_macierz_rozszerzona( Matrix *mat, Matrix *A, Matrix *B );

Matrix * wybor_elementu_glownego( Matrix * mat, int nr_k);

Matrix * selekcja( Matrix *A, Matrix *B, Matrix *X);

#endif
