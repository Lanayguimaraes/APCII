// Avaliacao 04 - Questao 02 //
// Lanay Guimaraes de Paiva - 2512130054 //


#include <stdio.h>

void min_max(int n, int vet[], int *min_idx, int *max_idx) {
    *min_idx = 0;
    *max_idx = 0;

    for (int i = 1; i < n; i++) {
        if (vet[i] < vet[*min_idx]) {
            *min_idx = i;
        }
        if (vet[i] > vet[*max_idx]) {
            *max_idx = i;
        }
    }
}

int main() {
   

    int vet[] = {8, -4, 9, -2, 5, 1};

   
    int n = sizeof(vet) / sizeof(vet[0]);
    int min, max;

    min_max(n, vet, &min, &max);

    printf("Vetor de teste: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    printf("Índice do menor valor: %d (valor = %d)\n", min, vet[min]);
    printf("Índice do maior valor: %d (valor = %d)\n", max, vet[max]);

    return 0;
}