#include <stdio.h>
#include "funciones.h"

float CalcularSuma(float x,float y)
{
    float suma;

    suma = x + y;
    return suma;
}

float CalcularResta(float x, float y)
{
    float resta;

    resta = x - y;
    return resta;
}

float CalcularDivision(float x, float y)
{
    float division;

    if(y != 0){
        division = (float)x / y;
    }else{
        division = 0;
    }
    return division;
}
float CalcularMultiplicacion(float x, float y)
{
    float multiplicacion;

    multiplicacion = x * y;

    return multiplicacion;
}
int CalcularFactorial(int xy)
{
    int factoreo;
    if(xy == 0 ){
        return 1;
    }else{
        factoreo = xy * CalcularFactorial(xy-1);
    }

    return factoreo;
}
