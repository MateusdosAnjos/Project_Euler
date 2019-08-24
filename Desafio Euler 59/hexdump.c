/*                      hexdump.c
 *
 * Thales Paiva <thalespaiva em gmail>
 *  
 * Simples hexdump para ilustrar como ler um arquivo binário para um vetor.
 * Escreve no arquivo_saida e arquivo_entrada XOR FF, byte a byte.
 *
 * Para compilar:
 *  gcc -Wall -ansi -o hexdump hexdump.c
 *
 * Para rodar:
 *  ./hexdump <arquivo_entrada> <arquivo_saida>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100

typedef unsigned char byte_t;

long get_file_size(char file_name[]);
void read_file_to_array(char file_name[], byte_t file_bytes[], long file_size);
void write_array_to_file(char file_name[], byte_t file_bytes[], long file_size);

int main(int argc, char *argv[]) {
    long   file_size;
    byte_t    *file_bytes;
    char    input_file_name[MAX_FILE_NAME_SIZE];
    char    output_file_name[MAX_FILE_NAME_SIZE];
    int     i;

    if (argc != 3) {
        printf("Usage: %s <input_file_name> <output_file_name>\n", argv[0]);
        exit(1);
    }

    strcpy(input_file_name, argv[1]);
    strcpy(output_file_name, argv[2]);
    
    file_size = get_file_size(input_file_name);
    file_bytes = malloc(file_size*sizeof(*file_bytes));
    read_file_to_array(input_file_name, file_bytes, file_size);

    printf("    %02x ", file_bytes[0]);
    for (i = 1; i < file_size; i++) {
        if (i % 16 == 0)
            printf("\n    ");
        else if (i % 4 == 0)
            printf(" ");
        printf("%02X ", file_bytes[i]);
    }
    printf("\n");

    for (i = 0; i < file_size; i++)
        file_bytes[i] ^= 0xFF; 

    write_array_to_file(output_file_name, file_bytes, file_size);

    free (file_bytes);
    return 0;
}

long get_file_size(char file_name[]) {
    FILE *p_input_file;
    long file_size;

    p_input_file = fopen(file_name, "rb");
    if (p_input_file == NULL) {
        printf("Input file %s not found.\n", file_name);
        exit(1);
    }

    fseek(p_input_file, 0, SEEK_END);
    file_size = ftell(p_input_file);
    fseek(p_input_file, 0, SEEK_SET);
    fclose(p_input_file);

    return file_size;
}

void read_file_to_array(char file_name[], byte_t file_bytes[], long file_size) {
    FILE *p_input_file;

    p_input_file = fopen(file_name, "rb");
    if (p_input_file == NULL) {
        printf("Input file %s not found.\n", file_name);
        exit(1);
    }

    fread(file_bytes, sizeof(*file_bytes), file_size, p_input_file);
    fclose(p_input_file);
}

void write_array_to_file(char file_name[], byte_t file_bytes[], long file_size) {
    FILE *p_output_file;

    p_output_file = fopen(file_name, "wb");
    if (p_output_file == NULL) {
        printf("Output file %s not found.\n", file_name);
        exit(1);
    }

    fwrite(file_bytes, sizeof(*file_bytes), file_size, p_output_file);
    
    fclose(p_output_file);
}
