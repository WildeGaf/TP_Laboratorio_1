#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListColor(LinkedList* pArrayListEmployee);
int controller_ListComponente(LinkedList* pArrayListEmployee);
//int controller_sortEmployee(LinkedList* listaFiltrada);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromTextColor(char* path, LinkedList* pArrayListEmployee);
int menu(void);
int controller_ListaFecha(LinkedList* listaEmpleados,LinkedList* listaFichajes,LinkedList* listaFiltrada);
int controller_ListEmployeeComponentes(LinkedList* listaFichaje);
void fichajeEmpleado(LinkedList* listaEmpleado,LinkedList* listaFichaje);
int controller_saveAsTextFichaje(char* path , LinkedList* lista);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
void controller_esBase(char* nombre,int base);
int controller_addComponente(LinkedList* pArrayListEmployee);
int controller_editComponente(LinkedList* pArrayListEmployee);
int controller_removeComponente(LinkedList* pArrayListEmployee);
int controller_ListaComponentesBase(LinkedList* listaComponentes,LinkedList* listaFiltrada);
void NuevoColor(LinkedList* listaColor,LinkedList* listaComponentes);
int controller_CheckBase(LinkedList* listaColor,LinkedList* listaComponentes,int idColor);
int controller_saveAsTextComp(char* path , LinkedList* lista);
int controller_saveAsTextColor(char* path , LinkedList* lista);
void ComponentesColor(LinkedList* listaColor);
#endif // CONTROLLER_H_INCLUDED


