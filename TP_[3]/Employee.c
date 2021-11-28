#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
	 Employee* nuevoEmpleado;

	 nuevoEmpleado = (Employee*) malloc (sizeof(Employee));

	 if(nuevoEmpleado != NULL)
	 {
		 nuevoEmpleado->id=0;
		 strcpy(nuevoEmpleado->nombre, "nn");
		 nuevoEmpleado->horasTrabajadas=0;
		 nuevoEmpleado->sueldo=0;
	 }

	 return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* nuevoEmpleado;

	nuevoEmpleado = employee_new();

	if(nuevoEmpleado != NULL)
	{
		if(!(employee_setId(nuevoEmpleado, atoi(idStr))
		          && employee_setNombre(nuevoEmpleado, nombreStr)
		           && employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))
		          && employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))))
		{
		     free(nuevoEmpleado);
		     nuevoEmpleado=NULL;
		}
	}

	return nuevoEmpleado;
}

int employee_setId(Employee* this,int id)
{
    int todoOk=0;

    if(this != NULL && id > 0)
    {
    	this->id = id;
        todoOk=1;
    }
    else
    {
    	printf("Id invalido\n");
    }

    return todoOk;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk=0;

    if(this != NULL && nombre != NULL)
    {
        if(strlen(nombre) < 128 && strlen(nombre) > 2)
        {
            strcpy(this->nombre, nombre);
            strlwr(this->nombre);
            this->nombre[0] = toupper(this->nombre[0]);
            for(int i = 0; i < 128; i++)
            {
                 if(nombre[i] == ' ')
                 {
                	 this->nombre[i+1] = toupper(this->nombre[i+1]);
                 }
            }
            todoOk=1;
        }
    }
    else
    {
    	printf("Nombre invalido\n");
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;

    if(this != NULL && horasTrabajadas >= 0)
    {
    	this->horasTrabajadas = horasTrabajadas;
        todoOk=1;
    }
    else
    {
    	printf("Horas trabajadas invalidas\n");
    }

    return todoOk;
}


int employee_setSueldo(Employee* this,float sueldo)
{
    int todoOk = 0;
    if(this != NULL && sueldo >= 5000 && sueldo <= 100000)
    {
    	this->sueldo=sueldo;
        todoOk=1;
    }
    else
    {
    	printf("Sueldo invalido\n");
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
	int todoOk = 0;

	   if(this != NULL && id != NULL)
	   {
	       *id=this->id;
	       todoOk=1;
	   }
	   return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk=0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk=1;
    }

    return todoOk;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
    int todoOk=0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo=this->sueldo;
        todoOk=1;
    }

    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int todoOk = 0;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		 todoOk=1;
	}
	 return todoOk;
}

void employee_mostrarEmpleado(Employee* emp)
{
	int id;
	char nombre[128];
	int horasTrabajadas;
	float sueldo;
	if(emp != NULL)
	{
		employee_getId(emp, &id);
		employee_getNombre(emp, nombre);
		employee_getHorasTrabajadas(emp, &horasTrabajadas);
		employee_getSueldo(emp, &sueldo);

		printf("%d   %10s   \t%d\t\t\t%.2f\n",id, nombre, horasTrabajadas, sueldo);
	}
}


int employee_comparaPersonas(void* pPersonaA, void* pPersonaB)
{
	char cadena[128];
	char cadenaDos[128];

	Employee* emp = NULL;
	Employee* empDos = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPersonaA != NULL && pPersonaB != NULL)
	{
		emp = (Employee*) pPersonaA;
		empDos = (Employee*) pPersonaB;

		if(employee_getNombre(emp, cadena) == 1
		&& employee_getNombre(empDos, cadenaDos) == 1)
		{
			if(strcmp(cadena, cadenaDos) > 0)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
			{
				if(strcmp(cadena, cadenaDos) < 0)
				{
					retornoXqSinEstoMeDaUnWarning = -1;
				}
			}
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}

int employee_comparaPersonasSueldo(void* pPersonaA, void* pPersonaB)
{
	float sueldo;
	float sueldoDos;

	Employee* emp = NULL;
	Employee* empDos = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPersonaA != NULL && pPersonaB != NULL)
	{
		emp = (Employee*) pPersonaA;
		empDos = (Employee*) pPersonaB;
		if(employee_getSueldo(emp, &sueldo) == 1
		&& employee_getSueldo(empDos, &sueldoDos) == 1)
		{
			if(sueldo > sueldoDos)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
			{
				if(sueldo < sueldoDos)
				{
					retornoXqSinEstoMeDaUnWarning = -1;
				}
			}
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}

int employee_comparaPersonasHoras(void* pPersonaA, void* pPersonaB)
{
	int horas;
	int horasDos;

	Employee* emp = NULL;
	Employee* empDos = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPersonaA != NULL && pPersonaB != NULL)
	{
		emp = (Employee*) pPersonaA;
		empDos = (Employee*) pPersonaB;
		if(employee_getHorasTrabajadas(emp, &horas) == 1
		&& employee_getHorasTrabajadas(empDos, &horasDos) == 1)
		{
			if(horas > horasDos)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
			{
				if(horas < horasDos)
				{
					retornoXqSinEstoMeDaUnWarning = -1;
				}
			}
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}

