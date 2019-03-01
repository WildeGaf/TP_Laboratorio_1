#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

eComponente* componente_new(){
    eComponente* persona = malloc(sizeof(eComponente));
    return persona;
}

eColor* eColor_new(){
    eColor* persona = malloc(sizeof(eColor));
    return persona;
}


eComponente* eComponente_newParametros(char *var1, char *var2, char *var3)
{
    int idAux,baseAux;
    eComponente* p = componente_new();
    idAux = atoi(var1);
    baseAux = atoi(var3);
    controller_esBase(var3,baseAux);
    eComponente_setIdComponente(p,idAux);
    eComponente_setNombre(p,var2);
    eComponente_setBase(p,var3);
    return p;
}

eColor* eColor_newParametros(char *var1, char *var2, char *var3, char *var4)
{
    int idColorAux,idComponenteAux,cantidadAux;
    eComponente* p = eColor_new();
    idColorAux = atoi(var1);
    idComponenteAux = atoi(var3);
    cantidadAux = atoi(var4);
    eColor_setIdColor(p,idColorAux);
    eColor_setIdComponente(p,idComponenteAux);
    eColor_setNombre(p,var2);
    eColor_setCantidad(p,cantidadAux);
    return p;
}

/********FUNCIONES SET***********/

void eComponente_setIdComponente(eComponente* this, int idComponente)
{
    if(idComponente > 0)
        this->idComponente = idComponente;
}

void eComponente_setNombre(eComponente* this, char* nombre)
{
    if(nombre[0] != '\0')
    strncpy(this->nombre, nombre, sizeof(this->nombre));
}

void eComponente_setBase(eComponente* this, char* base)
{
    if(base[0] != '\0')
    strncpy(this->base, base, sizeof(this->base));
}


/*******************************************************/


void eColor_setIdColor(eColor* this, int idColor)
{
    if(idColor > 0)
        this->idColor = idColor;
}

void eColor_setCantidad(eColor* this, int cantidad)
{
    if(cantidad > 0)
        this->cantidad = cantidad;
}

void eColor_setIdComponente(eColor* this, int idComponente)
{
    if(idComponente > 0)
        this->idComponente = idComponente;
}

void eColor_setNombre(eColor* this, char* nombre)
{
    if(nombre[0] != '\0')
    strncpy(this->nombre, nombre, sizeof(this->nombre));
}

/*********FUNCIONES GET**********/

int eComponente_getIdComponente(eComponente* this)
{
    return this->idComponente;
}

char * eComponente_getNombre(eComponente* this)
{
    return this->nombre;
}

char * eComponente_getBase(eComponente* this)
{
    return this->base;
}

/*************************************************************************/



int eColor_getIdColor(eColor* this)
{
    return this->idColor;
}

int eColor_getIdComponente(eColor* this)
{
    return this->idComponente;
}

int eColor_getCantidad(eColor* this)
{
    return this->cantidad;
}

char * eColor_getNombre(eColor* this)
{
    return this->nombre;
}


int employee_sortByName(void* thisA,void* thisB)
{
    int retorno = 0;
    char nameA[50];
    char nameB[50];
    eComponente* punteroA;
    eComponente* punteroB;
    punteroA = thisA;
    punteroB = thisB;
    if (punteroA != NULL && punteroB != NULL){
        strcpy(nameA,eComponente_getNombre(thisA));
        strcpy(nameB,eComponente_getNombre(thisB));

        if(strcmp(nameA,nameB)>0){
            retorno = 1;
        }
        else if(strcmp(nameA,nameB)< 0){
            retorno = 0;
        }
    }
    return retorno;
}
