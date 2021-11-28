#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "archivos.h"
#include "personas.h"
#include "miBiblioteca.h"


int arch_loadFromText(char* path , LinkedList* pArrayListaPersonas)
{
	int todoOk = 0;
	if(path != NULL && pArrayListaPersonas != NULL)
	{
		FILE* f = fopen(path, "r");
		if(f != NULL)
		{
			arch_parsearPersonaPorTexto(f, pArrayListaPersonas);

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

int arch_ListarPersonas(LinkedList* pArrayListaPersonas)
{

	int todoOk = 0;
	int tam;
	ePersona* persona = NULL;

	if(pArrayListaPersonas != NULL)
	{
		tam = ll_len(pArrayListaPersonas);

		printf("        *** Lista de Personas ***\n");
		printf("-----------------------------------------------------------\n");
		printf("Id\tNombre\t\tSexo  \t \tAltura    \n");
		printf("-----------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			persona = ll_get(pArrayListaPersonas, i);
			if(persona != NULL)
			{
				persona_mostrarPersona(persona);
				todoOk = 1;
			}
		}
	}
	    return todoOk;
}


int arch_parsearPersonaPorTexto(FILE* pFile , LinkedList* pArrayListaPersonas)
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

	ePersona* persona = NULL;

	if(pFile != NULL && pArrayListaPersonas != NULL)
	{
        //fscanf(pFile, "%d,%[^,],%d,%f",&id, nombre, &horas, &sueldo);
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile))
        {
    		fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);

			persona = persona_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

			if(persona != NULL)
			{
				ll_add(pArrayListaPersonas, persona);

				todoOk = 1;
			}
        }
	}
    return todoOk;
}

int arch_addEmployee(LinkedList* pArrayListaPersonas)
{
	int todoOk = 0;

	ePersona* persona;

	int id;
	char nombre[128];
    char sexo;
	float altura;

	int alturaMin = 1.4;
	int alturaMax = 2.5;
	char confirmar;

		if(pArrayListaPersonas != NULL)
		{
			persona = persona_new();
			if(persona != NULL)
			{
				system("cls");
				printf("        *** Alta Persona ***\n");
				printf("        *** Lista de Personas ***\n");
				printf("-----------------------------------------------------------\n");
				printf("Id\tNombre\t\tHoras trabajadas\tSueldo    \n");
				printf("-----------------------------------------------------------\n");

				id = nextId();
				persona_setId(persona, id);

                pedirCadena(nombre, 128, "Ingrese nombre: ", "Error, nombre invalido. Ingrese nombre nuevamente: ");

                printf("Ingrese sexo: ");
                fflush(stdin);
                scanf("%c", &sexo);

                while(sexo != 'f' && sexo != 'm')
                {
                    printf("Error. Reingrese sexo: ");
                    fflush(stdin);
                    scanf("%c", &sexo);
                }

                pedirFlotante(&altura, "Ingrese su altura (1.4 a 2.5): ", "Error. Ingrese su altura (1.4 a 2.5): ", alturaMin, alturaMax);

				persona_setNombre(persona, nombre);
				persona_setSexo(persona, sexo);
				persona_setAltura(persona, altura);

				persona_mostrarPersona(persona);

				pedirCaracter(&confirmar,'s','n', "Confirmar? s/n\n", "Error. Caracter invalido. Confirmar? s/n");
				if(confirmar == 's')
				{
					ll_add(pArrayListaPersonas, persona);
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

int arch_editarPersonas(LinkedList* pArrayListaPersonas)
{
	int todoOk = 0;
	int indice = -3;
	char confirmar = 'n';
	int nombreCambio = 0;

	char auxNombre[128];
	char auxSexo;
	float auxAltura;
	int alturaCambio = 0;
	float alturaMax = 2.5;
	float alturaMin = 1.4;
	int sexoCambio = 0;

	ePersona* persona;

	if(pArrayListaPersonas != NULL)
	{
		while(confirmar == 'n')
		{
			system("cls");
			printf("        *** Modificar Persona ***\n");
			printf("-----------------------------------------------------------\n");

			arch_ListarPersonas(pArrayListaPersonas);

			do
			{
				indice = arch_findPersonaById(pArrayListaPersonas);
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

			printf("Id\tNombre\t\tSexo\tAltura    \n");
			printf("-----------------------------------------------------------\n");

			persona=ll_get(pArrayListaPersonas, indice);
			persona_mostrarPersona(persona);

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
							pedirCadena(auxNombre, 128, "Ingrese nombre: ", "Error, nombre invalido. Ingrese nombre nuevamente: ");

				            strlwr(auxNombre);
				            auxNombre[0] = toupper(auxNombre[0]);

							persona_setNombre(persona, auxNombre);
				            nombreCambio=1;
				            break;
						case 2:
                            pedirFlotante(&auxAltura, "Ingrese su altura (1.4 a 2.5): ", "Error. Ingrese su altura (1.4 a 2.5): ", alturaMin, alturaMax);
							persona_setAltura(persona, auxAltura);
							alturaCambio=1;
						    break;
						case 3:
			                printf("Ingrese sexo: ");
                            fflush(stdin);
                            scanf("%c", &auxSexo);

                            while(auxSexo != 'f' && auxSexo != 'm')
                            {
                                printf("Error. Reingrese sexo: ");
                                fflush(stdin);
                                scanf("%c", &auxSexo);
                            }
                            persona_setSexo(persona, auxSexo);
							sexoCambio=1;
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
			if(alturaCambio)
			{
				printf("Se ha cambiado la altura a: %.2f \n", auxAltura);
			}
			if(sexoCambio)
			{
				printf("Se ha cambiado el sexo a: %c \n", auxSexo);
			}
			if(nombreCambio == 0 && auxAltura == 0 && auxSexo == 0 )
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

int arch_findPersonaById(LinkedList* pArrayListaPersonas)
{
	int todoOk = -1;
	int id;
	int igualar;
	int tam;
	//int buscar;
	char caracter = 'n';

	ePersona* persona;

	if(pArrayListaPersonas != NULL)
	{
		tam = ll_len(pArrayListaPersonas);

		do{
			printf("Ingrese id de la persona: ");
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
				persona = ll_get(pArrayListaPersonas, i);
				persona_getId(persona, &igualar);

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

int arch_bajaPersona(LinkedList* pArrayListaPersonas)
{
	int todoOk = 0;
	int indice = -3;
	char confirmar = 'n';

	ePersona* persona;

	if(pArrayListaPersonas != NULL)
	{
		while(confirmar == 'n')
		{
			system("cls");
			printf("        *** Baja persona ***\n");
			printf("-----------------------------------------------------------\n");

			arch_ListarPersonas(pArrayListaPersonas);

			do
			{
				indice = arch_findPersonaById(pArrayListaPersonas);
			}while(indice < -2);

			if(indice == -2)
			{
				confirmar = 'x';
				break;
			}

			printf("Id\tNombre\t\tSexo\tAltura    \n");
			printf("-----------------------------------------------------------\n");

			persona=ll_get(pArrayListaPersonas, indice);
			persona_mostrarPersona(persona);

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
				ll_remove(pArrayListaPersonas, indice);
				free(persona);
				todoOk = 1;
			}
			else
			{
				printf("Baja cancelada\n");
				todoOk = 1;
			}

		}
	}

	return todoOk;
}

int arch_sortPersonas(LinkedList* pArrayListaPersonas)
{
	int todoOk = 0;
	int tipo;
	int criterio;
	int criterioMin = 0;
	int criterioMax = 1;

	LinkedList* mostrar;

	if(pArrayListaPersonas != NULL)
	{
		system("cls");
		mostrar = ll_clone(pArrayListaPersonas);
		pedirEntero(&criterio, "Ingrese el criterio de ordenamiento (0 descendente, 1 ascendente): ","Error. Criterio invalido.\nReingrese el criterio de ordenamiento (0 ascendente, 1 descendente): ", criterioMin, criterioMax);

		printf("      ***Ordenar por***\n");
		printf("--------------------------------\n");
		printf("1. Nombre\n");
		printf("2. Sexo\n");
		printf("3. Altura\n");
		printf("Ingrese tipo de orden: ");
		scanf("%d", &tipo);

		switch(tipo)
		{
			case 1:
				ll_sort(mostrar, persona_comparaPersonasNombre, criterio);
				arch_ListarPersonas(mostrar);
				break;
			case 2:
				ll_sort(mostrar, persona_comparaPersonasSexo, criterio);
				arch_ListarPersonas(mostrar);
				break;
			case 3:
				ll_sort(mostrar, persona_comparaPersonasAltura, criterio);
				arch_ListarPersonas(mostrar);
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
