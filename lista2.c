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
	int dia;
	int mes;
	int ano;

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
void mostrarContatos(Ficha agenda[], int tam);
void salvarAgenda(FILE *arq, Ficha agenda[], int tam);

int main() {
	FILE *arq;
	Ficha agenda[100];
	char flag;
	int op, i = 0;

	do {

		menu();

		printf("Entre com a operação:\n");
		scanf("%d", &op);
		__fpurge(stdin);

		switch(op) {

			case 1: inserirContato(&agenda[i++]); // so ira alterar o valor de i depois de executar a funcao
				break;

			case 2: mostrarContatos(agenda, i);
				break;

			case 3: salvarAgenda(arq, agenda, i);s

			default: printf("Operação Inválida.\n");
				break;
		}

		printf("Deseja fazer outra operação? (s ou n)\n");
		scanf("%c", &flag);

	} while(flag == 's');

	return 0;
}

void menu() {

	printf("\n============ Agenda ============\n\n");
	printf("1- Inserir Contado\n");
	printf("2- Mostrar Todos Contatos\n");
	printf("3- Salvar Agenda\n");
	printf("\n================================\n\n");
}

void inserirContato(Ficha *contato) {
	int dia, mes, ano;

	__fpurge(stdin);

	printf("Nome: ");
	fgets((*contato).nome, sizeof((*contato).nome), stdin);
	__fpurge(stdin);

	printf("Email: ");
	fgets((*contato).email, sizeof((*contato).email), stdin);
	__fpurge(stdin);

	printf("Telefone: ");
	fgets((*contato).telefone, sizeof((*contato).telefone), stdin);
	__fpurge(stdin);

	printf("Data de Nascimento: ");
	scanf("%d/%d/%d", &dia, &mes, &ano);
	__fpurge(stdin);

	(*contato).nasc.dia = dia;
	(*contato).nasc.mes = mes;
	(*contato).nasc.ano = ano;

	printf("Oservacao:\n");
	fgets((*contato).obs, sizeof((*contato).obs), stdin);
	__fpurge(stdin);

	printf("\n");

	printf("ENDERECO\n");
	printf("Rua: ");
	fgets((*contato).endereco.rua, sizeof((*contato).endereco.rua), stdin);
	__fpurge(stdin);

	printf("Numero: ");
	fgets((*contato).endereco.num, sizeof((*contato).endereco.rua), stdin);
	__fpurge(stdin);

	printf("Complemento: ");
	fgets((*contato).endereco.comp, sizeof((*contato).endereco.comp), stdin);
	__fpurge(stdin);

	printf("Bairro: ");
	fgets((*contato).endereco.bairro, sizeof((*contato).endereco.bairro), stdin);
	__fpurge(stdin);

	printf("CEP: ");
	fgets((*contato).endereco.cep, sizeof((*contato).endereco.cep), stdin);
	__fpurge(stdin);

	printf("Cidade: ");
	fgets((*contato).endereco.cidade, sizeof((*contato).endereco.cidade), stdin);
	__fpurge(stdin);

	printf("Estado: ");
	fgets((*contato).endereco.estado, sizeof((*contato).endereco.estado), stdin);
	__fpurge(stdin);

	printf("Pais: ");
	fgets((*contato).endereco.pais, sizeof((*contato).endereco.pais), stdin);
	__fpurge(stdin);
}

void mostrarContatos(Ficha agenda[], int tam) {
	int i;

	for(i=0; i<tam; i++) {
		printf("============= %dº Contato =============\n", i+1);
		printf("\n");
		printf("----------------- Dados ---------------\n");
		printf("Nome: %s\n", agenda[i].nome);
		printf("Email: %s\n", agenda[i].email);
		printf("Telefone: %s\n", agenda[i].telefone);
		printf("Nascimento: %d/%d/%d\n", agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
		printf("Observacoes: %s\n", agenda[i].obs);


		printf("---------------- Endereco -------------\n");
		printf("ENDERECO\n");
		printf("Rua: %s\n", agenda[i].endereco.rua);
		printf("Nº: %s\n", agenda[i].endereco.num);
		printf("Complemento: %s\n", agenda[i].endereco.comp);
		printf("Bairro: %s\n", agenda[i].endereco.bairro);
		printf("CEP: %s\n", agenda[i].endereco.cep);
		printf("Cidade: %s\n", agenda[i].endereco.cidade);
		printf("Estado: %s\n", agenda[i].endereco.estado);
		printf("Pais: %s\n", agenda[i].endereco.pais);
	}
}

void salvarAgenda(FILE *arq, Ficha agenda[], int tam) {


}