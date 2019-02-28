#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"

int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaFichajes = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();
    option = menu();
    int bandera = 0;
    controller_loadFromText("socios.csv",listaEmpleados);
    controller_loadFromTextFichaje("fichajes.csv",listaFichajes);
    int cantF = ll_len(listaFichajes);
    int cantE = ll_len(listaEmpleados);
    printf("%d %d",cantF,cantE);
    do{
        switch(option)
        {
            case 1:
                system("cls");
                controller_addEmployee(listaEmpleados);
                break;
            case 2:
                system("cls");
                controller_editEmployee(listaEmpleados);
                break;
            case 3:
                system("cls");
                controller_removeEmployee(listaEmpleados);
                break;
           case 4:
                system("cls");
                controller_ListaFecha(listaEmpleados,listaFichajes,listaFiltrada);
                ll_sort(listaFiltrada,employee_sortByName,1);
                controller_ListEmployee(listaFiltrada);
                bandera = 1;
                break;
           case 5:
                system("cls");
                fichajeEmpleado(listaEmpleados,listaFichajes);
                controller_ListEmployeeFichaje(listaFichajes);
                break;
           case 6:
              controller_ListaFecha(listaEmpleados,listaFichajes,listaFiltrada);
              controller_ListEmployee(listaFiltrada);
              bandera = 1;
                break;
           case 7:
                if (bandera == 1){
                controller_saveAsText("empleadosFiltrados",listaFiltrada);
                }
                else {
                    printf("Debe crear la lista primero");
                }
                break;
           case 8:
               controller_saveAsText("socios.csv",listaEmpleados);
               controller_saveAsTextFichaje("fichajes.csv",listaFichajes);
               break;
           case 9:
                printf("Ha salido del programa");
            break;
        }
    option = menu();
    }while(option != 9);
    printf("Ha salido del programa\n\n");
    return 0;
}
