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
    LinkedList* listaComponentes = ll_newLinkedList();
    LinkedList* listaColor = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();
    option = menu();
    controller_loadFromText("componentes.txt",listaComponentes);
    controller_loadFromTextColor("color.txt",listaColor);
    controller_ListColor(listaColor);
    controller_ListComponente(listaComponentes);
    int cantF = ll_len(listaColor);
    int cantE = ll_len(listaComponentes);
    printf("%d %d",cantF,cantE);
   do{
        switch(option)
        {
            case 1:
                system("cls");
                controller_addComponente(listaComponentes);
                controller_ListComponente(listaComponentes);
                break;
            case 2:
                system("cls");
                controller_editComponente(listaComponentes);
                controller_ListComponente(listaComponentes);
                break;
            case 3:
                system("cls");
                controller_removeComponente(listaComponentes);
                controller_ListComponente(listaComponentes);
                break;
            case 4:
                system("cls");
                controller_ListaComponentesBase(listaComponentes,listaFiltrada);
                ll_sort(listaFiltrada,employee_sortByName,1);
                controller_ListComponente(listaFiltrada);
                break;
           case 5:
                system("cls");
                NuevoColor(listaColor,listaComponentes);
                controller_ListColor(listaColor);
                break;
           case 6:
              ComponentesColor(listaColor);
                break;
           case 7:
               controller_saveAsTextColor("color.txt",listaColor);
               controller_saveAsTextComp("componentes.txt",listaComponentes);
                break;
        }
    option = menu();
    }while(option != 8);
    printf("Ha salido del programa\n\n");
    return 0;
}
