#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "controller.h"
#include "input.h"

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);

int main()
{
    int opcion;
    char doc[51];
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();
    opcion = menu();
    do{
        switch (opcion){
        case 1:
          printf("Ingrese el nombre del archivo sin la extension");
            getString(doc);
            strcat(doc,".csv");
            controller_loadFromText("data.csv",listaEmpleados);
            break;
        case 2:
            controller_ListEmployee(listaEmpleados);
            break;
        case 3:
            ll_map (listaEmpleados,&calcularComision);
            break;
        case 4:
            listaFiltrada = ll_filter(listaEmpleados,&nivelEmpleado);
            controller_saveAsText("info.csv",listaFiltrada);
            break;
        case 5:
            printf("\n\nAh salido del programa");
            break;
        }
        opcion = menu();
    }while(opcion != 5);
    return 0;
}
