#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define LENGTH 100

int main()
{
    char seguir='s';
    int opcion=0;
    int i;

    EMovie *pMovie;
    EMovie movie[LENGTH];

    pMovie=&movie;

    inicializarPeliculas(pMovie,LENGTH);

    if(!cargarArchivo(pMovie, LENGTH))
	{
	    printf("Archivo cargado.\n");
	}
	else
	{
		printf("No se pudo abrir el archivo.");
	}


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                agregarPelicula(pMovie,LENGTH);
                break;
            case 2:
                modificarPelicula(pMovie,LENGTH);
                break;
            case 3:
                borrarPelicula(pMovie,LENGTH);
               break;
            case 4:
                generarHTML(pMovie,LENGTH);
                break;
            case 5:
                printf("\nGuardar cambios s/n ?: ");
				opcion = tolower(getche());

				if(opcion == 's')
				{
					if(guardarArchivo(pMovie, LENGTH))
					{
						printf("\nNo se pudo abrir el archivo\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
				}

				seguir='n';
                break;
        }
    }

    return 0;
}
