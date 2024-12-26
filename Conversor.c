#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void exibirMenuMassa()
{
    printf("\nEscolha a unidade de entrada:\n");
    printf("1 - Quilograma (kg)\n");
    printf("2 - Grama (g)\n");
    printf("3 - Tonelada (t)\n");
    printf("Digite sua escolha: ");
}

void converterUnidadeMassa()
{
    int unidadeOrigem;
    double valor;
    char opcao = 's';
    do
    {
        limparTela();
        exibirMenuMassa();
        if (scanf("%d", &unidadeOrigem) != 1 || unidadeOrigem < 1 || unidadeOrigem > 3)
        {
            printf("Unidade inválida! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        printf("Digite o valor a ser convertido: ");
        if (scanf("%lf", &valor) != 1 || valor < 0)
        {
            printf("Valor inválido! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        double quilogramas, gramas, toneladas;
        if (unidadeOrigem == 1)
        {
            quilogramas = valor;
        }
        else if (unidadeOrigem == 2)
        {
            quilogramas = valor / 1000.0;
        }
        else if (unidadeOrigem == 3)
        {
            quilogramas = valor * 1000.0;
        }

        gramas = quilogramas * 1000.0;
        toneladas = quilogramas / 1000.0;

        printf("\nResultados:\n");
        printf("Quilogramas: %.4f kg\n", quilogramas);
        printf("Gramas: %.2f g\n", gramas);
        printf("Toneladas: %.6f t\n", toneladas);

        printf("\n>>> Deseja realizar outra conversão de massa? (s/n): ");
        scanf(" %c%*c", &opcao);
    } while (opcao == 's' || opcao == 'S');
}

void exibirMenuComprimento()
{
    printf("\nEscolha a unidade de entrada:\n");
    printf("1 - Metro (m)\n");
    printf("2 - Centímetro (cm)\n");
    printf("3 - Milímetro (mm)\n");
    printf("Digite sua escolha: ");
}

void converterUnidadeComprimento()
{
    int unidadeOrigem;
    double valor;
    char opcao = 's';
    do
    {
        limparTela();
        exibirMenuComprimento();
        if (scanf("%d", &unidadeOrigem) != 1 || unidadeOrigem < 1 || unidadeOrigem > 3)
        {
            printf("Unidade inválida! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        printf("Digite o valor a ser convertido: ");
        if (scanf("%lf", &valor) != 1 || valor < 0)
        {
            printf("Valor inválido! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        double metros, centimetros, milimetros;
        if (unidadeOrigem == 1)
        {
            metros = valor;
        }
        else if (unidadeOrigem == 2)
        {
            metros = valor / 100.0;
        }
        else if (unidadeOrigem == 3)
        {
            metros = valor / 1000.0;
        }

        centimetros = metros * 100.0;
        milimetros = metros * 1000.0;

        printf("\nResultados:\n");
        printf("Metros: %.4f m\n", metros);
        printf("Centímetros: %.2f cm\n", centimetros);
        printf("Milímetros: %.2f mm\n", milimetros);

        printf("\n>>> Deseja realizar outra conversão de comprimento? (s/n): ");
        scanf(" %c%*c", &opcao);
    } while (opcao == 's' || opcao == 'S');
}

void exibirMenuInfDigital()
{
    printf("\n====================================="
           "\n  CONVERSOR DE INFORMAÇÕES DIGITAIS\n"
           "          (Prefixo do S.I.)\n"
           "====================================="
           "\nEscolha a unidade de entrada:\n");
    printf(" [1] Bits (b)\n");
    printf(" [2] Bytes (B)\n");
    printf(" [3] Kilobytes (kB)\n");
    printf(" [4] Megabytes (MB)\n");
    printf(" [5] Gigabytes (GB)\n");
    printf(" [6] Terabytes (TB)\n");
    printf("\n>>> Digite o número correspondente à unidade de entrada: ");
}

void converterInfDigital()
{
    int unidadeOrigem;
    double valor;
    char opcao = 's';
    const double BITS_POR_BYTE = 8.0;
    const double BYTES_POR_KILOBYTE = 1000.0;
    const double BYTES_POR_MEGABYTE = 1000.0 * 1000.0;
    const double BYTES_POR_GIGABYTE = 1000.0 * 1000.0 * 1000.0;
    const double BYTES_POR_TERABYTE = 1000.0 * 1000.0 * 1000.0 * 1000.0;
    do
    {
        limparTela();
        exibirMenuInfDigital();
        if (scanf("%d%*c", &unidadeOrigem) != 1 || unidadeOrigem < 1 || unidadeOrigem > 6)
        {
            printf("Unidade inválida! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        printf("Digite o valor a ser convertido: ");
        if (scanf("%lf%*c", &valor) != 1 || valor < 0)
        {
            printf("Valor inválido! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        double valor_em_bytes;
        switch (unidadeOrigem)
        {
        case 1:
            valor_em_bytes = valor / BITS_POR_BYTE;
            break;
        case 2:
            valor_em_bytes = valor;
            break;
        case 3:
            valor_em_bytes = valor * BYTES_POR_KILOBYTE;
            break;
        case 4:
            valor_em_bytes = valor * BYTES_POR_MEGABYTE;
            break;
        case 5:
            valor_em_bytes = valor * BYTES_POR_GIGABYTE;
            break;
        case 6:
            valor_em_bytes = valor * BYTES_POR_TERABYTE;
            break;
        }

        long long em_bits = (long long)(valor_em_bytes * BITS_POR_BYTE + 0.5);
        double em_kb = valor_em_bytes / BYTES_POR_KILOBYTE;
        double em_mb = valor_em_bytes / BYTES_POR_MEGABYTE;
        double em_gb = valor_em_bytes / BYTES_POR_GIGABYTE;
        double em_tb = valor_em_bytes / BYTES_POR_TERABYTE;

        printf("\n--------------------------------------\n");
        printf("Resultados (base 10)\n");
        printf("--------------------------------------\n");
        printf("Bits       : %lld b\n", em_bits);
        printf("Bytes      : %.2f B\n", valor_em_bytes);
        printf("Kilobytes  : %.2f kB\n", em_kb);
        printf("Megabytes  : %.2f MB\n", em_mb);
        printf("Gigabytes  : %.2f GB\n", em_gb);
        printf("Terabytes  : %.2f TB\n", em_tb);

        printf("\n>>> Deseja realizar outra conversão de informações digitais? (s/n): ");
        scanf(" %c%*c", &opcao);
    } while (opcao == 's' || opcao == 'S');
}

void exibirMenuEletrico()
{
    printf("\n====================================="
           "\n  CONVERSOR DE GRANDEZAS ELÉTRICAS\n"
           "====================================="
           "\nEscolha o tipo de grandeza:\n");
    printf(" [1] Volts (V)\n");
    printf(" [2] Ampere (A)\n");
    printf(" [3] Ohms (Ω)\n");
    printf("\n>>> Digite sua escolha: ");
}

void exibirResultados(double valorBase, const char *grandeza)
{
    printf("\nResultados da conversão para %s:\n", grandeza);
    printf("Micro%s (µ%s): %.6f\n", grandeza, grandeza, valorBase * 1e6);
    printf("Mili%s (m%s): %.6f\n", grandeza, grandeza, valorBase * 1e3);
    printf("Base %s (%s): %.6f\n", grandeza, grandeza, valorBase);
    printf("Kilo%s (k%s): %.6f\n", grandeza, grandeza, valorBase / 1e3);
    printf("Mega%s (M%s): %.6f\n", grandeza, grandeza, valorBase / 1e6);
}

void converterEletrico()
{
    int tipoGrandeza;
    double valor;
    char opcao = 's';
    do
    {
        limparTela();
        exibirMenuEletrico();
        if (scanf("%d%*c", &tipoGrandeza) != 1 || tipoGrandeza < 1 || tipoGrandeza > 3)
        {
            printf("Opção inválida! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        const char *grandeza = (tipoGrandeza == 1) ? "V" : (tipoGrandeza == 2) ? "A"
                                                                               : "Ω";

        printf("\n>>> Digite o valor em %s (base): ", grandeza);
        if (scanf("%lf", &valor) != 1 || valor < 0)
        {
            printf("Valor inválido!\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        exibirResultados(valor, grandeza);

        printf("\n>>> Deseja realizar outra conversão de grandezas elétricas? (s/n): ");
        scanf(" %c%*c", &opcao);
    } while (opcao == 's' || opcao == 'S');
}

void exibirMenuTemperatura()
{
    printf("\n====================================="
           "\n      CONVERSOR DE UNIDADES DE TEMPERATURA\n"
           "====================================="
           "\nEscolha a unidade de entrada:\n");
    printf(" [1] Celsius (°C)\n");
    printf(" [2] Fahrenheit (°F)\n");
    printf(" [3] Kelvin (K)\n");
    printf(" [4] Rankine (°R)\n");
    printf(" [5] Réaumur (°Re)\n");
    printf("\n>>> Digite sua escolha: ");
}

void exibirResultadosTemperatura(double valor, int unidadeOrigem)
{
    double celsius, fahrenheit, kelvin, rankine, reaumur;

    switch (unidadeOrigem)
    {
    case 1:
        celsius = valor;
        fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        kelvin = celsius + 273.15;
        rankine = (celsius + 273.15) * 9.0 / 5.0;
        reaumur = celsius * 0.8;
        break;
    case 2:
        fahrenheit = valor;
        celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
        kelvin = celsius + 273.15;
        rankine = fahrenheit + 459.67;
        reaumur = celsius * 0.8;
        break;
    case 3:
        kelvin = valor;
        celsius = kelvin - 273.15;
        fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        rankine = kelvin * 9.0 / 5.0;
        reaumur = celsius * 0.8;
        break;
    case 4:
        rankine = valor;
        kelvin = rankine * 5.0 / 9.0;
        celsius = kelvin - 273.15;
        fahrenheit = rankine - 459.67;
        reaumur = celsius * 0.8;
        break;
    case 5:
        reaumur = valor;
        celsius = reaumur * 1.25;
        fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        kelvin = celsius + 273.15;
        rankine = (celsius + 273.15) * 9.0 / 5.0;
        break;
    default:
        printf("Erro: Unidade inválida!\n");
        return;
    }

    printf("\n=====================================\n");
    printf("Resultados da Conversão de Temperatura:\n");
    printf("=====================================\n");
    printf("Celsius (°C): %.2f\n", celsius);
    printf("Fahrenheit (°F): %.2f\n", fahrenheit);
    printf("Kelvin (K): %.2f\n", kelvin);
    printf("Rankine (°R): %.2f\n", rankine);
    printf("Réaumur (°Re): %.2f\n", reaumur);
    printf("=====================================\n");
}

void converterTemperatura()
{
    int unidadeOrigem;
    double valor;
    char opcao = 's';

    do
    {
        limparTela();
        exibirMenuTemperatura();
        if (scanf("%d%*c", &unidadeOrigem) != 1 || unidadeOrigem < 1 || unidadeOrigem > 5)
        {
            printf("Opção inválida! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        printf("\n>>> Digite o valor a ser convertido: ");
        if (scanf("%lf", &valor) != 1)
        {
            printf("Valor inválido! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        exibirResultadosTemperatura(valor, unidadeOrigem);

        printf("\n>>> Deseja realizar outra conversão de temperatura? (s/n): ");
        scanf(" %c%*c", &opcao);
    } while (opcao == 's' || opcao == 'S');
}

void converterVelocidade()
{
    double valor;
    printf("Informe qual valor voce quer converte ?\n");
    scanf("%lf", &valor);

    // Conversão para todas as unidades
    double em_ms = valor / 3.6;      // km/h -> m/s
    double em_kmh = valor;           // km/h permanece o mesmo
    double em_mph = valor / 1.60934; // km/h -> mph

    // Exibe os resultados
    printf("Velocidade convertida:\n");
    printf("- %.2lf km/h\n", em_kmh);
    printf("- %.2lf m/s\n", em_ms);
    printf("- %.2lf mph\n", em_mph);
}

void exibirMenuVolume()
{
    printf("\nEscolha a unidade de origem:\n");
    printf("1 - Litros\n");
    printf("2 - Mililitros\n");
    printf("3 - Metros cúbicos\n");
    printf("Digite sua escolha: ");
}

void converterUnidadeVolume()
{
    int unidadeOrigem;
    double valor;
    char opcao = 's';
    do
    {
        limparTela();
        exibirMenuVolume();
        if (scanf("%d", &unidadeOrigem) != 1 || unidadeOrigem < 1 || unidadeOrigem > 3)
        {
            printf("Unidade inválida! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        printf("Digite o valor a ser convertido: ");
        if (scanf("%lf", &valor) != 1 || valor < 0)
        {
            printf("Valor inválido! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        double litros, mililitros, metrosCubicos;
        if (unidadeOrigem == 1)
        {
            litros = valor;
        }
        else if (unidadeOrigem == 2)
        {
            litros = valor / 1000.0;
        }
        else if (unidadeOrigem == 3)
        {
            litros = valor * 1000.0;
        }

        mililitros = litros * 1000.0;
        metrosCubicos = litros / 1000.0;

        printf("\nResultados:\n");
        printf("Litros: %.4f L\n", litros);
        printf("Mililitros: %.2f mL\n", mililitros);
        printf("Metros cúbicos: %.6f m³\n", metrosCubicos);

        printf("\n>>> Deseja realizar outra conversão de volume? (s/n): ");
        scanf(" %c%*c", &opcao);
    } while (opcao == 's' || opcao == 'S');
}

void exibirMenuTempo()
{
    printf("\n====================================="
           "\n        CONVERSOR DE TEMPO\n"
           "====================================="
           "\nEscolha a unidade de entrada:\n");
    printf(" [1] Milésimos de segundo (ms)\n");
    printf(" [2] Centésimos de segundo (cs)\n");
    printf(" [3] Segundos (s)\n");
    printf(" [4] Minutos (min)\n");
    printf(" [5] Horas (h)\n");
    printf(" [6] Dias (d)\n");
    printf(" [7] Anos (anos)\n");
    printf("\n>>> Digite sua escolha: ");
}

void exibirResultadosTempo(double valorBase, int unidadeOrigem)
{
    double milisegundos, centesimos, segundos, minutos, horas, dias, anos;

    switch (unidadeOrigem)
    {
    case 1:
        milisegundos = valorBase;
        centesimos = milisegundos / 10.0;
        segundos = milisegundos / 1000.0;
        minutos = segundos / 60.0;
        horas = minutos / 60.0;
        dias = horas / 24.0;
        anos = dias / 365.0;
        break;
    case 2:
        centesimos = valorBase;
        milisegundos = centesimos * 10.0;
        segundos = centesimos / 100.0;
        minutos = segundos / 60.0;
        horas = minutos / 60.0;
        dias = horas / 24.0;
        anos = dias / 365.0;
        break;
    case 3:
        segundos = valorBase;
        milisegundos = segundos * 1000.0;
        centesimos = segundos * 100.0;
        minutos = segundos / 60.0;
        horas = minutos / 60.0;
        dias = horas / 24.0;
        anos = dias / 365.0;
        break;
    case 4:
        minutos = valorBase;
        segundos = minutos * 60.0;
        milisegundos = segundos * 1000.0;
        centesimos = segundos * 100.0;
        horas = minutos / 60.0;
        dias = horas / 24.0;
        anos = dias / 365.0;
        break;
    case 5:
        horas = valorBase;
        minutos = horas * 60.0;
        segundos = minutos * 60.0;
        milisegundos = segundos * 1000.0;
        centesimos = segundos * 100.0;
        dias = horas / 24.0;
        anos = dias / 365.0;
        break;
    case 6:
        dias = valorBase;
        horas = dias * 24.0;
        minutos = horas * 60.0;
        segundos = minutos * 60.0;
        milisegundos = segundos * 1000.0;
        centesimos = segundos * 100.0;
        anos = dias / 365.0;
        break;
    case 7:
        anos = valorBase;
        dias = anos * 365.0;
        horas = dias * 24.0;
        minutos = horas * 60.0;
        segundos = minutos * 60.0;
        milisegundos = segundos * 1000.0;
        centesimos = segundos * 100.0;
        break;
    default:
        printf("Erro: Unidade inválida!\n");
        return;
    }

    printf("\n=====================================\n");
    printf("Resultados da Conversão de Tempo:\n");
    printf("=====================================\n");
    printf("Milésimos de segundo (ms): %.2f\n", milisegundos);
    printf("Centésimos de segundo (cs): %.2f\n", centesimos);
    printf("Segundos (s): %.2f\n", segundos);
    printf("Minutos (min): %.4f\n", minutos);
    printf("Horas (h): %.6f\n", horas);
    printf("Dias (d): %.6f\n", dias);
    printf("Anos (anos): %.8f\n", anos);
    printf("=====================================\n");
}

void converterTempo()
{
    int unidadeOrigem;
    double valor;
    char opcao = 's';

    do
    {
        limparTela();
        exibirMenuTempo();
        if (scanf("%d%*c", &unidadeOrigem) != 1 || unidadeOrigem < 1 || unidadeOrigem > 7)
        {
            printf("Opção inválida! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        printf("\n>>> Digite o valor a ser convertido: ");
        if (scanf("%lf", &valor) != 1 || valor < 0)
        {
            printf("Valor inválido! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        exibirResultadosTempo(valor, unidadeOrigem);

        printf("\n>>> Deseja realizar outra conversão de tempo? (s/n): ");
        scanf(" %c%*c", &opcao);
    } while (opcao == 's' || opcao == 'S');
}
void exibirMenuArea()
{
    printf("\n====================================="
           "\n      CONVERSOR DE UNIDADES DE ÁREA\n"
           "====================================="
           "\nEscolha a unidade de entrada:\n");
    printf(" [1] Metros Quadrados (m²)\n");
    printf(" [2] Centímetros Quadrados (cm²)\n");
    printf(" [3] Hectares (ha)\n");
    printf(" [4] Acres (ac)\n");
    printf("\n>>> Digite sua escolha: ");
}

void converterUnidadeArea()
{
    int unidadeOrigem;
    double valor;
    char opcao = 's';
    do
    {
        limparTela();
        exibirMenuArea();
        if (scanf("%d", &unidadeOrigem) != 1 || unidadeOrigem < 1 || unidadeOrigem > 4)
        {
            printf("Unidade inválida! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        printf("\nDigite o valor a ser convertido: ");
        if (scanf("%lf", &valor) != 1 || valor < 0)
        {
            printf("Valor inválido! Por favor, tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        double metrosQuadrados;

        // Conversão para metros quadrados como unidade base
        switch (unidadeOrigem)
        {
        case 1:
            metrosQuadrados = valor;
            break;
        case 2:
            metrosQuadrados = valor / 10000.0;
            break;
        case 3:
            metrosQuadrados = valor * 10000.0;
            break;
        case 4:
            metrosQuadrados = valor * 4046.85642;
            break;
        default:
            printf("Erro inesperado.\n");
            return;
        }

        // Conversões para outras unidades
        double centimetrosQuadrados = metrosQuadrados * 10000.0;
        double hectares = metrosQuadrados / 10000.0;
        double acres = metrosQuadrados / 4046.85642;

        printf("\nResultados:\n");
        printf("Metros Quadrados: %.4f m²\n", metrosQuadrados);
        printf("Centímetros Quadrados: %.2f cm²\n", centimetrosQuadrados);
        printf("Hectares: %.6f ha\n", hectares);
        printf("Acres: %.6f ac\n", acres);

        printf("\n>>> Deseja realizar outra conversão de área? (s/n): ");
        scanf(" %c%*c", &opcao);
    } while (opcao == 's' || opcao == 'S');
}

void desenvolvedores()
{
    printf("\n=== DESENVOLVEDORES ===\n");
    printf("1 - Hércules Santos\n");
    printf("2 - Danilo Lacerda\n");
    printf("3 - Ariel Fernando\n");
    printf("4 - Cíntia Conceição\n");
    printf("5 - Julio Junior\n");
    printf("6 - Mágna Dias\n");
    printf("7 - Pedro Gabriel\n");
    printf("8 - Tárcio Santos\n");
}

void exibirMenu()
{
    printf("\nEscolha o tipo de conversão:\n");
    printf("1 - Conversor de Massa\n");
    printf("2 - Conversor de Comprimento\n");
    printf("3 - Conversor de Informações Digitais\n");
    printf("4 - Conversor de Grandezas Elétricas\n");
    printf("5 - Conversor de Temperatura\n");
    printf("6 - Conversor de velocidade\n");
    printf("7 - Conversor de Volume\n");
    printf("8 - Conversor de Tempo\n");
    printf("9 - Conversor de Área\n");
    printf("* - Desenvolvedores\n");
    printf("Digite sua escolha: ");
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif
    char tipoConversao;
    char opcao = 's';

    do
    {
        limparTela();
        exibirMenu();
        if (scanf(" %c", &tipoConversao) != 1)
        {
            printf("Entrada inválida! Tente novamente.\n");
            while (getchar() != '\n')
                ; // Limpa buffer
            continue;
        }

        switch (tipoConversao)
        {
        case '1':
            converterUnidadeMassa();
            break;
        case '2':
            converterUnidadeComprimento();
            break;
        case '3':
            converterInfDigital();
            break;
        case '4':
            converterEletrico();
            break;
        case '5':
            converterTemperatura();
            break;
        case '6':
            converterVelocidade();
            break;
        case '7':
            converterUnidadeVolume();
            break;
        case '8':
            converterTempo();
            break;
        case '9':
            converterUnidadeArea();
            break;
        case '*':
            limparTela();
            desenvolvedores();
            getchar(); // Pausa para o usuário visualizar os desenvolvedores
            break;
        default:
            printf("\nOpção inválida! Por favor, tente novamente.\n");
            break;
        }

        printf("\n>>> Deseja voltar ao menu principal? (s/n): ");
        scanf(" %c%*c", &opcao);
    } while (opcao == 's' || opcao == 'S');

    return 0;
}