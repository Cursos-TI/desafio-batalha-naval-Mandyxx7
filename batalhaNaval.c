#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // Inicializa com água
        }
    }
}

// Função para verificar se é possível posicionar o navio
bool podePosicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linhaInicial, int colunaInicial, bool ehHorizontal) {
    if (ehHorizontal) {
        if (colunaInicial + TAMANHO_NAVIO > TAMANHO) return false; // Verifica se o navio cabe horizontalmente
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            if (tabuleiro[linhaInicial][colunaInicial + j] != 0) return false; // Verifica se há sobreposição
        }
    } else {
        if (linhaInicial + TAMANHO_NAVIO > TAMANHO) return false; // Verifica se o navio cabe verticalmente
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaInicial + i][colunaInicial] != 0) return false; // Verifica se há sobreposição
        }
    }
    return true;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linhaInicial, int colunaInicial, bool ehHorizontal) {
    if (ehHorizontal) {
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            tabuleiro[linhaInicial][colunaInicial + j] = 3; // Marca a posição do navio
        }
    } else {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaInicial + i][colunaInicial] = 3; // Marca a posição do navio
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe o tabuleiro
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 1;
    int linhaNavioVertical = 5;
    int colunaNavioVertical = 5;

    // Verifica se é possível posicionar o navio horizontal
    if (podePosicionarNavio(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal, true)) {
        posicionarNavio(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal, true);
    } else {
        printf("Não foi possível posicionar o navio horizontal.\n");
    }

    // Verifica se é possível posicionar o navio vertical
    if (podePosicionarNavio(tabuleiro, linhaNavioVertical, colunaNavioVertical, false)) {
        posicionarNavio(tabuleiro, linhaNavioVertical, colunaNavioVertical, false);
    } else {
        printf("Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}