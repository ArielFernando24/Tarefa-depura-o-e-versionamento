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

// --- CONVERSOR DE INFORMAÇÕES DIGITAIS --

// Função para converter a unidade para minuscula
void exibirMenuInfDigital() {
    printf("\n=====================================\n");
    printf("  CONVERSOR DE INFORMACOES DIGITAIS\n");
    printf("          (Prefixo do S.I.)\n");
    printf("=====================================\n");
    printf("Escolha a unidade de entrada:\n");
    printf(" [1] Bits (b)\n");
    printf(" [2] Bytes (B)\n");
    printf(" [3] Kilobytes (kB)\n");
    printf(" [4] Megabytes (MB)\n");
    printf(" [5] Gigabytes (GB)\n");
    printf(" [6] Terabytes (TB)\n");
    printf("\n>>> Digite o numero correspondente a unidade de entrada: ");
}

// Função para converter informações digitais
void converterInfDigital() {
    int unidadeOrigem;
    double valor;
    char opcao = 's';

    const double BITS_POR_BYTE = 8.0;
    const double BYTES_POR_KILOBYTE = 1000.0;
    const double BYTES_POR_MEGABYTE = 1000.0 * 1000.0;
    const double BYTES_POR_GIGABYTE = 1000.0 * 1000.0 * 1000.0;
    const double BYTES_POR_TERABYTE = 1000.0 * 1000.0 * 1000.0 * 1000.0;
    do{
        exibirMenuInfDigital();
        if(scanf("%d%*c", &unidadeOrigem) != 1 || unidadeOrigem < 1 || unidadeOrigem > 6) {
            printf("Unidade invalida! Por favor, tente novamente.\n");
            continue;
        }
       
        printf(">>> Digite o valor a ser convertido: ");
        if(scanf("%lf%*c", &valor) != 1 || valor < 0) {
            printf("Valor invalido! Por favor, tente novamente.\n");
            continue;
        }

        double valor_em_bytes;

        switch (unidadeOrigem) {
            case 1: // Bits
                valor_em_bytes = valor / BITS_POR_BYTE;
                break;
            case 2: // Bytes
                valor_em_bytes = valor;
                break;
            case 3: // KB
                valor_em_bytes = valor * BYTES_POR_KILOBYTE;
                break;
            case 4: // MB
                valor_em_bytes = valor * BYTES_POR_MEGABYTE;
                break;
            case 5: // GB
                valor_em_bytes = valor * BYTES_POR_GIGABYTE;
                break;
            case 6: // TB
                valor_em_bytes = valor * BYTES_POR_TERABYTE;
                break;
        }
        // Converte para bits(arredonda para o inteiro mais proximo)
        long long em_bits = (long long) (valor_em_bytes * BITS_POR_BYTE + 0.5);

        // Converte de bytes para as demais unidades(decimal) 
        double em_kb = valor_em_bytes / BYTES_POR_KILOBYTE;
        double em_mb = valor_em_bytes / BYTES_POR_MEGABYTE;
        double em_gb = valor_em_bytes / BYTES_POR_GIGABYTE;
        double em_tb = valor_em_bytes / BYTES_POR_TERABYTE;

        printf("\n--------------------------------------\n");
        printf("Resultados (base 10)\n");
        printf("--------------------------------------\n");
        printf("%-12s : %lld b\n", "Bits", em_bits);
        printf("%-12s : %.2f B\n", "Bytes", valor_em_bytes);
        printf("%-12s : %.2f kB\n", "Kilobytes", em_kb);
        printf("%-12s : %.2f MB\n", "Megabytes", em_mb);
        printf("%-12s : %.2f GB\n", "Gigabytes", em_gb);
        printf("%-12s : %.2f TB\n", "Terabytes", em_tb);

        printf("\n>>> Deseja realizar outra conversao de informacoes digitais? (s/n): ");
        scanf(" %c%*c", &opcao);
    }while(opcao == 's'|| opcao == 'S');
}

// Função para exibir o menu principal
void exibirMenu() {
    printf("\nEscolha o tipo de conversão:\n");
    printf("1 - Conversor de Massa\n");
    printf("2 - Conversor de Comprimento\n");
    printf("8 - Conversor de Informacoes Digitais\n");
    printf("Digite sua escolha: ");
}

int main() {
    int tipoConversao, unidadeOrigem;
    double valor;
    char opcao = 's';

    do{
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
        case 8: // Conversão de Informações Digitais
            converterInfDigital();
            break;

        default: // Opção inválida
            printf("\nOpção inválida! Por favor, tente novamente.\n");
            break;
        }

        printf("\n>>> Deseja voltar ao menu principal? (s/n): ");
        scanf(" %c%*c", &opcao);
    }while(opcao == 's' || opcao == 'S');

    return 0;
}
