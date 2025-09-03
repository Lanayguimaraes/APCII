// Avaliacao 04 - Questao 01 //
// Lanay Guimaraes de Paiva - 2512130054 //


#include <stdio.h>

void modulo(double *x) {
    if (*x < 0) {     
        *x = -(*x);   
    }
}

int main() {
    double num = -7;
    printf("Antes: %f\n", num);

    modulo(&num);     
    printf("Depois: %f\n", num);

    return 0;
}