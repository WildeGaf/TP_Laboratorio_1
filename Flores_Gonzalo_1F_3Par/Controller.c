#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"
#include "controller.h"

int menu(void){
int option;
printf("Menu trabajo practico numero 3");
printf("\nSeleccione 1- Para dar de alta un empleado");
printf("\nSeleccione 2- Para modificar los datos de un empleado");
printf("\nSeleccione 3- Para dar de baja un empleado");
printf("\nSeleccione 4- Para imprimir la lista de empleados mediante una fecha determinada");
printf("\nSeleccione 5- Para el fichaje del empleado");
printf("\nSeleccione 6- Para informar empleados presentes en una fecha determinada");
printf("\nSeleccione 7- Para guardar la lista Filtrada");
printf("\nSeleccione 8- Para guardar cambios en las listas Empleados y Fichajes");
printf("\nSeleccione 9- Para salir");
printf("\nOpcion elegida: ");
scanf("%d",&option);
return option;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo = fopen(path,"r+");
    if(pArchivo == NULL){
        printf("Error al leer el archivo");
    }
    else{
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        printf("\n\nDatos cargados con Exito!\n\n");
    }
    fclose(pArchivo);
    return 0;
}

int controller_loadFromTextFichaje(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo = fopen(path,"r+");
    if(pArchivo == NULL){
        printf("Error al leer el archivo");
    }
    else{
        parser_EmployeeFromTextFichajes(pArchivo,pArrayListEmployee);
        printf("\n\nDatos cargados con Exito!\n\n");
    }
    fclose(pArchivo);
    return 0;
}



/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
   Employee* pB;
   Employee* lastPoint;
   int resp,cant;
   char var1[50],var3[50],var2[50],var4[50],var5[50];
   do{
        cant = ll_len(pArrayListEmployee);
        lastPoint = ll_get(pArrayListEmployee,cant-1);
        cant = lastPoint->id;
        sprintf(var1,"%d",cant+1);
        printf("\nIngrese el nombre del empleado: ");
        fflush(stdin);
        getString(var2);
        printf("\nIngrese el apellido del empleado: ");
        fflush(stdin);
        getString(var3);
        printf("\nIngrese el dni: ");
        fflush(stdin);
        getString(var4);
        printf("\nIngrese la clave: ");
        fflush(stdin);
        getString(var5);
        pB = employee_newParametros(var1,var2,var3,var4,var5);
        ll_add(pArrayListEmployee,pB);
        printf("\nPara continuar ingresando datos ingrese 1 o 0 para terminar: ");
        getInt(&resp);
        system("cls");
        }while (resp==1);
    controller_saveAsText("probando.csv",pArrayListEmployee);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id,resp,i,cant,bandera=0;
    char auxNombre[51],auxApellido[51],auxClave[51];
    int auxDni,auxId;
    Employee* puntero;
    Employee* ultimo;
    Employee* primero;
    printf ("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
        getInt(&resp);
        if (resp == 1){
            controller_ListEmployee(pArrayListEmployee);
        }
    printf ("\nIngrese el id del empleado a modificar: ");
    getInt(&id);
    cant = ll_len(pArrayListEmployee);
    ultimo = ll_get(pArrayListEmployee,cant-1);
    primero = ll_get(pArrayListEmployee,0);
    if ((pArrayListEmployee != NULL && id >= primero->id) && (id <= ultimo->id)){
        for (i=0;i<=cant;i++){
           puntero = ll_get(pArrayListEmployee,i);
           auxId = puntero->id;
            if (auxId == id){
            bandera = 1;
                break;
            }
        }
    }
        if (bandera == 1){
            printf("1-Para modificar el Nombre\t 2-Para el Apellido\t 3-Para el Dni \t 4- Para la Clave \t 5- Para todos");
            getInt(&resp);
            switch(resp){
                case 1:
                    printf("\nIngrese el nombre a asignar");
                    getString(auxNombre);
                    strcpy(puntero->nombre,auxNombre);
                    break;
                case 2:
                    printf("\nIngrese el apellido a asignar");
                    getString(auxApellido);
                    strcpy(puntero->apellido,auxApellido);
                    break;
                case 3:
                    printf("\nIngrese el dni a asignar");
                    getInt(&auxDni);
                    puntero->dni = auxDni;
                    break;
                case 4:
                    printf("\nIngrese la clave a asignar");
                    getString(auxClave);
                    strcpy(puntero->clave,auxClave);
                case 5:
                    printf("\nIngrese el nombre a asignar");
                    getString(auxNombre);
                    strcpy(puntero->apellido,auxApellido);
                    printf("\nIngrese el apellido a asignar");
                    getString(auxApellido);
                    strcpy(puntero->apellido,auxApellido);
                    printf("\nIngrese el dni a asignar");
                    getInt(&auxDni);
                    puntero->dni = auxDni;
                    printf("\nIngrese la clave a asignar");
                    getString(auxClave);
                    strcpy(puntero->clave,auxClave);
                    controller_saveAsText("probando.csv",pArrayListEmployee);
                    break;
                }
            }else{
             printf("No se encontro el id");
            }

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int cant,id,resp,i,auxId;
    Employee* puntero;
    Employee* ultimo;
    Employee* primero;
    printf ("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
        getInt(&resp);
        if (resp == 1){
            controller_ListEmployee(pArrayListEmployee);
        }
    printf ("\nIngrese el id del empleado a borrar: ");
    getInt(&id);
    cant = ll_len(pArrayListEmployee);
    ultimo = ll_get(pArrayListEmployee,cant-1);
    primero = ll_get(pArrayListEmployee,0);
    if ((pArrayListEmployee != NULL && id >= primero->id) && (id <= ultimo->id)){
        for (i=0;i<=cant;i++){
           puntero = ll_get(pArrayListEmployee,i);
           auxId = puntero->id;
            if (auxId == id){
            ll_remove(pArrayListEmployee,i);
            printf ("\nSe elimino correctamente\n");
            system("pause");
            system("cls");
            controller_saveAsText("probando.csv",pArrayListEmployee);
            break;
            }
        }
    }else{
        printf("No se encontro el id");
    }
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i,cant;
    cant = ll_len(pArrayListEmployee);
    Employee* lista;
    for (i=0;i<cant;i++){
        lista = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %s\t %d\t %s\n",employee_getId(lista),employee_getNombre(lista),
                                     employee_getApellido(lista),
                                     employee_getDni(lista),
                                     employee_getClave(lista));
    }
    return 1;
}


int controller_ListEmployeeFichaje(LinkedList* listaFichaje)
{
    int i,cant;
    cant = ll_len(listaFichaje);
    eFichaje* lista;
    for (i=0;i<cant;i++){
        lista = (eFichaje*)ll_get(listaFichaje,i);
        printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t %s\n",eFichaje_getIdFichaje(lista),eFichaje_getIdEmpleado(lista),
                                     eFichaje_getHora(lista),
                                     eFichaje_getMinutos(lista),
                                     eFichaje_getDia(lista),
                                     eFichaje_getMes(lista),
                                     eFichaje_getAnio(lista),
                                     eFichaje_getIngresoEgreso(lista));
    }
    return 1;
}


int controller_ListaFecha(LinkedList* listaEmpleados,LinkedList* listaFichajes,LinkedList* listaFiltrada){
    int dia,mes,anio,cantF,cantE,i,j,contador =0, total = 0;
    printf ("Ingrese el dia");
    getInt(&dia);
    printf ("Ingrese el mes");
    getInt(&mes);
    printf ("Ingrese el anio");
    getInt(&anio);
    eFichaje* punteroF;
    Employee* punteroE;
    cantF = ll_len(listaFichajes);
    cantE = ll_len(listaEmpleados);
    for (i=0;i<cantF-1;i++){
        punteroF = ll_get(listaFichajes,i);
        if ((punteroF->dia == dia) &&
            (punteroF->mes == mes) &&
            (punteroF->anio == anio)&&
            (strcmp(punteroF->ingresoEgreso,"IN"))==0){
            for (j=0;j<cantE-1;j++){
                punteroE = ll_get(listaEmpleados,j);
                    if(punteroE->id == punteroF->idEmpleado){
                        ll_add(listaFiltrada,punteroE);
                        contador++;
                    }
            }
        }
   }
    total = ll_len(listaFiltrada);
    printf("%d",total);
    printf ("\n\nSe encontaron %d empleados\n\n",total);
return 0;
}


void fichajeEmpleado(LinkedList* listaEmpleado,LinkedList* listaFichaje){
    Employee* punteroE;
    eFichaje* punteroF;
    char idEmpleado[51],horaAux[51],minutosAux[51],diaAux[51],mesAux[51],
    ingresoEgresoAux[51],anioAux[51],claveAux[51],idAux[51];
    int i,cantE,cantF,cant,idEmpleadoAux,bandera = 0;
    printf("Ingrese el ID del empleado");
    getInt(&idEmpleadoAux);
    printf("Ingrese su Clave");
    getString(claveAux);
    cantE = ll_len(listaEmpleado);
    cantF = ll_len(listaFichaje);
    for (i=0;i<cantE;i++){
            punteroE = ll_get(listaEmpleado,i);
        if ((punteroE->id == idEmpleadoAux) && (strcmp(punteroE->clave,claveAux))==0){
            punteroF = ll_get(listaFichaje,cantF-1);
            cant = (punteroF->idFichaje + 1);
            sprintf(idEmpleado,"%d",idEmpleadoAux);
            sprintf(idAux,"%d",cant);
            printf("Indique la hora");
            getString(horaAux);
            printf("Indique los minutos ");
            getString(minutosAux);
            printf("Indique el dia");
            getString(diaAux);
            printf("Indique el mes");
            getString(mesAux);
            printf("Indique el anio");
            getString(anioAux);
            printf("indique IN para ingreso o OUT para egreso");
            getString(ingresoEgresoAux);
            punteroF = eFichaje_newParametros(idAux,idEmpleado,horaAux,minutosAux,diaAux,mesAux,anioAux,ingresoEgresoAux);
            ll_add(listaFichaje,punteroF);
            bandera = 1;
            break;
        }
    }
    if (bandera != 1){
        printf("Error en el usuario o clave");
    }
    system("cls");
    controller_ListEmployeeFichaje(listaFichaje);
    system("pause");
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortEmployee(LinkedList* listaFiltrada)
{
    int i,j,len;
    Employee* actualEmpleado;
    Employee* empSiguiente;
    Employee* auxiliar;
    len = ll_len(listaFiltrada);
    for (i=0;i<len-1;i++){
        actualEmpleado = ll_get(listaFiltrada,i);
        for(j=i+1;j<len-1;j++){
            empSiguiente = ll_get(listaFiltrada,j);
            if (strcmp(actualEmpleado->apellido,empSiguiente->apellido)>=1){
                auxiliar = actualEmpleado;
                actualEmpleado = empSiguiente;
                empSiguiente = auxiliar;
            }
        }
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* lista)
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    Employee* auxEmpleado;
    len = ll_len(lista);
    pArchivo = fopen(path,"r+");
    if (pArchivo == NULL){
        pArchivo = fopen(path,"w+");
    }
    if (len>0){
        for (i=0;i<len;i++){
        auxEmpleado = ll_get(lista,i);
        fprintf(pArchivo,"%d,%s,%s,%d,%s\n",employee_getId(auxEmpleado),employee_getNombre(auxEmpleado),
                                            employee_getApellido(auxEmpleado),employee_getDni(auxEmpleado),
                                            employee_getClave(auxEmpleado));
        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}


int controller_saveAsTextFichaje(char* path , LinkedList* lista)
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    eFichaje* auxFichaje;
    len = ll_len(lista);
    pArchivo = fopen(path,"r+");
    if (pArchivo == NULL){
        pArchivo = fopen(path,"w+");
    }
    if (len>0){
        for (i=0;i<len-1;i++){
        auxFichaje = ll_get(lista,i);
        fprintf(pArchivo,"%d,%d,%d,%d,%d,%d,%d,%s\n",eFichaje_getIdFichaje(auxFichaje),eFichaje_getIdEmpleado(auxFichaje),
                                                    eFichaje_getHora(auxFichaje),eFichaje_getMinutos(auxFichaje),
                                                    eFichaje_getDia(auxFichaje),eFichaje_getMes(auxFichaje),
                                                    eFichaje_getAnio(auxFichaje),eFichaje_getIngresoEgreso(auxFichaje));

        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}
