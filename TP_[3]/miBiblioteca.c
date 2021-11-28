/*
 * miBiblioteca.c
 *
 *  Created on: 15 nov. 2021
 *      Author: Bazan
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
    int opcion;

    system("cls");
    printf("          *** Menu de Empleados ***\n");
    printf("------------------------------------------------------------\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf(" 3. Alta de empleado.\n");
    printf(" 4. Modificar datos de empleado.\n");
    printf(" 5. Baja de empleado.\n");
    printf(" 6. Listar empleados.\n");
    printf(" 7. Ordenar empleados.\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf(" 10. Salir .\n");

    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int validarNumCadenas(char* name, int tam)
{
    int okey;
    int error = 0;

    if(name != NULL && tam > 0)
    {
            error=0;
            for(int i = 0; i < tam; i++)
            {
                okey = isalpha(name[i]);
                if(okey == 0)
                {
                    error = 1;
                }
            }

    }
    return error;
}
int pedirCadena(char cadena[], int tam, char mensajeUno[], char mensajeError[])
{
    int todoOk =0;
    char entrada[256];
    int tamEntrada;
    int error;

    if(cadena != NULL && tam > 0 && mensajeUno != NULL && mensajeError != NULL)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        gets(entrada);
        tamEntrada = strlen(entrada);

        error=validarNumCadenas(entrada, tamEntrada);

        while(tamEntrada > tam || tamEntrada <= 2 || error == 1)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            gets(entrada);
            tamEntrada=strlen(entrada);
            error=validarNumCadenas(entrada, tamEntrada);
        }


        strcpy(cadena, entrada);
        todoOk=1;
    }

    return todoOk;
}

int pedirFlotante(float* numero, char mensajeUno[], char mensajeError[], float min, float max)
{
    int todoOk =0;

    if(numero != NULL && mensajeError != NULL && mensajeUno != NULL && min < max)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%f", numero);

        while(*numero < min || *numero > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%f", numero);
        }

        todoOk=1;
    }


    return todoOk;
}

int pedirEntero(int *numero, char mensajeUno[], char mensajeError[], int min, int max)
{
    int todoOk=0;

    if(numero != NULL && mensajeError != NULL && mensajeUno != NULL && min < max)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%d", numero);

        while(*numero < min || *numero > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", numero);
        }

    todoOk=1;
    }

    return todoOk;
}

int pedirCaracter(char* caracter,char x, char y, char mensajeUno[], char mensajeError[])
{
    int todoOk = 0;
    char caracIng;

    if(caracter != NULL && mensajeError != NULL && mensajeUno != NULL)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%c", &caracIng);

        todoOk=1;

        while(caracIng != x && caracIng != y)
        {
        	printf("%s", mensajeError);
            fflush(stdin);
            scanf("%c", &caracIng);
        }
        *caracter=caracIng;
    }
    return todoOk;
}


int nextId()
{
	FILE* f=fopen("ultimoID.txt", "r");
	int* iD=(int*) malloc(sizeof(int));
	int nextId;

	if(f==NULL)
	{
		nextId=1001;
	}
	else
	{
		fscanf(f, "%d", iD);
		nextId=*iD+1;
	}
	fclose(f);

 return nextId;
}


void saveNextId(int iD)
{
	FILE* f=fopen("ultimoID.txt", "r+");

	    if(f==NULL)
	    {
	        f=fopen("ultimoID.txt", "w");
	    }

	    fprintf(f,"%d", iD);
	    fclose(f);
}


int menuModificacion()
{
    int opcion;
    int opcionMin = 1;
    int opcionMax= 4;

    printf("\t *** Modificacion de datos ***\n");
    printf("------------------------------------\n");

    printf("1. Modificar Nombre\n");
    printf("2. Modificar Salario\n");
    printf("3. Modificar Horas Trabajadas\n");
    printf("4. Salir \n");

    pedirEntero(&opcion, "Ingrese opcion: ", "Opcion invalida. Ingrese la opcion: ", opcionMin,opcionMax);
    printf("\n");
    fflush(stdin);

    return opcion;
}

