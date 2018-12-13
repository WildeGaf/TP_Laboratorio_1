#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
void controller_asignarNivel(int numero,char* nivel);
void calcularComision(void* emp);
void nivelEmpleado (LinkedList* listaFiltrada,void* emp,int x);
#endif // CONTROLLER_H_INCLUDED


