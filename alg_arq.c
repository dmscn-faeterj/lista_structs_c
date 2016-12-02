// algoritmo para criar arquivo
// com informações para preencher
// os structs do outro exercicio

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 10

void preencheStruct(FILE *arq);
void randomString(char string[], int tam);
int randomNum(int aux);

int main() {
	FILE *arq;
	int i;

	srand(time(NULL));

	arq = fopen("arq.dat", "w+");

	fprintf(arq, "%d %d\n", TAM, 17); // 17 = numero de informacoes individuais do struct

	for(i=0; i<TAM; i++) {
		preencheStruct(arq);
	}

	fclose(arq);
	
}

void preencheStruct(FILE *arq) {
	int i;
	char string[50]; // 50 é a maior string que existe no struct
	
	for(i=0; i<3; i++) {
		randomString(string, 20);
		fprintf(arq, "%s\n", string);	// nome, email e rua
	}

	fprintf(arq, "%d\n", randomNum(9999)); 			// num

	randomString(string, 20);
	fprintf(arq, "%s\n", string); 					// complemeto

	randomString(string, 10);
	fprintf(arq, "%s\n", string);					// bairro

	
	fprintf(arq, "%d\n", randomNum(99999999)); 	// cep

	randomString(string, 20);
	fprintf(arq, "%s\n", string);					// cidade

	randomString(string, 2);
	fprintf(arq, "%s\n", string); 					// estado

	randomString(string, 10);
	fprintf(arq, "%s\n", string);					// pais

	fprintf(arq, "%d%d\n", randomNum(99999), randomNum(9999999));	// tel

	fprintf(arq, "%d\n", randomNum(99)); 			// dia
	fprintf(arq, "%d\n", randomNum(99)); 			// mes
	fprintf(arq, "%d\n", randomNum(99)); 			// ano

	randomString(string, 10);
	fprintf(arq, "%s\n", string); // obs
	
}

void randomString(char string[], int tam) {
	int aux;
	int i;

	for(i=0; i<tam; i++) {
		aux = 97 + rand() % (122-97);
		string[i] = (char) aux;
	}
}

int randomNum(int aux) {
	return rand() % aux;
}