#include <stdio.h>
#include <stdlib.h> // Para usar abs()
#define TAM 10
#define NAVIO 3
#define TAM_NAVIO 3

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

    // 4️⃣ Validação diagonal ↘
    if (linhaDiag1 + TAM_NAVIO > TAM || colunaDiag1 + TAM_NAVIO > TAM) {
        printf("Erro: Navio diagonal ↘ fora dos limites!\n");
        return 1;
    }

    // 5️⃣ Validação diagonal ↙
    if (linhaDiag2 + TAM_NAVIO > TAM || colunaDiag2 - (TAM_NAVIO - 1) < 0) {
        printf("Erro: Navio diagonal ↙ fora dos limites!\n");
        return 1;
    }

    // 6️⃣ Verifica sobreposição
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
    }

    // 8️⃣ Posiciona navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaNavioV + i][colunaNavioV] = NAVIO;
    }

    // 9️⃣ Posiciona navio diagonal ↘
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaDiag1 + i][colunaDiag1 + i] = NAVIO;
    }

    // 🔟 Posiciona navio diagonal ↙
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaDiag2 + i][colunaDiag2 - i] = NAVIO;
    }

    // 🧩 Exibe tabuleiro Nível Aventureiro
    printf("\n=== TABULEIRO BATALHA NAVAL — Nível Aventureiro ===\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // ===================================================
    // 🏆 NÍVEL MESTRE — HABILIDADES ESPECIAIS
    // ===================================================
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Habilidade CONE
    for (int i = 0; i < 5; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            if (j >= 0 && j < 5) {
                cone[i][j] = 1;
            }
        }
    }

    // Habilidade CRUZ
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1;
        cruz[i][2] = 1;
    }

    // Habilidade OCTAEDRO
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // 📌 Exibir matrizes Mestre
    printf("\n=== HABILIDADE: CONE ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }

    printf("\n=== HABILIDADE: CRUZ ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }

    printf("\n=== HABILIDADE: OCTAEDRO ===\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
