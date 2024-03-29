#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
	char *str, *criptografado, *decriptografado;
	unsigned char *chave;
	char c;
	int i = 0, num_char = 0, tamanho_vetor = 1;

	arquivo = fopen("teste.txt","r");
	chave = malloc(3 * sizeof(unsigned char));
	str = malloc(3 * sizeof(char));
	criptografado = malloc(1 * sizeof(char));
	/*Le o arquivo e armazena em criptografado*/
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
			criptografado[num_char] = atoi(str);
			num_char++;
			str[0] = 0;
			str[1] = 0;
			str[2] = 0;
			i = 0;
		}
	}
	/*Encerra operacoes com arquivo*/
	fclose(arquivo);

	/*Tenta decriptografar para cada chave*/
	decriptografado = malloc (num_char * sizeof(char));
	/*Gera nova chave*/
	for (i = 0; i < (26*26*26); i++) {
		gera_chave(chave, i);
		/*Decriptografa e armazena em decriptografado*/
		for (i = 0; i < num_char; i++) {
			decriptografado[i] = chave[i%3]^criptografado[i];
		}
		/*Caso julgue como provável chave*/
		if(provavel_chave(decriptografado)) {
			printf("Soma = %d\n",calcula_soma(decriptografado));
			printf("%c%c%c\n", chave[0], chave[1], chave[2]);
			break;
		}
	}
	free(chave);
	free(decriptografado);
	return 0;
}