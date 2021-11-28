#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * @fn Employee employee_new*()
 * @brief funcion contructora
 *
 * @return etorna empleado
 */
Employee* employee_new();
/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief funcion constructora por parametros
 *
 * @param idStr id que necesita castear
 * @param nombreStr nombre
 * @param horasTrabajadasStr horas trabajadas que necesita castearse
 * @param sueldoStr sueldo que necesita castearse
 * @return retorna emp
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/**
 * @fn void employee_delete()
 * @brief utiliza free para liberar memoria
 *
 */
void employee_delete();

/**
 * @fn int employee_setId(Employee*, int)
 * @brief setea el id
 *
 * @param this recibe un punetro a estructura
 * @param id
 * @return
 */
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief setea un nombre
 *
 * @param this puntero a esctructura
 * @param nombre recibe nombre
 * @return
 */
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief Carga las horas trabajadas del empleado.
 *
 * @param this Puntero a la lista de empleados.
 * @param horasTrabajadas horas trabajadas a cargar en el empleado.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief setea el sueldo
 *
 * @param this puntero a esctrucutra
 * @param sueldo recibe sueldo a setear
 * @return
 */
int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);


/**
 * @fn void employee_mostrarEmpleado(Employee*)
 * @brief recibe un puntero a esctructura
 *
 * @param retorna void
 */
void employee_mostrarEmpleado(Employee* emp);
int employee_comparaPersonas(void* pPersonaA, void* pPersonaB);
int employee_comparaPersonasSueldo(void* pPersonaA, void* pPersonaB);
int employee_comparaPersonasHoras(void* pPersonaA, void* pPersonaB);

#endif // employee_H_INCLUDED
