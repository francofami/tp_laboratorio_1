#include "funciones.h"

float sumar(float numero1, float numero2)
{
    float suma=-1;

    suma=numero1+numero2;

    return suma;
}

float restar(float numero1, float numero2)
{
    float resta=-1;

    resta=numero1-numero2;

    return resta;
}

float dividir(float numero1, float numero2)
{
    float division;

    if(numero2==0)
    {
        printf("Error! No se puede dividir por 0.\n");
        return division;
    }

    division=numero1/numero2;

    return division;
}

float multiplicar(float numero1, float numero2)
{
    float multiplicacion=-1;

    multiplicacion=numero1*numero2;

    return multiplicacion;
}
