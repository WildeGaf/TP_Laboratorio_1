#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesPersonales.h"


/************ FUNCIONES CALCULADORA **************/

/**
* @brief Se imprime una lista de opciones, en la cual el usuario debe seleccionar una.
* @return Devuelve un valor correspondido a la opcion seleccionada.
*/

int menu(){
    int opcion;
    printf("Menu de la calculadora\n");
    printf("\n1- Ingrese 1 para realizar una suma \n");
    printf("2- Ingrese 2 para realizar una resta \n");
    printf("3- Ingrese 3 para realizar una division \n");
    printf("4- Ingrese 4 para realizar una multiplicacion \n");
    printf("5- Ingrese 5 para realizar el factorial \n");
    printf("6- Ingrese 6 para realizar todas las operaciones \n");
    printf("\nDigite la opcion elegida: ");
    scanf("%d",&opcion);
    return opcion;
}

/**
* @brief Suma dos valores enteros.
* @param num1 El primer valor, para realizar la operacion.
* @param num2 El segundo valor, para realizar la operacion.
* @return Devuelve el resultado de la suma de los operadores ingresados.
*/
int suma(int num1, int num2){
    int suma;
    suma = (num1+num2);
    return suma;
}

/**
* @brief Resta dos valores enteros.
* @param num1 El primer valor, para realizar la operacion.
* @param num2 El segundo valor, para realizar la operacion.
* @return Devuelve el resultado de la resta de los operadores ingresados.
*/
int resta(int num1, int num2){
    int resta;
    resta = num1-num2;
    return resta;
}

/**
* @brief Multiplica dos valores enteros.
* @param num1 El primer valor, para realizar la operacion.
* @param num2 El segundo valor, para realizar la operacion.
* @return Devuelve el resultado de la multiplicacion de los operadores ingresados.
*/
int multiplicacion(int num1,int num2){
    int multi;
    multi = num1*num2;
    return multi;
}

/**
* @brief Divide dos valores enteros y si no es posible da mensaje de error.
* @param num1 El primer valor, para realizar la operacion.
* @param num2 El segundo valor, para realizar la operacion el cual debe ser distinto de 0.
* @return Devuelve el resultado de la division de los operadores ingresados.
*/
int division(int num1,int num2){
    int div;
    div = num1/num2;
    return div;
}

/**
* @brief Realiza el factorial de un numero ingresado, en caso de que sea un numero negativo, da un mensaje de error.
* @param num El numero al cual se desea realizar el factorial.
* @return Devuelve el resultado del factorial del numero ingresado.
*/
int factorial(int num){
    int contador,acumuladorUno=0;
    if (num<0){
        return -1;
    }
    else{
        if (num==0 || num==1){
           return 1;
           }
        else{
            for (contador=num-1;contador!=0;contador--){
                acumuladorUno = num * contador + acumuladorUno;
            }
        }
    return acumuladorUno;
    }
}


/**************ENTRADA DE DATOS*****************/


void getInt(int* puntero)
{
    int numero;
    scanf("%d",&numero);
    *puntero = numero;
}

void getFloat(float* puntero)
{
    float numero;
    scanf ("%f",&numero);
    *puntero = numero;
}

void getChar(char* mensaje)
{
    char letra;
    fflush(stdin);
    scanf("%c",&letra);
    *mensaje = letra;

}

int getString(char* input){
scanf("%s",input);
return 0;
}

/**************VALIDACION DE DATOS*****************/

int esNumerico(char str[]){
    int i=0;
    while(str[i] != '\0' ){
        if(str[i]<'0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[]){
    int i=0;
    while(str[i] != '\0'){
        if ((str[i] != ' ') &&
            (str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z')){
            return 0;}
        i++;
    }
    return 1;
}

int esAlfaNumerico(char str[]){
    int i=0;
     while(str[i] != '\0'){
        if ((str[i] != ' ') &&
            (str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < '0' || str[i] > '9'))
        return 0;
    }
    return 1;
}

int esTelefono(char str[])
{
    int i = 0;
    int contadorGuiones = 0;
    while (str[i] != '\0'){
        if ((str[i] != ' ') && (str[i] != '-') &&
            (str[i] < '0' || str[i] > '9')){
            return 0;}
        if (str[i] == '-'){
            contadorGuiones++;
        }
        i++;
    }
    if (contadorGuiones==1){
        return 1;
    }
    return 0;
}

int getSringLetras(char input[]){
    char aux[256];
    getString(aux);
    if (esSoloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**************FUNCIONES AGENDA*****************/

int initEmployees(Employee* lista, int len){
int i,retorno;
retorno = -1;
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }
return retorno;
}


int addEmployee(Employee* lista, int len,int id,
                char name[],char lastName[],
                float salary, int sector)
{
    int r,retorno = -1;
    r = initEmployees(lista,len);
    if (r != -1){
        strcpy(lista[r].name,name);
        strcpy(lista[r].lastName,lastName);
        lista[r].salary = salary;
        lista[r].sector = sector;
        lista[r].id = id;
        lista[r].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}

int findEmployeeById(Employee* lista, int len,int id)
{
    int retorno = -1;
    int i;
    for (i=0;i<len;i++){
        if(lista[i].id == id){
            retorno = i;
            break;
        }
    }
return retorno;
}

int sortEmployees(Employee* lista, int len, int order)
{
 Employee AuxLista;
 int i,j,retorno;
 retorno = -1;
    if(lista != NULL && len>0){
        for (i=0;i<len;i++){
            for(j=i+1;j<len;j++){
                if (order == 1)
                {
                    if(strcmp(lista[i].lastName,lista[j].lastName)>0)
                    {
                        AuxLista = lista[i];
                        lista[i] = lista[j];
                        lista[j] = AuxLista;
                        retorno = 0;
                    }
                    else{
                        if (strcmp(lista[i].lastName,lista[j].lastName)==0)
                        {
                                  if (lista[i].sector > lista[i].sector)
                                  {
                                        AuxLista = lista[i];
                                        lista[i] = lista[j];
                                        lista[j] = AuxLista;
                                        retorno = 0;
                                  }
                        }
                    }
                }
                else
                {
                   if(strcmp(lista[i].lastName,lista[j].lastName)<0)
                   {
                        AuxLista = lista[i];
                        lista[i] = lista[j];
                        lista[j] = AuxLista;
                        retorno = 0;
                   }
                    else
                    {
                        if(strcmp(lista[i].lastName,lista[j].lastName)==0)
                        {
                            if (lista[i].sector < lista[j].sector)
                            {
                                AuxLista = lista[i];
                                lista[i] = lista[j];
                                lista[j] = AuxLista;
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
    }
return retorno;
}

void removeEmployee(Employee* lista, int len, int id){
    int empleadoIdEncontrado;
    empleadoIdEncontrado = findEmployeeById(lista,len,id);
    if (empleadoIdEncontrado == -1){
        printf("Ese id no se encuentra en el registro");
    }
    else{
    lista[empleadoIdEncontrado].isEmpty = 0;
    }
}




