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
float compCirc(float r);
int formaTri(Ponto x, Ponto y, Ponto z);
void clasTri(Ponto x, Ponto y, Ponto z, char str[]);
void stringResp(char str[], int i);
double mod(Ponto x, Ponto y);

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
	printf("O comprimento do circulo de centro C e raio R é de %f\n", compCirc(r));

	printf("\n=========================================================\n\n");
}

void triangulo() {
	Ponto x, y, z;
	char resp[20];
	
	printf("\n=========================================================\n\n");

	printf("Entre com as coordenadas do ponto X: ");
	scanf("%d %d", &x.x, &x.y);

	printf("Entre com as coordenadas do ponto Y: ");
	scanf("%d %d", &y.x, &y.y);

	printf("Entre com as coordenadas do ponto Z: ");
	scanf("%d %d", &z.x, &z.y);

	printf("\n=========================================================\n\n");

	if(formaTri(x, y, z)>0) {

		clasTri(x, y, z, resp);
		printf("Os pontos X, Y e Z formam um triangulo %s.", resp);
	}
	else {
		printf("Os pontos X, Y e Z não formam um triangulo.\n");	
	}

	printf("\n=========================================================\n\n");

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

	modP = mod(c, p);

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

float compCirc(float r) {
	double pi = 3.14;

	return 2 * pi * r;
}

int formaTri(Ponto x, Ponto y, Ponto z) {
	double a, b, c;

	if(x.x == y.x && x.y == y.y) {
		return 0;
	}
	else {
		return 1;
	}
}

void clasTri(Ponto x, Ponto y, Ponto z, char str[]) {
	double ladoA, ladoB, ladoC;

	ladoA = mod(x, y);
	ladoB = mod(x, z);
	ladoC = mod(y, z);

	if(ladoA == ladoB && ladoB == ladoC) {
		strcpy(str, "equilatero");
	}
	else {
		if(ladoA == ladoB || ladoA == ladoC || ladoB == ladoC) {
			strcpy(str, "isoceles");
		}
		else {
			strcpy(str, "escaleno");
		}
	}
}

void stringResp(char str[], int i) {

	if(i>=1) {
		if(i==1) {
			strcpy(str, "esta dentro do");
		}
		else {
			strcpy(str, "pertence ao");
		}
	}
	else {
		strcpy(str, "esta fora do");
	}
}

double mod(Ponto x, Ponto y) {
	return sqrt(pow((double) x.x - y.x, 2.0) + pow((double) x.y - y.y, 2.0));
}