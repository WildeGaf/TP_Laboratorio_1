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
        char var1[50],var3[50],var2[50],var4[50],var5[50];
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
        do{
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
            if(r==5){
                Employee* p = employee_newParametros(var1, var2, var3, var4,var5);
                i++;
                ll_add(pArrayListEmployee,p);
            }
            else
                break;
        }while( !feof(pFile));
    }
    return i;
}

int parser_EmployeeFromTextFichajes(FILE* pFile , LinkedList* pArrayListEmployee){
    int r,i=0;
    if (pFile == NULL){
        printf ("Error al leer el archivo");
    }
    else{
        char var1[50],var3[50],var2[50],var4[50],var5[50],var6[50],var7[50],var8[50];
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7,var8);
        do{
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7,var8);
            if(r==8){
                eFichaje* p = eFichaje_newParametros(var1, var2, var3, var4,var5,var6,var7,var8);
                i++;
                ll_add(pArrayListEmployee,p);
            }
            else
                break;
        }while( !feof(pFile));
    }
    return i;
}
