#include <stdio.h>
#include <stdlib.h>
#include "cripto.h"

int test_gera_chaves() {
	char *chave;

	chave = malloc (3 * sizeof(char));
	gera_chave(chave, 27);
	if (chave[0] != 'b') printf("Erro em gera_chave()\n");
	if (chave[1] != 'b') printf("Erro em gera_chave()\n");
	if (chave[2] != 'a') printf("Erro em gera_chave()\n");
	free(chave);
	return 0;
}

int main() {
	test_gera_chaves();
	return 0;
}
