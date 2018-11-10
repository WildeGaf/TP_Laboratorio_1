#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"

int menu(void){
int option;
printf("Menu trabajo practico numero 3");
printf("\nSeleccione 1- Para cargar los datos de los empleados en modo texo");
printf("\nSeleccione 2- Para cargar los datos de los empleados en modo binario");
printf("\nSeleccione 3- Para dar de alta un empleado");
printf("\nSeleccione 4- Para modificar los datos de un empleado");
printf("\nSeleccione 5- Para dar de baja un empleado");
printf("\nSeleccione 6- Para ordenar la lista de empleados");
printf("\nSeleccione 7- Para imprimir la lista de empleados");
printf("\nSeleccione 8- Para guardar los datos de los empleados en modo texto");
printf("\nSeleccione 9- Para guardar los datos de los empleados en modo binario");
printf("\nSeleccione 10- Para salir del programa");
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
    }
    return 0;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
FILE* pArchivo;
    if((pArchivo = fopen(path,"rb")) == NULL){
        printf("Error al abrir el archivo");
    }
    else{
    parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    }
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
   char* resp;
   char var1[50],var3[50],var2[50],var4[50];
   resp = "s";
   while (resp == "s"){
        printf("\nIngrese el id del empleado");
        getSringLetras(var1);
        printf("\nIngrese el nombre del empleado");
        getSringLetras(var2);
        printf("\nIngrese las horas trabajadas del empleado");
        getSringLetras(var3);
        printf("\nIngrese el sueldo del empleado");
        getSringLetras(var4);
        pB = employee_newParametros(var1,var2,var3,var4);
        ll_add(pArrayListEmployee,pB);
        printf("\nPara continuar ingresando datos ingrese s");
        getString(resp);
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
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee, int codigo)
{

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
    for (i=0;cant;i++){
        lista = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %d\t %d\n",employee_getId(lista),employee_getNombre(lista),employee_getHorasTrabajadas(lista),employee_getSueldo(lista));
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
    int i,len;
    Employee* Aux;
    len = ll_len(pArrayListEmployee);
    for (i=0,i<len,i++){
        for(j=i+1;j<len;j++){
            if (*(Aux.id))
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
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int cant,len;
    pArchivo = fopen(path,"r+");
    len = ll_len(pArrayListEmployee);
    cant = fwrite(pArrayListEmployee,sizeof(Employee),len,pArchivo);
    if (cant<len){
        printf("\nError al escribir el archivo");
    }
    else{
        printf("\nSe escribieron %d caracteres", cant);
    }
    fclose(path);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int cant,len;
    pArchivo = fopen(path,"r+b");
    len = ll_len(pArrayListEmployee);
    cant = fwrite(pArrayListEmployee,sizeof(Employee),len,pArchivo);
    if (cant<len){
        printf("\nError al escribir el archivo");
    }
    else{
        printf("\nSe escribieron %d caracteres", cant);
    }
    fclose(path);
    return 1;
}

