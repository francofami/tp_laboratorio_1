#include "factorial.h"

float factorial(float numero1)
{
    int i, entero;
    float facto=1;

    entero=(int) numero1;

    if(numero1<0)
    {
        printf("Error! No se puede calcular el factorial de un numero negativo.\n");
        return;
    }

    if(entero!=numero1)
    {
        printf("Error! No se puede calcular el factorial de un numero con decimales.\n");
        return;
    }

    if(numero1==0 || numero1==1)
    {
        facto=1;
    }

    for(i=numero1;i>=1;i--)
    {
        facto = facto*i;
    }

    return facto;
}
