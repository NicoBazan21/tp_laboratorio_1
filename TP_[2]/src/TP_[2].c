#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1000
#define TAM_MIN 1


int main()
{
	setbuf(stdout, NULL);
    char seguir = 's';
    char seguro;

    int nextId = 1;

    eEmployee lista[TAM];

    char auxNombre[51];
    char auxApellido[51];
    float auxSalario;
    int auxSector;

    float minimo = 10000;
    float maximo = 50000;

    int sectorMin = 1;
    int sectroMax=10;

    int encontrarId;
    int buscarId;
    int orden;

    int ordenAsc = 1;
    int ordenDesc =2;

    int entrar = 0;

    initEmployees(lista, TAM);


    fflush(stdin);
    do{
        switch(menu())
        {
            case 1:
                if(buscarLibre(lista, TAM) > -1)
                {
                    pedirCadena(auxNombre, 51, "Ingrese nombre: ", "Error, nombre invalido. Ingrese nombre nuevamente: ");
                    pedirCadena(auxApellido, 51, "Ingrese apellido: ", "Error, apellido invalido. Ingrese apellido nuevamente: ");
                    pedirFlotante(&auxSalario, "Ingrese salario(10000 y 50000): ", "Salario invalido (10000 y 50000): ", minimo,maximo);
                    pedirEntero(&auxSector, "Ingrese sector (1 al 10): ", "Sector invalido (1 al 10): ", sectorMin,sectroMax);

                addEmployee(lista, TAM, nextId, auxNombre, auxApellido, auxSalario, auxSector);
                nextId++;
                }
                else
                {
                    printf("No hay lugar en el sistema.\n");
                }
                entrar = 1;
                break;
            case 2:
                if(entrar)
                {
                    modificarPersona(lista,TAM);
                }
                else
                {
                    printf("Primero se deben ingresar empleados \n");
                }
                break;
            case 3:
                if(entrar)
                {
                pedirEntero(&orden, "Ingrese (1 o 2) para ver la lista en orden ascendente o descendente: ","Error. Ingrese (1 o 2) para ver la lista en orden ascendente o descendente: ",ordenAsc,ordenDesc );
                sortEmployees(lista, TAM, orden);
                pedirEntero(&buscarId, "Ingrese el id a buscar: ", "Error. Id Invalido. Ingrese id nuevamente: ", TAM_MIN, TAM);
                encontrarId=findEmployeeById(lista, TAM, buscarId);
                if(encontrarId > -1)
                {
                    printf("Nombre completo del id ingresado: %s %s\n", lista[encontrarId].name, lista[encontrarId].lastName);
                    pedirCaracter(&seguro, "Esta seguro de darlo de baja? s/n", "Cancelando...", 's');

                    if(seguro == 's' || seguro == 'S')
                    {
                        if(removeEmployee(lista, TAM, buscarId) == -1)
                        {
                            printf("Hubo un error durante la operacion. \n");
                        }
                        printf("\n Baja exitosa \n");

                    }
                    else
                    {
                        printf("Operacion baja cancelada. \n");
                    }
                }
                }
                else
                {
                    printf("Primero se deben ingresar empleados \n");
                }
                break;
            case 4:
                if(entrar)
                {
                pedirEntero(&orden, "Ingrese (1 o 2) para ver la lista en orden ascendente o descendente: ","Error. Ingrese (1 o 2) para ver la lista en orden ascendente o descendente: ",ordenAsc,ordenDesc );
                sortEmployees(lista, TAM, orden);
                datosVarios(lista, TAM);
                }
                else
                {
                    printf("Primero se deben ingresar empleados \n");
                }
                break;
            case 5:
                pedirCaracter(&seguir, "Desea salir? s/n", "Saliendo...", 's');
                break;
            default:
                printf("Opcion incorrecta.\n");
                fflush(stdin);
                break;
        }

        system("pause");
    }while(seguir == 'n');

    return EXIT_SUCCESS;
}
