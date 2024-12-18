#include <stdio.h>

void exibirMenu() {
    printf("\nEscolha a unidade de entrada:\n");
    printf("1 - Metro (m)\n");
    printf("2 - Centímetro (cm)\n");
    printf("3 - Milímetro (mm)\n");
    printf("Digite sua escolha: ");
}

void converterUnidade(int unidadeOrigem, double valor) {
    double metros, centimetros, milimetros;

    // Conversão para metros
    if (unidadeOrigem == 1) {
        metros = valor;
    } else if (unidadeOrigem == 2) {
        metros = valor / 100.0; // cm para m
    } else if (unidadeOrigem == 3) {
        metros = valor / 1000.0; // mm para m
    } else {
        printf("Unidade inválida!\n");
        return;
    }

    // Conversões a partir de metros
    centimetros = metros * 100.0;
    milimetros = metros * 1000.0;

    // Exibir resultados
    printf("\nResultados:\n");
    printf("Metros: %.4f m\n", metros);
    printf("Centímetros: %.2f cm\n", centimetros);
    printf("Milímetros: %.2f mm\n", milimetros);
}

int main() {
    int unidadeOrigem;
    double valor;

    printf("Conversor de Unidades de Comprimento\n");
    exibirMenu();
    scanf("%d", &unidadeOrigem);

    printf("Digite o valor a ser convertido: ");
    scanf("%lf", &valor);

    converterUnidade(unidadeOrigem, valor);

    return 0;
}
