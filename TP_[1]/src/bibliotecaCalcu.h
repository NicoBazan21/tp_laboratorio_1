#ifndef BIBLIOTECACALCU_H_INCLUDED
#define BIBLIOTECACALCU_H_INCLUDED



#endif // BIBLIOTECACALCU_H_INCLUDED

/** \brief ingresar primer parametro, segundo parametro, recibe la variable cambiante del menu
 *
 * \param uno int  primer numero
 * \param dos int  segundo numero
 * \param si int*  variable que cambia el menu|| 0 = menu estandar 1 = primer numero asignado 2 = segundo numero asignado 3 = realizar operaciones 4 = mostrar resultados
 * \return int retorna la opcion
 *
 */
int menu(int uno, int dos, int si);

/** \brief  recibe numero uno, recibe numero 2, recibe la direccion de memoria de la variable donde se asignara respuesta
 *
 * \param uno int   numero 1
 * \param dos int   numero 2
 * \param rta int*  asigna la respuesta a la direccino de memoria pasada por referencia
 * \return void retorna void
 *
 */
void fSuma(int uno, int dos, int* rta);

/** \brief  recibe numero uno, recibe numero 2, recibe la direccion de memoria de la variable donde se asignara respuesta
 *
 * \param uno int   numero 1
 * \param dos int   numero 2
 * \param rta int* asigna la respuesta a la direccino de memoria pasada por referencia
 * \return void retorna void
 *
 */
void fResta(int uno, int dos, int* rta);

/** \brief recibe numero uno, recibe numero 2, recibe la direccion de memoria de la variable donde se asignara respuesta
 *
 * \param uno int   numero 1
 * \param dos int   numero 2
 * \param rta float*    asigna la respuesta a la direccino de memoria pasada por referencia
 * \return int retorna 0 para division erronea y 1 para division exitosa
 *
 */
int fDivision(int uno, int dos, float* rta);

/** \brief recibe numero uno, recibe numero 2, recibe la direccion de memoria de la variable donde se asignara respuesta
 *
 * \param uno int   numero 1
 * \param dos int   numero 2
 * \param rta int*  asigna la respuesta a la direccino de memoria pasada por referencia
 * \return void
 *
 */
void fMulti(int uno, int dos, int* rta);

/** \brief recibe numero uno, recibe numero 2, recibe la direccion de memoria de la variable donde se asignara respuesta
 *
 * \param uno int numero 1
 * \param rta long longint* asigna la respuesta a la direccino de memoria pasada por referencia
 * \return void
 *
 */
int fFactorial(int uno, unsigned long* respuesta);

/** \brief recibe variables para mostrar
 *
 * \param suma int recibe int suma
 * \param resta int  recibe int resta
 * \param division float recibe float division
 * \param mult int  recibe int multiplicacion
 * \param factorialA long longint recibe lli factorialA
 * \param factorialB long longint recibe lli factorialB
 * \param error int contempla el error de la division
 * \param uno int   recibe numero 1
 * \param dos int   recibe numero 2
 * \return void retorna 0
 *
 */
void mostrarResultados(int suma, int resta, float division, int mult, long long int factorialA, long long int factorialB, int error, int uno, int dos);
