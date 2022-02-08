/**************************************
Escuela Colombiana de ingeniería Julio Garavito
Mateo Felipe Umaña - Arthur Stink Paipilla
Paula Rodriguez Gonzalez - Paul Sebastian Romero
Trabajo martes 8 de febrero
***************************************/

#include <stdio.h>
#include <math.h>
#define E 0.001 //Tanto el criterio de exactitud como de precision valen lo mismo en este programa
#define MAX 40

int main(void){
    //xi=punto inicial, xi_1=punto inicial - 1, f = funcion, conver = criterio de convergencia
    float xi = 0.0, xi_1 = 0.0, f = 1.0, conver = 1.0; //conver se inicializa en 1 para que si se entre al while
    int iteraciones = 0, opc = 0;

	printf("\n\nEste programa consiste en el método del punto fijo para hallar");
	printf(" las raices de una de las siguientes ecuaciones:\n\n\t\t\t\t     1) f(x)=2x**2-x-5.\n");
    printf("\n\t\t\t\t     2) f(x)=x**3+2x**2+10x-20.\n\n");
    printf("\n>>>Selecciona la ecuación que quieras hallar sus ceros (1 o 2?): ");
    scanf("%d",&opc);

    while(opc != 1 && opc != 2){        //Se valida que ingresen alguna de las opciones validas
        printf("\n\nEsa opcion no existe.");
        printf("\nSelecciona la ecuación que quieras hallar sus ceros (1 o 2?): ");
        scanf("%d",&opc);
    }

    if(opc == 1){
        printf("\n\n\t==========================================================================");
        printf("\n\tNOTA:Como g(x)=((x+5)/2)**(1/2) dicha funcion tiene un dominio el cual es");
        printf("\n\t\t\t\t\tx >= -3\n");
        printf("\tAsi que por favor ingrese un punto inicial mayor o igual que -3. Gracias.");
        printf("\n\t==========================================================================");

        printf("\n\n\n>>Ingrese el punto inicial que desea evaluar en el método (X0):");
        scanf("%f", &xi);

        while(xi < -3){     //Validacion del dominio de g(x)
        printf("\n\t<<<<No ingresó un número mayor o igual que -3, por favor corregirlo>>>>");
        printf("\n\n>>Ingrese el punto inicial que desea evaluar en el método (X0):");
        scanf("%f", &xi);   //se vuelve a pedir el X0
        }

        while(iteraciones <= MAX && (conver < -E || conver > E) && (f < -E || f > E)){//La idea es que salga del while si y solo si ya se cumplio los criterios o se acabo las iteraciones
            f = 2*(xi)*(xi) - xi - 5;
            xi_1 = sqrt((xi + 5)/2);
            if(f == 0){                 //si f ya es cero con X0 no hay nesecidad de iterar
                iteraciones = 21;       //con esto no se entraria al while
            }
            iteraciones++;
            conver = xi - xi_1;
            xi = xi_1;
        }
    }else{
        printf("\n\n\t==========================================================================");
        printf("\n\tNOTA:Como g(x)=(20-2x**2-10x)**(1/3) dicha funcion tiene un dominio el cual es");
        printf("\n\t\t\t\t\tTodos los reales");
        printf("\n\tAsi que puede ingresar un punto inicial cualquiera. Gracias.");
        printf("\n\t==========================================================================");

        printf("\n\n\n>>Ingrese el punto inicial que desea evaluar en el método (X0):");
        scanf("%f", &xi);
        /*
        while(xi < -3){     //Validacion del dominio de g(x)
        printf("\n\t<<<<No ingresó un número mayor o igual que -3, por favor corregirlo>>>>");
        printf("\n\n>>Ingrese el punto inicial que desea evaluar en el método (X0):");
        scanf("%f", &xi);   //se vuelve a pedir el X0
        }*/

        while(iteraciones <= MAX && (conver < -E || conver > E) && (f < -E || f > E)){//La idea es que salga del while si y solo si ya se cumplio los criterios o se acabo las iteraciones
            f = xi*xi*xi+2*xi*xi+10*xi-20;
            xi_1 = cbrt(20-2*xi*xi-10*xi);  
            if(f == 0){                 //si f ya es cero con X0 no hay nesecidad de iterar
                iteraciones = 21;       //con esto no se entraria al while
            }
            iteraciones++;
            conver = xi - xi_1;
            xi = xi_1;
        }
    }
    printf("\n\n-Se obtuvo un criterio de exactitud de %.4f", f);
    printf("\n-Se realizaron %d iteraciones", iteraciones-1);
    printf("\n-Obteniendo un cero en x = %.4f\n\n", xi);
}


