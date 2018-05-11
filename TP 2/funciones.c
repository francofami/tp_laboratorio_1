#include "funciones.h"
#include <stdio.h>
#include <string.h>

void inicializarEstados(EPersona lista[], int length)
{
    int i;

    for(i=0;i<length;i++)
    {
        lista[i].estado=0;
        strcpy(lista[i].nombre,"");
        lista[i].edad=0;
        lista[i].dni=0;
    }
}

void altaPersona(EPersona lista[], int length)
{
    int posicionVacia;
    char validaEdad[3];
    char validaDni[10];

    posicionVacia=obtenerEspacioLibre(lista, length);

    if(posicionVacia!=-1)
    {
        do{
            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(lista[posicionVacia].nombre);
        }while(validarNombre(lista[posicionVacia].nombre)==0);


        do{
            printf("\nIngrese edad: ");
            scanf("%s",&validaEdad);
        }while(validarNumero(validaEdad)==0);

        lista[posicionVacia].edad=atoi(validaEdad);

        do{
            printf("\nIngrese DNI (sin puntos ni comas): ");
            scanf("%s",&validaDni);
        }while(validarNumero(validaDni)==0);

        lista[posicionVacia].dni=atoi(validaDni);

        lista[posicionVacia].estado=1;
    }
    else
        printf("No se puede agregar mas personas.\n");
}

int obtenerEspacioLibre(EPersona lista[], int length)
{
    int i, posicionVacia=-1;

    for(i=0;i<length;i++)
    {
        if(lista[i].estado==0)
        {
            posicionVacia=i;
            break;
        }
    }
    return posicionVacia;
}

void bajaPersona(EPersona lista[], int length)
{
    int dni, indiceBorrar,i;

    for(i=0;i<length;i++)
    {
        if(lista[i].estado==1)
        printf("Nombre: %s     -     Edad: %d     -    DNI: %d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
    }

    printf("Ingrese dni a ser dado de baja: ");
    scanf("%d",&dni);
    indiceBorrar=buscarPorDni(lista, dni,length);

    if(indiceBorrar!=-1)
    {
        lista[indiceBorrar].estado=0;
        strcpy(lista[indiceBorrar].nombre,"");
        lista[indiceBorrar].edad=0;
        lista[indiceBorrar].dni=0;
    }
    else
        printf("El usuario seleccionado no existe. \n");

}

int buscarPorDni(EPersona lista[], int dni, int length)
{
    int i, indiceBorrar=-1;

    for(i=0;i<length;i++)
    {
        if(dni==lista[i].dni)
        {
            indiceBorrar=i;
            break;
        }
        else if(i==length-1)
            printf("El DNI ingresado no esta en la lista. ");
    }

    return indiceBorrar;
}

void imprimirLista(EPersona lista[], int length)
{
    int i, j, auxInt, contadorActivos=0;
    char aux[50];

    for(i=0;i<length;i++)
    {
        if(lista[i].estado==1)
        {
            contadorActivos+=1;
        }
    }

    for(i=0;i<contadorActivos-1;i++)
    {
        for(j=i+1;j<contadorActivos;j++)
        {
            if((stricmp(lista[j].nombre,lista[i].nombre))==-1)
            {
                strcpy(aux,lista[j].nombre);
                strcpy(lista[j].nombre,lista[i].nombre);
                strcpy(lista[i].nombre,aux);

                auxInt=lista[j].edad;
                lista[j].edad=lista[i].edad;
                lista[i].edad=auxInt;

                auxInt=lista[j].dni;
                lista[j].dni=lista[i].dni;
                lista[i].dni=auxInt;
            }
        }
    }

    for(i=0;i<contadorActivos;i++)
    {
        printf("Nombre: %s Edad: %d DNI: %d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
    }
}

void imprimirGrafico(EPersona lista[], int length)
{
    int i, j, cantidadUno=0, cantidadDos=0, cantidadTres=0, masAlto=0, cantidades[21], filas;

    for(i=0;i<length;i++)
    {
        if(lista[i].edad<18 && lista[i].estado==1)
        {
            cantidadUno+=1;
        }

        if(lista[i].edad>=19 && lista[i].edad<=35 && lista[i].estado==1)
        {
            cantidadDos+=1;
        }

        if(lista[i].edad>35 && lista[i].estado==1)
        {
            cantidadTres+=1;
        }
    }

	cantidades[1]=cantidadUno;
	cantidades[2]=cantidadDos;
	cantidades[3]=cantidadTres;

    for(i=1;i<=3;i++)
    {
        if (masAlto < cantidades[i])
        {
            masAlto = cantidades[i];
        }
    }

	filas = masAlto;

	for (i = 0; i < masAlto; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			if (cantidades[j] >= filas)
			{
				printf(" *        ");
			}
			else
			{
				printf("          ");
			}
		}
		filas = filas - 1;
		printf("\n");
	}

    printf("<18      ");
    printf("19-35      ");
    printf(">35\n");
}

int validarNumero(char numero[])
{
    int retorno=1;

    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            retorno=0;
            printf("Error, ingrese solo numeros. \n");
            break;
        }
    }

    return retorno;
}

int validarNombre(char nombre[])
{

    int retorno=1;
    int i;
    for(i=0 ; i<strlen(nombre); i++)
    {
        if(!(nombre[i]>=65 && nombre[i]<=90 || nombre[i]>=97 && nombre[i]<=122 || nombre[i]==32))
        {
            printf("Error, solo se pueden ingresar letras.");
            retorno=0;
        }
    }
    return retorno;
}
