#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int potencia(int x, int y) {
	int i, resultado = 1;


	for (i = 0; i < y; i++) {
		resultado *= x;
	}
	return resultado;
}

void gera_chave(unsigned char *chave, int num_chave) {
	int i;
	
	if (chave == NULL) return;
	for (i = 0; i < 3; i++) {
		chave[i] = 'a';
		chave[i] += (num_chave/potencia(26, i)) % 26;
	}
	return;
}

/*Falta implementar a heuristica para julgar uma chave*/
int provavel_chave(char *decriptografado) {
	return 0;
}

/*Somar todos os decimais da solucao*/
int calcula_soma(char *decriptografado) {
	return 0;
}