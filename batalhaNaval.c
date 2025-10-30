#include <stdio.h>

#define TAM 10       // Tamanho do tabuleiro
#define AGUA 0       // Representa água
#define NAVIO 3      // Representa navio
#define HABILIDADE 5 // Representa área afetada por habilidade
#define TAM_HAB 5    // Tamanho das matrizes de habilidade (5x5)
#define TAM_NAVIO 3  // Tamanho fixo dos navios

//--------------------------------------------------------------
// Função: Inicializa o tabuleiro com água
//--------------------------------------------------------------
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

//--------------------------------------------------------------
// Função: Exibe o tabuleiro formatado
//--------------------------------------------------------------
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda: 0 = Água | 3 = Navio | 5 = Área de Habilidade\n");
}

//--------------------------------------------------------------
// Função: Posiciona um navio horizontal no tabuleiro
//--------------------------------------------------------------
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (coluna + i < TAM)
            tabuleiro[linha][coluna + i] = NAVIO;
    }
}

//--------------------------------------------------------------
// Função: Posiciona um navio vertical no tabuleiro
//--------------------------------------------------------------
void posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linha + i < TAM)
            tabuleiro[linha + i][coluna] = NAVIO;
    }
}

//--------------------------------------------------------------
// Função: Cria matriz de habilidade em forma de CONE (ponta em cima)
//--------------------------------------------------------------
void criarCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Condicional que define a forma do cone:
            // À medida que desce (i aumenta), a área do cone se expande
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

//--------------------------------------------------------------
// Função: Cria matriz de habilidade em forma de CRUZ
//--------------------------------------------------------------
void criarCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

//--------------------------------------------------------------
// Função: Cria matriz de habilidade em forma de OCTAEDRO (losango)
//--------------------------------------------------------------
void criarOctaedro(int octaedro[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Fórmula de distância de Manhattan: forma um losango
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

//--------------------------------------------------------------
// Função: Sobrepõe uma habilidade no tabuleiro
//--------------------------------------------------------------
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha - centro + i;
                int colunaTab = origemColuna - centro + j;

                // Garante que a habilidade não saia dos limites
                if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                    // Marca no tabuleiro sem sobrescrever navios
                    if (tabuleiro[linhaTab][colunaTab] != NAVIO)
                        tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

//--------------------------------------------------------------
// Função principal
//--------------------------------------------------------------
int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posicionando navios (mesmo esquema do nível anterior)
    posicionarNavioHorizontal(tabuleiro, 2, 2);
    posicionarNavioVertical(tabuleiro, 6, 7);

    // Matrizes das habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // Criando as formas
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Definindo origens no tabuleiro (centro aproximado de cada habilidade)
    aplicarHabilidade(tabuleiro, cone, 1, 5);
    aplicarHabilidade(tabuleiro, cruz, 5, 3);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);

    // Exibindo resultado
    exibirTabuleiro(tabuleiro);

    printf("\n=== MATRIZES DE HABILIDADE ===\n");

    printf("\nCone:\n");
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++)
            printf("%d ", cone[i][j]);
        printf("\n");
    }

    printf("\nCruz:\n");
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++)
            printf("%d ", cruz[i][j]);
        printf("\n");
    }

    printf("\nOctaedro:\n");
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++)
            printf("%d ", octaedro[i][j]);
        printf("\n");
    }

    return 0;
}
