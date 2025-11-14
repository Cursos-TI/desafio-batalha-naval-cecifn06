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

    // Navios diagonais
    int linhaDiag1 = 1, colunaDiag1 = 1; // Diagonal principal (↘)
    int linhaDiag2 = 1, colunaDiag2 = 8; // Diagonal inversa   (↙)

    // 2️⃣ Validação dos limites (horizontal)
    if (colunaNavioH + TAM_NAVIO > TAM) {
        printf("Erro: Navio horizontal fora dos limites!\n");
        return 1;
    }

    // 3️⃣ Validação dos limites (vertical)
    if (linhaNavioV + TAM_NAVIO > TAM) {
        printf("Erro: Navio vertical fora dos limites!\n");
        return 1;
    }

    // 4️⃣ Validação dos limites (diagonal principal)
    if (linhaDiag1 + TAM_NAVIO > TAM || colunaDiag1 + TAM_NAVIO > TAM) {
        printf("Erro: Navio diagonal principal fora dos limites!\n");
        return 1;
    }

    // 5️⃣ Validação dos limites (diagonal inversa)
    if (linhaDiag2 + TAM_NAVIO > TAM || colunaDiag2 - (TAM_NAVIO - 1) < 0) {
        printf("Erro: Navio diagonal inversa fora dos limites!\n");
        return 1;
    }

    // 6️⃣ Verifica sobreposição para todos os navios
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaNavioH][colunaNavioH + i] == NAVIO ||
            tabuleiro[linhaNavioV + i][colunaNavioV] == NAVIO ||
            tabuleiro[linhaDiag1 + i][colunaDiag1 + i] == NAVIO ||
            tabuleiro[linhaDiag2 + i][colunaDiag2 - i] == NAVIO) {
            printf("Erro: Sobreposição de navios encontrada!\n");
            return 1;
        }
    }

    // 7️⃣ Posiciona navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaNavioH][colunaNavioH + i] = NAVIO;
        printf("Navio horizontal parte %d → posição (%d, %d)\n",
               i + 1, linhaNavioH, colunaNavioH + i);
    }

    // 8️⃣ Posiciona navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaNavioV + i][colunaNavioV] = NAVIO;
        printf("Navio vertical parte %d → posição (%d, %d)\n",
               i + 1, linhaNavioV + i, colunaNavioV);
    }

    // 9️⃣ Posiciona navio diagonal ↘ (principal)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaDiag1 + i][colunaDiag1 + i] = NAVIO;
        printf("Navio diagonal ↘ parte %d → posição (%d, %d)\n",
               i + 1, linhaDiag1 + i, colunaDiag1 + i);
    }

    // 🔟 Posiciona navio diagonal ↙ (inversa)
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaDiag2 + i][colunaDiag2 - i] = NAVIO;
        printf("Navio diagonal ↙ parte %d → posição (%d, %d)\n",
               i + 1, linhaDiag2 + i, colunaDiag2 - i);
    }

    // 🔟 Exibe o tabuleiro completo
    printf("\n=== TABULEIRO BATALHA NAVAL — Nível Aventureiro ===\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
