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

int parser_eComponente(FILE* pFile , LinkedList* pArrayListEmployee){
    int r,i=0;
    if (pFile == NULL){
        printf ("Error al leer el archivo");
    }
    else{
        char var1[50],var3[50],var2[50];
        r = fscanf(pFile,"%[^;];%[^;];%[^\n]\n",var1,var2,var3);
        do{
            r = fscanf(pFile,"%[^;];%[^;];%[^\n]\n",var1,var2,var3);
            if(r==3){
                eComponente* p = eComponente_newParametros(var1, var2, var3);
                i++;
                ll_add(pArrayListEmployee,p);
            }
            else
                break;
        }while( !feof(pFile));
    }
    return i;
}

int parser_eColor(FILE* pFile , LinkedList* pArrayListEmployee){
    int r,i=0;
    if (pFile == NULL){
        printf ("Error al leer el archivo");
    }
    else{
        char var1[50],var3[50],var2[50],var4[50];
        r = fscanf(pFile,"%[^;];%[^;];%[^;];%[^\n]\n",var1,var2,var3,var4);
        do{
            r = fscanf(pFile,"%[^;];%[^;];%[^;];%[^\n]\n",var1,var2,var3,var4);
            if(r==4){
                eColor* p = eColor_newParametros(var1, var2, var3, var4);
                i++;
                ll_add(pArrayListEmployee,p);
            }
            else
                break;
        }while( !feof(pFile));
    }
    return i;
}
