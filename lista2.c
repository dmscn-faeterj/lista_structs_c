#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define TAM 1

typedef struct {
	char rua[20];
	char num[4];
	char comp[20];
	char bairro[10];
	char cep[8];
	char cidade[10];
	char estado[2];
	char pais[10];

} Endereco;

typedef struct {
	char dia[2];
	char mes[2];
	char ano[4];

} Data;

typedef struct {
	char nome[20];
	char email[20];
	Endereco endereco;
	char telefone[12];
	Data nasc;
	char obs[50];

} Ficha;

// preenche a agenda
void lerArq(FILE *arq, Ficha agenda[], int tam);
void imprimeFicha(Ficha agenda[], int tam);

int main() {
	Ficha agenda[TAM];
	FILE *arq;

	arq = fopen("arq.dat", "r");

	
	imprimeFicha(agenda, TAM);

	return 0;
}

void lerArq(FILE *arq, Ficha agenda[], int tam) {
	int i, q, linhas;

	fscanf(arq, "%d %d\n", &q, &linhas);

	for(i=0; i<q; i++) {
		fscanf(arq, "%s\n", agenda[i].nome);
		fscanf(arq, "%s\n", agenda[i].email);

		fscanf(arq, "%s\n", agenda[i].endereco.rua);
		fscanf(arq, "%s\n", agenda[i].endereco.num);
		fscanf(arq, "%s\n", agenda[i].endereco.comp);
		fscanf(arq, "%s\n", agenda[i].endereco.bairro);
		fscanf(arq, "%s\n", agenda[i].endereco.cep);
		fscanf(arq, "%s\n", agenda[i].endereco.cidade);
		fscanf(arq, "%s\n", agenda[i].endereco.estado);
		fscanf(arq, "%s\n", agenda[i].endereco.pais);

		fscanf(arq, "%s\n", agenda[i].telefone);

		fscanf(arq, "%s\n", agenda[i].nasc.dia);
		fscanf(arq, "%s\n", agenda[i].nasc.mes);
		fscanf(arq, "%s\n", agenda[i].nasc.ano);

		fscanf(arq, "%s\n", agenda[i].obs);

	}
}

void imprimeFicha(Ficha agenda[], int tam) {
	int i;

	for(i=0; i<tam; i++) {

		printf("\n");

		printf("%s\n", agenda[i].nome);
		printf("%s\n", agenda[i].email);
		printf("%s\n", agenda[i].endereco.rua);
		printf("%s\n", agenda[i].endereco.num);
		printf("%s\n", agenda[i].endereco.comp);
		printf("%s\n", agenda[i].endereco.bairro);
		printf("%s\n", agenda[i].endereco.cep);
		printf("%s\n", agenda[i].endereco.cidade);
		printf("%s\n", agenda[i].endereco.estado);
		printf("%s\n", agenda[i].endereco.pais);
		printf("%s\n", agenda[i].telefone);
		printf("%s/%s/%s\n", agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
		printf("%s\n", agenda[i].obs);
	}
}