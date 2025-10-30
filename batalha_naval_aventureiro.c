#include <stdio.h>

#define TAM 10         // Tamanho fixo do tabuleiro (10x10)
#define AGUA 0         // Representa água
#define NAVIO 3        // Representa parte do navio
#define TAM_NAVIO 3    // Tamanho fixo dos navios (3 posições)

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se há sobreposição de navios
int verificaSobreposicao(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (tabuleiro[linha][coluna] == NAVIO)
        return 1; // Já existe navio nessa posição
    return 0;
}

// Função para posicionar navio horizontal
int posicionarHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM)
        return 0; // Fora dos limites

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (verificaSobreposicao(tabuleiro, linha, coluna + i))
            return 0; // Sobreposição detectada
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
    return 1;
}

// Função para posicionar navio vertical
int posicionarVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM)
        return 0; // Fora dos limites

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (verificaSobreposicao(tabuleiro, linha + i, coluna))
            return 0; // Sobreposição detectada
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
    return 1;
}

// Função para posicionar navio na diagonal principal (\)
int posicionarDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM || coluna + TAM_NAVIO > TAM)
        return 0; // Fora dos limites

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (verificaSobreposicao(tabuleiro, linha + i, coluna + i))
            return 0; // Sobreposição detectada
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
    return 1;
}

// Função para posicionar navio na diagonal secundária (/)
int posicionarDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM || coluna - (TAM_NAVIO - 1) < 0)
        return 0; // Fora dos limites

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (verificaSobreposicao(tabuleiro, linha + i, coluna - i))
            return 0; // Sobreposição detectada
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
    return 1;
}

// Função para exibir o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda: 0 = Água | 3 = Navio\n");
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posicionando quatro navios
    // Dois navios tradicionais (horizontal e vertical)
    if (!posicionarHorizontal(tabuleiro, 1, 2))
        printf("Erro ao posicionar navio horizontal.\n");

    if (!posicionarVertical(tabuleiro, 5, 7))
        printf("Erro ao posicionar navio vertical.\n");

    // Dois navios diagonais
    if (!posicionarDiagonalPrincipal(tabuleiro, 3, 1))
        printf("Erro ao posicionar navio diagonal principal.\n");

    if (!posicionarDiagonalSecundaria(tabuleiro, 0, 9))
        printf("Erro ao posicionar navio diagonal secundaria.\n");

    // Exibindo o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
