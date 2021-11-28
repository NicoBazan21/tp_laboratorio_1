#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "personas.h"


ePersona* persona_new()
{
	 ePersona* nuevaPersona;

	 nuevaPersona = (ePersona*) malloc (sizeof(ePersona));

	 if(nuevaPersona != NULL)
	 {
		 nuevaPersona->id=0;
		 strcpy(nuevaPersona->nombre, "nn");
		 nuevaPersona->sexo='n';
		 nuevaPersona->altura=0;
	 }

	 return nuevaPersona;
}

ePersona* persona_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	ePersona* nuevaPersona;

	nuevaPersona = persona_new();


	if(nuevaPersona != NULL)
	{
		if(!(persona_setId(nuevaPersona, atoi(idStr))
            && persona_setNombre(nuevaPersona, nombreStr)
            && persona_setSexo(nuevaPersona, *(horasTrabajadasStr))
            && persona_setAltura(nuevaPersona, atof(sueldoStr))))
		{
		     free(nuevaPersona);
		     nuevaPersona=NULL;
		}
	}

	return nuevaPersona;
}

ePersona* new_personaParam(int id, char nombre[], float altura, char sexo)
{
    ePersona* nuevaPersona;

	nuevaPersona = persona_new();


	if(nuevaPersona != NULL)
	{
		if(!(persona_setId(nuevaPersona, (id))
            && persona_setNombre(nuevaPersona, nombre)
            && persona_setSexo(nuevaPersona, (sexo))
            && persona_setAltura(nuevaPersona, (altura))))
		{
		     free(nuevaPersona);
		     nuevaPersona=NULL;
		}
	}

	return nuevaPersona;
}

int persona_setId(ePersona* this,int id)
{
    int todoOk=0;

    if(this != NULL && id > 0)
    {
    	this->id = id;
        todoOk=1;
    }
    else
    {
    	printf("Id invalido\n");
    }

    return todoOk;
}


int persona_setNombre(ePersona* this,char* nombre)
{
    int todoOk=0;

    if(this != NULL && nombre != NULL)
    {
        if(strlen(nombre) < 128 && strlen(nombre) > 2)
        {
            strcpy(this->nombre, nombre);
            strlwr(this->nombre);
            this->nombre[0] = toupper(this->nombre[0]);
            for(int i = 0; i < 128; i++)
            {
                if(nombre[i] == ' ')
                {
                    this->nombre[i+1] = toupper(this->nombre[i+1]);
                }
            }
            todoOk=1;
        }
    }
    else
    {
    	printf("Nombre invalido\n");
    }

    return todoOk;
}

int persona_setSexo(ePersona* this,char sexo)
{
    int todoOk=0;

    if(this != NULL)
    {
    	this->sexo = sexo;
        todoOk=1;
    }
    else
    {
    	printf("Sexo invalidas\n");
    }

    return todoOk;
}


int persona_setAltura(ePersona* this,float altura)
{
    int todoOk = 0;
    if(this != NULL)
    {
    	this->altura=altura;
        todoOk=1;
    }
    else
    {
    	printf("Sueldo invalido\n");
    }
    return todoOk;
}

int persona_getId(ePersona* this,int* id)
{
	int todoOk = 0;

	   if(this != NULL && id != NULL)
	   {
	       *id=this->id;
	       todoOk=1;
	   }
	   return todoOk;
}

int persona_getNombre(ePersona* this,char* nombre)
{
    int todoOk=0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk=1;
    }

    return todoOk;
}

int persona_getAltura(ePersona* this,float* altura)
{
    int todoOk=0;

    if(this != NULL && altura != NULL)
    {
        *altura=this->altura;
        todoOk=1;
    }

    return todoOk;
}

int persona_getSexo(ePersona* this,char* sexo)
{
	int todoOk = 0;

	if(this != NULL && sexo != NULL)
	{
		*sexo=this->sexo;
		 todoOk=1;
	}
	 return todoOk;
}

void persona_mostrarPersona(ePersona* pers)
{
	int id;
	char nombre[128];
	char sexo;
	float altura;

    char sexoComp[15];

	if(pers != NULL)
	{
		persona_getId(pers, &id);
		persona_getNombre(pers, nombre);
		persona_getSexo(pers, &sexo);
		persona_getAltura(pers, &altura);

        if(sexo == 'f')
        {
            strcpy(sexoComp, "Femenino");
            printf("%d   %10s   \t%s   \t%.2f\n",id, nombre, sexoComp, altura);
        }
        else
        {
            if(sexo == 'm')
            {
                strcpy(sexoComp, "Masculino");
                printf("%d   %10s   \t%1s\t%.2f\n",id, nombre, sexoComp, altura);

            }
            else
            {
                strcpy(sexoComp, "Sin definir");
                printf("%d   %10s   \t%1s\t%.2f\n",id, nombre, sexoComp, altura);
            }
        }
	}
}

int persona_comparaPersonasNombre(void* pPersonaA, void* pPersonaB)
{
	char cadena[128];
	char cadenaDos[128];

	ePersona* pers = NULL;
	ePersona* persDos = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPersonaA != NULL && pPersonaB != NULL)
	{
		pers = (ePersona*) pPersonaA;
		persDos = (ePersona*) pPersonaB;

		if(persona_getNombre(pers, cadena) == 1
		&& persona_getNombre(persDos, cadenaDos) == 1)
		{
			if(strcmp(cadena, cadenaDos) > 0)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
			{
				if(strcmp(cadena, cadenaDos) < 0)
				{
					retornoXqSinEstoMeDaUnWarning = -1;
				}
			}
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}

int persona_comparaPersonasAltura(void* pPersonaA, void* pPersonaB)
{
	float altura;
	float alturaDos;

	ePersona* pers = NULL;
	ePersona* persDos = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPersonaA != NULL && pPersonaB != NULL)
	{
		pers = (ePersona*) pPersonaA;
		persDos = (ePersona*) pPersonaB;
		if(persona_getAltura(pers, &altura) == 1
		&& persona_getAltura(persDos, &alturaDos) == 1)
		{
			if(altura > alturaDos)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
			{
				if(altura < alturaDos)
				{
					retornoXqSinEstoMeDaUnWarning = -1;
				}
			}
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}

int persona_comparaPersonasSexo(void* pPersonaA, void* pPersonaB)
{
	char sexo;
	char sexoDos;

	ePersona* pers = NULL;
	ePersona* persDos = NULL;

	int retornoXqSinEstoMeDaUnWarning;

	if(pPersonaA != NULL && pPersonaB != NULL)
	{
		pers = (ePersona*) pPersonaA;
		persDos = (ePersona*) pPersonaB;
		if(persona_getSexo(pers, &sexo) == 1
		&& persona_getSexo(persDos, &sexoDos) == 1)
		{
			if(sexo > sexoDos)
			{
				retornoXqSinEstoMeDaUnWarning = 1;
			}
			else
			{
				if(sexo < sexoDos)
				{
					retornoXqSinEstoMeDaUnWarning = -1;
				}
			}
		}
	}
	return retornoXqSinEstoMeDaUnWarning;
}
