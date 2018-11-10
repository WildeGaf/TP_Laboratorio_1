#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "input.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    int r,i=0;
    if (pFile == NULL){
        printf ("Error al leer el archivo");
    }
    else{
        char var1[50],var3[50],var2[50],var4[50];
        //leo los titulos
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        do{
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
            if(r==4){
                Employee* p = employee_newParametros(var1, var2, var3, var4);
                i++;
                ll_add(pArrayListEmployee,p);
            }
            else
                break;
        }while( !feof(pFile));

    fclose(pFile);
    }
    return i;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    Employee* pBinario;
    if (pFile == NULL){
        printf ("Error al leer el archivo");
    }
    else{
        pBinario = employee_new();
        r = fread(pBinario,sizeof(Employee),1,pFile)!=0;
        do{
            if(r==1){
                ll_add(pArrayListEmployee,pBinario);
                printf("%d %s %d %d\n", employee_getId(pBinario), employee_getNombre(pBinario), employee_getSueldo(pBinario),
                       employee_getHorasTrabajadas(pBinario));
            }
            else
                break;
        }while( !feof(pFile));
    }
    return 1;
}
/*
Employee* pBinario = employee_new();
        while (fread(pBinario,size_t (Employee),1,pFile)!=0){
            if (strcmp(nombre,pBinario.nombre)==0){
                bandera = 1;
            }
        }
        */
