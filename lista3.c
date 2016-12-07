#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct {
	int x;
	int y;
} Ponto;

int inRect(Ponto p, Ponto x, Ponto y);
int areaRect(Ponto x, Ponto y);

int main() {
	Ponto p, x, y;
	char resp[20];

	printf("Entre com as coordenadas do ponto P: ");
	scanf("%d %d", &p.x, &p.y);

	printf("Entre com as coordenadas do ponto X: ");
	scanf("%d %d", &x.x, &x.y);

	printf("Entre com as coordenadas do ponto Y: ");
	scanf("%d %d", &y.x, &y.y);

	printf("\n=========================================================\n\n");

	if(inRect(p, x, y)>=1) {
		if(inRect(p, x, y)==1) {
			strcpy(resp, "esta dentro do");
		}
		else {
			strcpy(resp, "pertence ao");
		}
	}
	else {
		strcpy(resp, "esta fora do");
	}

	printf("O ponto P %s retangulo formado por X e Y.\n", resp);
	printf("A area do retangulo formado pelos pontos X e Y é %d.\n", areaRect(x, y));

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