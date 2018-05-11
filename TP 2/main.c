#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define LENGTH 20


int main()
{
    char seguir='s';
    int opcion=0;
    char opcionString[2];

    EPersona lista[LENGTH];

    inicializarEstados(lista, LENGTH);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        do{
            fflush(stdin);
            scanf("%s", &opcionString);
        }while(validarNumero(opcionString)==0);

        opcion=atoi(opcionString);

        system("cls");

        switch(opcion)
        {
            case 1:
                altaPersona(lista, LENGTH);
                break;
            case 2:
                bajaPersona(lista, LENGTH);
                break;
            case 3:
                imprimirLista(lista, LENGTH);
                break;
            case 4:
                imprimirGrafico(lista, LENGTH);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
