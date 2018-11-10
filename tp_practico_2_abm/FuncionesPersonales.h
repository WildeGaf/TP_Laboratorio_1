#ifndef FUNCIONESPERSONALES_H_INCLUDED
#define FUNCIONESPERSONALES_H_INCLUDED

typedef struct
{
     int id;
     char name[51];
     char lastName[51];
     float salary;
     int sector;
     int isEmpty;
}Employee;

int menu();
int suma(int,int);
int resta(int,int);
int division(int,int);
int multiplicacion(int,int);
int factorial(int);
void getInt(int*);
void getFloat(float*);
void getChar(char*);
int getString(char input[]);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);
int getSringLetras(char input[]);
int sortEmployees(Employee* lista, int len, int order);
void removeEmployee(Employee* lista, int len, int id);

int initEmployees(Employee* lista, int len);

int addEmployee(Employee* lista, int len,int id,
                char name[],char lastName[],
                float salary, int sector);
int findEmployeeById(Employee* lista, int len,int id);


#endif // FUNCIONESPERSONALES_H_INCLUDED
