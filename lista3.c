#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} Ponto;

void menu();
void retangulo();
void circunferencia();
void triangulo();
int inRect(Ponto p, Ponto x, Ponto y);
int areaRect(Ponto x, Ponto y);
int inCirc(Ponto p, Ponto c, float r);
float areaCirc(float r);
void stringResp(char string[], int i);

int main() {
	int op;
	char resp;

	menu();

	printf("Entre com a opção: ");
	scanf("%d", &op);

	do {

		switch(op) {
			case 1: retangulo();
				break;

			case 2: circunferencia();
				break;

			case 3: triangulo();
				break;

			default: 
				printf("Opção Inválida.\n");
				break;
		}

		__fpurge(stdin);
		printf("Deseja terminar? (s ou n)\n");
		scanf("%c", &resp);

	} while(resp == 'n');

	return 0;
}

void menu() {

	printf("\n=========================================================\n\n");
	printf("1- Retangulo\n");
	printf("2- Circunferencia\n");
	printf("3- Triangulo\n");
	printf("\n");

}

void retangulo() {
	Ponto p, x, y;
	char resp[20];

	printf("\n=========================================================\n\n");

	printf("Entre com as coordenadas do ponto P: ");
	scanf("%d %d", &p.x, &p.y);

	printf("Entre com as coordenadas do ponto X: ");
	scanf("%d %d", &x.x, &x.y);

	printf("Entre com as coordenadas do ponto Y: ");
	scanf("%d %d", &y.x, &y.y);

	printf("\n=========================================================\n\n");

	stringResp(resp, inRect(p, x, y));

	printf("O ponto P %s retangulo formado por X e Y.\n", resp);
	printf("A area do retangulo formado pelos pontos X e Y é %d.\n", areaRect(x, y));

	printf("\n=========================================================\n\n");
}

void circunferencia() {
	Ponto p, c;
	float r;
	char resp[20];

	printf("\n=========================================================\n\n");

	printf("Entre com as coordenadas do ponto P: ");
	scanf("%d %d", &p.x, &p.y);	

	printf("Entre com as coordenadas de C: ");
	scanf("%d %d", &c.x, &c.y);

	printf("Entre com R: ");
	scanf("%f", &r);

	printf("\n=========================================================\n\n");

	stringResp(resp, inCirc(p, c, r));

	printf("O ponto P %s circulo formado por centro C de raio R.\n", resp);
	printf("A area do circulo de centro C e raio R é de %f\n", areaCirc(r));

	printf("\n=========================================================\n\n");
}

void triangulo() {







}

int inRect(Ponto p, Ponto x, Ponto y) {
	if(x.x <= p.x && p.x <= y.x) {
		if(y.y <= p.y && p.y <= x.y) {
			if(p.x == x.x || p.x == y.x || p.y == x.y || p.y == y.y) {
				return 2;
			}
			else {
				return 1;
			}
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}

}

int areaRect(Ponto x, Ponto y) {
	return (x.y - y.y) * (y.x - x.x);
}

int inCirc(Ponto p, Ponto c, float r) {
	double modP;

	modP = sqrt(pow((double) (c.x-p.x), 2.0) + pow((double) (c.y-p.y), 2.0));

	if(modP >= r) {
		if(modP == r) {
			return 2;
		}
		else {
			return 1;
		}
	}
	else {
		return 0;
	}
}

float areaCirc(float r) {
	double pi = 3.14;

	return pi * pow((double) r, 2);
}

void stringResp(char string[], int i) {

	if(i>=1) {
		if(i==1) {
			strcpy(string, "esta dentro do");
		}
		else {
			strcpy(string, "pertence ao");
		}
	}
	else {
		strcpy(string, "esta fora do");
	}
}