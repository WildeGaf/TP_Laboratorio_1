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
printf("\nSeleccione 1- Para dar de alta");
printf("\nSeleccione 2- Para modificar");
printf("\nSeleccione 3- Para dar de baja");
printf("\nSeleccione 4- Para imprimir la lista de color");
printf("\nSeleccione 5- Para agregar un color");
printf("\nSeleccione 6- Para imprimir una lista con las cantidades necesarias");
printf("\nSeleccione 7- Para guardar las listas");
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
        parser_eComponente(pArchivo,pArrayListEmployee);
        printf("\n\nDatos cargados con Exito!\n\n");
    }
    fclose(pArchivo);
    return 0;
}

int controller_loadFromTextColor(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo = fopen(path,"r+");
    if(pArchivo == NULL){
        printf("Error al leer el archivo");
    }
    else{
        parser_eColor(pArchivo,pArrayListEmployee);
        printf("\n\nDatos cargados con Exito!\n\n");
    }
    fclose(pArchivo);
    return 0;
}

void controller_esBase(char* nombre,int base){
    if (base == 1){
        strcpy(nombre,"Base");
    }
    else if(base == 0){
        strcpy(nombre,"Pigmento");
    }
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_addComponente(LinkedList* pArrayListEmployee)
{
   eComponente* pB;
   eComponente* lastPoint;
   int resp,cant;
   char var1[50],var3[50],var2[50];
   do{
        cant = ll_len(pArrayListEmployee);
        lastPoint = ll_get(pArrayListEmployee,cant-1);
        cant = lastPoint->idComponente;
        sprintf(var1,"%d",cant+1);
        printf("\nIngrese el nombre del componente: ");
        fflush(stdin);
        getString(var2);
        printf("\nIndique 1- Base o 0-Pigmento ");
        fflush(stdin);
        getString(var3);
        pB = eComponente_newParametros(var1,var2,var3);
        ll_add(pArrayListEmployee,pB);
        printf("\nPara continuar ingresando datos ingrese 1 o 0 para terminar: ");
        getInt(&resp);
        system("cls");
        }while (resp==1);
   // controller_saveAsText("componentes.csv",pArrayListEmployee);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_editComponente(LinkedList* pArrayListEmployee)
{
    int id,resp,i,cant,bandera=0;
    char auxNombre[51],auxApellido[51];
    int auxId;
    eComponente* puntero;
    eComponente* ultimo;
    eComponente* primero;
    printf ("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
        getInt(&resp);
        if (resp == 1){
            controller_ListComponente(pArrayListEmployee);
        }
    printf ("\nIngrese el id del componente a modificar: ");
    getInt(&id);
    cant = ll_len(pArrayListEmployee);
    ultimo = ll_get(pArrayListEmployee,cant-1);
    primero = ll_get(pArrayListEmployee,0);
    if ((pArrayListEmployee != NULL && id >= primero->idComponente) && (id <= ultimo->idComponente)){
        for (i=0;i<=cant;i++){
           puntero = ll_get(pArrayListEmployee,i);
           auxId = puntero->idComponente;
            if (auxId == id){
            bandera = 1;
                break;
            }
        }
    }
        if (bandera == 1){
            printf("1-Para modificar el Nombre\t 2-Para Base o Pigmento  \t 3- Para todos");
            getInt(&resp);
            switch(resp){
                case 1:
                    printf("\nIngrese el nombre a asignar");
                    getString(auxNombre);
                    strcpy(puntero->nombre,auxNombre);
                    break;
                case 2:
                    printf("\nIngrese 1-Base o 0-Pigmento");
                    getString(auxApellido);
                    strcpy(puntero->base,auxApellido);
                    break;
                case 3:
                    printf("\nIngrese el nombre a asignar");
                    getString(auxNombre);
                    strcpy(puntero->nombre,auxNombre);
                    printf("\nIngrese Base o Pigmento");
                    getString(auxApellido);
                    strcpy(puntero->base,auxApellido);
                    //controller_saveAsText("componentes.txt",pArrayListEmployee);
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
int controller_removeComponente(LinkedList* pArrayListEmployee)
{
    int cant,id,resp,i,auxId;
    eComponente* puntero;
    eComponente* ultimo;
    eComponente* primero;
    printf ("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
        getInt(&resp);
        if (resp == 1){
            controller_ListComponente(pArrayListEmployee);
        }
    printf ("\nIngrese el id del empleado a borrar: ");
    getInt(&id);
    cant = ll_len(pArrayListEmployee);
    ultimo = ll_get(pArrayListEmployee,cant-1);
    primero = ll_get(pArrayListEmployee,0);
    if ((pArrayListEmployee != NULL && id >= primero->idComponente) && (id <= ultimo->idComponente)){
        for (i=0;i<=cant;i++){
           puntero = ll_get(pArrayListEmployee,i);
           auxId = puntero->idComponente;
            if (auxId == id){
            ll_remove(pArrayListEmployee,i);
            printf ("\nSe elimino correctamente\n");
            system("pause");
            system("cls");
            //controller_saveAsText("probando.csv",pArrayListEmployee);
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
int controller_ListComponente(LinkedList* pArrayListEmployee)
{
    int i,cant;
    cant = ll_len(pArrayListEmployee);
    eComponente* lista;
    for (i=0;i<cant;i++){
        lista = (eComponente*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %s\n",eComponente_getIdComponente(lista),
                                eComponente_getNombre(lista),
                                eComponente_getBase(lista));
    }
    return 1;
}


int controller_ListColor(LinkedList* listaFichaje)
{
    int i,cant;
    cant = ll_len(listaFichaje);
    eColor* lista;
    for (i=0;i<cant;i++){
        lista = (eColor*)ll_get(listaFichaje,i);
        printf("%d\t %s\t %d\t %d\n",eColor_getIdColor(lista),
                                     eColor_getNombre(lista),
                                     eColor_getIdComponente(lista),
                                     eColor_getCantidad(lista));
    }
    return 1;
}


int controller_ListaComponentesBase(LinkedList* listaComponentes,LinkedList* listaFiltrada){
    int cant,i, total = 0;
    eComponente* punteroC;
    cant = ll_len(listaComponentes);
    for (i=0;i<cant-1;i++){
        punteroC = ll_get(listaComponentes,i);
        if (strcmp(punteroC->base,"Base")==0){
            ll_add(listaFiltrada,punteroC);
        }
    }
    total = ll_len(listaFiltrada);
    printf("%d",total);
    printf ("\n\nSe encontaron %d componentes\n\n",total);
return 0;
}

void NuevoColor(LinkedList* listaColor,LinkedList* listaComponentes){
    eComponente* punteroComp;
    eColor* punteroColor;
    char idColorAux[51],componenteAux[51],colorAux[50],cantidadAux[50];
    int i,idComponenteAux,cantComp,cantColor,resp,base;
    printf("Ingrese el nombre del Color");
    getString(colorAux);
    cantColor = ll_len(listaColor);
    cantComp = ll_len(listaComponentes);
    for (i=0;i<cantColor-1;i++){
        punteroColor = ll_get(listaColor,i);
        if (strcmp (punteroColor->nombre,colorAux)==0){
            base = controller_CheckBase(listaColor,listaComponentes,punteroColor->idColor);//Verifica si ya existe un comp base
            sprintf(idColorAux,"%d",punteroColor->idColor);

        }else{
            sprintf(idColorAux,"%d",cantColor+1);
        }
    }
    do{
        printf("Desea imprimir la lista de componentes 1-Si 0-No");
        getInt(&resp);
        if (resp == 1){
            controller_ListComponente(listaComponentes);
        }
        printf("Ingrese el id del Componente");
        getInt(&idComponenteAux);
        for (i=0;i<cantComp-1;i++){
            punteroComp = ll_get(listaComponentes,i);
            if (punteroComp->idComponente == idComponenteAux){
                if (strcmp(punteroComp->base,"Pigmento")==0){
                    sprintf(componenteAux,"%d",punteroComp->idComponente);
                    resp = 0;
                }
                else{
                    if (base == 1){
                        printf("Ya se encuentra un componente Base");
                    }
                    else{
                        sprintf(componenteAux,"%d",punteroComp->idComponente);
                        resp =0;
                    }
                }
            }
        }
        }while(resp==1);
        printf("Ingrese la cantidad");
        getString(cantidadAux);
    punteroColor = eColor_newParametros(idColorAux,colorAux,componenteAux,cantidadAux);
    ll_add(listaColor,punteroColor);
    system("cls");
    controller_ListColor(listaColor);
    system("pause");
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

void ComponentesColor(LinkedList* listaColor){
    int cantColor,idColorAux,resp,litros,i;
    eColor* punteroColor;
    cantColor = ll_len(listaColor);
    printf("\nDesea imprimir la lista? 1-Si 0-No\n");
    getInt(&resp);
    if (resp == 1){
        controller_ListColor(listaColor);
    }
        printf("\nIngrese el id del color\n");
        getInt(&idColorAux);
        printf("\nIngrese la cantidad de litros");
        getInt(&litros);
        for (i=0;i<cantColor;i++){
            punteroColor = ll_get(listaColor,i);
            if (punteroColor->idColor == idColorAux){
                printf ("\n\nID componente : %d Cantidad necesaria : %d\n\n",punteroColor->idComponente,punteroColor->cantidad*litros);
            }
        }
}

int controller_CheckBase(LinkedList* listaColor,LinkedList* listaComponentes,int idColor){
    int cantComp,cantColor,i,j,base=0;
    eColor* punteroColor;
    eComponente* punteroComp;
    cantColor = ll_len(listaColor);
    cantComp= ll_len(listaComponentes);
    for (i=0;i<cantColor-1;i++){
        punteroColor = ll_get(listaColor,i);
        if (idColor == punteroColor->idColor){
            for(j=0;j<cantComp-1;j++){
                punteroComp = ll_get(listaComponentes,j);
                if (punteroComp->idComponente == punteroColor->idComponente){
                    if(strcmp(punteroComp->base,"Base")==0){
                       base = 1;
                       }
                }
            }
        }
    }
return base;

}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsTextComp(char* path , LinkedList* lista)
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    eComponente* listaComponentes;
    len = ll_len(lista);
    pArchivo = fopen(path,"r+");
    if (pArchivo == NULL){
        pArchivo = fopen(path,"w+");
    }
    if (len>0){
        for (i=0;i<len;i++){
            listaComponentes = ll_get(lista,i);
            fprintf(pArchivo,"%d,%s,%s\n",eComponente_getIdComponente(listaComponentes),
                                            eComponente_getNombre(listaComponentes),
                                            eComponente_getBase(listaComponentes));
        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}


int controller_saveAsTextColor(char* path , LinkedList* lista)
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    eColor* listaColor;
    len = ll_len(lista);
    pArchivo = fopen(path,"r+");
    if (pArchivo == NULL){
        pArchivo = fopen(path,"w+");
    }
    if (len>0){
        for (i=0;i<len-1;i++){
        listaColor = ll_get(lista,i);
        fprintf(pArchivo,"%d,%s,%d,%d\n",eColor_getIdColor(listaColor),
                                        eColor_getNombre(listaColor),
                                        eColor_getIdComponente(listaColor),
                                        eColor_getCantidad(listaColor));
        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}


