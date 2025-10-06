// Atividade 05 ex 02 -  // 
// Lanay Guimaraes de Paiva - 2512130054 //

#include <stdio.h>

struct pessoa {
    char nome [100];
    int idade;
};


int main (){
    int n;
    printf("Digite o numero de pessoas: ");
    scanf("%d", &n);
    while (getchar() != '\n');
    printf("\n");


    struct pessoa pessoas[n];

    printf("Cadastro de %d pessoas!\n", n);

    for(int i = 0; i < n; i++){
        printf("Digite o nome da pessoa [%d] : ", i+1);
        scanf("%[^\n]", pessoas[i].nome);
        printf("Digite a idade: ");
        scanf("%d", &pessoas[i].idade);
        while (getchar() != '\n');
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < n; i++){
        printf("nome: %s, idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }
    return 0;
}

