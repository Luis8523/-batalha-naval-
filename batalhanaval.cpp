#include <stdio.h>
#include <stdlib.h>


#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5
#define OCUPADO 3
#define AGUA 0
#define AFETADO 5

// Inicializa todas as posições do tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Verifica se o navio pode ser posicionado (horizontal, vertical, diagonal ↘ ou diagonal ↙)
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                   int linha, int coluna, int direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
        if (direcao == 0) c += i;
        else if (direcao == 1) l += i;
        else if (direcao == 2) { l += i; c += i; }
        else if (direcao == 3) { l += i; c -= i; }

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO || tabuleiro[l][c] != AGUA)
            return 0;
    }
    return 1;
}

// Posiciona o navio com valor OCUPADO
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                     int linha, int coluna, int direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;
        if (direcao == 0) c += i;
        else if (direcao == 1) l += i;
        else if (direcao == 2) { l += i; c += i; }
        else if (direcao == 3) { l += i; c -= i; }
        tabuleiro[l][c] = OCUPADO;
    }
}

// Cria matriz de habilidade para CONE (↧)
void construirCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int meio = TAMANHO_HABILIDADE / 2;
            matriz[i][j] = (j >= meio - i && j <= meio + i) ? 1 : 0;
        }
    }
}

// Cria matriz em forma de CRUZ
void construirCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz[i][j] = (i == meio || j == meio) ? 1 : 0;
        }
    }
}

// Cria matriz em forma de OCTAEDRO (losango)
void construirOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz[i][j] = (abs(i - meio) + abs(j - meio) <= meio) ? 1 : 0;
        }
    }
}

// Aplica a habilidade ao tabuleiro no ponto de origem
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int origemLinha, int origemColuna,
                       int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int offset = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (matriz[i][j] == 1) {
                int l = origemLinha - offset + i;
                int c = origemColuna - offset + j;
                if (l >= 0 && l < TAMANHO_TABULEIRO && c >= 0 && c < TAMANHO_TABULEIRO) {
                    if (tabuleiro[l][c] == AGUA) {
                        tabuleiro[l][c] = AFETADO; // Marca área atingida com valor 5
                    }
                }
            }
        }
    }
}

// Mostra o tabuleiro completo no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("    ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) printf("%2d ", j);
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d |", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) printf(" ~ ");
            else if (tabuleiro[i][j] == OCUPADO) printf(" # ");
            else if (tabuleiro[i][j] == AFETADO) printf(" * ");
            else printf(" ? ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posiciona 4 navios
    int navios[4][3] = {
        {1, 1, 0}, // Horizontal
        {4, 2, 1}, // Vertical
        {0, 0, 2}, // Diagonal ↘
        {2, 9, 3}  // Diagonal ↙
    };

    for (int i = 0; i < 4; i++) {
        int l = navios[i][0], c = navios[i][1], d = navios[i][2];
        if (podePosicionar(tabuleiro, l, c, d)) {
            posicionarNavio(tabuleiro, l, c, d);
        } else {
            printf("⚠️ Erro ao posicionar navio %d\n", i + 1);
        }
    }

    // Matrizes de habilidade
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, 2, 2, cone);       // Cone em (2,2)
    aplicarHabilidade(tabuleiro, 5, 5, cruz);       // Cruz em (5,5)
    aplicarHabilidade(tabuleiro, 7, 7, octaedro);   // Octaedro em (7,7)

    // Exibe resultado final
    printf("\n🌊 Tabuleiro com Habilidades:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}