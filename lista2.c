#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

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
void inserirContato(Ficha agenda[], int tam);
void removerContato(Ficha agenda[], int tam);
void mostrarContatos(Ficha agenda[], int tam);
void salvarAgenda(FILE *arq, Ficha agenda[], int tam);
void abrirAgenda(FILE *arq, Ficha agenda[], int *j);
void strtoupper(char s[]);
int buscaPosicao(Ficha agenda[], int tam, char s[]);
void reposicionarAgenda(Ficha agenda[], int tam, int i);
void buscaContato(Ficha agenda[], int tam);
void imprimeContato(Ficha contato);
void imprimeContatoRed(Ficha contato);
void buscaNome(Ficha agenda[], int tam, char nome[]);
void buscaMes(Ficha agenda[], int tam, int mes);
void buscaDiaMes(Ficha agenda[], int tam, int dia, int mes);


int main() {
	FILE *arq;
	Ficha agenda[100];
	char flag;
	int op, i = 0, lop = 0;

	do {

		menu();

		printf("Entre com a operação: ");
		scanf("%d", &op);
		__fpurge(stdin);

		printf("\n");

		switch(op) {

			case 1: inserirContato(agenda, i++); // so ira alterar o valor de i depois de executar a funcao
				lop = 1;
				break;

			case 2: removerContato(agenda, i--);
				lop = 1;
				break;

			case 3: mostrarContatos(agenda, i);
				break;

			case 4: buscaContato(agenda, i);
				break;

			case 5: salvarAgenda(arq, agenda, i);
				lop = 0;
				break;

			case 6: abrirAgenda(arq, agenda, &i);
				break;

			default: printf("Operação Inválida.\n");
				break;
		}

		printf("\nDeseja fazer outra operação? (s ou n)\n");
		scanf("%c", &flag);
		printf("\n");

	} while(flag != 'n');

	if(lop == 1) {
		printf("Deseja sair sem salvar? (s ou n)\n");
		scanf("%c", &flag);
		__fpurge(stdin);

		if(flag == s) {
			salvarAgenda(arq, agenda, i);
		}
	}

	return 0;
}

void menu() {

	printf("\n============ Agenda ============\n\n");
	printf("1- Inserir Contado\n");
	printf("2- Remover Contato\n");
	printf("3- Mostrar Todos Contatos\n");
	printf("4- Buscar Contato\n");
	printf("5- Salvar Agenda\n");
	printf("6- Abrir Agenda Existente\n");
	printf("\n================================\n\n");
}

void inserirContato(Ficha agenda[], int tam) {
	int dia, mes, ano, i;
	char str[50];

	printf("=================================\n");
	printf("\n");
	__fpurge(stdin);

	printf("Nome: ");
	fgets(str, sizeof(str), stdin);
	strtoupper(str);
	__fpurge(stdin);

	if(tam > 0) {
		
		i = buscaPosicao(agenda, tam, str);

		reposicionarAgenda(agenda, tam, i);
	}
	else {

		i = 0;
	}

	strcpy(agenda[i].nome, str);

	printf("Email: ");
	fgets(agenda[i].email, sizeof(agenda[i].email), stdin);
	__fpurge(stdin);

	printf("Telefone: ");
	fgets(agenda[i].telefone, sizeof(agenda[i].telefone), stdin);
	__fpurge(stdin);

	printf("Data de Nascimento: ");
	scanf("%d/%d/%d", &dia, &mes, &ano);
	__fpurge(stdin);

	agenda[i].nasc.dia = dia;
	agenda[i].nasc.mes = mes;
	agenda[i].nasc.ano = ano;

	printf("Oservacao:\n");
	fgets(agenda[i].obs, sizeof(agenda[i].obs), stdin);
	__fpurge(stdin);

	printf("\n");

	printf("Rua: ");
	fgets(agenda[i].endereco.rua, sizeof(agenda[i].endereco.rua), stdin);
	strtoupper(agenda[i].endereco.rua);
	__fpurge(stdin);

	printf("Numero: ");
	fgets(agenda[i].endereco.num, sizeof(agenda[i].endereco.num), stdin);
	__fpurge(stdin);

	printf("Complemento: ");
	fgets(agenda[i].endereco.comp, sizeof(agenda[i].endereco.comp), stdin);
	__fpurge(stdin);

	printf("Bairro: ");
	fgets(agenda[i].endereco.bairro, sizeof(agenda[i].endereco.bairro), stdin);
	strtoupper(agenda[i].endereco.bairro);
	__fpurge(stdin);

	printf("CEP: ");
	fgets(agenda[i].endereco.cep, sizeof(agenda[i].endereco.cep), stdin);
	__fpurge(stdin);

	printf("Cidade: ");
	fgets(agenda[i].endereco.cidade, sizeof(agenda[i].endereco.cidade), stdin);
	strtoupper(agenda[i].endereco.cidade);
	__fpurge(stdin);

	printf("Estado: ");
	fgets(agenda[i].endereco.estado, sizeof(agenda[i].endereco.estado), stdin);
	strtoupper(agenda[i].endereco.estado);
	__fpurge(stdin);

	printf("Pais: ");
	fgets(agenda[i].endereco.pais, sizeof(agenda[i].endereco.pais), stdin);
	strtoupper(agenda[i].endereco.pais);
	__fpurge(stdin);
}

void removerContato(Ficha agenda[], int tam) {
	int i, j;
	char str[50];

	printf("Entre com o nome completo do contato: ");
	fgets(str, sizeof(str), stdin);

	strtoupper(str);

	j = buscaPosicao(agenda, tam, str);

	for(i=j; i<tam+1; i++) {
		strcpy(agenda[j].nome, agenda[j+1].nome);
		strcpy(agenda[j].email, agenda[j+1].email);

		strcpy(agenda[j].endereco.rua, agenda[j+1].endereco.rua);
		strcpy(agenda[j].endereco.num, agenda[j+1].endereco.num);
		strcpy(agenda[j].endereco.comp, agenda[j+1].endereco.comp);
		strcpy(agenda[j].endereco.bairro, agenda[j+1].endereco.bairro);
		strcpy(agenda[j].endereco.cep, agenda[j+1].endereco.cep);
		strcpy(agenda[j].endereco.cidade, agenda[j+1].endereco.cidade);
		strcpy(agenda[j].endereco.estado, agenda[j+1].endereco.estado);
		strcpy(agenda[j].endereco.pais, agenda[j+1].endereco.pais);

		strcpy(agenda[j].telefone, agenda[j+1].telefone);

		agenda[j].nasc.dia = agenda[j+1].nasc.dia;
		agenda[j].nasc.mes = agenda[j+1].nasc.mes;
		agenda[j].nasc.ano = agenda[j+1].nasc.ano;

		strcpy(agenda[j].obs, agenda[j+1].obs);
	}
}

void mostrarContatos(Ficha agenda[], int tam) {
	int i, op;

	printf("1- Contato Reduzido\n");
	printf("2- Contato Completo\n");
	
	printf("\nEntre com a opcao: ");
	scanf("%d", &op);
	__fpurge(stdin);

	switch(op) {
		case 1:
			for(i=0; i<tam; i++) {
				imprimeContatoRed(agenda[i]);
			}
			break;

		case 2:
			for(i=0; i<tam; i++) {
				imprimeContato(agenda[i]);
			}
			break;

		default:
			printf("Opção Inválida.\n");
			break;
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

void strtoupper(char s[]) {
	int i;

	for(i=0; i < strlen(s); i++) {
		s[i] = toupper(s[i]);
	}
}

int buscaPosicao(Ficha agenda[], int tam, char s[]) {
	int i = 0;
	char aux[50];

	strcpy(aux, agenda[i].nome);

	while(strcmp(s,aux)>0 && i<tam) {

		i++;
		strcpy(aux, agenda[i].nome);
	}

	return i;
}

void reposicionarAgenda(Ficha agenda[], int tam, int i) {
	Ficha aux;
	int j;
	char str[50]; 

	for(j=tam; j>=i; j--) {

		strcpy(agenda[j+1].nome, agenda[j].nome);
		strcpy(agenda[j+1].email, agenda[j].email);

		strcpy(agenda[j+1].endereco.rua, agenda[j].endereco.rua);
		strcpy(agenda[j+1].endereco.num, agenda[j].endereco.num);
		strcpy(agenda[j+1].endereco.comp, agenda[j].endereco.comp);
		strcpy(agenda[j+1].endereco.bairro, agenda[j].endereco.bairro);
		strcpy(agenda[j+1].endereco.cep, agenda[j].endereco.cep);
		strcpy(agenda[j+1].endereco.cidade, agenda[j].endereco.cidade);
		strcpy(agenda[j+1].endereco.estado, agenda[j].endereco.estado);
		strcpy(agenda[j+1].endereco.pais, agenda[j].endereco.pais);

		strcpy(agenda[j+1].telefone, agenda[j].telefone);

		agenda[j+1].nasc.dia = agenda[j].nasc.dia;
		agenda[j+1].nasc.mes = agenda[j].nasc.mes;
		agenda[j+1].nasc.ano = agenda[j].nasc.ano;

		strcpy(agenda[j+1].obs, agenda[j].obs);
	}
}

void buscaContato(Ficha agenda[], int tam) {
	int op, dia, mes;
	char nome[20];

	printf("Deseja buscar o contato por:\n");
	printf("1- Nome\n");
	printf("2- Mes de Aniversario\n");
	printf("3- Dia e Mes de Aniversario\n");

	printf("\nEntre com a opção: ");
	scanf("%d", &op);
	__fpurge(stdin);

	switch(op) {
		case 1: 
			printf("Entre com o nome do contato: ");
			fgets(nome, sizeof(nome), stdin);
			__fpurge(stdin);

			buscaNome(agenda, tam, nome);
			break;

		case 2: 
			printf("Entre com o mes: ");
			scanf("%d", &mes);
			__fpurge(stdin);

			buscaMes(agenda, tam, mes);
			break;

		case 3: 
			printf("Entre com o dia e mes: ");
			scanf("%d/%d", &dia, &mes);
			__fpurge(stdin);

			buscaDiaMes(agenda, tam, dia, mes);
			break;
	}

}

void imprimeContato(Ficha contato) {

	printf("\n============================================\n");
	printf("\n");
	printf("---------------- Dados ---------------\n");
	printf("Nome: %s", contato.nome);
	printf("Email: %s\n", contato.email);
	printf("Telefone: %s\n", contato.telefone);
	printf("Nascimento: %d/%d/%d\n", contato.nasc.dia, contato.nasc.mes, contato.nasc.ano);
	printf("Observacoes: %s", contato.obs);


	printf("--------------- Endereco -------------\n");
	printf("Rua: %s", contato.endereco.rua);
	printf("Nº: %s\n", contato.endereco.num);
	printf("Complemento: %s", contato.endereco.comp);
	printf("Bairro: %s", contato.endereco.bairro);
	printf("CEP: %s\n", contato.endereco.cep);
	printf("Cidade: %s", contato.endereco.cidade);
	printf("Estado: %s", contato.endereco.estado);
	printf("Pais: %s", contato.endereco.pais);
	printf("\n============================================\n");
}

void imprimeContatoRed(Ficha contato) {

	printf("\n============================================\n");
	printf("\n");
	printf("Nome: %s", contato.nome);
	printf("Email: %s\n", contato.email);
	printf("Telefone: %s\n", contato.telefone);
	printf("\n============================================\n");
}

void buscaNome(Ficha agenda[], int tam, char nome[]) {
	int i = 0;
	char aux[50];

	strtoupper(nome);

	nome[strlen(nome)-1] = '\0'; // elimina o ultimo caracter vazio

	do {

		sscanf(agenda[i].nome, "%s", aux);	// guarda somente o primeiro nome

		if(strcmp(aux, nome) == 0) {

			imprimeContato(agenda[i]);
		}

		i++;

	} while(strcmp(aux, nome)<=0 && i<tam);
}

void buscaMes(Ficha agenda[], int tam, int mes) {
	int i = 0;
	int aux;

	do {

		aux = agenda[i].nasc.mes;

		if(aux == mes) {

			imprimeContato(agenda[i]);
		}

		i++;
	} while (i<tam);
}

void buscaDiaMes(Ficha agenda[], int tam, int dia, int mes) {
	int i = 0;
	int auxMes, auxDia;

	do {

		auxMes = agenda[i].nasc.mes;
		auxDia = agenda[i].nasc.dia;

		if(auxMes == mes && auxDia == dia) {

			imprimeContato(agenda[i]);
		}
		
		i++;
	} while (i<tam);
}