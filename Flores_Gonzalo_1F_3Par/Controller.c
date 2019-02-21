#include <stdio.h>
#include <stdlib.h>
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
printf("\nSeleccione 4- Para imprimir la lista de empleados");
printf("\nSeleccione 5- Para el fichaje del empleado");
printf("\nSeleccione 6- Para informar empleados presentes");
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

int controller_addEmployee(LinkedList* pArrayListEmployee,LinkedList* listaFichaje)
{
   Employee* pB;
   int resp,cant;
   char var1[50],var3[50],var2[50],var4[50],var5[50];
   resp = 1;
   while (resp == 1){
        cant = ll_len(pArrayListEmployee);
        cantF = ll_len(listaFichaje);
        sprintf(var1,"%d",cant);
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
        printf("\nPara continuar ingresando datos ingrese 1 : ");
        getInt(&resp);
        system("cls");
   }
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
    int id,resp;
    char auxNombre[51],auxApellido[51];
    int auxDni,auxClave;
    Employee* puntero;
    printf ("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
        getInt(&resp);
        if (resp == 1){
            controller_ListEmployee(pArrayListEmployee);
        }
    printf ("\nIngrese el id del empleado a modificar: ");
    getInt(&id);
    if (pArrayListEmployee != NULL){
        puntero = ll_get(pArrayListEmployee,id);
        printf("1-Para modificar el Nombre\t 2-Para el Apellido\t 3-Para el Dni \t 4- Para la Clave");
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
                getInt(&auxClave);
                puntero->clave = auxClave;
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
                getInt(&auxClave);
                puntero->clave = auxClave;
                break;
        }
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
    int cant,codigo,resp;
    Employee* puntero;
    printf ("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
        getInt(&resp);
        if (resp == 1){
            controller_ListEmployee(pArrayListEmployee);
        }
    printf ("\nIngrese el id del empleado a borrar: ");
    getInt(&codigo);
    if (pArrayListEmployee != NULL){
        cant = ll_len(pArrayListEmployee);
        if (codigo >0 && codigo <= cant){
            puntero = ll_get(pArrayListEmployee,codigo);
            free(puntero);
            ll_remove(pArrayListEmployee,codigo);
            printf ("\nSe elimino correctamente\n");
            system("pause");
            system("cls");
        }
        else{
            printf("\nEl codigo debe estar entre 1 y %d\n\n",cant);
            system("pause");
            system("cls");
        }
    }
    else{
        printf("\n\nError al eliminar el registro \n\n");
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
    for (i=1;i<cant;i++){
        lista = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %s\t %d\t %d\n",employee_getId(lista),employee_getNombre(lista),
                                     employee_getApellido(lista),
                                     employee_getDni(lista),
                                     employee_getClave(lista));
    }
    return 1;
}


int controller_ListEmployeeFichaje(LinkedList* pArrayListEmployee)
{
    int i,cant;
    cant = ll_len(pArrayListEmployee);
    Employee* lista;
    for (i=1;i<cant;i++){
        lista = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%d\t %d\t %d\t %d\t %d\t %d\t %s\t %s\n",employee_getId(lista),employee_getNombre(lista),
                                     employee_getApellido(lista),
                                     employee_getDni(lista),
                                     employee_getClave(lista));
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int i,j,len;
    Employee* actualEmpleado;
    Employee* empSiguiente;
    Employee* auxiliar;
    len = ll_len(pArrayListEmployee);
    for (i=1;i<len;i++){
        actualEmpleado = ll_get(pArrayListEmployee,i);
        for(j=i+1;j<len;j++){
            empSiguiente = ll_get(pArrayListEmployee,j);
            if (employee_getSueldo(actualEmpleado) > employee_getSueldo(empSiguiente)){
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

/*
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    Employee* auxEmpleado;
    len = ll_len(pArrayListEmployee);
    pArchivo = fopen(path,"r+");
    if (pArchivo == NULL){
        pArchivo = fopen(path,"w+");
    }
    if (len>0){
        for (i=0;i<len;i++){
        auxEmpleado = ll_get(pArrayListEmployee,i);
        fprintf(pArchivo,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}
*/
