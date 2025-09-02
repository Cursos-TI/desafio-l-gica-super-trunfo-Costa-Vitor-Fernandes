#include <stdio.h>

struct Carta{

    char nome_cidade[50], estado[4], codigo_carta[4];

    float pib, area, densidade_populacional, pib_per_capita, super_poder;

    unsigned long int populacao;

    int n_pontos_turisticos;

};

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

    printf("Digite o PIB : ");

    scanf("%f", &carta->pib);

    printf("Digite a Area : ");

    scanf("%f", &carta->area);

    printf("Digite a Populacao: ");

    scanf("%lu", &carta->populacao);

    printf("Digite o numero de pontos turisticos: ");

    scanf("%d", &carta->n_pontos_turisticos);

    calcular_valores_dinamicos(carta);

    calcular_super_poder(carta);

}

void CompararTodosAtributos(struct Carta carta1, struct Carta carta2) {

    printf("\nComparacao de Cartas:\n");

    printf("Populacao: %s venceu (%d)\n", (carta1.populacao > carta2.populacao) ? "Carta 1" : "Carta 2", carta1.populacao > carta2.populacao);

    printf("Area: %s venceu (%d)\n", (carta1.area > carta2.area) ? "Carta 1" : "Carta 2", carta1.area > carta2.area);

    printf("PIB: %s venceu (%d)\n", (carta1.pib > carta2.pib) ? "Carta 1" : "Carta 2", carta1.pib > carta2.pib);

    printf("Pontos Turisticos: %s venceu (%d)\n", (carta1.n_pontos_turisticos > carta2.n_pontos_turisticos) ? "Carta 1" : "Carta 2", carta1.n_pontos_turisticos > carta2.n_pontos_turisticos);

    printf("Densidade Populacional: %s venceu (%d)\n", (carta1.densidade_populacional < carta2.densidade_populacional) ? "Carta 1" : "Carta 2", carta1.densidade_populacional < carta2.densidade_populacional);

    printf("PIB per Capita: %s venceu (%d)\n", (carta1.pib_per_capita > carta2.pib_per_capita) ? "Carta 1" : "Carta 2", carta1.pib_per_capita > carta2.pib_per_capita);

    printf("Super Poder: %s venceu (%d)\n", (carta1.super_poder > carta2.super_poder) ? "Carta 1" : "Carta 2", carta1.super_poder > carta2.super_poder);

}


void CompararUmAtributo(struct Carta carta1, struct Carta carta2, int atributo_escolhido){

    printf("\n--- Comparacao de Cartas ---\n");


    // Lógica para comparar o atributo escolhido usando switch-case

    switch (atributo_escolhido) {

        case 1:

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


        case 2:

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


        case 3:

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


        case 4:

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


        case 5:

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


        case 6:

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


        case 7:

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

            printf("Atributo escolhido não é valido. Por favor, insira valores numéricos válidos");

    }


}

int main() {

    // Cadastra e calcula valores dinamicos das cartas, inves de usar
    // Cadastro(&carta1, 1);Cadastro(&carta2, 2) e inserir manualmente

    struct Carta carta1 = {

         .nome_cidade = "São Paulo",

         .estado = "SP",

         .populacao = 12300000,

         .area = 1521.0,

         .pib = 763.8,

         .n_pontos_turisticos = 15

     };

    calcular_valores_dinamicos(&carta1);

    calcular_super_poder(&carta1);

    struct Carta carta2 = {

        .nome_cidade = "Rio de Janeiro",

        .estado = "RJ",

        .populacao = 6700000,

        .area = 1200.0,

        .pib = 350.0,

        .n_pontos_turisticos = 20

    };

    calcular_valores_dinamicos(&carta2);

    calcular_super_poder(&carta2);

    //Cadastra e calcula valores dinamicos das cartas


    enum Atributos {

      POPULACAO = 1,

      AREA = 2,

      PIB = 3,

      DENSIDADE_POPULACIONAL = 4,

      PIB_PER_CAPITA = 5,

      PONTOS_TURISTICOS = 6,

      SUPER_PODER = 7

    };

    // int atributo_escolhido = PONTOS_TURISTICOS;
    printf("----MENU DE COMPARAÇÃO-----\n\n");
       printf("POPULACAO = 1 \n");
       printf("AREA = 2 \n");
       printf("PIB = 3 \n");
       printf("DENSIDADE_POPULACIONAL = 4 \n");
       printf("PIB_PER_CAPITA = 5 \n");
       printf("PONTOS_TURISTICOS = 6 \n");
       printf("SUPER_PODER = 7 \n\n");
       printf("Escolha uma opcao numérica: ");

       // Você pode adicionar a lógica para ler a escolha do usuário aqui
       int atributo_escolhido;
       scanf("%d", &atributo_escolhido);

    printf("Voce escolheu a opcao: %d\n", atributo_escolhido);

    CompararUmAtributo(carta1,carta2,atributo_escolhido);

    return 0;

}
