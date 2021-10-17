/*
 * ArrayEmployees.c
 *
 *  Created on: 16 oct 2021
 *      Author: Bazan
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include <ctype.h>




int menu()
{
    int opcion;
    int opcionMin = 1;
    int opcionMax = 5;

    system("cls");
    printf("\t ***Nomina de empleados***\n");
    printf("------------------------------------\n");
    printf(" 1. ALTAS\n");
    printf(" 2. MODIFICAR\n");
    printf(" 3. BAJA\n");
    printf(" 4. INFORMAR\n");
    printf(" 5. Salir\n");

    pedirEntero(&opcion, "Ingrese opcion: ", "Opcion invalida. Ingrese la opcion: ", opcionMin,opcionMax);
    printf("\n");
    fflush(stdin);

    return opcion;
}

void mostrarPersona(eEmployee hola)
{
    printf("  %d %13s\t%10s\t %.2f\t %d \n",
            hola.id,
            hola.name,
            hola.lastName,
            hola.salary,
            hola.sector);

}

int sortEmployees(eEmployee list[], int len, int order)
{
    int todoOk=0;

    int holis=0;

    eEmployee auxiliar;

    if(list != NULL && len >0)
    {
        system("cls");
        printf("\t ***Listado de personas***\n");
        printf("----------------------------------------------------------------------\n");
        printf("  Id\t    Nombre\tApellido\t Salario\t Sector\t\n");
        printf("----------------------------------------------------------------------\n");

        for(int i=0;i<len-1;i++)
        {
            for(int j = i+1; j < len; j++)
            {
                if(order==1 &&
                ((strcmp(list[i].lastName, list[j].lastName)>0) ||
                ((strcmp(list[i].lastName, list[j].lastName)==0) && (list[i].sector>list[j].sector))))
                {
                    auxiliar=list[i];
                    list[i]=list[j];
                    list[j]=auxiliar;
                }
                else
                {
                if(order==2 &&
                ((strcmp(list[i].lastName, list[j].lastName)<0) ||
                ((strcmp(list[i].lastName, list[j].lastName)==0) && (list[i].sector<list[j].sector))))
                    {
                        auxiliar=list[i];
                        list[i]=list[j];
                        list[j]=auxiliar;
                    }
                }
            }
        }
        for(int h = 0; h < len; h++)
        {
            if(list[h].isEmpty == 0)
            {
                mostrarPersona(list[h]);
                holis=1;
            }
        }
        if(!holis)
        {
            printf("No hay personas para mostrar.\n");
        }
        printf("\n\n");

        todoOk=1;
    }
    return todoOk;
}

int initEmployees(eEmployee list[], int len)
{
    int todoOk = 0;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i<len;i++)
        {
            list[i].isEmpty=1;//esto significa que esta vacío
        }
        todoOk=1;
    }

    return todoOk;
}


int validarNumCadenas(char* name, int tam)
{
    int todoOk= 0;
    int okey;
    int error = 1;

    if(name != NULL && tam > 0)
    {
        do{
            error=0;
            for(int i = 0; i < tam; i++)
            {
                okey = isalpha(name[i]);
                if(okey == 0)
                {
                    printf("Error. Ingreso con caracteres invalidos. Ingrese nuevamente: ");
                    gets(name);
                    tam=strlen(name);
                    error = 1;
                }
            }

        }while(error == 1);

        todoOk=1;
    }
    return todoOk;
}

int pedirCadena(char cadena[], int tam, char mensajeUno[], char mensajeError[])
{
    int todoOk =0;
    char entrada[256];
    int tamEntrada;

    if(cadena != NULL && tam > 0 && mensajeUno != NULL && mensajeError != NULL)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        gets(entrada);
        tamEntrada = strlen(entrada);

        validarNumCadenas(entrada, tamEntrada);

        while(tamEntrada > tam || tamEntrada < 1)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            gets(entrada);
            tamEntrada=strlen(entrada);
        }

        strcpy(cadena, entrada);
        todoOk=1;
    }

    return todoOk;
}


int pedirCaracter(char *caracter, char mensajeUno[], char mensajeError[], char si)
{
    int todoOk = 0;

    if(caracter != NULL && mensajeError != NULL && mensajeUno != NULL)
    {
        printf("%s", mensajeUno);
        fflush(stdin);
        scanf("%c", caracter);

        if(*caracter != si)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%c", caracter);
        }
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

int buscarLibre(eEmployee lista[], int tam)
{
    int libre = -1;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty)
            {
                libre=i;
                break;
            }
        }
    }
    return libre;
}


int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int todoOk = -1;
    int libre;



    if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && salary > 0 && sector > 0)
    {
        libre = buscarLibre(list, len);
        todoOk=1;


        strlwr(name);
        name[0] = toupper(name[0]);

        strlwr(lastName);
        lastName[0] = toupper(lastName[0]);

        //no valido el buscar libre, porque ya antes pasó en el main por una validacion
            list[libre].id=id;
            strcpy(list[libre].name, name);
            strcpy(list[libre].lastName, lastName);
            list[libre].salary=salary;
            list[libre].sector=sector;
            list[libre].isEmpty=0;

    }

    return todoOk;
}

int findEmployeeById(eEmployee* list, int len,int iDe)
{
    int indice = -1;

    if(list != NULL && len > 0 && (iDe > 0 && iDe <= len))
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == iDe && list[i].isEmpty == 0)
            {
                indice=i;
                break;
            }
        }
    }
        if(indice == -1)
        {
            printf("No existe el empleado. \n");
        }
    return indice;
}

int removeEmployee(eEmployee* list, int len, int id)
{
    int todoOk = -1;
    int indice;

    if(list != NULL && len > 0 && id > -1)
    {
        indice=findEmployeeById(list, len, id);

        list[indice].isEmpty=1;

        todoOk=0;
    }

    return todoOk;
}

int menuModificacion()
{
    int opcion;
    int opcionMin = 1;
    int opcionMax= 5;

    printf("\t *** Modificacion de datos ***\n");
    printf("------------------------------------\n");

    printf("1. Modificar Nombre\n");
    printf("2. Modificar Apellido\n");
    printf("3. Modificar Salario\n");
    printf("4. Modificar Sector\n");
    printf("5. Salir \n");

    pedirEntero(&opcion, "Ingrese opcion: ", "Opcion invalida. Ingrese la opcion: ", opcionMin,opcionMax);
    printf("\n");
    fflush(stdin);

    return opcion;
}

int printEmployees(eEmployee* list, int len)
{
    int todoOk=0;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("\t ***Listado de personas***\n");
        printf("-----------------------------------------------------\n");
        printf("  Id\t    Nombre\tApellido\t Salario\t Sector\t\n");
        printf("-----------------------------------------------------\n");

        for(int h = 0; h < len; h++)
        {
            if(list[h].isEmpty == 0)
            {
                mostrarPersona(list[h]);
            }
        }
    }

    return todoOk;
}

int modificarPersona(eEmployee lista[], int tam)
{
    int todoOk=0;
    int indice;
    int buscarId;
    char confirmar;
    char auxNombre[51];
    int nombreCambio = 0;
    char auxApellido[51];
    int apellidoCambio = 0;
    float auxSalario;
    int salarioCambio = 0;
    int auxSector;
    int sectorCambio = 0;

    char seguir = 'n';

    if(lista != NULL && tam > 0)
    {
        printEmployees(lista, tam);

        printf("\n");
        printf("     ***  Menu Modificar  ***\n\n");

        pedirEntero(&buscarId, "Ingrese el id: ", "Error. Id Invalido. Ingrese id nuevamente: ", 0, 1000);
        indice=findEmployeeById(lista, tam, buscarId);
        printf("\n");

        if(indice == -1)
        {
            printf("No existe esta persona. \n");
        }
        else
        {
            printf("Nombre completo del id ingresado: %s %s\n", lista[indice].name, lista[indice].lastName);
            pedirCaracter(&confirmar, "\nDesea modificarlo? s/n", "Cancelando...", 's');

            if(confirmar=='s')
            {
                do{
                    system("cls");
                    switch(menuModificacion())
                    {
                        case 1:
                            pedirCadena(auxNombre, 51, "Ingrese nombre: ", "Error, nombre invalido. Ingrese nombre nuevamente: ");

                            strlwr(auxNombre);
                            auxNombre[0] = toupper(auxNombre[0]);

                            strcpy(lista[indice].name, auxNombre);
                            nombreCambio=1;
                            break;
                        case 2:
                            pedirCadena(auxApellido, 51, "Ingrese apellido: ", "Error, apellido invalido. Ingrese apellido nuevamente: ");

                            strlwr(auxApellido);
                            auxApellido[0] = toupper(auxApellido[0]);

                            strcpy(lista[indice].lastName, auxApellido);
                            apellidoCambio = 1;
                            break;
                        case 3:
                            pedirFlotante(&auxSalario, "Ingrese salario(10000 y 50000): ", "Salario invalido (10000 y 50000): ", 10000,50000);
                            lista[indice].salary=auxSalario;
                            salarioCambio=1;
                            break;
                        case 4:
                            pedirEntero(&auxSector, "Ingrese sector (1 al 10): ", "Sector invalido (1 al 10): ", 1,10);
                            lista[indice].sector=auxSector;
                            sectorCambio=1;
                            break;
                        case 5:
                            pedirCaracter(&seguir, "Desea salir? s/n", "Error. Desea salir? s/n?", 's');
                            break;
                        default:
                            printf("Opcion invalida\n");
                            break;
                    }
                    system("pause");
                }while(seguir == 'n');
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la modificacion. \n");
            }
            if(nombreCambio)
            {
                printf("Se ha cambiado el nombre a: %s\n", lista[indice].name);
            }
            if(apellidoCambio)
            {
                printf("Se ha cambiado el apellido a: %s \n", lista[indice].lastName);

            }
            if(salarioCambio)
            {
                printf("Se ha cambiado el salario a: %.2f \n", lista[indice].salary);

            }
            if(sectorCambio)
            {
                printf("Se ha cambiado el sector a: %d \n", lista[indice].sector);
            }
        }
    }
    return todoOk;

}

int datosVarios(eEmployee list[],int len)
{
    int hola=1;
    int todoOk=0;
    int contador=0;
    int contadorMayorPromedio=0;
    float totalSalarios=0;
    float promedio;
    if(list!=NULL&&len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {
                totalSalarios+=list[i].salary;
                contador++;
                hola=0;
            }
        }
        if(hola)
        {
            printf("No existen datos ingresados\n");
        }
        if(contador!=0)
        {
            promedio=(float)totalSalarios/contadorMayorPromedio;
        }
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0&&list[i].salary>promedio)
            {
                contadorMayorPromedio++;
            }
        }
        todoOk=1;
    }
    if(contador!=0)
    {
        printf("\nTotal de sueldos: %.2f\n",totalSalarios);
        printf("Promedio de sueldos totales: %.2f\n",promedio);
        printf("Cantidad de empleados con salario mayor al promedio : %d\n",contadorMayorPromedio);
    }

    return todoOk;
}
