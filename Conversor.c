#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

// CONVERSOR DE INFORMAÇÕES DIGITAIS
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}

void converterInfDigital(){
    double valor;
    char unidade[10], continuar = 's';
    
    //constante para a conversão
    const double BITS_POR_BYTE = 8.0;
    const double BYTES_POR_KILOBYTE = 1024.0;
    const double BYTES_POR_MEGABYTE = 1024.0 * 1024.0;
    const double BYTES_POR_GIGABYTE = 1024.0 * 1024.0 * 1024.0;
    const double BYTES_POR_TERABYTE = 1024.0 * 1024.0 * 1024.0 * 1024.0;

    while(continuar == 's' || continuar == 'S'){
        printf("\n======Conversor de Informacoes Digitais======\n");

        printf("Digite o valor: ");
        if(scanf("%lf%*c", &valor) != 1){
            printf("Valor inválido!\n");
           continue;
        }

        printf("Digite a unidade(bits, bytes, KB, MB, GB, TB): ");

        if(scanf("%9s%*c", unidade) != 1){
            printf("Unidade inválida!\n");
            continue;
        }

        //converter unidade para minuscula para facilitar a comparação
        to_lowercase(unidade);

        // Converte o valor para bytes
        double valor_em_bytes;
        if (strcmp(unidade, "bits") == 0 || strcmp(unidade, "bit") == 0) {
            valor_em_bytes = valor / BITS_POR_BYTE;
        } else if (strcmp(unidade, "bytes") == 0 || strcmp(unidade, "byte") == 0) {
            valor_em_bytes = valor;
        } else if (strcmp(unidade, "kb") == 0 || strcmp(unidade, "kilobytes") == 0) {
            valor_em_bytes = valor * BYTES_POR_KILOBYTE;
        } else if (strcmp(unidade, "mb") == 0 || strcmp(unidade, "megabytes") == 0) {
            valor_em_bytes = valor * BYTES_POR_MEGABYTE;
        } else if (strcmp(unidade, "gb") == 0 || strcmp(unidade, "gigabytes") == 0) {
            valor_em_bytes = valor * BYTES_POR_GIGABYTE;
        } else if (strcmp(unidade, "tb") == 0 || strcmp(unidade, "terabytes") == 0) {
            valor_em_bytes = valor * BYTES_POR_TERABYTE;
        } else {
            printf("Unidade inválida!\n");
            return;
        }
        // Converte o valor em bytes para outras unidades
        double em_bits = valor_em_bytes * BITS_POR_BYTE;
        double em_kb = valor_em_bytes / BYTES_POR_KILOBYTE;
        double em_mb = valor_em_bytes / BYTES_POR_MEGABYTE;
        double em_gb = valor_em_bytes / BYTES_POR_GIGABYTE;
        double em_tb = valor_em_bytes / BYTES_POR_TERABYTE;

        printf("\n======Resultados======\n");
        printf("Bits: %.2f\n", em_bits);
        printf("Bytes: %.2f\n", valor_em_bytes);
        printf("Kilobytes: %.2f\n", em_kb);
        printf("Megabytes: %.2f\n", em_mb);
        printf("Gigabytes: %.2f\n", em_gb);
        printf("Terabytes: %.2f\n", em_tb);
        
        printf("\nDeseja outra conversao? (s/n): ");
        scanf("%c%*c", &continuar);
    }
}

int main() {
    converterInfDigital();

    return 0;
}
