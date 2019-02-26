#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new(){
    Employee* persona = malloc(sizeof(Employee));
    return persona;
}

eFichaje* eFichaje_new(){
    eFichaje* persona = malloc(sizeof(Employee));
    return persona;
}


Employee* employee_newParametros(char *var1, char *var2, char *var3, char *var4, char * var5)
{
    int idAux,dniAux;
    Employee* p = employee_new();
    idAux = atoi(var1);
    dniAux = atoi(var4);
    employee_setId(p,idAux);
    employee_setNombre(p,var2);
    employee_setApellido(p,var3);
    employee_setDni(p,dniAux);
    employee_setClave(p,var5);

    return p;
}

eFichaje* eFichaje_newParametros(char *var1, char *var2, char *var3, char *var4, char * var5,
                                 char * var6,char * var7,char * var8)
{
    int idFichajeAux,idEmpleadoAux,horaAux,minutosAux,diaAux,mesAux,anioAux;
    eFichaje* p = eFichaje_new();
    idFichajeAux = atoi(var1);
    idEmpleadoAux = atoi(var2);
    horaAux = atoi(var3);
    minutosAux = atoi(var4);
    diaAux = atoi(var5);
    mesAux = atoi(var6);
    anioAux = atoi(var7);
    eFichaje_setIdFichaje(p,idFichajeAux);
    eFichaje_setIdEmpleado(p,idEmpleadoAux);
    eFichaje_setHora(p,horaAux);
    eFichaje_setMinutos(p,minutosAux);
    eFichaje_setDia(p,diaAux);
    eFichaje_setMes(p,mesAux);
    eFichaje_setAnio(p,anioAux);
    eFichaje_setIngresoEgreso(p,var8);
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

void employee_setApellido(Employee* this, char* apellido)
{
    if(apellido[0] != '\0')
    strncpy(this->apellido, apellido, sizeof(this->apellido));
}

void employee_setDni(Employee* this, int dni)
{
    if(dni > 0)
        this->dni = dni;
}

void employee_setClave(Employee* this, char* clave)
{
    if(clave[0] != '\0')
    strncpy(this->clave, clave, sizeof(this->clave));
}



/*******************************************************/


void eFichaje_setIdFichaje(eFichaje* this, int idFichaje)
{
    if(idFichaje > 0)
        this->idFichaje = idFichaje;
}

void eFichaje_setIdEmpleado(eFichaje* this, int idEmpleado)
{
    if(idEmpleado > 0)
        this->idEmpleado = idEmpleado;
}

void eFichaje_setHora(eFichaje* this, int hora)
{
    if(hora > 0)
        this->hora = hora;
}
void eFichaje_setMinutos(eFichaje* this, int minutos)
{
    if(minutos > 0)
        this->minutos = minutos;
}
void eFichaje_setDia(eFichaje* this, int dia)
{
    if(dia > 0)
        this->dia = dia;
}
void eFichaje_setMes(eFichaje* this, int mes)
{
    if(mes > 0)
        this->mes = mes;
}
void eFichaje_setAnio(eFichaje* this, int anio)
{
    if(anio > 0)
        this->anio = anio;
}
void eFichaje_setIngresoEgreso(eFichaje* this, char* ingresoEgreso)
{
    if(ingresoEgreso[0] != '\0')
    strncpy(this->ingresoEgreso, ingresoEgreso, sizeof(this->ingresoEgreso));
}

/*********FUNCIONES GET**********/

int employee_getId(Employee* this)
{
    return this->id;
}

char * employee_getNombre(Employee* this)
{
    return this->nombre;
}

char * employee_getApellido(Employee* this)
{
    return this->apellido;
}

int employee_getDni(Employee* this)
{
    return this->dni;
}

char* employee_getClave(Employee* this)
{
    return this->clave;
}



/*************************************************************************/



int eFichaje_getIdFichaje(eFichaje* this)
{
    return this->idFichaje;
}

int eFichaje_getIdEmpleado(eFichaje* this)
{
    return this->idEmpleado;
}

int eFichaje_getHora(eFichaje* this)
{
    return this->hora;
}

int eFichaje_getMinutos(eFichaje* this)
{
    return this->minutos;
}

int eFichaje_getDia(eFichaje* this)
{
    return this->dia;
}

int eFichaje_getMes(eFichaje* this)
{
    return this->mes;
}

int eFichaje_getAnio(eFichaje* this)
{
    return this->anio;
}

char * eFichaje_getIngresoEgreso(eFichaje* this)
{
    return this->ingresoEgreso;
}
