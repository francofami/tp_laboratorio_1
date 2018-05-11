#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

#endif // FUNCIONES_H_INCLUDED

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

/** \brief Valida que solo se ingresen numeros
 *
 * \param numero[] char El array que contiene al numero
 * \return int Devuelve 0 si contiene un caracter distinto a un numero, de lo contrario devuelve 1.
 *
 */
int validarNumero(char numero[]);

/** \brief Valida que solo se ingresen caracteres de la A a la Z (incluyendo may�sculas, min�sculas y espacios)
 *
 * \param nombre[] char El array que contiene al nombre.
 * \return int Devuelve 0 si contiene un caracter distinto a un caracter de la A a la Z (incluyendo may�sculas, min�sculas y espacios), de lo contrario devuelve 1.
 *
 */
int validarNombre(char nombre[]);
