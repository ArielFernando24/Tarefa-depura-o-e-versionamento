#include <stdio.h>

// Função para exibir o menu de conversão de massa
void exibirMenuMassa() {
    printf("\nEscolha a unidade de entrada:\n");
    printf("1 - Quilograma (kg)\n");
    printf("2 - Grama (g)\n");
    printf("3 - Tonelada (t)\n");
    printf("Digite sua escolha: ");
}

// Função para converter unidades de massa
void converterUnidadeMassa(int unidadeOrigem, double valor) {
    double quilogramas, gramas, toneladas;

    // Conversão para quilogramas
    if (unidadeOrigem == 1) {
        quilogramas = valor;
    } else if (unidadeOrigem == 2) {
        quilogramas = valor / 1000.0; // g para kg
    } else if (unidadeOrigem == 3) {
        quilogramas = valor * 1000.0; // t para kg
    } else {
        printf("Unidade inválida!\n");
        return;
    }

    // Conversões a partir de quilogramas
    gramas = quilogramas * 1000.0;
    toneladas = quilogramas / 1000.0;

    // Exibir resultados
    printf("\nResultados:\n");
    printf("Quilogramas: %.4f kg\n", quilogramas);
    printf("Gramas: %.2f g\n", gramas);
    printf("Toneladas: %.6f t\n", toneladas);
}

// Função para exibir o menu de conversão de comprimento
void exibirMenuComprimento() {
    printf("\nEscolha a unidade de entrada:\n");
    printf("1 - Metro (m)\n");
    printf("2 - Centímetro (cm)\n");
    printf("3 - Milímetro (mm)\n");
    printf("Digite sua escolha: ");
}

// Função para converter unidades de comprimento
void converterUnidadeComprimento(int unidadeOrigem, double valor) {
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

// Função para exibir o menu principal
void exibirMenu() {
    printf("\nEscolha o tipo de conversão:\n");
    printf("1 - Conversor de Massa\n");
    printf("2 - Conversor de Comprimento\n");
    printf("Digite sua escolha: ");
}

int main() {
    int tipoConversao, unidadeOrigem;
    double valor;

    // Exibe o menu principal
    exibirMenu();
    scanf("%d", &tipoConversao);

    switch (tipoConversao) {
    case 1: // Conversão de massa
        printf("\nConversor de Unidades de Massa\n");
        exibirMenuMassa();
        scanf("%d", &unidadeOrigem);
        printf("Digite o valor a ser convertido: ");
        scanf("%lf", &valor);
        converterUnidadeMassa(unidadeOrigem, valor);
        break;

    case 2: // Conversão de comprimento
        printf("\nConversor de Unidades de Comprimento\n");
        exibirMenuComprimento();
        scanf("%d", &unidadeOrigem);
        printf("Digite o valor a ser convertido: ");
        scanf("%lf", &valor);
        converterUnidadeComprimento(unidadeOrigem, valor);
        break;

    default: // Opção inválida
        printf("\nOpção inválida! Por favor, tente novamente.\n");
        break;
    }

    return 0;
}
