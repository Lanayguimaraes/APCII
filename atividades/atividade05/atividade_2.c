// Sistema Linear //
// Lanay Guimarães de Paiva - 2512130054 //


#include <stdio.h>
#include <math.h>


void obter_submatriz(int N, float matriz[N][N], float sub[N-1][N-1], int linha_excluir, int coluna_excluir) {
    int r = 0, c;
    for (int i = 0; i < N; i++) {
        if (i == linha_excluir) continue;
        c = 0;
        for (int j = 0; j < N; j++) {
            if (j == coluna_excluir) continue;
            sub[r][c++] = matriz[i][j];
        }
        r++;
    }
}


void imprimir_matriz(int N, float matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%7.2f ", matriz[i][j]); 
        printf("\n");
    }
}


float det_exp_cof(int N, float matriz[N][N], int nivel) { 
    if (N == 1) return matriz[0][0];
    if (N == 2) return matriz[0][0]*matriz[1][1] - matriz[0][1]*matriz[1][0];

    float det = 0.0;

    for (int j = 0; j < N; j++) {
        float sub[N-1][N-1]; 
        
        obter_submatriz(N, matriz, sub, 0, j); 
        
        float sinal = ((0 + j) % 2 == 0) ? 1.0 : -1.0;

        float subdet = det_exp_cof(N-1, sub, nivel+1); 
        det += sinal * matriz[0][j] * subdet;

        
        for(int t=0; t<nivel; t++) printf("  ");
        printf("Elemento A[1][%d] = %.2f | Sinal = %.0f | Subdet = %.2f | Termo = %.2f\n",
               j+1, matriz[0][j], sinal, subdet, sinal*matriz[0][j]*subdet);
    }
    return det;
}


int main() {
    int N;
    printf("Digite a ordem do sistema (3 ou 4): ");
    printf("\n");
    scanf("%d", &N);
    if (N != 3 && N != 4) {
        printf("Erro: apenas sistemas 3x3 ou 4x4.\n");
        printf("\n");
        return 1;
    }

    float A[N][N], B[N], X[N];


    printf("\n--- * Entrada dos coeficientes * ---\n");
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("A[%d][%d]: ", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
        printf("B[%d]: ", i+1);
        printf("\n");
        scanf("%f", &B[i]);
    }

  
    printf("\n--- * Calculo do determinante principal * ---\n");
    printf("\n");
   
    float D = det_exp_cof(N, A, 0); 
    printf("\nDeterminante principal D = %.2f\n", D); 
    printf("\n");

    if (fabs(D) < 1e-6) {
        printf("Determinante nulo — sistema sem solução unica.\n");
        printf("\n");
        return 0;
    }

   
    printf("\n--- * Calculo das solucoes * ---\n");
    printf("\n");
    for (int k = 0; k < N; k++) {
        float Ak[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                Ak[i][j] = (j == k) ? B[i] : A[i][j];

        
        float Dk = det_exp_cof(N, Ak, 0); 
        X[k] = Dk / D;
        printf("x%d = %.2f\n", k+1, X[k]); 
    }

    return 0;
}
