#include <stdio.h>

#define TAM 10   // Tamanho fixo do tabuleiro (10x10)
#define NAVIO 3  // Valor que representa um navio no tabuleiro
#define AGUA 0   // Valor que representa água
#define TAM_NAVIO 3  // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 1️⃣ Inicializando o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2️⃣ Definindo as coordenadas iniciais dos navios
    // Navio horizontal
    int linhaH = 2; // Linha inicial do navio horizontal
    int colunaH = 4; // Coluna inicial do navio horizontal

    // Navio vertical
    int linhaV = 5; // Linha inicial do navio vertical
    int colunaV = 7; // Coluna inicial do navio vertical

    // 3️⃣ Validação: garantir que os navios cabem no tabuleiro
    if (colunaH + TAM_NAVIO > TAM) {
        printf("Erro: navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }
    if (linhaV + TAM_NAVIO > TAM) {
        printf("Erro: navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // 4️⃣ Posicionando o navio horizontal (valor 3)
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // 5️⃣ Posicionando o navio vertical (valor 3)
    for (i = 0; i < TAM_NAVIO; i++) {
        // Verifica se a posição já está ocupada
        if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
            printf("Erro: sobreposição de navios detectada!\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // 6️⃣ Exibindo o tabuleiro
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}
