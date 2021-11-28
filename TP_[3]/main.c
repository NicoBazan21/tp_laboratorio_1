#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "miBiblioteca.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    char seguir = 'n';
    int entrarTxt = 0;
    int entrarBin = 0;
    int unEmp = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(menu())
        {
            case 1:
            	if(entrarTxt == 0 && entrarBin == 0)
            	{
            		if(controller_loadFromText("data.csv",listaEmpleados))
            		{
                		entrarTxt=1;
            		}
            	}
            	else
            	{
            		if(entrarBin)
            		{
            			printf("No se puede cargar el arhivo si antes ya se cargo un .bin\n");
            		}
            		else
            		{
            			printf("Ya está cargado el .txt\n");
            		}
            	}
                break;
            case 2:
            	if(entrarTxt == 0 && entrarBin == 0)
            	{
            		if(controller_loadFromBinary("data.bin",listaEmpleados))
            		{
                		entrarBin=1;
            		}
            	}
                else
                {
                	if(entrarTxt)
                	{
                		printf("No se puede cargar el arhivo si antes ya se cargo un .txt\n");
                	}
                	else
                	{
                		printf("Ya está cargado el .bin\n");
                	}
                }
            	break;
            case 3:
                controller_addEmployee(listaEmpleados);
                unEmp++;
                break;
            case 4:
            	if(entrarBin || entrarTxt || unEmp)
            	{
            		controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("No se puede editar ahora mismo\n");
            	}
            	break;
            case 5:
            	if(entrarBin || entrarTxt || unEmp)
            	{
            		controller_removeEmployee(listaEmpleados);
            		unEmp--;
            	}
            	else
            	{
            		printf("No se puede dar de baja ahora mismo\n");
            	}
            	break;
            case 6:
            	if(entrarBin || entrarTxt || unEmp)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("No hay nada para mostrar\n");
            	}
            	break;
            case 7:
            	if(entrarBin || entrarTxt || unEmp)
            	{
            		controller_sortEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("No hay nada para listar\n");
            	}
            	break;
            case 8:
            	if(!(entrarBin || entrarTxt || unEmp))
            	{
            		controller_saveAsText("data.csv",listaEmpleados);
            		printf("Notificacion: Se guardara un documento en blanco\n");
            	}
            	else
            	{
            		controller_saveAsText("data.csv",listaEmpleados);
            	}
            	break;
            case 9:
            	if(!(entrarBin || entrarTxt || unEmp))
            	{
            		controller_saveAsBinary("data.bin",listaEmpleados);
            		printf("Notificacion: Se guardara un documento en blanco\n");
            	}
            	else
            	{
            		controller_saveAsBinary("data.bin",listaEmpleados);
            	}
            	break;
            case 10:
            	pedirCaracter(&seguir , 's', 'n', "Desea salir? s/n","Caracter Invalido. Desea salir? s/n");
            	if(seguir=='s')
            	{
            		printf("Bueno me voy\n");
            	}
            	break;
            default:
            	printf("Opcion invalida\n");
            	break;
        }
        system("pause");

    }while(seguir == 'n');
    return 0;
}
