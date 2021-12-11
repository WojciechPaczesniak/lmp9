#ifndef _SELEKCJA_H_
#define _SELEKCJA_H_	

#include "mat_io.h"

void wybor_elementu_glownego( Matrix * A, Matrix * B, int nr_k);

Matrix * selekcja( Matrix *A, Matrix *B, Matrix *X);

#endif
