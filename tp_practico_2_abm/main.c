#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesPersonales.h"
#define CANT 1000


int main()
{
    Employee lista[CANT];


    char auxiliarNombre[51];
    char auxiliarApellido[51];
    int empleadoIdEncontrado,eleccionModificar;
    int bandera = 0,banderaPrimerDato = 0;
    int validarString;
    int auxId;
    int orden;
    int auxSector;
    int contador;
    int contadorMayorSalario=0;
    float auxSalario;
    float promedio=0,acumulador=0;
    int indiceLugarLibre;
    int eleccion = 0;
    int i;

    for (i=0;i<CANT;i++){
        lista[i].isEmpty = 0;
    }

    while (eleccion != 6){
        printf("------------Administracion de empleados------------\n");
        printf("1- Ingrese 1 para dar de alta a un empleado\n");
        printf("2- Ingrese 2 para dar de baja a un empleado\n");
        printf("3- Ingrese 3 para modificar los datos de un empleado\n");
        printf("4- Ingrese 4 para ordenarlos alfabeticamente\n");
        printf("5- Ingrese 5 para imprimir los datos de los empleados\n");
        printf("6- Ingrese 6 para salir del programa e imprimir el promedio\n\n");
        getInt(&eleccion);
        system("cls");
        switch (eleccion){
        case 1:
            indiceLugarLibre = initEmployees(lista,CANT);
            if(indiceLugarLibre == -1){
                printf("No quedan lugares disponibles.\n");
                break;
            }
            printf("Alta de empleado");
            do{
            printf("\n\nIngrese el nombre: ");
            fflush(stdin);
            validarString = getSringLetras(auxiliarNombre);
            }while (validarString != 1);
            do{
            printf("\nIngrese el apellido: ");
            fflush(stdin);
            validarString = getSringLetras(auxiliarApellido);
            }while (validarString != 1);
            printf("\nIngrese el sector: ");
            getInt(&auxSector);
            printf("\nIngrese el salario: ");
            getFloat(&auxSalario);
            auxId = indiceLugarLibre;
            addEmployee(lista,CANT,auxId,auxiliarNombre,auxiliarApellido,auxSalario,auxSector);
            banderaPrimerDato = 1;
            system("cls");
            break;
            case 2:
                if (banderaPrimerDato == 1){
                    printf("Ingrese el id del empleado al que desea borrar del registro");
                    getInt(&auxId);
                    removeEmployee(lista,CANT,auxId);
                    break;
                }
                else{
                    printf("No se ha ingresado ningun dato\n\n");
                    break;
                }
            case 3:
                if (banderaPrimerDato == 1){
                    printf("Ingrese el id del empleado al que desea modificar el registro");
                    getInt(&auxId);
                    empleadoIdEncontrado = findEmployeeById(lista,CANT,auxId);
                    if (empleadoIdEncontrado != -1){
                        printf("\nNombre: %s",lista[i].name);
                        printf("\nApellido: %s",lista[i].lastName);
                        printf("\nSector: %d",lista[i].sector);
                        printf("\nSalario: %f",lista[i].salary);
                        printf("\nId: %d\n\n",lista[i].id);
                        printf("\nIngrese para cambiar 1-Apellido 2-Nombre 3-Sector 4-Salario");
                        getInt(&eleccionModificar);
                        switch(eleccionModificar){
                            case 1:
                                printf("\n\nIngrese el nombre: ");
                                getSringLetras(auxiliarNombre);
                                strcpy(lista[empleadoIdEncontrado].name,auxiliarNombre);
                                break;
                            case 2:
                                printf("\n\nIngrese el apellido: ");
                                getSringLetras(auxiliarApellido);
                                strcpy(lista[empleadoIdEncontrado].lastName,auxiliarApellido);
                            break;
                            case 3:
                                printf("\n\nIngrese el sector: ");
                                getInt(&auxSector);
                                lista[empleadoIdEncontrado].sector = auxSector;
                            break;
                            case 4:
                                printf("\n\nIngrese el salario: ");
                                getFloat(&auxSalario);
                                lista[empleadoIdEncontrado].salary = auxSalario;
                            break;
                        }

                        }
                        else {
                            printf("El id buscado no se encuentra en el registro");
                             break;
                        }
                    }
                    else{
                    printf("No se ha ingresado ningun dato\n\n");
                    break;
                    }
            case 4:
                if (banderaPrimerDato == 1){
                    printf("Ingrese 1 para ordenar de menor a mayor o 0 para ordenar de mayor a menor: ");
                    getInt(&orden);
                    sortEmployees(lista,CANT,orden);
                    system("cls");
                    break;
                }
                else{
                    printf("No se ha ingresado ningun dato\n\n");
                break;
                }
            case 5:
                for (i=0;i<CANT;i++){
                    if (lista[i].isEmpty == 1){
                        printf("\nNombre: %s",lista[i].name);
                        printf("\nApellido: %s",lista[i].lastName);
                        printf("\nSector: %d",lista[i].sector);
                        printf("\nSalario: %f",lista[i].salary);
                        printf("\nId: %d\n\n",lista[i].id);
                        system("pause");
                        system("cls");
                        }
                }
                break;
            case 6:
            for (i=0;i<CANT;i++){
                if (lista[i].isEmpty == 1){
                    contador++;
                    acumulador = acumulador + lista[i].salary;
                    bandera = 1;
                }
            }
            if (bandera == 1){
                promedio = acumulador/contador;
                for (i=0;i<CANT;i++){
                        if (lista[i].isEmpty == 1){
                            if (lista[i].salary > promedio){
                            contadorMayorSalario++;
                            }
                        }
                }
            printf("El promedio es de: %f y la cantidad de empleados con mayor sueldo que el promedio es de: %d \n",promedio,contadorMayorSalario);
            }
            printf("\nEl programa ah finalizado");
            break;

        }
    }

return 0;
}
