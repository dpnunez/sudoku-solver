#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void leSudoku(sudoku *game) {
  FILE *fp;
  char ch;
	bool primeiro = true;
  int
    gameNumbers[81] = {0}, 
    parsedNumber,
    gamePosition = 0;
	
  fp = fopen("game1.txt", "r");

  // Validaçao de leitura;
  if(fp == NULL) {
    printf("Error while opening the file");
    exit(1);
  }

	inicializaLista(game);
  // fgetc doc: http://www.cmaismais.com.br/referencia/cstdio/fgetc/
  while((ch = fgetc(fp)) != EOF) {
    // Verifica se o caractere lido é numério
    if(ch-'0' >= 0 && ch-'0' <= 9){
      parsedNumber = ch-'0';
			inserirCelula(game, parsedNumber, primeiro);
			primeiro = false;
    }
  }

  if (gamePosition < 81) {
    printf("Invalid game!");
    exit(1);
  }
}

void inserirCelula(sudoku *game, int valor, bool primeiro) {
	celula *novaCelula;
	novaCelula = (celula *)malloc(sizeof(celula));
	novaCelula->valor=valor;
	novaCelula->proximo=NULL;
	novaCelula->anterior=game->fim;

	game->fim->proximo=novaCelula;
	game->fim=novaCelula;
	game->tamanho++;

	if(primeiro)
		game->inicio=novaCelula;
}

void inicializaLista(sudoku *game) {
	game->fim=NULL;
	game->inicio=NULL;
	game->tamanho=0;
}