#include <stdio.h>
#include <stdlib.h>
#include "cripto.h"

void realoc(char *vetor, int tamanho) {
	int i;
	char *novo_vetor;

	novo_vetor = malloc (tamanho * sizeof(char));

	for (i = 0; i < tamanho/2; i++) {
		novo_vetor[i] = vetor[i];
	}
	vetor = novo_vetor;
	return;
}

int main() {
	FILE *arquivo = NULL;
	char *chave, *str, *criptografado;
	char c;
	int i = 0, num_char = 0, tamanho_vetor = 1;

	arquivo = fopen("p059_cipher.txt","r");
	chave = malloc(3 * sizeof(char));
	str = malloc(3 * sizeof(char));
	criptografado = malloc(1 * sizeof(char));
	gera_chave(chave, 0);
	
	while ((c = fgetc(arquivo)) != EOF) {
		if (c != ',' && i < 3) {
			str[i] = c;
			i++;
		}
		else {
			if (num_char > tamanho_vetor) {
				tamanho_vetor *= 2;
				realoc(criptografado, 2 * num_char);
			}
			criptografado[num_char] = str_to_dec(str, i);
			num_char++;
			str[0] = 0;
			str[1] = 0;
			str[2] = 0;
			i = 0;
		}
	}
	for (i = 0; i < num_char; i++) {
		printf("%d\n", criptografado[i]);
	}
	free(chave);
	return 0;
}