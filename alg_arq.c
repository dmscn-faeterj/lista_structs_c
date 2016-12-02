// algoritmo para criar arquivo
// com informações para preencher
// os structs do outro exercicio

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <time.h>

#define TAM 100;

void preencheStruct(FILE *arq);
void randomString(char string[], int tam);

int main() {
	FILE *arq;
	int i;

	arq = fopen("arq.dat", "w+");

	fprintf(arq, "%d %d\n", TAM, 17); // 17 = numero de informacoes individuais do struct

	for(i=0; i<TAM; i++) {
		preencheStruct(arq);
	}

}

void preencheStruct(FILE *arq) {
	int i;
	string[50]; // 50 é a maior string que existe no struct
	
	for(i=0; i<3; i++) {
		fprintf(arq, "%s\n", randomString(string, 20));	// nome, email e rua
	}

	fprintf(arq, "%d\n", randomNum(9999)); 			// num
	fprintf(arq, "%s\n", randomString(string, 20)); // complemeto
	fprintf(arq, "%s\n", randomString(string, 10));	// bairro
	fprintf(arq, "%d\n", randomNum(99999999)); 		// cep
	fprintf(arq, "%s\n", randomString(string, 20));	// cidade
	fprintf(arq, "%s\n", randomString(string, 2)); 	// estado
	fprintf(arq, "%s\n", randomString(string, 10));	// pais

	fprintf(arq, "%d\n", randomNum(999999999999));	// tel

	fprintf(arq, "%d\n", randomNum(99)); 			// dia
	fprintf(arq, "%d\n", randomNum(99)); 			// mes
	fprintf(arq, "%d\n", randomNum(99)); 			// ano

	fprintf(arq, "%s\n", randomString(string, 50)); // obs
	
}

void randomString(char string[], int tam) {
	int aux;
	srand(time(NULL));

	for(i=0; i<tam; i++) {
		aux = 97 + rand() % (122-97);
		string[i] = (char) aux;
	}
}

int randomNum(int aux) {
	srand(time(NULL));
	return rand() % aux;
}