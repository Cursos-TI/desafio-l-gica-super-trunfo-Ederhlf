#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 100

typedef struct {
    char estado[2];
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    double area;
    double pib;
    int pontosTuristicos;
    double densidade;
    double pibPerCapita;
} Carta;

void cadastrarCarta(Carta cartas[], int *quantidade) {
    if (*quantidade >= MAX_CARTAS) {
        printf("Limite de cartas atingido.\n");
        return;
    }

    Carta novaCarta;
    printf("Estado (ex: A): ");
    scanf("%s", novaCarta.estado);
    printf("Código (ex: A01): ");
    scanf("%s", novaCarta.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", novaCarta.nomeCidade);
    printf("População: ");
    scanf("%d", &novaCarta.populacao);
    printf("Área (km²): ");
    scanf("%lf", &novaCarta.area);
    printf("PIB (em reais): ");
    scanf("%lf", &novaCarta.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &novaCarta.pontosTuristicos);

    novaCarta.densidade = novaCarta.populacao / novaCarta.area;
    novaCarta.pibPerCapita = novaCarta.pib / novaCarta.populacao;

    cartas[(*quantidade)++] = novaCarta;

    printf("\nCarta cadastrada com sucesso!\n\n");
}

void exibirCartas(const Carta cartas[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhuma carta cadastrada.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %s\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nomeCidade);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2lf km²\n", cartas[i].area);
        printf("PIB: R$ %.2lf\n", cartas[i].pib);
        printf("Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
        printf("Densidade Populacional: %.2lf habitantes/km²\n", cartas[i].densidade);
        printf("PIB per Capita: R$ %.2lf\n", cartas[i].pibPerCapita);
    }
}

void compararCartasCompletas(const Carta cartas[], int quantidade) {
    if (quantidade < 2) {
        printf("É necessário ao menos duas cartas para comparar.\n");
        return;
    }

    int c1, c2;
    printf("Escolha a primeira carta (1-%d): ", quantidade);
    scanf("%d", &c1);
    printf("Escolha a segunda carta (1-%d): ", quantidade);
    scanf("%d", &c2);

    if (c1 < 1 || c1 > quantidade || c2 < 1 || c2 > quantidade) {
        printf("Cartas inválidas.\n");
        return;
    }

    c1--; c2--;
    double superPoder1 = cartas[c1].populacao + cartas[c1].pib + cartas[c1].pontosTuristicos;
    double superPoder2 = cartas[c2].populacao + cartas[c2].pib + cartas[c2].pontosTuristicos;

    printf("\nSuper Poder da Carta %d: %.2lf\n", c1 + 1, superPoder1);
    printf("Super Poder da Carta %d: %.2lf\n", c2 + 1, superPoder2);

    if (superPoder1 > superPoder2) {
        printf("Carta %d vence!\n", c1 + 1);
    } else if (superPoder2 > superPoder1) {
        printf("Carta %d vence!\n", c2 + 1);
    } else {
        printf("Empate entre as cartas!\n");
    }
}

void compararAtributos(const Carta cartas[], int quantidade) {
    if (quantidade < 2) {
        printf("É necessário ao menos duas cartas para comparar.\n");
        return;
    }

    int c1, c2, atributo1, atributo2;
    printf("Escolha a primeira carta (1-%d): ", quantidade);
    scanf("%d", &c1);
    printf("Escolha a segunda carta (1-%d): ", quantidade);
    scanf("%d", &c2);

    if (c1 < 1 || c1 > quantidade || c2 < 1 || c2 > quantidade) {
        printf("Cartas inválidas.\n");
        return;
    }

    printf("Escolha o primeiro atributo (1-População, 2-Área, 3-PIB, 4-Pontos Turísticos, 5-Densidade): ");
    scanf("%d", &atributo1);
    printf("Escolha o segundo atributo (1-População, 2-Área, 3-PIB, 4-Pontos Turísticos, 5-Densidade): ");
    scanf("%d", &atributo2);

    c1--; c2--;

    double valor1 = (atributo1 == 1 ? cartas[c1].populacao : 
                     atributo1 == 2 ? cartas[c1].area : 
                     atributo1 == 3 ? cartas[c1].pib : 
                     atributo1 == 4 ? cartas[c1].pontosTuristicos : 
                     cartas[c1].densidade);

    double valor2 = (atributo1 == 1 ? cartas[c2].populacao : 
                     atributo1 == 2 ? cartas[c2].area : 
                     atributo1 == 3 ? cartas[c2].pib : 
                     atributo1 == 4 ? cartas[c2].pontosTuristicos : 
                     cartas[c2].densidade);

    printf("\nResultado do atributo 1: ");
    if (valor1 > valor2)
        printf("Carta %d vence!\n", c1 + 1);
    else if (valor2 > valor1)
        printf("Carta %d vence!\n", c2 + 1);
    else
        printf("Empate no atributo 1!\n");
}

int main() {
    Carta cartas[MAX_CARTAS];
    int quantidade = 0, opcao;

    do {
        printf("\nMenu:\n1 - Cadastrar Carta\n2 - Exibir Cartas\n3 - Comparar Cartas Completas\n4 - Comparar Atributos\n0 - Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCarta(cartas, &quantidade);
                break;
            case 2:
                exibirCartas(cartas, quantidade);
                break;
            case 3:
                compararCartasCompletas(cartas, quantidade);
                break;
            case 4:
                compararAtributos(cartas, quantidade);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
