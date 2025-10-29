#include <stdio.h>
#include <string.h>

// Estrutura representando uma carta de país
typedef struct {
    char nome[30];
    float area;       // em km²
    float pib;        // em trilhões
    float populacao;  // em milhões
    float densidade;  // hab/km²
} Carta;

// Função para exibir os atributos disponíveis
void mostrarAtributos() {
    printf("\nAtributos disponíveis:\n");
    printf("1 - Área (maior vence)\n");
    printf("2 - PIB (maior vence)\n");
    printf("3 - População (maior vence)\n");
    printf("4 - Densidade Demográfica (menor vence)\n");
}

// Função para comparar os dois países com base nos atributos escolhidos
void compararCartas(Carta c1, Carta c2, int attr1, int attr2) {
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;
    float soma_c1 = 0, soma_c2 = 0;

    // --- Primeiro atributo ---
    switch (attr1) {
        case 1: valor1_c1 = c1.area; valor1_c2 = c2.area; break;
        case 2: valor1_c1 = c1.pib; valor1_c2 = c2.pib; break;
        case 3: valor1_c1 = c1.populacao; valor1_c2 = c2.populacao; break;
        case 4: valor1_c1 = c1.densidade; valor1_c2 = c2.densidade; break;
        default: printf("Erro no atributo 1!\n"); return;
    }

    // --- Segundo atributo ---
    switch (attr2) {
        case 1: valor2_c1 = c1.area; valor2_c2 = c2.area; break;
        case 2: valor2_c1 = c1.pib; valor2_c2 = c2.pib; break;
        case 3: valor2_c1 = c1.populacao; valor2_c2 = c2.populacao; break;
        case 4: valor2_c1 = c1.densidade; valor2_c2 = c2.densidade; break;
        default: printf("Erro no atributo 2!\n"); return;
    }

    // --- Exibir Comparação ---
    printf("\n===== RESULTADOS DA COMPARAÇÃO =====\n");
    printf("Comparando %s x %s\n\n", c1.nome, c2.nome);

    printf("Atributo 1: ");
    switch (attr1) {
        case 1: printf("Área\n"); break;
        case 2: printf("PIB\n"); break;
        case 3: printf("População\n"); break;
        case 4: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", c1.nome, valor1_c1, c2.nome, valor1_c2);

    printf("\nAtributo 2: ");
    switch (attr2) {
        case 1: printf("Área\n"); break;
        case 2: printf("PIB\n"); break;
        case 3: printf("População\n"); break;
        case 4: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", c1.nome, valor2_c1, c2.nome, valor2_c2);

    // --- Soma dos atributos ---
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f | %s: %.2f\n", c1.nome, soma_c1, c2.nome, soma_c2);

    // --- Regras especiais ---
    // Densidade é invertida (menor vence), mas soma é direta (sem inversão)
    // Resultado final
    if (soma_c1 > soma_c2)
        printf("\nVencedor: %s 🏆\n", c1.nome);
    else if (soma_c2 > soma_c1)
        printf("\nVencedor: %s 🏆\n", c2.nome);
    else
        printf("\nEmpate!\n");
}

int main() {
    Carta carta1 = {"Brasil", 8515767, 2.1, 213, 25.04};
    Carta carta2 = {"Canadá", 9976140, 1.7, 38, 3.81};

    int opcao1, opcao2;

    printf("===== JOGO DE CARTAS - PAISES =====\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n", carta2.nome);

    // --- Escolha do primeiro atributo ---
    mostrarAtributos();
    printf("\nEscolha o primeiro atributo (1-4): ");
    scanf("%d", &opcao1);

    switch (opcao1) {
        case 1: printf("Você escolheu: Área\n"); break;
        case 2: printf("Você escolheu: PIB\n"); break;
        case 3: printf("Você escolheu: População\n"); break;
        case 4: printf("Você escolheu: Densidade Demográfica\n"); break;
        default:
            printf("Opção inválida! Encerrando o jogo.\n");
            return 0;
    }

    // --- Menu dinâmico: remove o atributo já escolhido ---
    printf("\nAgora escolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 4; i++) {
        if (i == opcao1)
            continue;

        switch (i) {
            case 1: printf("1 - Área\n"); break;
            case 2: printf("2 - PIB\n"); break;
            case 3: printf("3 - População\n"); break;
            case 4: printf("4 - Densidade Demográfica\n"); break;
        }
    }

    printf("\nEscolha o segundo atributo: ");
    scanf("%d", &opcao2);

    if (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 4) {
        printf("Opção inválida! Você deve escolher um atributo diferente.\n");
        return 0;
    }

    // --- Realiza a comparação e exibe o resultado ---
    compararCartas(carta1, carta2, opcao1, opcao2);

    return 0;
}
