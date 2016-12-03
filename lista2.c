#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

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
	int dia[2];
	int mes[2];
	int ano[4];

} Data;

typedef struct {
	char nome[20];
	char email[20];
	Endereco endereco;
	char telefone[12];
	Data nasc;
	char obs[50];

} Ficha;

void menu();
void inserirContato(Ficha *contato);
void mostrarContatos(FILE *arq);

int main() {
	FILE *arq;
	Ficha agenda[100];
	char ok;
	int op;

	do {

		menu();

		printf("Entre com a operação:\n");
		scanf("%d", &op);

		switch(op) {

			case 1: inserirContato(arq);
				break;

			case 2: mostrarContatos(arq);
				break;

			default: printf("Operação Inválida.\n");
				break;
		}

	} while(ok == 'n');

}

void menu() {

	printf("\n============ Agenda ============\n\n");
	printf("1- Inserir Contado\n");
	printf("2- Mostrar Todos Contatos\n");
	printf("\n================================\n\n");
}

void inserirContato(Ficha *contato) {

	printf("Nome: ");
	fgets((*contato).nome, sizeof((*contato).nome), stdin);

	printf("Email: ");
	fgets((*contato).email, sizeof((*contato).email), stdin);

	printf("\n");

	printf("ENDERECO\n");
	printf("Rua: ");
	fgets((*contato).endereco.rua, sizeof((*contato).endereco.rua), stdin);

	printf("Numero: ");
	fgets((*contato).endereco.num, sizeof((*contato).endereco.rua), stdin);

	printf("Complemento: ");
	fgets((*contato).endereco.comp, sizeof((*contato).endereco.comp), stdin);

	printf("Bairro: ");
	fgets((*contato).endereco.bairro, sizeof((*contato).endereco.bairro), stdin);

	printf("CEP: ");
	fgets((*contato).endereco.cep, sizeof((*contato).endereco.cep), stdin);

	printf("Cidade: ");
	fgets((*contato).endereco.cidade, sizeof((*contato).endereco.cidade), stdin);

	printf("Estado: ");
	fgets((*contato).endereco.estado, sizeof((*contato).endereco.estado), stdin);

	printf("Pais: ");
	fgets((*contato).endereco.pais, sizeof((*contato).endereco.pais), stdin);

	printf("\n");

	printf("Telefone: ");
	fgets((*contato).telefone, sizeof((*contato).telefone), stdin);

	printf("Data de Nascimento: ");
	scanf("%d/%d/%d", contato.nasc.dia, contato.nasc.mes, contato.nasc.ano);

	printf("Oservacao:\n");
	fgets((*contato).obs, sizeof((*contato).obs), stdin);
}

void mostrarContatos() {

}