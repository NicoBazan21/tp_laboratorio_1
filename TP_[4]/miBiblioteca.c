#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"

int menu()
{
    int opcion;

    system("cls");
    printf("          *** Menu de personas ***\n");
    printf("------------------------------------------------------------\n");
    printf(" 1. Crear LinkedList (ll_newLinkedList).\n");
    printf(" 2. Obtener tamanio del LinkedList (ll_len)\n");
    printf(" 3. Obtener un nodo del linkedList (ll_get).\n");
    printf(" 4. Agregar un elemento a la lista mediante ll_push\n");
    printf(" 5. Agregar una persona al LinkedList (ll_add)\n");
    printf(" 6. Set de un elemento de la lista sobre otro (ll_set)\n");
    printf(" 7. Elimina un elemento de la lista (ll_remove)\n");
    printf(" 8. Elimina todos los elementos de la lista (ll_clear)\n");
    printf(" 9. Elimina la LinkedList(ll_deleteLinkedList)\n");
    printf(" 10. Busca un elemento sobre la lista (ll_indexOf)\n");
    printf(" 11. Confirma si la lista esta vacia (ll_isEmpty)\n");
    printf(" 12. Elimina un elemento de la lista y devuelve su puntero (ll_pop)\n");
    printf(" 13. Confirma si un elemento de una lista pertenece a otra lista (ll_contains)\n");
    printf(" 14. Confirma si toda una lista pertenece a otra lista (ll_containsAll)\n");
    printf(" 15. Crear una lista hasta el elemento ingresado (ll_sublist)\n");
    printf(" 16. Clona una lista y retorna una nueva igual(ll_clone)\n");
    printf(" 17. Ordena lista segun funciones (ll_sort)\n");
    printf(" 20. Menu personas\n");
    printf(" 21. Salir\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuDos()
{
    int opcion;

    system("cls");
    printf("          *** Menu de personas ***\n");
    printf("------------------------------------------------------------\n");
    printf(" 1. Cargar los datos de las personas desde el archivo data.csv (modo texto).\n");
    printf(" 2. Alta de personas.\n");
    printf(" 3. Modificar datos de personas.\n");
    printf(" 4. Baja de personas.\n");
    printf(" 5. Listar personas.\n");
    printf(" 6. Ordenar personas.\n");
    printf(" 10. Volver al menu anterior.\n");

    printf("Ingrese opcion: ");
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

        while(tamEntrada > tam || tamEntrada <= 3 || error == 1)
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
    printf("2. Modificar Altura\n");
    printf("3. Modificar Sexo\n");
    printf("4. Salir \n");

    pedirEntero(&opcion, "Ingrese opcion: ", "Opcion invalida. Ingrese la opcion: ", opcionMin,opcionMax);
    printf("\n");
    fflush(stdin);

    return opcion;
}

