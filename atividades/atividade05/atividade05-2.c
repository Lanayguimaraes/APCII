// Atividade 05 ex 02 -  // 
// Lanay Guimaraes de Paiva - 2512130054 //

#include <stdio.h>

typedef unsigned int uint;  

typedef struct pessoa Pessoa;

struct pessoa {
    char nome[100];
    int idade;
    
};

void preencher(uint n, Pessoa pessoas[n]) {
    for (uint i = 0; i < n; i++) {
        printf("Cadastro de pessoa %d: ", i + 1);
        printf("Digite o nome: %d: ", i + 1);
        scanf(" %99[^\n]%c", pessoas[i].nome);  
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d%c", &pessoas[i].idade);  
    }
}

void exibir(uint n, struct pessoa pessoas[n]){
    printf("\nLista de pessoas cadastradas:\n");
    for (uint i = 0; i < n; i++) {
        printf("Pessoa %d: Nome: %s, Idade: %d\n", i + 1, pessoas[i].nome, pessoas[i].idade);
    }
}

int main() {
    uint n;

    printf("Digite o numero de pessoas a serem cadastradas: ");
    scanf("%u%c", &n);  

    Pessoa pessoas[n];  

    preencher(n, pessoas);  

    exibir(n, pessoas);  

    return 0;
}