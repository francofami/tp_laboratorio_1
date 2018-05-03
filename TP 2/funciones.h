#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param largo del array lista
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni, int);

/** \brief
 *  Permite el ingreso de personas siempre y cuando el array no este lleno.
 * \param lista el array se pasa como parametro.
 * \param largo del array lista
 * \return void
 *
 */
void altaPersona(EPersona lista[], int);

/** \brief
 *  Permite la baja de personas (poner estado, edad, dni en 0 y nombre vacio) mediante el ingreso de dni validando que el mismo este cargado.
 * \param lista el array se pasa como parametro.
 * \param largo del array lista
 * \return void
 *
 */
void bajaPersona(EPersona lista[], int);

/** \brief
 *
 * \param lista el array se pasa como parametro.
 * \param largo del array lista
 * \return void
 *
 */
void imprimirLista(EPersona lista[], int);

/** \brief
 *
 * \param lista el array se pasa como parametro.
 * \param largo del array lista
 * \return void
 *
 */
void inicializarEstados(EPersona lista[], int);

/** \brief
 *  Muestra un grafico de barras vertical en donde se agrupan 3 barras: menores de 18, de 19 a 35 y mayores de 35.
 * \param lista el array se pasa como parametro.
 * \param largo del array lista
 * \return void
 *
 */
void imprimirGrafico(EPersona lista[], int);

#endif // FUNCIONES_H_INCLUDED
