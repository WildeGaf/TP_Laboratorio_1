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
    int bandera = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaFichajes = ll_newLinkedList();
    option = menu();
    controller_loadFromText("socios.csv",listaEmpleados);
    controller_loadFromText("fichajes.csv",listaFichajes);
    controller_ListEmployee(listaEmpleados);
    controller_ListEmployee(listaEmpleados);


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
           /* case 4:
                if (bandera == 1){
                system("cls");
                controller_editEmployee(listaEmpleados);
                }
                break;
            case 5:
                if (bandera == 1){
                system("cls");
                controller_removeEmployee(listaEmpleados);
                }
                break;
            case 6:
                if (bandera == 1){
                system("cls");
                controller_ListEmployee(listaEmpleados);
                system("pause");
                system("cls");
                }
                break;*/
        }
    option = menu();
    }while(option != 10);
    return 0;
}
