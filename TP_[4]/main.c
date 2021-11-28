#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "linkedList.h"
#include "personas.h"
#include "archivos.h"
#include "miBiblioteca.h"
#include "implementacion.h"

int main()
{
    char seguir = 'n';
    int llContainsAll = 0;
    char seguirDos = 'n';

    int crear = 0;
    int crear2 = 0; int g = 0;

    LinkedList* listaPersonas = ll_newLinkedList();
    LinkedList* listaPersonasDos = ll_newLinkedList();
    LinkedList* listaDePersonas; //= ll_newLinkedList;


     do{
        system("cls");
        switch(menu())
        {
            case 1:
                if(crear == 0)
                {
                    printf("Se creara una nueva LinkedList cargada con el archivo .txt de la carpeta\n");
                    listaDePersonas = ll_newLinkedList();
                    arch_loadFromText("personas.txt",listaDePersonas);
                    arch_ListarPersonas(listaDePersonas);//ll_len, ll_get
                    crear=5;
                    g=1;
                }
                else
                {
                    printf("Ya se creo la LinkedList\n");
                }
                break;
            case 2:
                if(crear == 0)
                {
                    printf("No se puede usar ll_len porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_len(listaDePersonas);
                }
                break;
            case 3:
                if(crear == 0)
                {
                    printf("No se puede usar ll_get porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_get(listaDePersonas);
                }
                break;
            case 4:
                if(crear == 0)
                {
                    printf("No se puede usar ll_push porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_push(listaDePersonas);
                    crear++;
                }
                break;
            case 5:
                if(crear == 0)
                {
                    printf("No se puede usar ll_add porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_add(listaDePersonas);
                }
                break;
            case 6:
                if(crear == 0)
                {
                    printf("No se puede usar ll_set porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_set(listaDePersonas);
                }
                break;
            case 7:
                if(crear == 0)
                {
                    printf("No se puede remover, porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_remove(listaDePersonas);
                    crear--;
                }
                break;
            case 8:
                if(crear == 0)
                {
                    printf("No se puede hacer un clear porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_clear(listaDePersonas);
                    crear=0;
                }
                break;
            case 9:
                if(crear == 0)
                {
                    printf("No se puede usar ll_deleteLinkedList porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_deleteLinkedList(listaDePersonas);
                    crear=0;
                }
                break;
            case 10:
                if(crear == 0)
                {
                    printf("No se puede usar ll_indexOf porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_indexOf(listaDePersonas);
                }
                break;
            case 11:
                if(g)
                {
                    funcion_ll_isEmpty(listaDePersonas);
                }
                    //listaDePersonas=NULL;
                break;
            case 12:
                if(crear == 0)
                {
                    printf("No se puede usar ll_pop porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_pop(listaDePersonas);
                }
                break;
            case 13:
                printf("\n");
                printf("Reinicie los datos para que el usuario pueda probar todas las posibilidades del ll_contains\n");
                listaDePersonas=ll_newLinkedList();
                arch_loadFromText("personas.txt",listaDePersonas);

                listaPersonasDos = ll_newLinkedList();
                arch_loadFromText("personas2.txt",listaPersonasDos);

                funcion_ll_contains(listaDePersonas, listaPersonasDos);
                break;
            case 14:
                if(llContainsAll == 0 && g)
                {
                    if(crear==0)
                    {
                        listaDePersonas=ll_newLinkedList();
                        arch_loadFromText("personas.txt",listaDePersonas);
                    }
                    printf("La primera vez que entres a este punto, las dos linkedList apuntaran a los mismos elementos\n");
                    printf("de manera que se pueda chequear la efectividad de la funcion.\n");
                    printf("Luego usted puede añadir vagones al primer LinkedList y volver a este punto para probar\n");
                    printf("la falla de la funcion.\n");

                    arch_loadFromText("personas2.txt",listaPersonasDos);

                    funcion_igualadora(listaDePersonas, listaPersonasDos);

                    funcion_ll_containsAll(listaDePersonas, listaPersonasDos);
                    llContainsAll=1;
                }
                else
                {
                    if(g)
                    {
                        funcion_ll_containsAll(listaDePersonas, listaPersonasDos);
                    }
                }
                break;
            case 15:
                if(crear == 0)
                {
                    printf("No se puede usar ll_subList porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_subList(listaDePersonas);
                }
                break;
            case 16:
                if(crear == 0)
                {
                    printf("No se puede usar ll_clone porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_clone(listaDePersonas);
                }
                break;
            case 17:
                if(crear == 0)
                {
                    printf("No se puede usar ll_sort porque no hay una LinkedList activa\n");
                }
                else
                {
                    funcion_ll_sort(listaDePersonas);
                }
                break;
            case 20:
                do{
                    switch(menuDos())
                    {
                        case 1:
                            if(crear == 1)
                            {
                                printf("No se puede cargar datos porque ya hay una LinkedList activa\n");
                            }
                            else
                            {
                                arch_loadFromText("personas3.txt",listaPersonas);
                                crear2=1;
                            }
                            break;
                        case 2:
                            arch_addEmployee(listaPersonas); //ll_add y get_node
                            crear2++;
                            break;
                        case 3:
                            if(crear2 == 0)
                            {
                                printf("No se puede modificar porque no hay una LinkedList activa\n");
                            }
                            else
                            {
                                arch_editarPersonas(listaPersonas);
                            }
                            break;
                        case 4:
                            if(crear2 == 0)
                            {
                                printf("No se puede dar de baja porque no hay una LinkedList activa\no no quedan personas\n");
                            }
                            else
                            {
                                arch_bajaPersona(listaPersonas);//ll_remove
                                crear2--;
                            }
                            break;
                        case 5:
                            if(crear2 == 0)
                            {
                                printf("No se puede listar porque no hay una LinkedList activa\no no quedan personas\n");
                            }
                            else
                            {
                                arch_ListarPersonas(listaPersonas);//ll_len, ll_get
                            }
                            break;
                        case 6:
                            if(crear2 == 0)
                            {
                                printf("No se puede ordenar porque no hay una LinkedList activa\no no quedan personas\n");
                            }
                            else
                            {
                                arch_sortPersonas(listaPersonas);//ll_sort, ll_clone
                            }
                            break;
                        case 10:
                            pedirCaracter(&seguirDos, 's', 'n', "Desea salir al menu anterior? s/n","Caracter Invalido. Desea salir al menu anterior? s/n");
                            if(seguir=='s')
                            {
                                printf("Bueno me voy\n");
                            }
                            break;
                    }
                            system("pause");
                }while(seguirDos=='n');
                    break;
            case 21:
                pedirCaracter(&seguir, 's', 'n', "Desea salir al menu anterior? s/n","Caracter Invalido. Desea salir al menu anterior? s/n");
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
