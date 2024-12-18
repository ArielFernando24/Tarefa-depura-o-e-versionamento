#include <stdio.h>
void converterVelocidade(double valor);
void exibirMenu() {
    printf("\nEscolha a conversão que deseja:\n");
    printf("1. Unidades de comprimento (metro, centímetro, milímetro)\n");
    printf("2. Unidades de massa (quilograma, grama, tonelada)\n");
    printf("3. Unidades de volume (litro, mililitro, metros cúbicos)\n");
    printf("4. Unidades de temperatura (Celsius, Fahrenheit, Kelvin)\n");
    printf("5. Unidades de velocidade (km/h, m/s, mph)\n");
    printf("6. Watts (W), quilowatts (kW), cavalos-vapor (cv ou hp)\n");
    printf("7. Unidades de área (metro quadrado, centímetro quadrado)\n");
    printf("8. Unidades de tempo (segundos, minutos, horas)\n");
    printf("9. Bits, bytes, kilobytes (KB), megabytes (MB), gigabytes (GB), terabytes (TB)\n");
    printf("Digite sua escolha: ");
}

void converterUnidade(int unidadeOrigem, double valor) {

switch(unidadeOrigem){
    case 1:
        printf("Unidades de comprimento (metro, centímetro, milímetro)");

    break;

    case 2:
        printf("2. Unidades de massa (quilograma, grama, tonelada)\n");

    break;

    case 3:
        printf("3. Unidades de volume (litro, mililitro, metros cúbicos)\n");

    break;

    case 4:
        printf("4. Unidades de temperatura (Celsius, Fahrenheit, Kelvin)\n");

    break;

    case 5:
        printf("5. Unidades de velocidade (km/h, m/s, mph)\n");
        converterVelocidade(valor);
    break;

    case 6:
         printf("6. Watts (W), quilowatts (kW), cavalos-vapor (cv ou hp)\n");
    break;

    case 7:
        printf("7. Unidades de área (metro quadrado, centímetro quadrado)\n");
    break;

    case 8:
        printf("8. Unidades de tempo (segundos, minutos, horas)\n");
    break;

    case 9:
        printf("9. Bits, bytes, kilobytes (KB), megabytes (MB), gigabytes (GB), terabytes (TB)\n"); 
    break;

    default :
    printf ("Valor invalido!\n");

}
}

void converterVelocidade(double valor) {
    // Conversão para todas as unidades
    double em_ms = valor / 3.6;       // km/h -> m/s
    double em_kmh = valor;           // km/h permanece o mesmo
    double em_mph = valor / 1.60934; // km/h -> mph

    // Exibe os resultados
    printf("Velocidade convertida:\n");
    printf("- %.2lf km/h\n", em_kmh);
    printf("- %.2lf m/s\n", em_ms);
    printf("- %.2lf mph\n", em_mph);

}

int main() {
    int unidadeOrigem;
    double valor;

    printf("Conversor de Unidades \n");
    exibirMenu();
    scanf("%d", &unidadeOrigem);

    printf("Digite o valor a ser convertido: ");
    scanf("%lf", &valor);

    converterUnidade(unidadeOrigem, valor);

    return 0;
}
