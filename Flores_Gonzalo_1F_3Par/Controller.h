#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
//int controller_sortEmployee(LinkedList* listaFiltrada);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromTextFichaje(char* path, LinkedList* pArrayListEmployee);
int menu(void);
int controller_ListaFecha(LinkedList* listaEmpleados,LinkedList* listaFichajes,LinkedList* listaFiltrada);
int controller_ListEmployeeFichaje(LinkedList* listaFichaje);
void fichajeEmpleado(LinkedList* listaEmpleado,LinkedList* listaFichaje);
int controller_saveAsTextFichaje(char* path , LinkedList* lista);
int controller_sortEmployee(LinkedList* pArrayListEmployee);


#endif // CONTROLLER_H_INCLUDED


