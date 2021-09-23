#include "bibliotecaCalcu.h"
#include <stdio.h>
#include <stdlib.h>

void fSuma(int uno, int dos, int* rta)
{
    *rta=uno+dos;
}

void fResta(int uno, int dos, int* rta)
{
    *rta=uno-dos;
}

int fDivision(int uno, int dos, float* rta)
{
    int todoOk = 0;
    if(dos != 0)
    {
        *rta = (float)uno/dos;
        todoOk=1;
    }
    return todoOk;
}

void fMulti(int uno, int dos, int* rta)
{
    *rta=uno*dos;
}

int fFactorial(int uno, unsigned long* respuesta)
{
    int todoOk = 0;
    unsigned long resultado = 1;

    if(uno >-1)
    {
        for(int i=1; i <= uno ; i++)
        {
            resultado=resultado*i;
        }
        *respuesta=resultado;
        todoOk=1;
    }

    return todoOk;
}

int menu(int uno, int dos, int si)
{
        int opcion;
        int suma;
        int resta;
        float division;
        int error;
        int errorF;
        int errorF2;
        unsigned long factorialA;
        unsigned long factorialB;
        int mult;

        system("cls");
        printf("Menu de opciones ");
        if(si >= 3)
        {
            printf("\n1. Ingresar 1er operando: (A = %d)", uno);
            printf("\n2. Ingresar 2do operando: (B = %d)", dos);
            printf("\n3. Calcular operaciones: ");
            printf("\n   a) Calcular la suma (%d + %d)", uno, dos);
            printf("\n   b) Calcular la resta (%d - %d)", uno, dos);
            printf("\n   c) Calcular la division (%d / %d)", uno, dos);
            printf("\n   d) Calcular la multiplicacion (%d * %d)", uno, dos);
            printf("\n   e) Calcular el factorial de (!%d y !%d )", uno, dos);
        }
        else
        {
            if(si >= 2)
            {
                printf("\n1. Ingresar 1er operando: (A = %d)", uno);
                printf("\n2. Ingresar 2do operando: (B = %d)", dos);
                printf("\n3. Calcular operaciones: ");

            }
            else
            {
                if(si>=1)
                {
                    printf("\n1. Ingresar 1er operando: (A = %d)", uno);
                    printf("\n2. Ingresar 2do operando: ");
                    printf("\n3. Calcular operaciones: ");
                }
                else
                {
                    printf("\n1. Ingresar 1er operando: ");
                    printf("\n2. Ingresar 2do operando: ");
                    printf("\n3. Calcular operaciones: ");
                }
            }
        }

        printf("\n4. Informar resultados: ");
        if(si >= 4)
        {
            fSuma(uno,dos, &suma);
            fResta(uno,dos, &resta);
            error=fDivision(uno,dos,&division);
            fMulti(uno, dos, &mult);
            errorF=fFactorial(uno, &factorialA);
            errorF2=fFactorial(dos, &factorialB);

            printf("\n   a) El resultado de (%d + %d) es %d",uno,dos, suma);
            printf("\n   a) El resultado de (%d - %d) es %d",uno,dos, resta);
            if(error)
            {
                printf("\n   c) El resultado de (%d / %d) es %.2f", uno, dos, division);
            }
            else
            {
                printf("\n   No se puede dividir por 0");
            }
            printf("\n   d) El resultado de (%d * %d) es %d", uno, dos, mult);
            if(errorF && errorF2)
            {
                printf("\n   e) El factorial de !%d es: %ld y el de !%d es: %ld \n", uno, factorialA, dos, factorialB);

            }
            else
            {
                if(errorF)
                {
                    printf("\n   e) El factorial de !%d es: %ld y no hay factorial de %d\n", uno, factorialA, dos);
                }
                else
                {
                    printf("\n   e) El factorial de !%d es: %ld y no hay factorial de %d\n", dos, factorialB, uno);
                }
            }
        }
        printf("\n5. Salir?: ");
        printf("\n");
        printf("\nIngrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

    return opcion;
}

