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

void menu();
void inserirContato(Ficha *agenda);
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

void inserirContato() {
	char string[50];

	arq = fopen("arq.dat", "w");

	printf("Nome: ");
	fgets(string, sizeof(string), stdin); 	// recebe do usuario o nome do contato
	fprintf(arq, "%s\n", string); 			// salva no arquivo o nome do contato

	printf("Email: ");
	fgets(string, sizeof(string), stdin);
	fprintf(arq, "%s\n", string);

	fclose(arq);
}

void mostrarContatos(FILE *arq) {

	fopen("arq.dat", "r");


}