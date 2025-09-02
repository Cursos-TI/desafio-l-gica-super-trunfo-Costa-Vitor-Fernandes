#include <stdio.h>

struct Carta{
    char nome_cidade[50], estado[4], codigo_carta[4];
    float pib, area, densidade_populacional, pib_per_capita, super_poder;
    unsigned long int populacao;
    int n_pontos_turisticos;
};


typedef enum {
    POPULACAO = 1,
    AREA = 2,
    PIB = 3,
    PONTOS_TURISTICOS = 4,
    DENSIDADE_POPULACIONAL = 5,
    PIB_PER_CAPITA = 6,
    SUPER_PODER = 7
} Atributo;


void calcular_super_poder(struct Carta *carta) {
    carta->super_poder = (float)carta->populacao + carta->area + carta->pib + (float)carta->n_pontos_turisticos + carta->pib_per_capita + (1.0 / carta->densidade_populacional);
}


void calcular_valores_dinamicos (struct Carta *carta){
    carta->densidade_populacional = (float)carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / (float)carta->populacao;
}


void ExibirCarta(struct Carta carta) {
    printf("Nome: %s\n", carta.nome_cidade);
    printf("Estado: %s\n", carta.estado);
    printf("Codigo da Carta: %s\n", carta.codigo_carta);
    printf("PIB: %.2f\n", carta.pib);
    printf("Area: %.2f\n", carta.area);
    printf("Populacao: %lu\n", carta.populacao);
    printf("Pontos Turisticos: %d\n", carta.n_pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", carta.densidade_populacional);
    printf("PIB per Capita: %.2f\n", carta.pib_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
}

void Cadastro(struct Carta *carta, int i) {
    printf("CADASTRO DE CARTA NUMERO %d\n", i);
    printf("Insira as informacoes da Carta:\n");
    printf("Digite o nome da cidade: ");
    scanf("%s", carta->nome_cidade);
    printf("Digite o estado: ");
    scanf("%s", carta->estado);
    printf("Digite o codigo da carta: ");
    scanf("%s", carta->codigo_carta);
    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);
    printf("Digite a Area: ");
    scanf("%f", &carta->area);
    printf("Digite a Populacao: ");
    scanf("%lu", &carta->populacao);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta->n_pontos_turisticos);
    calcular_valores_dinamicos(carta);
    calcular_super_poder(carta);
}


float pegaValorAtributo(const struct Carta* carta, int atributo) {
    switch (atributo) {
        case POPULACAO: return (float)carta->populacao;
        case AREA: return carta->area;
        case PIB: return carta->pib;
        case PONTOS_TURISTICOS: return (float)carta->n_pontos_turisticos;
        case DENSIDADE_POPULACIONAL: return carta->densidade_populacional;
        case PIB_PER_CAPITA: return carta->pib_per_capita;
        case SUPER_PODER: return carta->super_poder;
        default: return 0.0;
    }
}

void CompararUmAtributo(struct Carta carta1, struct Carta carta2, int atributo_escolhido){
    printf("\n--- Comparacao de Cartas ---\n");

    switch (atributo_escolhido) {
        case POPULACAO:
            printf("Atributo para comparacao: Populacao\n\n");
            printf("Carta 1 - %s (%s): %lu\n", carta1.nome_cidade, carta1.estado, carta1.populacao);
            printf("Carta 2 - %s (%s): %lu\n", carta2.nome_cidade, carta2.estado, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case AREA:
            printf("Atributo para comparacao: Area\n\n");
            printf("Carta 1 - %s (%s): %.2f km2\n", carta1.nome_cidade, carta1.estado, carta1.area);
            printf("Carta 2 - %s (%s): %.2f km2\n", carta2.nome_cidade, carta2.estado, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case PIB:
            printf("Atributo para comparacao: PIB\n\n");
            printf("Carta 1 - %s (%s): %.2f bilhoes de R$\n", carta1.nome_cidade, carta1.estado, carta1.pib);
            printf("Carta 2 - %s (%s): %.2f bilhoes de R$\n", carta2.nome_cidade, carta2.estado, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case PONTOS_TURISTICOS:
            printf("Atributo para comparacao: Pontos Turisticos\n\n");
            printf("Carta 1 - %s (%s): %d\n", carta1.nome_cidade, carta1.estado, carta1.n_pontos_turisticos);
            printf("Carta 2 - %s (%s): %d\n", carta2.nome_cidade, carta2.estado, carta2.n_pontos_turisticos);
            if (carta1.n_pontos_turisticos > carta2.n_pontos_turisticos) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.n_pontos_turisticos > carta1.n_pontos_turisticos) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case DENSIDADE_POPULACIONAL:
            printf("Atributo para comparacao: Densidade Populacional\n\n");
            printf("Carta 1 - %s (%s): %.2f hab/km2\n", carta1.nome_cidade, carta1.estado, carta1.densidade_populacional);
            printf("Carta 2 - %s (%s): %.2f hab/km2\n", carta2.nome_cidade, carta2.estado, carta2.densidade_populacional);
            // Regra especial: menor valor vence
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case PIB_PER_CAPITA:
            printf("Atributo para comparacao: PIB per Capita\n\n");
            printf("Carta 1 - %s (%s): %.2f R$\n", carta1.nome_cidade, carta1.estado, carta1.pib_per_capita);
            printf("Carta 2 - %s (%s): %.2f R$\n", carta2.nome_cidade, carta2.estado, carta2.pib_per_capita);
            if (carta1.pib_per_capita > carta2.pib_per_capita) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case SUPER_PODER:
            printf("Atributo para comparacao: Super Poder\n\n");
            printf("Carta 1 - %s: %.2f R$\n", carta1.nome_cidade, carta1.super_poder);
            printf("Carta 2 - %s: %.2f R$\n", carta2.nome_cidade, carta2.super_poder);
            if (carta1.super_poder > carta2.super_poder) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.super_poder > carta1.super_poder) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        default:
            printf("Atributo escolhido não e valido. Por favor, insira valores numericos validos\n");
    }
}

int main() {
    // Cartas pré-cadastradas, sem tempo irmao
    struct Carta carta1 = {
        .nome_cidade = "Sao Paulo", .estado = "SP", .populacao = 12300000,
        .area = 1521.0, .pib = 763.8, .n_pontos_turisticos = 15
    };
    calcular_valores_dinamicos(&carta1);
    calcular_super_poder(&carta1);

    struct Carta carta2 = {
        .nome_cidade = "Rio de Janeiro", .estado = "RJ", .populacao = 6700000,
        .area = 1200.0, .pib = 350.0, .n_pontos_turisticos = 20
    };
    calcular_valores_dinamicos(&carta2);
    calcular_super_poder(&carta2);

    int escolha_menu, atributo1, atributo2;

    printf("---- MENU PRINCIPAL SUPER TRUNFO ----\n");
    printf("1: Cadastrar Carta\n");
    printf("2: Comparacao com 1 atributo (Nivel Aventureiro)\n");
    printf("3: Comparacao com 2 atributos (Nivel Mestre)\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha_menu);

    switch (escolha_menu) {
        case 1:
            Cadastro(&carta1, 1);
            Cadastro(&carta2, 2);
            break;
        case 2:
            //Comparacao com 1 atributo
            printf("\n---- MENU DE COMPARAÇÃO -----\n");
            printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n");
            printf("5 - Densidade Populacional\n6 - PIB per Capita\n7 - Super Poder\n\n");
            printf("Escolha um atributo numerico: ");
            scanf("%d", &atributo1);
            CompararUmAtributo(carta1, carta2, atributo1);
            break;
        case 3:
            // Comparacao com 2 atributos
            printf("\n---- COMPARACAO COM 2 ATRIBUTOS -----\n");
            printf("Escolha o PRIMEIRO atributo para comparar:\n");
            printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n");
            printf("5 - Densidade Populacional\n6 - PIB per Capita\n7 - Super Poder\n\n");
            printf("Opcao: ");
            scanf("%d", &atributo1);

            printf("\nEscolha o SEGUNDO atributo para comparar:\n");
            // Menu dinamico para o segundo atributo
            if (atributo1 != POPULACAO) printf("1 - Populacao\n");
            if (atributo1 != AREA) printf("2 - Area\n");
            if (atributo1 != PIB) printf("3 - PIB\n");
            if (atributo1 != PONTOS_TURISTICOS) printf("4 - Pontos Turisticos\n");
            if (atributo1 != DENSIDADE_POPULACIONAL) printf("5 - Densidade Populacional\n");
            if (atributo1 != PIB_PER_CAPITA) printf("6 - PIB per Capita\n");
            if (atributo1 != SUPER_PODER) printf("7 - Super Poder\n");
            printf("Opcao: ");
            scanf("%d", &atributo2);

            // Valida se o usuario escolheu o mesmo atributo
            if (atributo1 == atributo2) {
                printf("Erro: Voce escolheu o mesmo atributo duas vezes.\n");
                return 1;
            }

            // Calculo da soma dos atributos com a regra da Densidade Populacional
            float valor1_c1 = pegaValorAtributo(&carta1, atributo1);
            float valor2_c1 = pegaValorAtributo(&carta1, atributo2);
            float valor1_c2 = pegaValorAtributo(&carta2, atributo1);
            float valor2_c2 = pegaValorAtributo(&carta2, atributo2);

            // Usa o operador ternario para ajustar os valores de densidade populacional na soma
            float soma1 = (atributo1 == DENSIDADE_POPULACIONAL && valor1_c1 > 0) ? (1.0 / valor1_c1) : valor1_c1;
            soma1 += (atributo2 == DENSIDADE_POPULACIONAL && valor2_c1 > 0) ? (1.0 / valor2_c1) : valor2_c1;

            float soma2 = (atributo1 == DENSIDADE_POPULACIONAL && valor1_c2 > 0) ? (1.0 / valor1_c2) : valor1_c2;
            soma2 += (atributo2 == DENSIDADE_POPULACIONAL && valor2_c2 > 0) ? (1.0 / valor2_c2) : valor2_c2;

            // Exibicao dos resultados
            printf("\n--- RESULTADO DA RODADA AVANCADA ---\n");
            printf("Atributos comparados: %d e %d\n", atributo1, atributo2);
            printf("Carta 1 (%s): Atributo 1 = %.2f, Atributo 2 = %.2f, Soma = %.2f\n", carta1.nome_cidade, valor1_c1, valor2_c1, soma1);
            printf("Carta 2 (%s): Atributo 1 = %.2f, Atributo 2 = %.2f, Soma = %.2f\n", carta2.nome_cidade, valor1_c2, valor2_c2, soma2);

            if (soma1 > soma2) {
                printf("\nResultado: Carta 1 (%s) VENCEU!\n", carta1.nome_cidade);
            } else if (soma2 > soma1) {
                printf("\nResultado: Carta 2 (%s) VENCEU!\n", carta2.nome_cidade);
            } else {
                printf("\nResultado: EMPATE!\n");
            }
            break;
        default:
            printf("Opcao invalida...\n");
            break;
    }

    return 0;
}
