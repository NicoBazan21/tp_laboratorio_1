#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaCalcu.h"

int main()
{
	setbuf(stdout,NULL);
    int numeroUno;
    int numeroDos;
    char salir = 'n';
    int hola = 0;
    int cambiar = 1;
    char cambiarSeguro;
    char reiniciar;

    do{
        switch(menu(numeroUno, numeroDos, hola))
        {
            case 1:
                if(cambiar)
                {
                    if(hola==0)
                    {
                        hola=1;
                        printf("\nIngrese el numero: ");
                        scanf("%d", &numeroUno);
                    }
                    else
                    {
                        printf("\nQuiere cambiar el primer operando? s/n\n");
                        fflush(stdin);
                        scanf("%c", &cambiarSeguro);
                        if(cambiarSeguro=='s')
                        {
                            printf("\nIngrese el primer operando: ");
                            printf("\n");
                            scanf("%d", &numeroUno);
                        }
                    }
                }
                else
                {
                    if(hola==4)
                    {
                        printf("Quiere ingresar nuevos operadores? s/n");
                        fflush(stdin);
                        scanf("%c", &reiniciar);

                        if(reiniciar=='s')
                        {
                            hola=0;
                            cambiar=1;
                        }
                    }
                    else
                    {
                        printf("\nNo puede cambiar los numeros despues de haber realizado las operaciones\n");
                    }
                }
                break;
            case 2:
               if(cambiar)
               {
                   switch(hola)
                   {
                        case 1:
                            printf("\nIngrese el numero: ");
                            scanf("%d", &numeroDos);
                            hola=2;
                            break;
                        case 0:
                            printf("\nPrimero hay que ingresar el primer operando\n");
                            break;
                        default:
                            printf("\nQuiere cambiar el segundo operando? s/n \n");
                            fflush(stdin);
                            scanf("%c", &cambiarSeguro);
                            if(cambiarSeguro=='s')
                            {
                                printf("\nIngrese el segundo operando: ");
                                printf("\n");
                                scanf("%d", &numeroDos);
                            }
                        break;
                   }
                }
                else
                {
                    printf("\nNo puede cambiar los numeros despues de haber realizado las operaciones\n");
                }
                break;
            case 3:
                switch(hola)
                {
                    case 2:
                        hola=3;
                        cambiar=0;
                        break;
                    case 1:
                        printf("\nPrimero hay que ingresar el segundo operando\n");
                        break;
                    case 0:
                        printf("\nPrimero hay que ingresar el primer operando\n");
                        break;
                    default:
                        printf("\nYa realizo las operaciones\n");
                        break;
                }
                break;
            case 4:
                switch(hola)
                {
                    case 3:
                        hola=4;
                        break;
                    case 2:
                        printf("\nPrimero hay que realizar las operaciones\n");
                        break;
                    case 1:
                        printf("\nPrimero hay que ingresar el segundo operando\n");
                        break;
                    case 0:
                        printf("\nPrimero hay que ingresar el primer operando\n");
                        break;
                    default:
                        printf("\nYa mostro los resultados\n");
                        break;
                }
                break;
            case 5:
                printf("\nEsta seguro? s/n ");
                fflush(stdin);
                scanf("%c", &salir);
                break;
            default:
                    printf("Opcion invalida\n");
                break;
        }
        system("pause");

    }while(salir == 'n');
}
