#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    char sexo;
    float altura;
}ePersona;


#endif // PERSONAS_H_INCLUDED
/** \brief crea una nueva persona linkedlist
 *
 * \return ePersona*
 *
 */
ePersona* persona_new();

ePersona* persona_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/** \brief   crea un nuevo elemento persona mediante parametros recibidos
 *
 * \param id int    recibe el id
 * \param nombre[] char recibe nombre
 * \param altura float  recibe la altura
 * \param sexo char recibe el sexo
 * \return ePersona* retorna un puntero a estructura persona
 *
 */
ePersona* new_personaParam(int id, char nombre[], float altura, char sexo);

/** \brief seter de id
 *
 * \param this ePersona* recibe puntero a estructura
 * \param id int    recibe id
 * \return int
 *
 */
int persona_setId(ePersona* this,int id);
/** \brief seter de nombre
 *
 * \param this ePersona* recibe puntero a estructura
 * \param nombre char* recibe nombre
 * \return int
 *
 */
int persona_setNombre(ePersona* this,char* nombre);
/** \brief seter de sexo
 *
 * \param this ePersona*recibe puntero a estructura
 * \param sexo char recibe sexo
 * \return int
 *
 */
int persona_setSexo(ePersona* this,char sexo);
/** \brief rseter de altura
 *
 * \param this ePersona*recibe puntero a estructura
 * \param altura float  recibe altura
 * \return int
 *
 */
int persona_setAltura(ePersona* this,float sueldo);

/** \brief geter de id
 *
 * \param this ePersona* recibe puntero a estructura
 * \param id int*
 * \return int
 *
 */
int persona_getId(ePersona* this,int* id);
/** \brief geter de nombre
 *
 * \param this ePersona*recibe puntero a estructura
 * \param nombre char*
 * \return int
 *
 */
int persona_getNombre(ePersona* this,char* nombre);
/** \brief geter de altura
 *
 * \param this ePersona* recibe puntero a estructura
 * \param sueldo float*
 * \return int
 *
 */
int persona_getAltura(ePersona* this,float* sueldo);
/** \brief geter de sexo
 *
 * \param this ePersona*recibe puntero a estructura
 * \param sexo char*
 * \return int
 *
 */
int persona_getSexo(ePersona* this,char* sexo);

/** \brief muestra una persona mediante puntero a esctrucutra
 *
 * \param emp ePersona*
 * \return void
 *
 */
void persona_mostrarPersona(ePersona* emp);

/** \brief funcion comparadora
 *
 * \param pPersonaA void*
 * \param pPersonaB void*
 * \return int
 *
 */
int persona_comparaPersonasNombre(void* pPersonaA, void* pPersonaB);
/** \brief
 *funcion comparadora
 * \param pPersonaA void*
 * \param pPersonaB void*
 * \return int
 *
 */
int persona_comparaPersonasAltura(void* pPersonaA, void* pPersonaB);
/** \brief funcion comparadora
 *
 * \param pPersonaA void*
 * \param pPersonaB void*
 * \return int
 *
 */
int persona_comparaPersonasSexo(void* pPersonaA, void* pPersonaB);
