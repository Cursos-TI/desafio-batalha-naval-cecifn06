#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro 10x10
#define NAVIO 3       // Valor que representa navio
#define TAM_NAVIO 3   // Tamanho fixo dos navios

int main() {

    int tabuleiro[TAM][TAM];

    // 1️⃣ Inicializa todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas definidas diretamente no código
    int linhaNavioH = 2, colunaNavioH = 1; // Horizontal
    int linhaNavioV = 5, colunaNavioV = 7; // Vertical

    // 2️⃣ Validação do navio horizontal dentro do tabuleiro
    if (colunaNavioH + TAM_NAVIO > TAM) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro!\n");
        return 1;
    }

    // 3️⃣ Validação do navio vertical dentro do tabuleiro
    if (linhaNavioV + TAM_NAVIO > TAM) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro!\n");
        return 1;
    }

    // 4️⃣ Verificação de sobreposição antes de posicionar
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaNavioH][colunaNavioH + i] == NAVIO ||
            tabuleiro[linhaNavioV + i][colunaNavioV] == NAVIO) {
            printf("Erro: Sobreposição de navios!\n");
            return 1;
        }
    }

    // 5️⃣ Posiciona navio horizontal no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaNavioH][colunaNavioH + i] = NAVIO;
        printf("Navio horizontal parte %d → posição (%d, %d)\n",
               i + 1, linhaNavioH, colunaNavioH + i);
    }

    // 6️⃣ Posiciona navio vertical no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaNavioV + i][colunaNavioV] = NAVIO;
        printf("Navio vertical parte %d → posição (%d, %d)\n",
               i + 1, linhaNavioV + i, colunaNavioV);
    }

    // 7️⃣ Exibe o tabuleiro completo no final
    printf("\n=== TABULEIRO BATALHA NAVAL — Nível Novato ===\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
