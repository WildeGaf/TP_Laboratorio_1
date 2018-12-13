#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{
  int id;
  char nombre[51];
  char nivel[51];
  int cantidadProductos;
  int monto;
  float valorCobrar;
}Employee;

void employee_setId(Employee* this,int id);
int employee_getId(Employee* this);

void employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this);

void employee_setNivel(Employee* this,char* nivel);
char* employee_getNivel(Employee* this);

void employee_setCantidadProductos(Employee* this,int cantidadProductos);
int employee_getCantidadProductos(Employee* this);

void employee_setMonto(Employee* this,int monto);
int employee_getMonto(Employee* this);

void employee_setValorCobrar(Employee* this,float valor);
int employee_getValorCobrar(Employee* this);

Employee* employee_newParametros(char *var1, char *var2, char *var3, char *var4,char *var5);

int menu();

#endif // EMPLEADO_H_INCLUDED
