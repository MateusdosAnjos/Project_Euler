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

unsigned int str_to_dec(char *str, int i) {
	return atoi(str);
}