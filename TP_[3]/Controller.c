#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "miBiblioteca.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* f = fopen(path, "r");
		if(f != NULL)
		{
			parser_EmployeeFromText(f, pArrayListEmployee);

			printf("Lista cargada con exito.\n");
			todoOk = 1;
		}
		else
		{
			printf("No se pudo cargar el archivo\n");
		}

		fclose(f);
	}
	return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
		FILE* f;
		if(path != NULL && pArrayListEmployee != NULL)
		{
			f = fopen(path, "rb");
			if(f != NULL)
			{
				parser_EmployeeFromBinary(f, pArrayListEmployee);
				printf("Lista cargada con exito.\n");
				todoOk = 1;
			}
			else
			{
				printf("No se pudo cargar el archivo\n");
			}
		}
		fclose(f);
		return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;

	Employee* empleado;

	int id;
	char nombre[128];
	int horasTrabajadas;
	float sueldo;

	int horasMin = 0;
	int horasMax = 500;
	int sueldoMax = 100000;
	int sueldoMin = 10000;
	char confirmar;

		if(pArrayListEmployee != NULL)
		{
			empleado = employee_new();
			if(empleado != NULL)
			{
				system("cls");
				printf("        *** Alta Empleado ***\n");
				printf("        *** Lista de Empleados ***\n");
				printf("-----------------------------------------------------------\n");
				printf("Id\tNombre\t\tHoras trabajadas\tSueldo    \n");
				printf("-----------------------------------------------------------\n");

				id = nextId();
				employee_setId(empleado, id);

                pedirCadena(nombre, 128, "Ingrese nombre: ", "Error, nombre invalido. Ingrese nombre nuevamente: ");
                pedirEntero(&horasTrabajadas, "Ingrese horas trabajadas: ", "Error. Horas invalidas. Reingrese nuevamente: ", horasMin,horasMax);
                pedirFlotante(&sueldo, "Ingrese su sueldo (10000 a 100000): ", "Error. Ingrese sueldo (10000 a 100000): ", sueldoMin, sueldoMax);

				employee_setNombre(empleado, nombre);
				employee_setHorasTrabajadas(empleado, horasTrabajadas);
				employee_setSueldo(empleado, sueldo);

				employee_mostrarEmpleado(empleado);

				pedirCaracter(&confirmar,'s','n', "Confirmar? s/n\n", "Error. Caracter invalido. Confirmar? s/n");
				if(confirmar == 's')
				{
					ll_add(pArrayListEmployee, empleado);
					printf("Alta exitosa.\n;");
					saveNextId(id);

					todoOk = 1;
				}
				else
				{
					printf("Alta cancelada.\n");
				}
			}
		}
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int indice = -3;
	char confirmar = 'n';
	int nombreCambio = 0;

	char auxNombre[128];
	int auxHoras;
	float auxSueldo;
	int sueldoCambio = 0;
	float sueldoMax = 100000;
	float sueldoMin = 10000;
	int horasMin = 0;
	int horasMax = 500;
	int horasCambio = 0;

	Employee* emp;

	if(pArrayListEmployee != NULL)
	{
		while(confirmar == 'n')
		{
			system("cls");
			printf("        *** Modificar empleado ***\n");
			printf("-----------------------------------------------------------\n");

			controller_ListEmployee(pArrayListEmployee);

			do
			{
				indice = controller_findEmployeeById(pArrayListEmployee);
			}while(indice < -2);

			if(indice == -2)
			{
				confirmar = 'x';
				break;
			}
			if(indice == -2)
			{
				confirmar = 'z';
				break;
			}

			printf("Id\tNombre\t\tHoras trabajadas\tSueldo    \n");
			printf("-----------------------------------------------------------\n");

			emp=ll_get(pArrayListEmployee, indice);
			employee_mostrarEmpleado(emp);

			printf("Desea confirmar? s/n");
			fflush(stdin);
			scanf("%c", &confirmar);

			while(confirmar != 's' && confirmar != 'n')
			{
				printf("Error. Desea confirmar? s/n");
				fflush(stdin);
				scanf("%c", &confirmar);
			}

		}

		if(confirmar != 'x')
		{
			confirmar='n';
			do{
        		system("cls");
				switch(menuModificacion())
				{
						case 1:
							pedirCadena(auxNombre, 51, "Ingrese nombre: ", "Error, nombre invalido. Ingrese nombre nuevamente: ");

				            strlwr(auxNombre);
				            auxNombre[0] = toupper(auxNombre[0]);

							employee_setNombre(emp, auxNombre);
				            nombreCambio=1;
				            break;
						case 2:
			                pedirFlotante(&auxSueldo, "Ingrese su sueldo (10000 a 100000): ", "Error. Ingrese sueldo (10000 a 100000): ", sueldoMin, sueldoMax);
							employee_setSueldo(emp, auxSueldo);
							sueldoCambio=1;
						    break;
						case 3:
			                pedirEntero(&auxHoras, "Ingrese horas trabajadas: ", "Error. Horas invalidas. Reingrese nuevamente: ", horasMin,horasMax);
							employee_setHorasTrabajadas(emp, auxHoras);
							horasCambio=1;
							break;
						case 4:
							printf("Desea salir? s/n");
							fflush(stdin);
							scanf("%c", &confirmar);

							while(confirmar != 's' && confirmar != 'n')
							{
								printf("Error. Desea salir? s/n");
								fflush(stdin);
								scanf("%c", &confirmar);
							}
							break;
						default:
							printf("Opcion invalidaºn");
							break;
				}
			}while(confirmar == 'n');

			if(nombreCambio)
			{
				   printf("Se ha cambiado el nombre a: %s\n", auxNombre);
			}
			if(sueldoCambio)
			{
				printf("Se ha cambiado el sueldo a: %.2f \n", auxSueldo);
			}
			if(horasCambio)
			{
				printf("Se ha cambiado las horas trabajadas a: %d \n", auxHoras);
			}
			if(nombreCambio == 0 && sueldoCambio == 0 && horasCambio == 0 )
			{
				printf("No se cambio ningun dato\n");
			}
		}
		else
		{
			if(confirmar == 'x')
			{
				printf("Modificacion cancelada\n");
			}
			else
			{
				printf("Empelado inexistente\n");
			}
		}
	}

    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int indice = -3;
	char confirmar = 'n';

	Employee* emp;

	if(pArrayListEmployee != NULL)
	{
		while(confirmar == 'n')
		{
			system("cls");
			printf("        *** Baja empleado ***\n");
			printf("-----------------------------------------------------------\n");

			controller_ListEmployee(pArrayListEmployee);

			do
			{
				indice = controller_findEmployeeById(pArrayListEmployee);
			}while(indice < -2);

			if(indice == -2)
			{
				confirmar = 'x';
				break;
			}

			printf("Id\tNombre\t\tHoras trabajadas\tSueldo    \n");
			printf("-----------------------------------------------------------\n");

			emp=ll_get(pArrayListEmployee, indice);
			employee_mostrarEmpleado(emp);

			printf("Desea confirmar la baja? s/n");
			fflush(stdin);
			scanf("%c", &confirmar);

			while(confirmar != 's' && confirmar != 'n')
			{
				printf("Error. Desea confirmar la baja? s/n");
				fflush(stdin);
				scanf("%c", &confirmar);
			}
			if(confirmar == 's')
			{
				ll_remove(pArrayListEmployee, indice);
				free(emp);
				todoOk = 1;
			}
			else
			{
				printf("Baja cancelada\n");
				todoOk = 1;
				break;
			}
		}
	}

	return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

	int todoOk = 0;
	int tam;
	Employee* emp = NULL;

	if(pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);

		printf("        *** Lista de Empleados ***\n");
		printf("-----------------------------------------------------------\n");
		printf("Id\tNombre\t\tHoras trabajadas\tSueldo    \n");
		printf("-----------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			emp = ll_get(pArrayListEmployee, i);
			if(emp != NULL)
			{
				employee_mostrarEmpleado(emp);
				todoOk = 1;
			}
		}
	}
	    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int tipo;
	int criterio;
	int criterioMin = 0;
	int criterioMax = 1;

	LinkedList* mostrar;

	if(pArrayListEmployee != NULL)
	{
		system("cls");
		mostrar = ll_clone(pArrayListEmployee);
		pedirEntero(&criterio, "Ingrese el criterio de ordenamiento (0 descendente, 1 ascendente): ","Error. Criterio invalido.\nReingrese el criterio de ordenamiento (0 ascendente, 1 descendente): ", criterioMin, criterioMax);

		printf("      ***Ordenar por***\n");
		printf("--------------------------------\n");
		printf("1. Nombre\n");
		printf("2. Sueldo\n");
		printf("3. Horas\n");
		printf("Ingrese tipo de orden: ");
		scanf("%d", &tipo);

		switch(tipo)
		{
			case 1:
				ll_sort(mostrar, employee_comparaPersonas, criterio);
				controller_ListEmployee(mostrar);
				break;
			case 2:
				ll_sort(mostrar, employee_comparaPersonasSueldo, criterio);
				controller_ListEmployee(mostrar);
				break;
			case 3:
				ll_sort(mostrar, employee_comparaPersonasHoras, criterio);
				controller_ListEmployee(mostrar);
				break;
			default:
				printf("Opcion invalida\n");
				break;
		}

		ll_deleteLinkedList(mostrar);
		todoOk = 1;
	}
	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk;

	int id;
	char nombre[128];
	float sueldo;
	int horasTrabajadas;

	Employee* emp;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		FILE* f = fopen(path, "w");

		emp = employee_new();

		fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			emp = ll_get(pArrayListEmployee, i);

			if(emp != NULL)
			{
				employee_getId(emp, &id);
				employee_getNombre(emp, nombre);
				employee_getSueldo(emp, &sueldo);
				employee_getHorasTrabajadas(emp, &horasTrabajadas);

				fprintf(f, "%d,%s,%d,%.2f\n", id, nombre, horasTrabajadas, sueldo);

				todoOk = 1;
			}
			else
			{
				todoOk = 0;
				break;
			}
		}
		fclose(f);
	}
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
		FILE* f;
		Employee* nuevoEmpleado;

		if(path != NULL && pArrayListEmployee != NULL)
		{
			f = fopen(path, "wb");

			nuevoEmpleado = employee_new();

			if(nuevoEmpleado != NULL)
			{
				for(int i = 0; i < ll_len(pArrayListEmployee); i++)
				{
					nuevoEmpleado = ll_get(pArrayListEmployee, i);
					fwrite(nuevoEmpleado, sizeof(Employee), 1, f);
				}
				todoOk = 1;
			}
			fclose(f);
		}
	    return todoOk;
}

int controller_findEmployeeById(LinkedList* pArrayListEmployee)
{
	int todoOk = -1;
	int id;
	int igualar;
	int tam;
	//int buscar;
	char caracter = 'n';

	Employee* emp;

	if(pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);

		do{
			printf("Ingrese id del empleado: ");
			fflush(stdin);
			scanf("%d", &id);

			while(id < 0)
			{
				printf("Id invalida. Desea cancelar la operacion? s/n");
				fflush(stdin);
				scanf("%c", &caracter);

				while(caracter != 's' && caracter != 'n')
				{
					printf("Caracter invalido. Desea cancelar la operacion? s/n");
					fflush(stdin);
					scanf("%c", &caracter);
				}

				if(caracter == 's')
				{
					todoOk=-2;
					break;
				}

				printf("Reingrese id: ");
				fflush(stdin);
				scanf("%d", &id);
			}

			for(int i = 0; i < tam; i++)
			{
				emp = ll_get(pArrayListEmployee, i);
				employee_getId(emp, &igualar);

				if(id == igualar)
				{
					todoOk = i;
					break;
				}
				else
				{
					todoOk=-3;
				}
			}
		}while(todoOk == -1);
	}

	return todoOk;
}

