#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "controller.h"
#include "input.h"

Employee* employee_new(){
    Employee* persona = malloc(sizeof(Employee));
    return persona;
}

int menu(){
    int opcion;
    printf("\nIngrese 1 para cargar los datos del archivo");
    printf("\nIngrese 2 para listar los empleados");
    printf("\nIngrese 3 para calcular la comision");
    printf("\nIngrese 4 para guardar en archivo de texto");
    printf("\nIngrese 5 para salir");
    getInt(&opcion);
    return opcion;
}

Employee* employee_newParametros(char *var1, char *var2, char *var3,char *var4,char *var5)
{
    int idAux, cantidadAux, montoAux,nivelAux;
    Employee* p = employee_new();
    float valorAux = 0;
    idAux = atoi(var1);
    cantidadAux = atoi(var4);
    nivelAux = atoi(var3);
    controller_asignarNivel(nivelAux,var3);
    montoAux = atoi(var5);
    employee_setValorCobrar(p,valorAux);
    employee_setId(p, idAux);
    employee_setNombre(p, var2);
    employee_setNivel(p, var3);
    employee_setCantidadProductos(p,cantidadAux);
    employee_setMonto(p,montoAux);
    return p;
}

/********FUNCIONES SET***********/

void employee_setId(Employee* this, int id)
{
    if(id > 0)
        this->id = id;
}

void employee_setNombre(Employee* this, char* nombre)
{
    if(nombre[0] != '\0')
    strncpy(this->nombre, nombre, sizeof(this->nombre));
}

void employee_setNivel(Employee* this, char* nivel)
{
    if(nivel[0] != '\0')
    strncpy(this->nivel, nivel, sizeof(this->nivel));
}

void employee_setCantidadProductos(Employee* this, int cantidadProductos)
{
    if(cantidadProductos > 0)
        this->cantidadProductos = cantidadProductos;
}

void employee_setMonto(Employee* this, int monto)
{
    if(monto > 0)
        this->monto = monto;
}

void employee_setValorCobrar(Employee* this,float valor)
{
    if(valor >= 0)
        this->valorCobrar = valor;
}


/**********************************************************/

int employee_getId(Employee* this)
{
    return this->id;
}

char * employee_getNombre(Employee* this)
{
    return this->nombre;
}

char * employee_getNivel(Employee* this)
{
    return this->nivel;
}

int employee_getCantidadProductos(Employee* this)
{
    return this->cantidadProductos;
}

int employee_getMonto(Employee* this)
{
    return this->monto;
}

int employee_getValorCobrar(Employee* this)
{
    return this->valorCobrar;
}
