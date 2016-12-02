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
void preencheStructs(Ficha *agenda, int tam);
void imprimeFicha(Ficha agenda, int tam);

int main() {
	Ficha agenda[TAM];

	preencheStructs(&agenda, TAM);
	imprimeFicha(agenda, TAM);

	return 0;
}

void preencheStructs(Ficha *agenda, int tam) {
	int i;

	for(i=0; i<tam; i++) {

		__fpurge(stdin);

		printf("Entre com seu nome:\n");
		fgets((*agenda).nome, sizeof((*agenda).nome), stdin);

		printf("Entre com seu email:\n");
		fgets((*agenda).email, sizeof((*agenda).email), stdin);

		// endereco
		printf("Rua:\n");
		fgets((*agenda).endereco.rua, sizeof((*agenda).endereco.rua), stdin);

		printf("Numero:\n");
		fgets((*agenda).endereco.num, sizeof((*agenda).endereco.num), stdin);

		printf("Complemento:\n");
		fgets((*agenda).endereco.comp, sizeof((*agenda).endereco.comp), stdin);

		printf("Bairro:\n");
		fgets((*agenda).endereco.bairro, sizeof((*agenda).endereco.bairro), stdin);

		printf("CEP:\n");
		fgets((*agenda).endereco.cep, sizeof((*agenda).endereco.cep), stdin);

		printf("Cidade:\n");
		fgets((*agenda).endereco.cidade, sizeof((*agenda).endereco.cidade), stdin);

		printf("Estado:\n");
		fgets((*agenda).endereco.estado, sizeof((*agenda).endereco.estado), stdin);

		printf("Pais:\n");
		fgets((*agenda).endereco.pais, sizeof((*agenda).endereco.pais), stdin);
		// fim endereco

		printf("Telefone:\n");
		fgets((*agenda).telefone, sizeof((*agenda).telefone), stdin);

		printf("Entre com seu aniversario:\n");
		fgets((*agenda).nasc.dia, sizeof((*agenda).nasc.dia), stdin);
		fgets((*agenda).nasc.mes, sizeof((*agenda).nasc.mes), stdin);
		fgets((*agenda).nasc.ano, sizeof((*agenda).nasc.dia), stdin);

		printf("Observações:\n");
		fgets((*agenda).obs, sizeof((*agenda).obs), stdin);

		printf("\n");

	}
}

void imprimeFicha(Ficha agenda, int tam) {
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
		printf("%s/%s/%s\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
		printf("%s\n", agenda[i].obs);
	}
}