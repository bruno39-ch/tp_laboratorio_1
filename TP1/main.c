#include <stdlib.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float x;
    float y;
    int opcion;

    float suma;
    float resta;
    float division;
    float multiplicacion;

    int factorialX;
    int factorialY;

    printf("Ingresar 1er operando(A): ");
    scanf("%f",&x);
    printf("Ingresar 2do operando(B): ");
    scanf("%f",&y);


    suma = CalcularSuma(x,y);
    resta = CalcularResta(x,y);
    division = CalcularDivision(x,y);
    multiplicacion = CalcularMultiplicacion(x,y);

    factorialX = CalcularFactorial(x);
    factorialY = CalcularFactorial(y);


    do{
        printf("\nElija una opcion:\n1. Sumar\n2. Restar\n3. Dividir\n4. Multiplicar\n5. Factorial\n6. Salir\n");
        scanf("%d",&opcion);

        switch(opcion){
        case 1:
            printf("El resultado de %f+%f es: %f\n",x,y,suma);
            break;
        case 2:
            printf("El resultado de %f-%f es: %f\n",x,y,resta);
            break;
        case 3:
            if(y != 0){
                printf("El resultado de %f/%f es: %f\n",x,y,division);
            }else{
                printf("No es posible dividir por cero\n");
            }
            break;
        case 4:
            printf("El resultado de %f*%f es: %f\n",x,y,multiplicacion);
            break;
        case 5:

            printf("El factorial de %f es: %d",x,factorialX);

            printf(" y El factorial de %f es: %d\n",y,factorialY);
            break;
        }
    }while(opcion != 6);

    return 0;
}
