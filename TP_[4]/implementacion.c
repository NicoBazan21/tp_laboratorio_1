#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "linkedList.h"
#include "personas.h"
#include "archivos.h"
#include "miBiblioteca.h"

int funcion_ll_len(LinkedList* listaPersonas)
{
    int todoOk = 0;
    int len;

    if(listaPersonas != NULL)
    {
        printf("Se obtendra el tamanio de la linkedList cargada\n");
        len=ll_len(listaPersonas);
        printf("El tamanio de la nueva LinkedList es: %d\n", len);
    }
    return todoOk;
}

int funcion_ll_get(LinkedList* listaPersonas)
{
    int todoOk = 0;
    int lenMin=0;
    int len;
    int lenIngresado;

    if(listaPersonas != NULL)
    {
        printf("Se obtendra un nodo a eleccion (getNode) y se lo mostrara posteriormente. \n");
        arch_ListarPersonas(listaPersonas);//ll_len, ll_get
        len=ll_len(listaPersonas);
        pedirEntero(&lenIngresado, "Ingrese el numero de id del elemento que quiere obtener (tener en cuenta que se muestra Nodo = id - 1) ","Numero fuera de rango. Reingrese el numero (id=pElement)",lenMin,len);
        printf("Id ingresado: %d\nPosicion del Nodo: %d\n",lenIngresado, lenIngresado-1);

        ePersona* mostrar;
        mostrar =ll_get(listaPersonas, lenIngresado-1);
        persona_mostrarPersona(mostrar);
        printf("\n");
    }
    return todoOk;
}

int funcion_ll_push(LinkedList* listaPersonas)
{
    int todoOk = 0;
    int lenMin = 0;
    int len;
    int lenIngresado;

    int deseoMin = 1;
    int deseo;
    int deseoMax=2;
    int id;

	char nombre[128];
    char sexo;
	float altura;

	float alturaMin = 1.4;
	float alturaMax = 2.5;
	char confirmar;

    if(listaPersonas != NULL)
    {
        todoOk=1;
        arch_ListarPersonas(listaPersonas);//ll_len, ll_get

        len=ll_len(listaPersonas);
        printf("\nTamanio actual de la lista: %d\n",len);

        pedirEntero(&lenIngresado, "Ingrese el numero del pElement en el que quiera agregar o enlazar un vagon (id=pElement)","Numero fuera de rango. Reingrese el numero (id=pElement)",lenMin,len);

        pedirEntero(&deseo, "Que desea hacer?: \n1. Agregar un vagon en blanco\n2. Agregar un vagon introduciendo previamente datos\n", "Error. Numero invalido. \n 1. Agregar un vagon en blanco\n2. Agregar un vagon introduciendo previamente datos: ", deseoMin, deseoMax);

        if(deseo == 1)
        {
            printf("Se aniadira un vagon vacio previamente inicializado en valores sin definicion\n");
            ePersona* pElementNuevo = persona_new();
            id = nextId();
            saveNextId(id);
            pElementNuevo->id=id;
            ll_push(listaPersonas, lenIngresado, pElementNuevo);
        }
        else if(deseo == 2)
        {
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

                id = nextId();

                ePersona* pElementNuevo;
                pElementNuevo=new_personaParam(id,nombre,altura,sexo);

                pedirCaracter(&confirmar,'s','n', "Confirmar? s/n\n", "Error. Caracter invalido. Confirmar? s/n");
				if(confirmar == 's')
				{
					ll_push(listaPersonas, lenIngresado, pElementNuevo);
					printf("ll_push exitoso.\n;");
					saveNextId(id);

					todoOk = 1;
				}
				else
				{
					printf("ll_push cancelado.\n");
				}
                saveNextId(id);
        }
    }
    return todoOk;
}

int funcion_ll_addNode(LinkedList* listaPersonas)
{
    int todoOk = 0;
    int len;
    int lenIngresado;

    int deseoMin = 1;
    int deseo;
    int deseoMax=2;
    int id;

	char nombre[128];
    char sexo;
	float altura;

	float alturaMin = 1.4;
	float alturaMax = 2.5;
	char confirmar;


    if(listaPersonas != NULL)
    {
        todoOk=1;
        arch_ListarPersonas(listaPersonas);//ll_len, ll_get

        len=ll_len(listaPersonas);
        printf("\nTamanio actual de la lista: %d\n",len);

        printf("addNode:  se enlazara un nuevo nodo al final de la lista\n");

        pedirEntero(&deseo, "Que desea hacer?: \n1. Agregar un vagon en blanco\n2. Agregar un vagon introduciendo previamente datos\n", "Error. Numero invalido. \n 1. Agregar un vagon en blanco\n2. Agregar un vagon introduciendo previamente datos: ", deseoMin, deseoMax);

        if(len>0)
        {
            lenIngresado=len;
        }
        else
        {
            lenIngresado=0;
        }

        if(deseo == 1)
        {
            printf("Se aniadira un vagon vacio previamente inicializado en valores sin definicion\n");
            ePersona* pElementNuevo = persona_new();
            id = nextId();
            saveNextId(id);
            pElementNuevo->id=id;
            addNode(listaPersonas, lenIngresado, pElementNuevo);
        }
        else
        {
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

                id = nextId();

                ePersona* pElementNuevo;
                pElementNuevo=new_personaParam(id,nombre,altura,sexo);

                pedirCaracter(&confirmar,'s','n', "Confirmar? s/n\n", "Error. Caracter invalido. Confirmar? s/n");
				if(confirmar == 's')
				{
					addNode(listaPersonas, lenIngresado, pElementNuevo);
					printf("nodo aniadido exitosamente.\n;");
					saveNextId(id);

					todoOk = 1;
				}
				else
				{
					printf("nodo cancelado.\n");
				}
                saveNextId(id);
        }


    }
    return todoOk;
}
int funcion_ll_add(LinkedList* listaPersonas)
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

		if(listaPersonas != NULL)
		{
			persona = persona_new();
			if(persona != NULL)
			{
				system("cls");
				printf("        *** Alta Persona ***\n");
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
					ll_add(listaPersonas, persona);
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

int funcion_ll_set(LinkedList* listaPersonas)
{
    int todoOk = 0;
    int len;

    int deseoMin = 1;
    int deseo;

    if(listaPersonas != NULL)
    {
        todoOk=1;
        arch_ListarPersonas(listaPersonas);//ll_len, ll_get
        ePersona* set;

        len=ll_len(listaPersonas);
        printf("\nTamanio actual de la lista: %d\n",len);

        printf("ll_set: pedira un elemento de la lista para setearlo sobre el pElement de un vagon ingresado por el usuario\n");

        pedirEntero(&deseo, "Ingrese un elemento de la lista: ", "Error. Numero invalido. \n Ingrese un elemento de la lista: ", deseoMin, len);

        deseo--;
        set=ll_get(listaPersonas, deseo);
        persona_mostrarPersona(set);

        pedirEntero(&deseo, "Ingrese el lugar de la lista para setear el elemento seleccionado: ", "Error. Ingrese el lugar de la lista para setear el elemento seleccionado: ", deseoMin, len);
        deseo--;
        ll_set(listaPersonas, deseo, set);
        arch_ListarPersonas(listaPersonas);//ll_len, ll_get
    }

    return todoOk;
}

int funcion_ll_remove(LinkedList* listaPersona)
{
    int todoOk = 0;
	int indice = -3;
	char confirmar = 'n';

	ePersona* persona;

	if(listaPersona != NULL)
	{
		while(confirmar == 'n')
		{
		    todoOk=1;
            printf("ll_remove eliminara un elemento de la lista ingresado por el usuario\n");

			arch_ListarPersonas(listaPersona);

			do
			{
				indice = arch_findPersonaById(listaPersona);
			}while(indice < -2);

			if(indice == -2)
			{
				confirmar = 'x';
				break;
			}

			printf("Id\tNombre\t\tSexo\tAltura    \n");
			printf("-----------------------------------------------------------\n");

			persona=ll_get(listaPersona, indice);
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
				ll_remove(listaPersona, indice);
				free(persona);
				todoOk = 1;
			}
			else
			{
				printf("ll_remove cancelado\n");
				todoOk = 1;
			}

		}
	}

	return todoOk;
}

int funcion_ll_clear(LinkedList* listaPersonas)
{
    int todoOk=0;

    if(listaPersonas != NULL)
    {
        arch_ListarPersonas(listaPersonas);
        printf("ll_clear limpiara toda la lista creada anteriormente.\nPara luego seguir con las pruebas se pide que ingrese posteriormente la opcion \"Crear Linkedlist\" nuevamente.\n");
        ll_clear(listaPersonas);
    }

    return todoOk;
}

int funcion_ll_deleteLinkedList(LinkedList* listaPersonas)
{
    int todoOk=0;

    if(listaPersonas != NULL)
    {
        printf("ll_clear eliminara la LinkedList \nPara luego seguir con las pruebas se pide que ingrese posteriormente la opcion \"Crear Linkedlist\" nuevamente.\n");
        ll_deleteLinkedList(listaPersonas);
    }

    return todoOk;
}

int funcion_ll_indexOf(LinkedList* listaPersonas)
{
    int todoOk=0;
    int vagon;
    int len;
    int deseo;
    int deseoMin = 0;

    if(listaPersonas!=NULL)
    {
        todoOk=1;
        arch_ListarPersonas(listaPersonas);//ll_len, ll_get
        ePersona* set;

        len=ll_len(listaPersonas);
        printf("\nTamanio actual de la lista: %d\n",len);

        printf("Se pedira un elemento de la lista.\nll_indexOf buscara el pElement del elemento ingresado sobre la lista y devolvera su numero de vagon\n");

        pedirEntero(&deseo, "Ingrese un elemento de la lista: ", "Error. Numero invalido. \n Ingrese un elemento de la lista: ", deseoMin, len);

        deseo--;
        set=ll_get(listaPersonas, deseo);
        persona_mostrarPersona(set);

        //pedirEntero(&deseo, "Ingrese el lugar de la lista para setear el elemento seleccionado: ", "Error. Ingrese el lugar de la lista para setear el elemento seleccionado: ", deseoMin, len);
        vagon=ll_indexOf(listaPersonas, set);
        if(vagon != -1)
        {
            printf("El elemento encontrado por IndexOf esta en el vagon: %d\n", vagon);
        }
        else
        {
            printf("No se encontro el elemento\n");
        }
        //arch_ListarPersonas(listaPersonas);//ll_len, ll_get
    }

    return todoOk;
}

int funcion_ll_isEmpty(LinkedList* listaPersonas)
{
    int todoOk = 0;
    int resultado;

        resultado=ll_isEmpty(listaPersonas);

        switch(resultado)
        {
            case 1:
                printf("Lista vacia\n");
                break;
            default:
                printf("Lista con valor NULL\n");
                break;
            case 0:
                printf("Lista ocupada\n");
                break;
        }
    return todoOk;
}

int funcion_ll_pop(LinkedList* listaPersonas)
{
    int todoOk=0;
    int len;
    int deseoMin =0;
    int deseo;

    if(listaPersonas != NULL)
    {
        todoOk=1;
        arch_ListarPersonas(listaPersonas);//ll_len, ll_get

        len=ll_len(listaPersonas);
        printf("\nTamanio actual de la lista: %d\n",len);

        printf("Se pedira un elemento de la lista.\nll_pop eliminara el elemento de la lista\nY devolvera su puntero. Con este se lo puede agregar a otra lista o a la misma\n");

        pedirEntero(&deseo, "Ingrese un elemento de la lista: ", "Error. Numero invalido. \n Ingrese un elemento de la lista: ", deseoMin, len);
        deseo--;

        ePersona* puntero;
        puntero=ll_pop(listaPersonas, deseo);

        printf("Elemento eliminado\n");
        persona_mostrarPersona(puntero);

        arch_ListarPersonas(listaPersonas);

    }
    return todoOk;
}

int funcion_ll_contains(LinkedList* listaPersonas, LinkedList* listaPersonasDos)
{
    int todoOk=0;
    int len;
    int deseoMin =0;
    int deseo;
    int respuesta;

    ePersona* copia;

    if(listaPersonas != NULL)
    {
        copia=ll_get(listaPersonas, 0);
        ll_set(listaPersonasDos, 0, copia);
        copia=ll_get(listaPersonas, 3);
        ll_set(listaPersonasDos, 3, copia);


        todoOk=1;
        printf("Primer lista:\n");
        arch_ListarPersonas(listaPersonas);//ll_len, ll_get
        printf("Segunda lista:\n");
        arch_ListarPersonas(listaPersonasDos);//ll_len, ll_get
        ePersona* set;

        len=ll_len(listaPersonasDos);
        printf("\nTamanio actual de la Segunda lista: %d\n",len);

        printf("Se pedira un elemento de la segunda lista.\nll_contains verificara si el elemento pertenece a la primer lista\n");

        printf("ll_contains solo sirve si dos LinkedList distintos apuntan al mismo elemento (misma direccion de memoria).\n");

        pedirEntero(&deseo, "Ingrese un elemento de la segunda lista: ", "Error. Numero invalido. \n Ingrese un elemento de la lista: ", deseoMin, len);
        deseo--;

        set=ll_get(listaPersonasDos, deseo);

        respuesta=ll_contains(listaPersonas, set);

        switch(respuesta)
        {
            case 1:
                printf("EXITO: Contiene el elemento\n");
                break;
            case 0:
                printf("FRACASO: No contiene el elemento\n");
                break;
            default:
                printf("ERROR: Puntero nulo\n");
                break;
        }

        arch_ListarPersonas(listaPersonas);

    }
    return todoOk;
}

int funcion_igualadora(LinkedList* listaUno, LinkedList* listaDos)
{
    int todoOk=0;
    int tam;

    if(listaUno != NULL && listaDos != NULL)
    {
        todoOk=1;
        tam = ll_len(listaUno);
        ePersona* copiar;

        for(int i = 0; i<tam;i++)
        {
            copiar=ll_get(listaUno,i);
            ll_set(listaDos,i,copiar);
        }

    }

    return todoOk;
}

int funcion_ll_containsAll(LinkedList* listaUno, LinkedList* listaDos)
{
    int todoOk=0;
    int resultado;
    if(listaUno != NULL && listaDos != NULL)
    {
        todoOk=1;
        printf("ll_containsAll verificara si toda la lista uno pertenece a la lista dos");

        printf("Primer lista:\n");
        arch_ListarPersonas(listaUno);//ll_len, ll_get
        printf("Segunda lista:\n");
        arch_ListarPersonas(listaDos);//ll_len, ll_get

        resultado=ll_containsAll(listaDos, listaUno);

        switch(resultado)
        {
            case 1:
                printf("EXITO: los contiene todos\n");
                break;
            case 0:
                printf("FRACASO: no los contiene a todos\n");
                break;
            default:
                printf("ERROR. valores nulos");
                break;
        }
    }
    return todoOk;
}

int funcion_ll_subList(LinkedList* listaPersonas)
{
    int todoOk=0;
    int len;
    int deseo;
    int deseoDos;
    int deseoMin=1;

    if(listaPersonas != NULL)
    {
        printf("ll_subList creara una nueva lista con los elementos de la lista mostrada hasta el elemento que\n el usuario decida\n");

        len=ll_len(listaPersonas);
        arch_ListarPersonas(listaPersonas);

        pedirEntero(&deseo, "Ingrese un elemento de la lista: ", "Error. Numero invalido. \n Ingrese un elemento de la lista: ", deseoMin, len);
        deseo--;

        pedirEntero(&deseoDos, "Ingrese un elemento de la lista hasta donde quiera copiar: ", "Error. Numero invalido. \n Ingrese un elemento de la lista hasta donde quiera copiar: ", deseoMin, len);
        //deseoDos--;

        LinkedList* retorno;

        retorno=ll_subList(listaPersonas, deseo, deseoDos);

        printf("Lista creada por ll_subList\n");
        arch_ListarPersonas(retorno);

    }
    return todoOk;
}

int funcion_ll_clone(LinkedList* listaPersonas)
{
    int todoOk=0;

    if(listaPersonas != NULL)
    {
        printf("ll_clone devuelve una lista copiada enteramente usando la funcion ll_sublist hasta el ll_len de esta\n");
        printf("Lista original\n");
        arch_ListarPersonas(listaPersonas);

        LinkedList* copia;

        copia=ll_clone(listaPersonas);

        if(copia != NULL)
        {
            printf("Lista copiada mediante ll_clone\n");
            arch_ListarPersonas(copia);
            todoOk=1;
        }

    }

    return todoOk;
}

int funcion_ll_sort(LinkedList* listaPersonas)
{
    int todoOk=0;
    int tipo;
	int criterio;
	int criterioMin = 0;
	int criterioMax = 1;

	LinkedList* mostrar;

    if(listaPersonas != NULL)
    {
        system("cls");
        printf("ll_sort recibira una funcion con criterio de orden. ll_sort utilizara la funcion pasada como referencia\n");
        printf("yendo a la ubicacion de memoria de la funcion, ejecutarla y retornar solamente los elementos validos\n");
        printf("ll_sort se clona a la linkedList recibida y efectua un burbujeo utilizando el retorno de la funcion ordenadora\n");
		mostrar = ll_clone(listaPersonas);
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
