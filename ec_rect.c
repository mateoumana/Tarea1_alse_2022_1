/**************************************
Escuela Colombiana de ingeniería Julio Garavito
Mateo Felipe Umaña - Arthur Stink Paipilla
Paula ROdriguez Gonzalez - Paul Sebastian Romero
Trabajo martes 1 de febrero
***************************************/


#include <stdio.h>

int main(void){

	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	float m = 0, b = 0;

	printf("\n\nEste programa consiste en mostrar la ecuación de una recta,");
	printf(" dados dos puntos de esta por el usuario.\n");

	printf("\n>>Ingrese el primer punto:");
	printf("\n\nAbscisa (x): ");
	scanf("%d", &x1);
	printf("Ordenada (y): ");
	scanf("%d", &y1);
	printf("\n\n>>Ingrese el segundo punto:");
	printf("\n\nAbscisa (x): ");
	scanf("%d", &x2);
	printf("Ordenada (y): ");
	scanf("%d", &y2);

	if(x1 == x2 && y1 == y2){
		printf("\n\nProporcione puntos diferentes para poder describir la recta.\n\n");
		return 0;
	}

	if(x1 == x2){
		printf("\n\nLa recta es vertical y pasa por X = %d \n\n", x1);
		return 0;
	}

	m =(float)(y2 - y1)/(float)(x2 -x1);
	b = y1 - m*x1;

	printf("\n\nLa ecuación de recta que contiene los dos puntos que ingreso");
	printf(" anteriormente, es:\n\n");

	if(b == 0){
		printf("\t\ty = %fx", m);
	}else if(b < 0){
		b = -1*b;
		printf("\t\ty = %fx - %f", m, b);
	}else{
		printf("\t\ty = %fx + %f", m, b);
	}


	if(m < 0){
		printf("\n\nLa recta es decreciente.\n\n");
	}else if(m > 0){
		printf("\n\nLa recta es creciente.\n\n");
	}else{
		printf("\n\nLa recta es constante.\n\n");
	}

}

