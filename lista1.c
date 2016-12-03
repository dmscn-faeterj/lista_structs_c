#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct {
	char nome[20];
	char email[20];
	char telefone[12];
} Ficha;

void pergunta(Ficha *ficha);
void imprimir(Ficha ficha);

int main() {
	Ficha ficha[5];
	int i;

	for(i=0; i<5; i++) {

		pergunta(&ficha[i]);
	}

	for(i=0; i<5; i++) {

		imprimir(ficha[i]);
	}

}

void pergunta(Ficha *ficha) {

	__fpurge(stdin);

	printf("Entre com o nome:\n");
	fgets((*ficha).nome, sizeof((*ficha).nome), stdin);

	printf("Entre com o email:\n");
	fgets((*ficha).email, sizeof((*ficha).email), stdin);

	printf("Entre com o telefone\n");
	fgets((*ficha).telefone, sizeof((*ficha).telefone), stdin);

	printf("\n");
}

void imprimir(Ficha ficha) {

	printf("\n");
	printf("Nome: %s\n", ficha.nome);
	printf("Email: %s\n", ficha.email);
	printf("Telefone: %s\n", ficha.telefone);
	printf("\n");
}