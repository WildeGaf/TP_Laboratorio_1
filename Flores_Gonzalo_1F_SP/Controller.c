#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "controller.h"
#include "input.h"

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
    fclose(pArchivo);
    return 0;
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
        printf("%d\t %s\t %s\t %d\t %d\t %d\n",employee_getId(lista),employee_getNombre(lista),
                                          employee_getNivel(lista),employee_getCantidadProductos(lista),
                                          employee_getMonto(lista),employee_getValorCobrar(lista));
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

int controller_saveAsText(char* path ,LinkedList* pArrayListEmployee)
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
            fprintf(pArchivo,"%d,%s,%s,%d,%d,%f\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->nivel,
                                                    auxEmpleado->cantidadProductos,auxEmpleado->monto,
                                                    auxEmpleado->valorCobrar);
            total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}

void controller_asignarNivel(int numero,char* nivel){

    switch (numero){
    case 0:
        strcpy(nivel,"Junior");
    break;
    case 1:
        strcpy(nivel,"Estandard");
    break;
    case 2:
        strcpy(nivel,"Experto");
    break;
    }
}

void calcularComision(void* emp){
    Employee* punteroE;
    punteroE = emp;
    if (punteroE != NULL){
        if (strcmp(punteroE->nivel,"Junior")==0){
            punteroE->valorCobrar = (punteroE->monto * 2)/100;
        }
        if ((strcmp(punteroE->nivel,"Estandard")==0) ||
            (strcmp(punteroE->nivel,"Experto")==0)){
            if (punteroE->cantidadProductos < 100){
                punteroE->valorCobrar = (punteroE->monto * 3.5)/100;
            }
            else if (punteroE->cantidadProductos >= 100){
                punteroE->valorCobrar = (punteroE->monto * 5)/100;
            }
        }
    }
}

void nivelEmpleado (LinkedList* listaFiltrada,void* emp,int x){
    Employee* punteroE;
    punteroE = emp;
    if (punteroE != NULL){
        if (x==0){
            if (strcmp(punteroE->nivel,"Junior")==0){
                ll_add(listaFiltrada,punteroE);
            }
        }
        if (x==1){
            if (strcmp(punteroE->nivel,"Estandard")==0){
                ll_add(listaFiltrada,punteroE);
            }
        }
        if (x==2){
            if (strcmp(punteroE->nivel,"Experto")==0){
                ll_add(listaFiltrada,punteroE);
            }
        }
    }
}

