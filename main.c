#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
#include "factorial.h"
#include <ctype.h>


int main()
{
    char seguir='s';
    int opcion=0, enteron1;
    float numero1=0, numero2=0, suma, resta, multiplicacion, division, facto;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%f)\n", numero1);
        printf("2- Ingresar 2do operando (B=%f)\n", numero2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                {
                    printf("Ingrese el 1er operando: ");
                    scanf("%f",&numero1);
                    enteron1=(int)numero1;
                }
                break;

            case 2:
                {
                    printf("Ingrese el 2do operando: ");
                    scanf("%f",&numero2);
                }
                break;

            case 3:
                {
                    suma=sumar(numero1,numero2);
                    printf("El resultado de la suma es: %f\n",suma);
                }

                break;
            case 4:
                {
                    resta=restar(numero1,numero2);
                    printf("El resultado de la resta es: %f\n",resta);
                }
                break;
            case 5:
                {
                    division=dividir(numero1,numero2);
                    if(numero2!=0)
                    printf("El resultado de la division es: %f\n",division);
                }
                break;
            case 6:
                {
                    multiplicacion=multiplicar(numero1,numero2);
                    printf("El resultado de la multiplicacion es: %f\n",multiplicacion);
                }
                break;
            case 7:
                {   facto=factorial(numero1);
                    if(numero1>=0 && (numero1==enteron1))
                    printf("El resultado del factorial es: %.0f\n",facto);
                }
                break;
            case 8:
                {
                    suma=sumar(numero1,numero2);
                    resta=restar(numero1,numero2);
                    division=dividir(numero1,numero2);
                    multiplicacion=multiplicar(numero1,numero2);
                    facto=factorial(numero1);

                    printf("El resultado de la suma es: %f\n",suma);
                    printf("El resultado de la resta es: %f\n",resta);
                    if(numero2!=0)
                    printf("El resultado de la division es: %f\n",division);
                    printf("El resultado de la multiplicacion es: %f\n",multiplicacion);
                    if(numero1>=0 && (numero1==enteron1))
                    printf("El resultado del factorial es: %.0f\n",facto);
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }



    return 0;

}
