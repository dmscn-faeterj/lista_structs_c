#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct {
	char rua[20];
	char num[5];
	char comp[20];
	char bairro[15];
	char cep[10];
	char cidade[15];
	char estado[15];
	char pais[15];

} Endereco;

typedef struct {
	int dia;
	int mes;
	int ano;

} Data;

typedef struct {
	char nome[30];
	char email[20];
	Endereco endereco;
	char telefone[15];
	Data nasc;
	char obs[50];

} Ficha;

void menu();
void inserirContato(Ficha *contato);
void mostrarContatos(Ficha agenda[], int tam);
void salvarAgenda(FILE *arq, Ficha agenda[], int tam);
void abrirAgenda(FILE *arq, Ficha agenda[], int *j);

int main() {
	FILE *arq;
	Ficha agenda[100];
	char flag;
	int op, i = 0;

	do {

		menu();

		printf("Entre com a operação: ");
		scanf("%d", &op);
		__fpurge(stdin);

		printf("\n");

		switch(op) {

			case 1: inserirContato(&agenda[i++]); // so ira alterar o valor de i depois de executar a funcao
				break;

			case 2: mostrarContatos(agenda, i);
				break;

			case 3: salvarAgenda(arq, agenda, i);
				break;

			case 4: abrirAgenda(arq, agenda, &i);
				break;

			default: printf("Operação Inválida.\n");
				break;
		}

		printf("\nDeseja fazer outra operação? (s ou n)\n");
		scanf("%c", &flag);
		printf("\n");

	} while(flag != 'n');

	return 0;
}

void menu() {

	printf("\n============ Agenda ============\n\n");
	printf("1- Inserir Contado\n");
	printf("2- Mostrar Todos Contatos\n");
	printf("3- Salvar Agenda\n");
	printf("4- Abrir Agenda Existente\n");
	printf("\n================================\n\n");
}

void inserirContato(Ficha *contato) {
	int dia, mes, ano;

	printf("=================================\n");
	printf("\n");
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

	printf("Rua: ");
	fgets((*contato).endereco.rua, sizeof((*contato).endereco.rua), stdin);
	__fpurge(stdin);

	printf("Numero: ");
	fgets((*contato).endereco.num, sizeof((*contato).endereco.num), stdin);
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
		printf("---------------- Dados ---------------\n");
		printf("Nome: %s", agenda[i].nome);
		printf("Email: %s\n", agenda[i].email);
		printf("Telefone: %s\n", agenda[i].telefone);
		printf("Nascimento: %d/%d/%d\n", agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
		printf("Observacoes: %s", agenda[i].obs);


		printf("--------------- Endereco -------------\n");
		printf("Rua: %s", agenda[i].endereco.rua);
		printf("Nº: %s\n", agenda[i].endereco.num);
		printf("Complemento: %s", agenda[i].endereco.comp);
		printf("Bairro: %s", agenda[i].endereco.bairro);
		printf("CEP: %s\n", agenda[i].endereco.cep);
		printf("Cidade: %s", agenda[i].endereco.cidade);
		printf("Estado: %s", agenda[i].endereco.estado);
		printf("Pais: %s", agenda[i].endereco.pais);
		printf("---------------------------------------\n");
	}
}

void salvarAgenda(FILE *arq, Ficha agenda[], int tam) {
	int i;
	char nomeArq[10];

	printf("Entre com o nome do arquivo: \n");
	fgets(nomeArq, sizeof(nomeArq), stdin);

	arq = fopen(nomeArq, "w");
	fprintf(arq, "%d\n", tam); // salva o numero de contatos salvos

	if(arq) {
		for(i=0; i<tam; i++) {

			fprintf(arq, "%s", agenda[i].nome);
			fprintf(arq, "%s", agenda[i].email);
			fprintf(arq, "%s", agenda[i].endereco.rua);
			fprintf(arq, "%s", agenda[i].endereco.num);
			fprintf(arq, "%s", agenda[i].endereco.comp);
			fprintf(arq, "%s", agenda[i].endereco.bairro);
			fprintf(arq, "%s", agenda[i].endereco.cep);
			fprintf(arq, "%s", agenda[i].endereco.cidade);
			fprintf(arq, "%s", agenda[i].endereco.estado);
			fprintf(arq, "%s", agenda[i].endereco.pais);
			fprintf(arq, "%s", agenda[i].telefone);
			fprintf(arq, "%d %d %d\n", agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
			fprintf(arq, "%s", agenda[i].obs);
		}

		printf("\n============================================\n");
		printf("\nAgenda salva com sucesso.\n");
		printf("\n============================================\n");
	}
	else {
		printf("ERRO. Nao foi possivel criar um arquivo com este nome.\n");
	}

	fclose(arq);
}

void abrirAgenda(FILE *arq, Ficha agenda[], int *j) {
	char nomeArq[10];
	int i;

	printf("Entre como nome do arquivo: ");
	fgets(nomeArq, sizeof(nomeArq), stdin);

	arq = fopen(nomeArq, "r");

	if(arq) {

		fscanf(arq, "%d\n", j);

		for(i=0; i<*j; i++) {
			fgets(agenda[i].nome, sizeof(agenda[i].nome), arq);
			fscanf(arq, "%s\n", agenda[i].email);
			fgets(agenda[i].endereco.rua, sizeof(agenda[i].endereco.rua), arq);
			fscanf(arq, "%s\n", agenda[i].endereco.num);
			fgets(agenda[i].endereco.comp, sizeof(agenda[i].endereco.comp), arq);
			fgets(agenda[i].endereco.bairro, sizeof(agenda[i].endereco.bairro), arq);
			fscanf(arq, "%s\n", agenda[i].endereco.cep);
			fgets(agenda[i].endereco.cidade, sizeof(agenda[i].endereco.cidade), arq);
			fgets(agenda[i].endereco.estado, sizeof(agenda[i].endereco.estado), arq);
			fgets(agenda[i].endereco.pais, sizeof(agenda[i].endereco.pais), arq);
			fscanf(arq, "%s\n", agenda[i].telefone);
			fscanf(arq, "%d %d %d\n", &agenda[i].nasc.dia, &agenda[i].nasc.mes, &agenda[i].nasc.ano);
			fgets(agenda[i].obs, sizeof(agenda[i].obs), arq);
		}


		printf("\n============================================\n");
		printf("\nAgenda recuperada com sucesso.\n");
		printf("\n============================================\n");
	}
	else {

		printf("Erro ao tentar abrir o arquivo.\n");
	}

	fclose(arq);
}