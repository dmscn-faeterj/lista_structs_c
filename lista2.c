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
void preencheStructs(Ficha agenda[], int tam);
void imprimeFicha(Ficha agenda[], int tam);

int main() {
	Ficha agenda[TAM];

	preencheStructs(agenda, TAM);
	imprimeFicha(agenda, TAM);

	return 0;
}

void preencheStructs(Ficha agenda[], int tam) {
	int i;

	for(i=0; i<tam; i++) {

		__fpurge(stdin);
		
		printf("Entre com seu nome:\n");
		fgets(agenda[i].nome, sizeof(agenda[i].nome), stdin);
		__fpurge(stdin);

		printf("Entre com seu email:\n");
		fgets(agenda[i].email, sizeof(agenda[i].email), stdin);
		__fpurge(stdin);

		// endereco
		printf("Rua:\n");
		fgets(agenda[i].endereco.rua, sizeof(agenda[i].endereco.rua), stdin);
		__fpurge(stdin);

		printf("Numero:\n");
		fgets(agenda[i].endereco.num, sizeof(agenda[i].endereco.num), stdin);
		__fpurge(stdin);

		printf("Complemento:\n");
		fgets(agenda[i].endereco.comp, sizeof(agenda[i].endereco.comp), stdin);
		__fpurge(stdin);

		printf("Bairro:\n");
		fgets(agenda[i].endereco.bairro, sizeof(agenda[i].endereco.bairro), stdin);
		__fpurge(stdin);

		printf("CEP:\n");
		fgets(agenda[i].endereco.cep, sizeof(agenda[i].endereco.cep), stdin);
		__fpurge(stdin);

		printf("Cidade:\n");
		fgets(agenda[i].endereco.cidade, sizeof(agenda[i].endereco.cidade), stdin);
		__fpurge(stdin);

		printf("Estado:\n");
		fgets(agenda[i].endereco.estado, sizeof(agenda[i].endereco.estado), stdin);
		__fpurge(stdin);

		printf("Pais:\n");
		fgets(agenda[i].endereco.pais, sizeof(agenda[i].endereco.pais), stdin);
		__fpurge(stdin);
		// fim endereco

		printf("Telefone:\n");
		fgets(agenda[i].telefone, sizeof(agenda[i].telefone), stdin);
		__fpurge(stdin);

		printf("Entre com seu aniversario:\n");
		fgets(agenda[i].nasc.dia, sizeof(agenda[i].nasc.dia), stdin);
		fgets(agenda[i].nasc.mes, sizeof(agenda[i].nasc.mes), stdin);
		fgets(agenda[i].nasc.ano, sizeof(agenda[i].nasc.dia), stdin);
		__fpurge(stdin);

		printf("Observações:\n");
		fgets(agenda[i].obs, sizeof(agenda[i].obs), stdin);
		__fpurge(stdin);

		printf("\n");

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