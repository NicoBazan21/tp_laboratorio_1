#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "miBiblioteca.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk=0;

	/*
	 typedef struct
	{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
	}Employee;
	*/
	char buffer[4][128];

	Employee* emp;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
        //fscanf(pFile, "%d,%[^,],%d,%f",&id, nombre, &horas, &sueldo);
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile))
        {
    		fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);

			emp = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

			if(emp != NULL)
			{
				ll_add(pArrayListEmployee, emp);

				todoOk = 1;
			}
        }
	}
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk;
		Employee* emp;
		int id;

		if(pFile != NULL && pArrayListEmployee != NULL)
		{
			while(feof(pFile) == 0)
			{
				emp = employee_new();
				fread(emp, sizeof(Employee), 1, pFile);

				if(!feof(pFile))
				{
					ll_add(pArrayListEmployee, emp);
					id = emp->id;
					todoOk = 1;
				}
				else
				{
					break;
				}
			}
			saveNextId(id);
		}
	    return todoOk;
}
